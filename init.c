/* Processor initialisation  routine */

#include "p30f6010A.h"

//configure oscillator
_FOSC(CSW_FSCM_OFF & HS3_PLL16); //26.667Mhz Fcy Tcy .0374995us
_FWDT(WDT_ON & WDTPSA_1 & WDTPSB_1); //watchdog timer on
_FBORPOR(MCLR_EN & PWMxH_ACT_HI & PWMxL_ACT_HI & PBOR_ON & BORV_42 & RST_IOPIN  );

void init(void)
{

//configure digital outputs
TRISGbits.TRISG0 = 0; 
TRISGbits.TRISG1 = 0; 
TRISGbits.TRISG2 = 0; 
TRISGbits.TRISG3 = 0; 
TRISGbits.TRISG6 = 0; 

//configure PWM
PTCONbits.PTMOD = 2;    //up down counting mode

PTPERbits.PTPER = 1777; //7.5Khz Fpwm

PWMCON1bits.PEN1L = 0;
PWMCON1bits.PEN2L = 0;
PWMCON1bits.PEN3L = 0;

PWMCON1bits.PEN1H = 0;
PWMCON1bits.PEN2H = 0;
PWMCON1bits.PEN3H = 0;

PWMCON2bits.IUE = 0;

//configure dead time
DTCON1bits.DTAPS = 2;
DTCON1bits.DTA = 10; //DT 2.99us//10

//fault input configuration
FLTBCONbits.FBEN1 = 0; //enable now
FLTBCONbits.FBEN2 = 0;
FLTBCONbits.FBEN3 = 0;

//timer1 configuration for sine sampling
PR1 = 3555; //7.5Khz
T1CONbits.TON = 0; //timer off

//timer2 for current control
PR2 = 1330; //20Khz
T2CONbits.TON = 0; //timer off

//timer3 for PLL
PR3 = 20700; //1.3Khz //
T3CONbits.TON = 0; //timer off

//timer4 for feedforward
PR4 = 53300; //0.5Khz //
T4CONbits.TON = 0; //timer off

//timer5 for oscillator
PR5 = 3555; //7.5Khz //
T5CONbits.TON = 0; //timer off

//ADC configuration

ADCON1bits.SSRC = 7;
ADCON1bits.SIMSAM = 0;

ADCON1bits.FORM = 2; //2 for q15 form
                     //0 for int form

ADCON2= 0; //CH0 only

ADCON3bits.SAMC = 2; //sample time 2*Tad //2
ADCON3bits.ADCS = 5; //4//Tconv = 112ns //5

ADPCFG = 0x8013;
ADCSSL = 0;

ADCON1bits.ADON = 1; //adc on

//configure interrupts
INTCON1bits.NSTDIS = 0; //disable interrupt nesting if set
IPC11bits.FLTBIP = 0x7;
IEC2bits.FLTBIE = 1; //enable fault interrupt
IEC0bits.T1IE = 1; //enable T1 interrupt
IEC0bits.T2IE = 0; //enable T2 interrupt
IPC0bits.T1IP = 0x6;
IEC2bits.PWMIE = 0; //enable pwm interrupt
}
