//user controlled variable definations//

//********************************************************
//Iout = (2.5+-(0.625*Ip/6)V)*(32735/5) 

//VDCout = (Vdc*15/600)V)*(32735/5)
//VACout = (2.5-(Vac*6.8/600)V)*(32735/5)
//transformer ratio 400/173 = 2.3121
//********************************************************

//general variables
int offset = 0;
int VDC_const = 29710; //3801  //[(6.8/15)*2]

//PI general variables
int PWM_max = 0; 
int PWM_min = 0;
int PWM_offset = 0;
int PWM_offset_N = 0;
int IPreError = 0;

// harmonic oscillator variables
int qSin = 0;
int qCos = 32440;        //initial value of 0.99

int OSC_F = 0; 
int OSC_Fmax =  45;
int OSC_Fmin = -45;
int OSC_Fcentral = 1372; //2*PI*F*T, F = 50Hz //1372
                         // 150samples //Fs/F

long theta = 205800;     //205800
long theta_2PI = 205800; //samples*OSC_Fcentral
                         //205800

//harmonic oscillator PI variables/////////////////////////
int iPI_Pgain = 18;   //HARMONIC PROPORTIONAL GAIN   //18
int iPI_Igain = 3;    //HARMONIC INTEGRAL GAIN       //3
///////////////////////////////////////////////////////////

int id_PI_out = 0;
int iq_PI_out = 0;

int Vgrid_Dvalue = 0;

//abc to dq variables
int Avalue = 0;
int Dvalue = 0;
int Qvalue = 0;

//Current control PI variables/////////////////////////////////
int P_Pgain = 27;        //CURRENT PROPORTIONAL GAIN //27
int P_Igain = 3;         //CURRENT INTEGRAL GAIN     //7
///////////////////////////////////////////////////////////////

int P_PIout = 0;

int I_ref = 0;

int ID_ref = 0;
int IQ_ref = 0;

//current reference///////////////////////////////////////////////////
int I_Dsetpoint = 742; //742 == 100Vpeak
//////////////////////////////////////////////////////////////////////

int DCLINK_MAX = 30800; //180V max//30800

//current protection variables
int current_max =  5440;  //+8A Ipeak limit //5440
int current_min = -5440;  //-8A Ipeak limit //-5440

//first order filter variables//////////////////////
int FOF_PreOut = 0;
int Filter_const_F = 1000;  // T/tau //25Hz/0.5Khz
int Filter_const_i = 273; // T/tau // 100HZ/12Khz
int Filter_const_p = 55;  // T/tau // 20Hz/12KHz
////////////////////////////////////////////////////

int _300ms_count = 1000;

int ffd_value = 0;

int sync_tick =  0;
int sync_flag = 0; 

int ffd_max =  1700;   //99% of max value 
int ffd_min = -1700;   //99% of min value 

int ffd_FOFout = 0;
int id_FOFout = 0;
int iq_FOFout = 0;

int p_FOFout = 0;













