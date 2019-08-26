/* definition header for system registers and functions used in main*/

#include "p30f6010A.h"

#define RL1_ON PORTGbits.RG0
#define RL2_ON PORTGbits.RG1
#define RL3_ON PORTGbits.RG2
#define RL4_ON PORTGbits.RG3
#define RL5_ON PORTGbits.RG6

#define PWM1 PDC1 //R PWM
#define PWM2 PDC2 //Y PWM
#define PWM3 PDC3 //B PWM

#define T1us_Flag IFS0bits.T1IF 
#define current_Flag IFS0bits.T2IF 
#define pll_Flag IFS0bits.T3IF 
#define ffd_Flag IFS1bits.T4IF 
#define osc_Flag IFS1bits.T5IF

#define pwm_flag IFS2bits.PWMIF

#define fault_Flag IFS2bits.FLTBIF

#define PWM_PERIOD PTPER 
#define Converstion_Done ADCON1bits.DONE
#define Start_Converstion ADCON1bits.SAMP

#define CH0_MULA ADCHSbits.CH0SA
#define CH0_MULB ADCHSbits.CH0SB

#define PWMenable PTCONbits.PTEN
#define PWM_InterruptEnable IEC2bits.PWMIE

#define T1ON T1CONbits.TON
#define T2ON T2CONbits.TON
#define T3ON T3CONbits.TON
#define T4ON T4CONbits.TON
#define T5ON T5CONbits.TON

#define ADC_ON ADCON1bits.ADON

#define FAULT_ENABLE FLTBCON

#define SET PWMCON1


//********************************************************
//function definations
void init(void);
void delay(unsigned int);
void starting(void);
//********************************************************






