//***********************************************************************************//
//*************GRID CONNECTED SINGLE PHASE HALF-BRIDGE INVERTER**********************// 
//*************BASED ON SINE PWM USING UNBALANCED DQ CONTROL*************************//
//***********************************************************************************//

#include "main.h"    // Include file containing processor registors definitions and function definitions
#include "user.h"    // Include definitions of local variables
#include "asmMath.h" // Include definition of math functions 

int main(void) //main
{
 
init();     // call processor initilisation code

starting(); // Before-PWM initiliasation and soft-start of system

  while(1) //main loop 
	{

//grid current control//
    if(current_Flag) //20Khz
       {  
           //generate dq references
           asm("disi #0x3FFF");
           Avalue = asmINT_MPQ(qSin,I_ref); //generate inverter current ref
           asm("disi #0x0000");

           asmABCtoDQ();
           ID_ref = Dvalue; //generate inverter current ref d
           IQ_ref = Qvalue; //generate inverter current ref q
           //

           //read inverter feedback current
          asm("disi #0x3FFF");
          Avalue = asmADC(0x0008) - offset; // read ADC channel 8 // inverter current feedback  
          asm("disi #0x0000");
           //

           //detect peak current
          if(Avalue > current_max) fault_Flag = 1;  //max current trip value
          if(Avalue < current_min) fault_Flag = 1;  //min current trip value

          asmABCtoDQ(); //convert feedback current to d-q frame

         /*current D PI******************************************************/
          IPreError = id_PI_out;
          id_PI_out = asmPIcontroller(ID_ref,Dvalue,iPI_Pgain,iPI_Igain);
           
         /*current Q PI******************************************************/
          IPreError = iq_PI_out;
          iq_PI_out = asmPIcontroller(IQ_ref,Qvalue,iPI_Pgain,iPI_Igain);

          //current D PI filter
          FOF_PreOut = id_FOFout;
          id_FOFout = asmFO_Filter(id_PI_out,Filter_const_i);

          //current Q PI filter
          FOF_PreOut = iq_FOFout;
          iq_FOFout = asmFO_Filter(iq_PI_out,Filter_const_i);

          Dvalue = id_FOFout + ffd_FOFout; //add feedforward feedback term  

          if(Dvalue >= PWM_offset) Dvalue = PWM_offset;
          if(Dvalue <= PWM_offset_N) Dvalue = PWM_offset_N;
       
          Qvalue = iq_FOFout;

          if(Qvalue >= PWM_offset) Qvalue = PWM_offset;
          if(Qvalue <= PWM_offset_N) Qvalue = PWM_offset_N;

          asmDQtoABC(); //generate single phase ref from d-q PI output

          asmPWM();     //generate Half-bridge duty cycle          
            
                               current_Flag = 0;   //reset flag
                                  } 
//current control//

//Power PLL//        
	if(pll_Flag) //12Khz _PLL_count
		{
          asm("disi #0x3FFF");
          Avalue = asmADC(0x0005) - offset; //adc channel 5 //read grid voltage 
          asm("disi #0x0000");

          asmABCtoDQ();         //single phase ac to unbalanced d-q frame
          Vgrid_Dvalue = Dvalue; //copy grid voltage magnitude 
                     
          //
          asm("disi #0x3FFF");
          Avalue = asmINT_MPQ(qSin,Avalue); //calculate fictious power = sine_ref*grid voltage
          asm("disi #0x0000");

          //Filter fictious power output
          FOF_PreOut = p_FOFout;
          p_FOFout = asmFO_Filter(Avalue,Filter_const_p);

          /*power PLL PI******************************************************/
          IPreError = P_PIout;
          P_PIout = asmPIcontroller(0,p_FOFout,P_Pgain,P_Igain); //set fictious power zero
          
          if(P_PIout >= OSC_Fmax) P_PIout = OSC_Fmax; //limit PI output
          if(P_PIout <= OSC_Fmin) P_PIout = OSC_Fmin;
         
				         pll_Flag = 0; //reset flag
						  }
//PLL//	


//feed forward and soft start//
		if(ffd_Flag) //0.5Khz   
      		{  
             asmDClink(); //monitor dc link and generate feedforward
              
              //ffd filter
              FOF_PreOut = ffd_FOFout;
              ffd_FOFout = asmFO_Filter(ffd_value,Filter_const_F);

                            //soft start and PLL sync delay
                            sync_tick++;

                            if((!sync_flag) && (sync_tick >= _300ms_count)) 
                                   {  
                                       if(ffd_value >= ffd_max) fault_Flag = 1;
                                       if(ffd_value <= ffd_min) fault_Flag = 1;

                                       if(ffd_value == 0) fault_Flag = 1; 
           
                                       SET = 0x0077; //all three switces are enabled
                                       sync_flag = 1; //reset sync flag 
                                       sync_tick = 0; //reset flag
                                    }   

                           if(sync_flag) //if PLL sync done
                                   {   
                                       if(ffd_value >= ffd_max) fault_Flag = 1;
                                       if(ffd_value <= ffd_min) fault_Flag = 1;

                                       if(ffd_value == 0) fault_Flag = 1; 

                                       I_ref++; //initiate soft start //update grid current ref

                                           if(I_ref >= I_Dsetpoint)
                                               { 
                                                 I_ref = I_Dsetpoint; //max grid current set
                           
                                                   }
                                       sync_tick = 0; //reset flag
                                       }
                             //soft start and sync delay  
                
       		                    ffd_Flag = 0; //reset flag
       							}
//feed forward and soft start//

    			ClrWdt();
    		}//while end////////////////////////////////////////////////////////

  
		ClrWdt();
	} //main end////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////


//T1 interrupt for oscillator tracking
		void _ISRFAST __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void) //7.5Khz
  			{   
                      
                  //harmonic oscillator for generating Sine and Cos ref. 
                  OSC_F = OSC_Fcentral + P_PIout; //determine angular frequency
                 
                  theta = theta + OSC_F;          //increment theta angle
     
         		    if(theta >= theta_2PI)        //reset harmonic oscillator
            		    {
           				qSin = 0;
           				qCos = 32440; //0.99
           				theta = 0;
              				}
              					else asmHARMONIC(); //Harmonic oscillator for power PLL
                
     			T1us_Flag = 0; //reset flag
                
   					} //T1 interupt end

///////////////////////////////////////////////////////////////////////

		//fault interrupt
		void _ISR __attribute__((interrupt, no_auto_psv)) _FLTBInterrupt(void)
  			 {
     			PWMenable = 0; //disable pwm
     			SET = 0;       //all switches off
          
     			RL2_ON = 0;    //open all relays
               
     			RL3_ON = 0;      
     			RL4_ON = 0; 
     			RL5_ON = 0;     
  
		fault_Flag = 0;  //reset flag
            
   			}//fault end

//////////////////////////////////////////////////////////////////////

		//initial startup routine before turning on PWM
			void starting(void)
  				{
                    PWM_offset = PWM_PERIOD;  //initialise PWM period value
                    PWM_offset_N = -PWM_PERIOD;

					PWM_max = PWM_offset*8;  //PI saturation values
					PWM_min = -PWM_offset*8;
					SET = 0;   //initialise PWM control registers
					PWMenable = 0; //reset PWM control register
					 //
					FAULT_ENABLE = 1; //0x000f; //reset fault register
					delay(30); //delay 30ms
					ADC_ON = 1;
					//precharging init
					RL1_ON = 1;  //precharging enable
					delay(15); //delay 1500ms
					//precharging init ends
					
					offset = asmADC(0x0e0e); //2.5V offset //read adc channel 14
					//
					//initiates startup
					RL1_ON = 0;  //precharging disable
					delay(30); //delay 30ms
					RL2_ON = 1;  //bypass precharging
					delay(30); //delay 30ms
					
					//set pwm
					PWM1 = PWM_offset;
					PWM2 = PWM_offset;
					PWM3 = PWM_offset;
					//SET = 0x0077; //all three switces are enabled
					//
					RL3_ON = 1;  //connect to grid
					delay(20); //delay 30ms
					RL4_ON = 1;
					delay(20); //delay 30ms
					RL5_ON = 1;
					
					delay(30); //delay 30ms
			
					PWMenable = 1;
					T1ON = 1;
                    T2ON = 1;
                    T3ON = 1;
                    T4ON = 1;
                    T5ON = 0; //not used
                    
					// 
					  	}//startup routine end

///////////////////////////////////////////////////////////////////////

			











