
/*-------------------------------------------------------------------------
 *
 * MPLAB-C30  dsPIC30F6010A processor header
 *
 * (c) Copyright 2005-2006 Microchip Technology, All rights reserved
 *
 * File Description / Notes:
 * =========================
 * 1] This header file defines special function registers (SFR), and useful  
 *    macros for the dsPIC30Fxxxx Family of Digital Signal
 *    Controllers (also referred to as the dsPIC).  
 * 2] The register and bit names used in this file match the  
 *    dsPIC30Fxxxx data sheets as closely as possible.  
 * 3] The memory locations of the registers defined in this header file are
 *    specified in the respective linker scripts.
 * 4] SFR definitions are listed in the ascending order of memory addresses
 *    and are grouped based on the module they belong to. For e.g., WREG10
 *    is listed before ACCAL, and the Core SFRs are grouped separately
 *    from the Interrupt Controller SFRs or the General Purpose Timer SFRs.
 * 
 * Revision History:
 * =================
 * --------------------------------------------------------------------------
 * Rev:   Date:        Details:                                     Who:
 * --------------------------------------------------------------------------
 * 4.1    31 Jan 2005  New file                                     P Sinha
 * 4.1a   14 Mar 2005  Removed LVD definitions                      P Sinha
 * 4.2    4  Apr 2005  Renamed EC_IO to ECIO and ERC_IO to ERCIO    P Sinha
 * 4.2a   11 Apr 2005  Corrected QEI register structures            P Sinha
 * 4.2b   27 Jun 2005  Fixed typos in comments regarding macros     G McCar
 * 4.3    1  Jul 2005  Updated section syntax in config macros      P Sinha
 * v3.00  02 Feb 2007  Added processor check                        S Curtis
 *                      (Rev reflects compiler version)
 * --------------------------------------------------------------------------
 *
 * ------------------------------------------------------------------------*/

#ifndef __dsPIC30F6010A__
#error "Include file does not match processor setting"
#endif

#ifndef __30F6010A_H
#define __30F6010A_H

/* ------------------------- */ 
/* Core Register Definitions */
/* ------------------------- */

/* W registers W0-W15 */
extern volatile unsigned int WREG0 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int WREG1 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int WREG2 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int WREG3 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int WREG4 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int WREG5 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int WREG6 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int WREG7 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int WREG8 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int WREG9 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int WREG10 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int WREG11 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int WREG12 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int WREG13 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int WREG14 __attribute__((__sfr__,__deprecated__,__unsafe__));
extern volatile unsigned int WREG15 __attribute__((__sfr__,__deprecated__,__unsafe__));

/* SPLIM: Stack Pointer Limit */
extern volatile unsigned int SPLIM __attribute__((__sfr__));

/* Alternative access structure for the 40-bit accumulators */
typedef struct tagACC {
    unsigned int L;
    unsigned int H;
    unsigned char U;
} ACC;

/* Acc A<15:0> */
extern volatile unsigned int ACCAL __attribute__((__sfr__));

/* Acc A<31:16> */
extern volatile unsigned int ACCAH __attribute__((__sfr__));

/* Acc A<39:32> */
extern volatile unsigned char ACCAU __attribute__((__sfr__));

/* Acc A defined as a structure consisting of the 3 parts */
extern volatile ACC ACCA __attribute__((__sfr__));

/* Acc B<15:0> */
extern volatile unsigned int ACCBL __attribute__((__sfr__));

/* Acc B<31:16> */
extern volatile unsigned int ACCBH __attribute__((__sfr__));

/* Acc B<39:32> */
extern volatile unsigned char ACCBU __attribute__((__sfr__));

/* Acc B defined as a structure consisting of the 3 parts */
extern volatile ACC ACCB __attribute__((__sfr__));

/* PCL: Program Counter low word */ 
extern volatile unsigned int PCL __attribute__((__sfr__));

/* PCH: Program Counter high byte */
extern volatile unsigned char PCH __attribute__((__sfr__));

/* TBLPAG: Table Page Register */
extern volatile unsigned char TBLPAG __attribute__((__sfr__));

/* PSVPAG: Program Space Visibility Page Register */
extern volatile unsigned char PSVPAG __attribute__((__sfr__));

/* RCOUNT: REPEAT loop count */
extern volatile unsigned int RCOUNT __attribute__((__sfr__));

/* DCOUNT: DO loop count */
extern volatile unsigned int DCOUNT __attribute__((__sfr__));

/* DOSTARTL: DO loop start address bits <15:0> */
extern volatile unsigned int DOSTARTL __attribute__((__sfr__));

/* DOSTARTH: DO loop start address bits <23:16> */
extern volatile unsigned int DOSTARTH __attribute__((__sfr__));

/* DOENDL: DO loop end address bits <15:0> */
extern volatile unsigned int DOENDL __attribute__((__sfr__));

/* DOENDH: DO loop end address bits <23:16> */
extern volatile unsigned int DOENDH __attribute__((__sfr__));

/* SR: Status Register */
extern volatile unsigned int SR __attribute__((__sfr__));
typedef struct tagSRBITS {
        unsigned C      :1;     /* Carry flag                   */
        unsigned Z      :1;     /* Sticky Zero flag             */
        unsigned OV     :1;     /* Overflow flag                */    
        unsigned N      :1;     /* Negative flag                */
        unsigned RA     :1;     /* REPEAT loop active flag      */
        unsigned IPL    :3;     /* CPU Interrupt Priority Level */
        unsigned DC     :1;     /* Digit Carry flag             */
        unsigned DA     :1;     /* DO loop active flag          */
        unsigned SAB    :1;     /* Combined A/B saturation flag */
        unsigned OAB    :1;     /* Combined A/B overflow flag   */    
        unsigned SB     :1;     /* Acc B saturation flag        */
        unsigned SA     :1;     /* Acc A saturation flag        */
        unsigned OB     :1;     /* Acc B overflow flag          */
        unsigned OA     :1;     /* Acc A overflow flag          */
} SRBITS;
extern volatile SRBITS SRbits __attribute__((__sfr__));

/* CORCON: CPU Mode control Register */
extern volatile unsigned int CORCON __attribute__((__sfr__));
typedef struct tagCORCONBITS {
        unsigned IF     :1;     /* Integer/Fractional mode              */    
        unsigned RND    :1;     /* Rounding mode                        */
        unsigned PSV    :1;     /* Program Space Visibility enable      */
        unsigned IPL3   :1;     /* CPU Interrupt Priority Level bit 3   */
        unsigned ACCSAT :1;     /* Acc saturation mode                  */
        unsigned SATDW  :1;     /* Data space write saturation enable   */
        unsigned SATB   :1;     /* Acc B saturation enable              */
        unsigned SATA   :1;     /* Acc A saturation enable              */
        unsigned DL     :3;     /* DO loop nesting level status         */
        unsigned EDT    :1;     /* Early DO loop termination control    */
        unsigned US     :1;     /* Signed/Unsigned mode                 */
        unsigned        :3;
} CORCONBITS;
extern volatile CORCONBITS CORCONbits __attribute__((__sfr__));

/* MODCON: Modulo Addressing Control Register */
extern volatile unsigned int MODCON __attribute__((__sfr__));
typedef struct tagMODCONBITS {
        unsigned XWM    :4;     /* X-RAGU/X-WAGU modulo addressing register select  */
        unsigned YWM    :4;     /* Y-RAGU modulo addressing register select         */
        unsigned BWM    :4;     /* Bit-reversed addressing register select          */
        unsigned        :2;
        unsigned YMODEN :1;     /* Y-RAGU modulo addressing enable                  */
        unsigned XMODEN :1;     /* X-RAGU/X-WAGU modulo addressing enable           */
} MODCONBITS;
extern volatile MODCONBITS MODCONbits __attribute__((__sfr__));

/* XMODSRT: X-RAGU/X-WAGU modulo buffer start address */
extern volatile unsigned int XMODSRT __attribute__((__sfr__));

/* XMODEND: X-RAGU/X-WAGU modulo buffer end address */
extern volatile unsigned int XMODEND __attribute__((__sfr__));

/* YMODSRT: Y-RAGU modulo buffer start address */
extern volatile unsigned int YMODSRT __attribute__((__sfr__));

/* YMODEND: Y-RAGU modulo buffer end address */
extern volatile unsigned int YMODEND __attribute__((__sfr__));

/* XBREV: X-WAGU Bit-reversed Addressing Control Register */
extern volatile unsigned int XBREV __attribute__((__sfr__));
typedef struct tagXBREVBITS {
        unsigned XB     :15;    /* Bit-reversed addressing register select  */
        unsigned BREN   :1;     /* Bit-reversed addressing enable           */
} XBREVBITS;
extern volatile XBREVBITS XBREVbits __attribute__((__sfr__));

/* DISICNT: Disable Interrupt Cycle Count */
extern volatile unsigned int DISICNT __attribute__((__sfr__));
typedef struct tagDISICNTBITS {
        unsigned DISICNT:14;
        unsigned        :2;
} DISICNTBITS;
extern volatile DISICNTBITS DISICNTbits __attribute__((__sfr__));


/* ----------------------------------------- */
/* Interrupt Controller register definitions */
/* ----------------------------------------- */

/* INTCON1: Interrupt Control Register 1 */
extern volatile unsigned int INTCON1 __attribute__((__sfr__));
typedef struct tagINTCON1BITS {
        unsigned        :1;
        unsigned OSCFAIL:1;
        unsigned STKERR :1;
        unsigned ADDRERR:1;
        unsigned MATHERR:1;
        unsigned        :3;
        unsigned COVTE  :1;
        unsigned OVBTE  :1;
        unsigned OVATE  :1;
        unsigned        :4;
        unsigned NSTDIS :1;
} INTCON1BITS;
extern volatile INTCON1BITS INTCON1bits __attribute__((__sfr__));

/* INTCON2: Interrupt Control Register 2 */
extern volatile unsigned int INTCON2 __attribute__((__sfr__));
typedef struct tagINTCON2BITS {
        unsigned INT0EP :1;
        unsigned INT1EP :1;
        unsigned INT2EP :1;
        unsigned INT3EP :1;
        unsigned INT4EP :1;
        unsigned        :9;
        unsigned DISI   :1;  
        unsigned ALTIVT :1;
} INTCON2BITS;
extern volatile INTCON2BITS INTCON2bits __attribute__((__sfr__));

/* IFS0: Interrupt Flag Status Register 0 */
extern volatile unsigned int IFS0 __attribute__((__sfr__));
typedef struct tagIFS0BITS {
        unsigned INT0IF :1;
        unsigned IC1IF  :1;
        unsigned OC1IF  :1;
        unsigned T1IF   :1;
        unsigned IC2IF  :1;
        unsigned OC2IF  :1;
        unsigned T2IF   :1;
        unsigned T3IF   :1;
        unsigned SPI1IF :1;
        unsigned U1RXIF :1;
        unsigned U1TXIF :1;
        unsigned ADIF   :1;
        unsigned NVMIF  :1;
        unsigned SI2CIF  :1;
        unsigned MI2CIF  :1;
        unsigned CNIF   :1;
} IFS0BITS;
extern volatile IFS0BITS IFS0bits __attribute__((__sfr__));

/* IFS1: Interrupt Flag Status Register 1 */
extern volatile unsigned int IFS1 __attribute__((__sfr__));
typedef struct tagIFS1BITS {
        unsigned INT1IF :1;
        unsigned IC7IF  :1;
        unsigned IC8IF  :1;
        unsigned OC3IF  :1;
        unsigned OC4IF  :1;
        unsigned T4IF   :1;
        unsigned T5IF   :1;
        unsigned INT2IF :1;
        unsigned U2RXIF :1;
        unsigned U2TXIF :1;
        unsigned SPI2IF :1;
        unsigned C1IF   :1;
        unsigned IC3IF  :1;
        unsigned IC4IF  :1;
        unsigned IC5IF  :1;
        unsigned IC6IF  :1;
} IFS1BITS;
extern volatile IFS1BITS IFS1bits __attribute__((__sfr__));

/* IFS2: Interrupt Flag Status Register 2 */
extern volatile unsigned int IFS2 __attribute__((__sfr__));
typedef struct tagIFS2BITS {
        unsigned OC5IF  :1;
        unsigned OC6IF  :1;
        unsigned OC7IF  :1;
        unsigned OC8IF  :1;
        unsigned INT3IF :1;
        unsigned INT4IF :1;
        unsigned C2IF   :1;
        unsigned PWMIF  :1;
        unsigned QEIIF  :1;
        unsigned        :2;
        unsigned FLTAIF :1;
        unsigned FLTBIF :1;
        unsigned        :3;
} IFS2BITS;
extern volatile IFS2BITS IFS2bits __attribute__((__sfr__));

/* IEC0: Interrupt Enable Control Register 0 */
extern volatile unsigned int IEC0 __attribute__((__sfr__));
typedef struct tagIEC0BITS {
        unsigned INT0IE :1;
        unsigned IC1IE  :1;
        unsigned OC1IE  :1;
        unsigned T1IE   :1;
        unsigned IC2IE  :1;
        unsigned OC2IE  :1;
        unsigned T2IE   :1;
        unsigned T3IE   :1;
        unsigned SPI1IE :1;
        unsigned U1RXIE :1;
        unsigned U1TXIE :1;
        unsigned ADIE   :1;
        unsigned NVMIE  :1;
        unsigned SI2CIE  :1;
        unsigned MI2CIE  :1;
        unsigned CNIE   :1;
} IEC0BITS;
extern volatile IEC0BITS IEC0bits __attribute__((__sfr__));

/* IEC1: Interrupt Enable Control Register 1 */
extern volatile unsigned int IEC1 __attribute__((__sfr__));
typedef struct tagIEC1BITS {
        unsigned INT1IE :1;
        unsigned IC7IE  :1;
        unsigned IC8IE  :1;
        unsigned OC3IE  :1;
        unsigned OC4IE  :1;
        unsigned T4IE   :1;
        unsigned T5IE   :1;
        unsigned INT2IE :1;
        unsigned U2RXIE :1;
        unsigned U2TXIE :1;
        unsigned SPI2IE :1;
        unsigned C1IE   :1;
        unsigned IC3IE  :1;
        unsigned IC4IE  :1;
        unsigned IC5IE  :1;
        unsigned IC6IE  :1;
} IEC1BITS;
extern volatile IEC1BITS IEC1bits __attribute__((__sfr__));

/* IEC2: Interrupt Enable Control Register 2 */
extern volatile unsigned int IEC2 __attribute__((__sfr__));
typedef struct tagIEC2BITS {
        unsigned OC5IE  :1;
        unsigned OC6IE  :1;
        unsigned OC7IE  :1;
        unsigned OC8IE  :1;
        unsigned INT3IE :1;
        unsigned INT4IE :1;
        unsigned C2IE   :1;
        unsigned PWMIE  :1;
        unsigned QEIIE  :1;
        unsigned        :2;
        unsigned FLTAIE :1;
        unsigned FLTBIE :1;
        unsigned        :3;
} IEC2BITS;
extern volatile IEC2BITS IEC2bits __attribute__((__sfr__));

/* IPC0: Interrupt Priority Control Register 0 */
extern volatile unsigned int IPC0 __attribute__((__sfr__));
typedef struct tagIPC0BITS {
        unsigned INT0IP :3;
        unsigned        :1;
        unsigned IC1IP  :3;
        unsigned        :1;
        unsigned OC1IP  :3;
        unsigned        :1;
        unsigned T1IP   :3;
        unsigned        :1;
} IPC0BITS;
extern volatile IPC0BITS IPC0bits __attribute__((__sfr__));

/* IPC1: Interrupt Priority Control Register 1 */
extern volatile unsigned int IPC1 __attribute__((__sfr__));
typedef struct tagIPC1BITS {
        unsigned IC2IP  :3;
        unsigned        :1;
        unsigned OC2IP  :3;
        unsigned        :1;
        unsigned T2IP   :3;
        unsigned        :1;
        unsigned T3IP   :3;
        unsigned        :1;
} IPC1BITS;
extern volatile IPC1BITS IPC1bits __attribute__((__sfr__));

/* IPC2: Interrupt Priority Control Register 2 */
extern volatile unsigned int IPC2 __attribute__((__sfr__));
typedef struct tagIPC2BITS {
        unsigned SPI1IP :3;
        unsigned        :1;
        unsigned U1RXIP :3;
        unsigned        :1;
        unsigned U1TXIP :3;
        unsigned        :1;
        unsigned ADIP   :3;
        unsigned        :1;
} IPC2BITS;
extern volatile IPC2BITS IPC2bits __attribute__((__sfr__));

/* IPC3: Interrupt Priority Control Register 3 */
extern volatile unsigned int IPC3 __attribute__((__sfr__));
typedef struct tagIPC3BITS {
        unsigned NVMIP  :3;
        unsigned        :1;
        unsigned SI2CIP  :3;
        unsigned        :1;
        unsigned MI2CIP  :3;
        unsigned        :1;
        unsigned CNIP   :3;
        unsigned        :1;
} IPC3BITS;
extern volatile IPC3BITS IPC3bits __attribute__((__sfr__));

/* IPC4: Interrupt Priority Control Register 4 */
extern volatile unsigned int IPC4 __attribute__((__sfr__));
typedef struct tagIPC4BITS {
        unsigned INT1IP :3;
        unsigned        :1;
        unsigned IC7IP  :3;
        unsigned        :1;
        unsigned IC8IP  :3;
        unsigned        :1;
        unsigned OC3IP  :3;
        unsigned        :1;
} IPC4BITS;
extern volatile IPC4BITS IPC4bits __attribute__((__sfr__));

/* IPC5: Interrupt Priority Control Register 5 */
extern volatile unsigned int IPC5 __attribute__((__sfr__));
typedef struct tagIPC5BITS {
        unsigned OC4IP  :3;
        unsigned        :1;
        unsigned T4IP   :3;
        unsigned        :1;
        unsigned T5IP   :3;
        unsigned        :1;
        unsigned INT2IP :3;
        unsigned        :1;
} IPC5BITS;
extern volatile IPC5BITS IPC5bits __attribute__((__sfr__));

/* IPC6: Interrupt Priority Control Register 6 */
extern volatile unsigned int IPC6 __attribute__((__sfr__));
typedef struct tagIPC6BITS {
        unsigned U2RXIP :3;
        unsigned        :1;
        unsigned U2TXIP :3;
        unsigned        :1;
        unsigned SPI2IP :3;
        unsigned        :1;
        unsigned C1IP   :3;
        unsigned        :1;
} IPC6BITS;
extern volatile IPC6BITS IPC6bits __attribute__((__sfr__));

/* IPC7: Interrupt Priority Control Register 7 */
extern volatile unsigned int IPC7 __attribute__((__sfr__));
typedef struct tagIPC7BITS {
        unsigned IC3IP  :3;
        unsigned        :1;
        unsigned IC4IP  :3;
        unsigned        :1;
        unsigned IC5IP  :3;
        unsigned        :1;
        unsigned IC6IP  :3;
        unsigned        :1;
} IPC7BITS;
extern volatile IPC7BITS IPC7bits __attribute__((__sfr__));

/* IPC8: Interrupt Priority Control Register 8 */
extern volatile unsigned int IPC8 __attribute__((__sfr__));
typedef struct tagIPC8BITS {
        unsigned OC5IP  :3;
        unsigned        :1;
        unsigned OC6IP  :3;
        unsigned        :1;
        unsigned OC7IP  :3;
        unsigned        :1;
        unsigned OC8IP  :3;
        unsigned        :1;
} IPC8BITS; 
extern volatile IPC8BITS IPC8bits __attribute__((__sfr__));

/* IPC9: Interrupt Priority Control Register 9 */
extern volatile unsigned int IPC9 __attribute__((__sfr__));
typedef struct tagIPC9BITS {
        unsigned INT3IP :3;
        unsigned        :1;
        unsigned INT4IP :3;
        unsigned        :1;
        unsigned C2IP   :3;
        unsigned        :1;
        unsigned PWMIP  :3;
        unsigned        :1;
} IPC9BITS;
extern volatile IPC9BITS IPC9bits __attribute__((__sfr__));

/* IPC10: Interrupt Priority Control Register 10 */
extern volatile unsigned int IPC10 __attribute__((__sfr__));
typedef struct tagIPC10BITS {
        unsigned QEIIP  :3;
        unsigned        :9;
        unsigned FLTAIP :3;
        unsigned        :1;
} IPC10BITS;
extern volatile IPC10BITS IPC10bits __attribute__((__sfr__));

/* IPC11: Interrupt Priority Control Register 11 */
extern volatile unsigned int IPC11 __attribute__((__sfr__));
typedef struct tagIPC11BITS {
        unsigned FLTBIP :3;
        unsigned        :13;
} IPC11BITS;
extern volatile IPC11BITS IPC11bits __attribute__((__sfr__));

/* INTTREG: Interrupt Controller Test Register */
extern volatile unsigned int INTTREG __attribute__((__sfr__));
typedef struct tagINTTREGBITS {
        unsigned VECNUM :6;
        unsigned        :2;
	unsigned ILR    :4;
	unsigned        :1;
	unsigned VHOLD  :1;
	unsigned TMODE  :1;
	unsigned IRQTOCPU:1;
} INTTREGBITS;
extern volatile INTTREGBITS INTTREGbits __attribute__((__sfr__));


/* ---------------------------------------------- */
/* Input Change Notification register definitions */
/* ---------------------------------------------- */

/* CNEN1: Input Change Notification Interrupt Enable Register 1 */
extern volatile unsigned int CNEN1 __attribute__((__sfr__));
typedef struct tagCNEN1BITS {
        unsigned CN0IE  :1;
        unsigned CN1IE  :1;
        unsigned CN2IE  :1;
        unsigned CN3IE  :1;
        unsigned CN4IE  :1;
        unsigned CN5IE  :1;
        unsigned CN6IE  :1;
        unsigned CN7IE  :1;
        unsigned CN8IE  :1;
        unsigned CN9IE  :1;
        unsigned CN10IE :1;
        unsigned CN11IE :1;
        unsigned CN12IE :1;
        unsigned CN13IE :1;
        unsigned CN14IE :1;
        unsigned CN15IE :1;
} CNEN1BITS;
extern volatile CNEN1BITS CNEN1bits __attribute__((__sfr__));

/* CNEN2: Input Change Notification Interrupt Enable Register 2 */
extern volatile unsigned int CNEN2 __attribute__((__sfr__));
typedef struct tagCNEN2BITS {
        unsigned CN16IE :1;
        unsigned CN17IE :1;
        unsigned CN18IE :1;
        unsigned CN19IE :1;
        unsigned CN20IE :1;
        unsigned CN21IE :1;
        unsigned        :10;
} CNEN2BITS;
extern volatile CNEN2BITS CNEN2bits __attribute__((__sfr__));

/* CNPU1: Input Change Notification Pullup Enable Register 1 */
extern volatile unsigned int CNPU1 __attribute__((__sfr__));
typedef struct tagCNPU1BITS {
        unsigned CN0PUE :1;
        unsigned CN1PUE :1;
        unsigned CN2PUE :1;
        unsigned CN3PUE :1;
        unsigned CN4PUE :1;
        unsigned CN5PUE :1;
        unsigned CN6PUE :1;
        unsigned CN7PUE :1;
        unsigned CN8PUE :1;
        unsigned CN9PUE :1;
        unsigned CN10PUE:1;
        unsigned CN11PUE:1;
        unsigned CN12PUE:1;
        unsigned CN13PUE:1;
        unsigned CN14PUE:1;
        unsigned CN15PUE:1;
} CNPU1BITS;
extern volatile CNPU1BITS CNPU1bits __attribute__((__sfr__));

/* CNPU2: Input Change Notification Pullup Enable Register 2 */
extern volatile unsigned int CNPU2 __attribute__((__sfr__));
typedef struct tagCNPU2BITS {
        unsigned CN16PUE:1;
        unsigned CN17PUE:1;
        unsigned CN18PUE:1;
        unsigned CN19PUE:1;
        unsigned CN20PUE:1;
        unsigned CN21PUE:1;
        unsigned        :10;
} CNPU2BITS;
extern volatile CNPU2BITS CNPU2bits __attribute__((__sfr__));


/* --------------------------- */
/* Timer1 register definitions */
/* --------------------------- */

/* Generic structure for Timer 1 Control Register */
typedef struct tagTCON_16BIT {
        unsigned        :1;
        unsigned TCS    :1;
        unsigned TSYNC  :1;
        unsigned        :1;
        unsigned TCKPS  :2;
        unsigned TGATE  :1;
        unsigned        :6;
        unsigned TSIDL  :1;
        unsigned        :1;
        unsigned TON    :1;
} TCON_16BIT;

/* TMR1: Timer 1 Count Register */
extern volatile unsigned int TMR1 __attribute__((__sfr__));

/* PR1: Timer 1 Period Register */
extern volatile unsigned int PR1 __attribute__((__sfr__));

/* T1CON: Timer 1 Control Register */
extern volatile unsigned int T1CON __attribute__((__sfr__));
extern volatile TCON_16BIT T1CONbits __attribute__((__sfr__));

/* ----------------------------- */
/* Timer2/3 register definitions */
/* ----------------------------- */

/* Generic structure for Timer 2 and Timer 4 Control Registers */
typedef struct tagTCON_EVEN {
        unsigned        :1;
        unsigned TCS    :1;
        unsigned        :1;
        unsigned T32    :1;
        unsigned TCKPS  :2;
        unsigned TGATE  :1;
        unsigned        :6;
        unsigned TSIDL  :1;
        unsigned        :1;
        unsigned TON    :1;
} TCON_EVEN;

/* Generic structure for Timer 3 and Timer 5 Control Registers */
typedef struct tagTCON_ODD {
        unsigned        :1;
        unsigned TCS    :1;
        unsigned        :2;
        unsigned TCKPS  :2;
        unsigned TGATE  :1;
        unsigned        :6;
        unsigned TSIDL  :1;
        unsigned        :1;
        unsigned TON    :1;
} TCON_ODD;

/* TMR2: Timer 2 Count Register */
extern volatile unsigned int TMR2 __attribute__((__sfr__));

/* TMR3HLD: Timer 3 Holding Register */
extern volatile unsigned int TMR3HLD __attribute__((__sfr__));

/* TMR3: Timer 3 Count Register */
extern volatile unsigned int TMR3 __attribute__((__sfr__));

/* PR2: Timer 2 Period Register */
extern volatile unsigned int PR2 __attribute__((__sfr__));

/* PR3: Timer 3 Period Register */
extern volatile unsigned int PR3 __attribute__((__sfr__));

/* T2CON: Timer 2 Control Register */
extern volatile unsigned int T2CON __attribute__((__sfr__));
extern volatile TCON_EVEN T2CONbits __attribute__((__sfr__));

/* T3CON: Timer 3 Control Register */
extern volatile unsigned int T3CON __attribute__((__sfr__));
extern volatile TCON_ODD T3CONbits __attribute__((__sfr__));


/* ----------------------------- */
/* Timer4/5 register definitions */
/* ----------------------------- */

/* TMR4: Timer 4 Count Register */
extern volatile unsigned int TMR4 __attribute__((__sfr__));

/* TMR5HLD: Timer 5 Holding Register */
extern volatile unsigned int TMR5HLD __attribute__((__sfr__));

/* TMR5: Timer 5 Count Register */
extern volatile unsigned int TMR5 __attribute__((__sfr__));

/* PR4: Timer 4 Period Register */
extern volatile unsigned int PR4 __attribute__((__sfr__));

/* PR5: Timer 5 Period Register */
extern volatile unsigned int PR5 __attribute__((__sfr__));

/* T4CON: Timer 4 Control Register */
extern volatile unsigned int T4CON __attribute__((__sfr__));
extern volatile TCON_EVEN T4CONbits __attribute__((__sfr__));

/* T5CON: Timer 5 Control Register */
extern volatile unsigned int T5CON __attribute__((__sfr__));
extern volatile TCON_ODD T5CONbits __attribute__((__sfr__));


/* ------------------------------------------------- */
/* Quadrature Encoder Interface register definitions */
/* ------------------------------------------------- */

/* QEICON: QEI Control Register */
extern volatile unsigned int QEICON __attribute__((__sfr__));
typedef struct tagQEICONBITS {
        unsigned UPDN_SRC:1;
        unsigned TQCS   :1;
        unsigned POSRES :1;
        unsigned TQCKPS :2;
        unsigned TQGATE :1;
        unsigned PCDOUT :1;
        unsigned SWPAB  :1;
        unsigned QEIM   :3;
        unsigned UPDN   :1;
        unsigned INDX   :1;
        unsigned QEISIDL:1;
        unsigned        :1;
        unsigned CNTERR :1;
} QEICONBITS;
extern volatile QEICONBITS QEICONbits __attribute__((__sfr__));

/* DFLTCON: Digital Filter Control Register */
extern volatile unsigned int DFLTCON __attribute__((__sfr__));
typedef struct tagDFLTCONBITS {
        unsigned        :4;
        unsigned QECK   :3;
        unsigned QEOUT  :1;
        unsigned CEID   :1;
        unsigned IMV    :2;
        unsigned        :5;
} DFLTCONBITS;
extern volatile DFLTCONBITS DFLTCONbits __attribute__((__sfr__));

/* POSCNT: Position Counter Register */
extern volatile unsigned int POSCNT __attribute__((__sfr__));

/* MAXCNT: Maximum Count Register */
extern volatile unsigned int MAXCNT __attribute__((__sfr__));


/* ---------------------------------- */
/* Input Capture register definitions */
/* ---------------------------------- */

/* Generic structure of entire SFR area for each Input Capture module */
typedef struct tagIC {
        unsigned int icxbuf;
        unsigned int icxcon;
} IC, *PIC;

/* SFR blocks for each Input Capture module */
extern volatile IC IC1 __attribute__((__sfr__));
extern volatile IC IC2 __attribute__((__sfr__));
extern volatile IC IC3 __attribute__((__sfr__));
extern volatile IC IC4 __attribute__((__sfr__));
extern volatile IC IC5 __attribute__((__sfr__));
extern volatile IC IC6 __attribute__((__sfr__));
extern volatile IC IC7 __attribute__((__sfr__));
extern volatile IC IC8 __attribute__((__sfr__));

/* Generic structure for Input Capture Control Registers */
typedef struct tagICxCONBITS {
        unsigned ICM    :3;
        unsigned ICBNE  :1;
        unsigned ICOV   :1;
        unsigned ICI    :2;
        unsigned ICTMR  :1;
        unsigned        :5;
        unsigned ICSIDL :1;
        unsigned        :2;
} ICxCONBITS;

/* IC1BUF: Input Capture 1 Buffer */
extern volatile unsigned int IC1BUF __attribute__((__sfr__));

/* IC1CON: Input Capture 1 Control Register */
extern volatile unsigned int IC1CON __attribute__((__sfr__));
extern volatile ICxCONBITS IC1CONbits __attribute__((__sfr__));

/* IC2BUF: Input Capture 2 Buffer */
extern volatile unsigned int IC2BUF __attribute__((__sfr__));

/* IC2CON: Input Capture 2 Control Register */
extern volatile unsigned int IC2CON __attribute__((__sfr__));
extern volatile ICxCONBITS IC2CONbits __attribute__((__sfr__));

/* IC3BUF: Input Capture 3 Buffer */
extern volatile unsigned int IC3BUF __attribute__((__sfr__));

/* IC3CON: Input Capture 3 Control Register */
extern volatile unsigned int IC3CON __attribute__((__sfr__));
extern volatile ICxCONBITS IC3CONbits __attribute__((__sfr__));

/* IC4BUF: Input Capture 4 Buffer */
extern volatile unsigned int IC4BUF __attribute__((__sfr__));

/* IC4CON: Input Capture 4 Control Register */
extern volatile unsigned int IC4CON __attribute__((__sfr__));
extern volatile ICxCONBITS IC4CONbits __attribute__((__sfr__));

/* IC5BUF: Input Capture 5 Buffer */
extern volatile unsigned int IC5BUF __attribute__((__sfr__));

/* IC5CON: Input Capture 5 Control Register */
extern volatile unsigned int IC5CON __attribute__((__sfr__));
extern volatile ICxCONBITS IC5CONbits __attribute__((__sfr__));

/* IC6BUF: Input Capture 6 Buffer */
extern volatile unsigned int IC6BUF __attribute__((__sfr__));

/* IC6CON: Input Capture 6 Control Register */
extern volatile unsigned int IC6CON __attribute__((__sfr__));
extern volatile ICxCONBITS IC6CONbits __attribute__((__sfr__));

/* IC7BUF: Input Capture 7 Buffer */
extern volatile unsigned int IC7BUF __attribute__((__sfr__));

/* IC7CON: Input Capture 7 Control Register */
extern volatile unsigned int IC7CON __attribute__((__sfr__));
extern volatile ICxCONBITS IC7CONbits __attribute__((__sfr__));

/* IC8BUF: Input Capture 8 Buffer */
extern volatile unsigned int IC8BUF __attribute__((__sfr__));

/* IC8CON: Input Capture 8 Control Register */
extern volatile unsigned int IC8CON __attribute__((__sfr__));
extern volatile ICxCONBITS IC8CONbits __attribute__((__sfr__));


/* --------------------------------------- */
/* Output Compare/PWM register definitions */
/* --------------------------------------- */

/* Generic structure of entire SFR area for each Output Compare module */
typedef struct tagOC {
        unsigned int ocxrs;
        unsigned int ocxr;
        unsigned int ocxcon;
} OC, *POC;

/* SFR blocks for each Output Compare module */
extern volatile OC OC1 __attribute__((__sfr__));
extern volatile OC OC2 __attribute__((__sfr__));
extern volatile OC OC3 __attribute__((__sfr__));
extern volatile OC OC4 __attribute__((__sfr__));
extern volatile OC OC5 __attribute__((__sfr__));
extern volatile OC OC6 __attribute__((__sfr__));
extern volatile OC OC7 __attribute__((__sfr__));
extern volatile OC OC8 __attribute__((__sfr__));

/* Generic structure for Output Compare Control Registers */
typedef struct tagOCxCONBITS {
        unsigned OCM    :3;
        unsigned OCTSEL :1;
        unsigned OCFLT  :1;
        unsigned        :8;
        unsigned OCSIDL :1;
        unsigned        :2;
} OCxCONBITS;

/* OC1RS: Output Compare 1 Secondary Register */
extern volatile unsigned int OC1RS __attribute__((__sfr__));

/* OC1R: Output Compare 1 Main Register */
extern volatile unsigned int OC1R __attribute__((__sfr__));

/* OC1CON: Output Compare 1 Control Register */
extern volatile unsigned int OC1CON __attribute__((__sfr__));
extern volatile OCxCONBITS OC1CONbits __attribute__((__sfr__));

/* OC2RS: Output Compare 2 Secondary Register */
extern volatile unsigned int OC2RS __attribute__((__sfr__));

/* OC2R: Output Compare 2 Main Register */
extern volatile unsigned int OC2R __attribute__((__sfr__));

/* OC2CON: Output Compare 2 Control Register */
extern volatile unsigned int OC2CON __attribute__((__sfr__));
extern volatile OCxCONBITS OC2CONbits __attribute__((__sfr__));

/* OC3RS: Output Compare 3 Secondary Register */
extern volatile unsigned int OC3RS __attribute__((__sfr__));

/* OC3R: Output Compare 3 Main Register */
extern volatile unsigned int OC3R __attribute__((__sfr__));

/* OC3CON: Output Compare 3 Control Register */
extern volatile unsigned int OC3CON __attribute__((__sfr__));
extern volatile OCxCONBITS OC3CONbits __attribute__((__sfr__));

/* OC4RS: Output Compare 4 Secondary Register */
extern volatile unsigned int OC4RS __attribute__((__sfr__));

/* OC4R: Output Compare 4 Main Register */
extern volatile unsigned int OC4R __attribute__((__sfr__));

/* OC4CON: Output Compare 4 Control Register */
extern volatile unsigned int OC4CON __attribute__((__sfr__));
extern volatile OCxCONBITS OC4CONbits __attribute__((__sfr__));

/* OC5RS: Output Compare 5 Secondary Register */
extern volatile unsigned int OC5RS __attribute__((__sfr__));

/* OC5R: Output Compare 5 Main Register */
extern volatile unsigned int OC5R __attribute__((__sfr__));

/* OC5CON: Output Compare 5 Control Register */
extern volatile unsigned int OC5CON __attribute__((__sfr__));
extern volatile OCxCONBITS OC5CONbits __attribute__((__sfr__));

/* OC6RS: Output Compare 6 Secondary Register */
extern volatile unsigned int OC6RS __attribute__((__sfr__));

/* OC6R: Output Compare 6 Main Register */
extern volatile unsigned int OC6R __attribute__((__sfr__));

/* OC6CON: Output Compare 6 Control Register */
extern volatile unsigned int OC6CON __attribute__((__sfr__));
extern volatile OCxCONBITS OC6CONbits __attribute__((__sfr__));

/* OC7RS: Output Compare 7 Secondary Register */
extern volatile unsigned int OC7RS __attribute__((__sfr__));

/* OC7R: Output Compare 7 Main Register */
extern volatile unsigned int OC7R __attribute__((__sfr__));

/* OC7CON: Output Compare 7 Control Register */
extern volatile unsigned int OC7CON __attribute__((__sfr__));
extern volatile OCxCONBITS OC7CONbits __attribute__((__sfr__));

/* OC8RS: Output Compare 8 Secondary Register */
extern volatile unsigned int OC8RS __attribute__((__sfr__));

/* OC8R: Output Compare 8 Main Register */
extern volatile unsigned int OC8R __attribute__((__sfr__));

/* OC8CON: Output Compare 8 Control Register */
extern volatile unsigned int OC8CON __attribute__((__sfr__));
extern volatile OCxCONBITS OC8CONbits __attribute__((__sfr__));


/* -------------------------------------- */
/* Motor Control PWM register definitions */
/* -------------------------------------- */

/* PTCON: PWM Timerbase Control Register */
extern volatile unsigned int PTCON __attribute__((__sfr__));
typedef struct tagPTCONBITS {
        unsigned PTMOD  :2;
        unsigned PTCKPS :2;
        unsigned PTOPS  :4;
        unsigned        :5;
        unsigned PTSIDL :1;
        unsigned        :1;
        unsigned PTEN   :1;
} PTCONBITS;
extern volatile PTCONBITS PTCONbits __attribute__((__sfr__));

/* PTMR: PWM Timebase Count Register */
extern volatile unsigned int PTMR __attribute__((__sfr__));
typedef struct tagPTMRBITS {
        unsigned PTMR   :15;
        unsigned PTDIR  :1;
} PTMRBITS;
extern volatile PTMRBITS PTMRbits __attribute__((__sfr__));

/* PTPER: PWM Timebase Period Register */
extern volatile unsigned int PTPER __attribute__((__sfr__));
typedef struct tagPTPERBITS {
        unsigned PTPER  :15;
        unsigned        :1;
} PTPERBITS;
extern volatile PTPERBITS PTPERbits __attribute__((__sfr__));

/* SEVTCMP: Special Event Compare Count Register */
extern volatile unsigned int SEVTCMP __attribute__((__sfr__));
typedef struct tagSEVTCMPBITS {
        unsigned SEVTCMP:15;
        unsigned SEVTDIR:1;
} SEVTCMPBITS;
extern volatile SEVTCMPBITS SEVTCMPbits __attribute__((__sfr__));

/* PWMCON1: PWM Control Register 1 */
extern volatile unsigned int PWMCON1 __attribute__((__sfr__));
typedef struct tagPWMCON1BITS {
        unsigned PEN1L  :1;
        unsigned PEN2L  :1;
        unsigned PEN3L  :1;
        unsigned PEN4L  :1;
        unsigned PEN1H  :1;
        unsigned PEN2H  :1;
        unsigned PEN3H  :1;
        unsigned PEN4H  :1;
        unsigned PMOD1  :1;
        unsigned PMOD2  :1;
        unsigned PMOD3  :1;
        unsigned PMOD4  :1;
        unsigned        :4;
} PWMCON1BITS;
extern volatile PWMCON1BITS PWMCON1bits __attribute__((__sfr__));

/* PWMCON2: PWM Control Register 2 */
extern volatile unsigned int PWMCON2 __attribute__((__sfr__));
typedef struct tagPWMCON2BITS {
        unsigned UDIS   :1;
        unsigned OSYNC  :1;
        unsigned IUE    :1; 
        unsigned        :5;
        unsigned SEVOPS :4;
        unsigned        :4;
} PWMCON2BITS;
extern volatile PWMCON2BITS PWMCON2bits __attribute__((__sfr__));

/* DTCON1: PWM Dead Time Control Register 1 */
extern volatile unsigned int DTCON1 __attribute__((__sfr__));
typedef struct tagDTCON1BITS {
        unsigned DTA    :6;
        unsigned DTAPS  :2;
        unsigned DTB    :6;
        unsigned DTBPS  :2;
} DTCON1BITS;
extern volatile DTCON1BITS DTCON1bits __attribute__((__sfr__));

/* DTCON2: PWM Dead Time Control Register 2 */
extern volatile unsigned int DTCON2 __attribute__((__sfr__));
typedef struct tagDTCON2BITS {
        unsigned DTS1I  :1;
        unsigned DTS1A  :1;
        unsigned DTS2I  :1;
        unsigned DTS2A  :1;
        unsigned DTS3I  :1;
        unsigned DTS3A  :1;
        unsigned DTS4I  :1;
        unsigned DTS4A  :1;
        unsigned        :8;
} DTCON2BITS;
extern volatile DTCON2BITS DTCON2bits __attribute__((__sfr__));

/* FLTACON: PWM Fault Input A Control Register */ 
extern volatile unsigned int FLTACON __attribute__((__sfr__));
typedef struct tagFLTACONBITS {
        unsigned FAEN1  :1;
        unsigned FAEN2  :1;
        unsigned FAEN3  :1;
        unsigned FAEN4  :1;
        unsigned        :3;
        unsigned FLTAM  :1;
        unsigned FAOV1L :1;
        unsigned FAOV1H :1;
        unsigned FAOV2L :1;
        unsigned FAOV2H :1;
        unsigned FAOV3L :1;
        unsigned FAOV3H :1;
        unsigned FAOV4L :1;
        unsigned FAOV4H :1;
} FLTACONBITS;
extern volatile FLTACONBITS FLTACONbits __attribute__((__sfr__));

/* FLTBCON: PWM Fault Input B Control Register */ 
extern volatile unsigned int FLTBCON __attribute__((__sfr__));
typedef struct tagFLTBCONBITS {
        unsigned FBEN1  :1;
        unsigned FBEN2  :1;
        unsigned FBEN3  :1;
        unsigned FBEN4  :1;
        unsigned        :3;
        unsigned FLTBM  :1;
        unsigned FBOV1L :1;
        unsigned FBOV1H :1;
        unsigned FBOV2L :1;
        unsigned FBOV2H :1;
        unsigned FBOV3L :1;
        unsigned FBOV3H :1;
        unsigned FBOV4L :1;
        unsigned FBOV4H :1;
} FLTBCONBITS;
extern volatile FLTBCONBITS FLTBCONbits __attribute__((__sfr__));

/* OVDCON: PWM Override Control Register */
extern volatile unsigned int OVDCON __attribute__((__sfr__));
typedef struct tagOVDCONBITS {
        unsigned POUT1L :1;
        unsigned POUT1H :1;
        unsigned POUT2L :1;
        unsigned POUT2H :1;
        unsigned POUT3L :1;
        unsigned POUT3H :1;
        unsigned POUT4L :1;
        unsigned POUT4H :1;
        unsigned POVD1L :1;
        unsigned POVD1H :1;
        unsigned POVD2L :1;
        unsigned POVD2H :1;
        unsigned POVD3L :1;
        unsigned POVD3H :1;
        unsigned POVD4L :1;
        unsigned POVD4H :1;
} OVDCONBITS;
extern volatile OVDCONBITS OVDCONbits __attribute__((__sfr__));

/* PDC1: PWM Duty Cycle Register 1 */
extern volatile unsigned int PDC1 __attribute__((__sfr__));

/* PDC2: PWM Duty Cycle Register 2 */
extern volatile unsigned int PDC2 __attribute__((__sfr__));

/* PDC3: PWM Duty Cycle Register 3 */
extern volatile unsigned int PDC3 __attribute__((__sfr__));

/* PDC4: PWM Duty Cycle Register 4 */
extern volatile unsigned int PDC4 __attribute__((__sfr__));


/* ------------------------ */
/* I2C register definitions */
/* ------------------------ */

/* I2CRCV: I2C Receive Register */
extern volatile unsigned char I2CRCV __attribute__((__sfr__));
typedef struct tagI2CRCVBITS {
        unsigned I2CRCV0:1;
        unsigned I2CRCV1:1;
        unsigned I2CRCV2:1;
        unsigned I2CRCV3:1;
        unsigned I2CRCV4:1;
        unsigned I2CRCV5:1;
        unsigned I2CRCV6:1;
        unsigned I2CRCV7:1;
} I2CRCVBITS;
extern volatile I2CRCVBITS I2CRCVbits __attribute__((__sfr__));

/* I2CTRN: I2C Transmit Register */
extern volatile unsigned char I2CTRN __attribute__((__sfr__));
typedef struct tagI2CTRNBITS {
        unsigned I2CTRN0:1;
        unsigned I2CTRN1:1;
        unsigned I2CTRN2:1;
        unsigned I2CTRN3:1;
        unsigned I2CTRN4:1;
        unsigned I2CTRN5:1;
        unsigned I2CTRN6:1;
        unsigned I2CTRN7:1;
} I2CTRNBITS;
extern volatile I2CTRNBITS I2CTRNbits __attribute__((__sfr__));

/* I2CBRG: I2C Baud Rate Generator Register */
extern volatile unsigned int I2CBRG __attribute__((__sfr__));
typedef struct tagI2CBRGBITS {
        unsigned I2CBRG :9;
        unsigned        :7;
} I2CBRGBITS;
extern volatile I2CBRGBITS I2CBRGbits __attribute__((__sfr__));

/* I2CCON: I2C Control Register */
extern volatile unsigned int I2CCON __attribute__((__sfr__));
typedef struct tagI2CCONBITS {
        unsigned SEN    :1;
        unsigned RSEN   :1;
        unsigned PEN    :1;
        unsigned RCEN   :1;
        unsigned ACKEN  :1;
        unsigned ACKDT  :1;
        unsigned STREN  :1;
        unsigned GCEN   :1;
        unsigned SMEN   :1;
        unsigned DISSLW :1;
        unsigned A10M  :1;
        unsigned IPMIEN :1;
        unsigned SCLREL :1;
        unsigned I2CSIDL:1;
        unsigned        :1;
        unsigned I2CEN  :1;
} I2CCONBITS;
extern volatile I2CCONBITS I2CCONbits __attribute__((__sfr__));

/* I2CSTAT: I2C Status Register */
extern volatile unsigned int I2CSTAT __attribute__((__sfr__));
typedef struct tagI2CSTATBITS {
        unsigned TBF    :1;
        unsigned RBF    :1;
        unsigned R_W    :1;
        unsigned S      :1;
        unsigned P      :1;
        unsigned D_A    :1;
        unsigned I2COV  :1;
        unsigned IWCOL  :1;
        unsigned ADD10  :1;
        unsigned GCSTAT :1;
        unsigned BCL    :1;
        unsigned        :3;
        unsigned TRSTAT :1;
        unsigned ACKSTAT:1;
} I2CSTATBITS;
extern volatile I2CSTATBITS I2CSTATbits __attribute__((__sfr__));

/* I2CADD: I2C Address Register */
extern volatile unsigned int I2CADD __attribute__((__sfr__));
typedef struct tagI2CADDBITS {
        unsigned I2CADD :10;
        unsigned        :6;
} I2CADDBITS;
extern volatile I2CADDBITS I2CADDbits __attribute__((__sfr__));


/* -------------------------- */
/* UART1 register definitions */
/* -------------------------- */

/* Generic structure of entire SFR area for each UART module */
typedef struct tagUART {
        unsigned int uxmode;
        unsigned int uxsta;
        unsigned int uxtxreg;
        unsigned int uxrxreg;
        unsigned int uxbrg;
} UART, *PUART;

/* SFR blocks for each UART module */
extern volatile UART UART1 __attribute__((__sfr__));
extern volatile UART UART2 __attribute__((__sfr__));

/* Generic structure for UART Mode Registers */
typedef struct tagUxMODEBITS {
        unsigned STSEL  :1;
        unsigned PDSEL  :2;
        unsigned        :2;
        unsigned ABAUD  :1;
        unsigned LPBACK :1;
        unsigned WAKE   :1;
        unsigned        :2;
        unsigned ALTIO  :1;
        unsigned        :2;
        unsigned USIDL  :1;
        unsigned        :1;
        unsigned UARTEN :1;
} UxMODEBITS;

/* Generic structure for UART Status and Control Registers */
typedef struct tagUxSTABITS {
        unsigned URXDA  :1;
        unsigned OERR   :1;
        unsigned FERR   :1;
        unsigned PERR   :1;
        unsigned RIDLE  :1;
        unsigned ADDEN  :1;
        unsigned URXISEL:2;
        unsigned TRMT   :1;
        unsigned UTXBF  :1;
        unsigned UTXEN  :1;
        unsigned UTXBRK :1;
        unsigned        :3;
        unsigned UTXISEL:1;
} UxSTABITS; 

/* Generic structure for UART Transmit Registers */
typedef struct tagUxTXREGBITS {
        unsigned UTXREG0:1;
        unsigned UTXREG1:1;
        unsigned UTXREG2:1;
        unsigned UTXREG3:1;
        unsigned UTXREG4:1;
        unsigned UTXREG5:1;
        unsigned UTXREG6:1;
        unsigned UTXREG7:1;
        unsigned UTX8   :1;
        unsigned        :7;
} UxTXREGBITS;

/* Generic structure for UART Receive Registers */
typedef struct tagUxRXREGBITS {
        unsigned URXREG0:1;
        unsigned URXREG1:1;
        unsigned URXREG2:1;
        unsigned URXREG3:1;
        unsigned URXREG4:1;
        unsigned URXREG5:1;
        unsigned URXREG6:1;
        unsigned URXREG7:1;
        unsigned URX8   :1;
        unsigned        :7;
} UxRXREGBITS;

/* U1MODE: UART1 Mode Regsiter */
extern volatile unsigned int U1MODE __attribute__((__sfr__));
extern volatile UxMODEBITS U1MODEbits __attribute__((__sfr__));

/* U1STA: UART1 Status and Control Register */
extern volatile unsigned int U1STA __attribute__((__sfr__));
extern volatile UxSTABITS U1STAbits __attribute__((__sfr__));

/* U1TXREG: UART1 Transmit Register */
extern volatile unsigned int U1TXREG __attribute__((__sfr__));
extern volatile UxTXREGBITS U1TXREGbits __attribute__((__sfr__));

/* U1RXREG: UART1 Receive Register */
extern volatile unsigned int U1RXREG __attribute__((__sfr__));
extern volatile UxRXREGBITS U1RXREGbits __attribute__((__sfr__));   

/* U1BRG: UART1 Baud Rate Generator Register */
extern volatile unsigned int U1BRG __attribute__((__sfr__));


/* -------------------------- */
/* UART2 register definitions */
/* -------------------------- */

/* U2MODE: UART2 Mode Regsiter */
extern volatile unsigned int U2MODE __attribute__((__sfr__));
extern volatile UxMODEBITS U2MODEbits __attribute__((__sfr__));

/* U2STA: UART2 Status and Control Register */
extern volatile unsigned int U2STA __attribute__((__sfr__));
extern volatile UxSTABITS U2STAbits __attribute__((__sfr__));

/* U2TXREG: UART2 Transmit Register */
extern volatile unsigned int U2TXREG __attribute__((__sfr__));
extern volatile UxTXREGBITS U2TXREGbits __attribute__((__sfr__));

/* U2RXREG: UART2 Receive Register */
extern volatile unsigned int U2RXREG __attribute__((__sfr__));
extern volatile UxRXREGBITS U2RXREGbits __attribute__((__sfr__));   

/* U2BRG: UART2 Baud Rate Generator Register */
extern volatile unsigned int U2BRG __attribute__((__sfr__));


/* ------------------------- */
/* SPI1 register definitions */
/* ------------------------- */

/* Generic structure of entire SFR area for each SPI module */
typedef struct tagSPI {
        unsigned int spixstat;
        unsigned int spixcon;
        unsigned int spixbuf;
} SPI, *PSPI;

/* SFR blocks for each SPI module */
extern volatile SPI SPI1 __attribute__((__sfr__));
extern volatile SPI SPI2 __attribute__((__sfr__));

/* Generic structure for SPI Status Registers */
typedef struct tagSPIxSTATBITS {
        unsigned SPIRBF :1;
        unsigned SPITBF :1;
        unsigned        :4;
        unsigned SPIROV :1;
        unsigned        :6;
        unsigned SPISIDL:1;
        unsigned        :1;
        unsigned SPIEN  :1;
} SPIxSTATBITS;

/* Generic structure for SPI Control Registers */
typedef struct tagSPIxCONBITS {
        unsigned PPRE   :2;
        unsigned SPRE   :3;
        unsigned MSTEN  :1;
        unsigned CKP    :1;
        unsigned SSEN   :1;
        unsigned CKE    :1;
        unsigned SMP    :1;
        unsigned MODE16 :1;
        unsigned DISSDO :1;
        unsigned        :1;
        unsigned SPIFSD:1;
        unsigned FRMEN  :1;
        unsigned        :1;
} SPIxCONBITS;

/* SPI1STAT: SPI1 Status Register */
extern volatile unsigned int SPI1STAT __attribute__((__sfr__));
extern volatile SPIxSTATBITS SPI1STATbits __attribute__((__sfr__));

/* SPI1CON: SPI1 Control Register */
extern volatile unsigned int SPI1CON __attribute__((__sfr__));
extern volatile SPIxCONBITS SPI1CONbits __attribute__((__sfr__));

/* SPI1BUF: SPI1 Buffer */
extern volatile unsigned int SPI1BUF __attribute__((__sfr__));


/* ------------------------- */
/* SPI2 register definitions */
/* ------------------------- */

/* SPI2STAT: SPI2 Status Register */
extern volatile unsigned int SPI2STAT __attribute__((__sfr__));
extern volatile SPIxSTATBITS SPI2STATbits __attribute__((__sfr__));

/* SPI2CON: SPI2 Control Register */
extern volatile unsigned int SPI2CON __attribute__((__sfr__));
extern volatile SPIxCONBITS SPI2CONbits __attribute__((__sfr__));

/* SPI2BUF: SPI2 Buffer */
extern volatile unsigned int SPI2BUF __attribute__((__sfr__));


/* ------------------------------------------------------------------ */
/* 10-bit (500 ksps) Analog-to-Digital Converter register definitions */
/* ------------------------------------------------------------------ */

/* ADC Buffers 0-F */
extern volatile unsigned int ADCBUF0 __attribute__((__sfr__));
extern volatile unsigned int ADCBUF1 __attribute__((__sfr__));
extern volatile unsigned int ADCBUF2 __attribute__((__sfr__));
extern volatile unsigned int ADCBUF3 __attribute__((__sfr__));
extern volatile unsigned int ADCBUF4 __attribute__((__sfr__));
extern volatile unsigned int ADCBUF5 __attribute__((__sfr__));
extern volatile unsigned int ADCBUF6 __attribute__((__sfr__));
extern volatile unsigned int ADCBUF7 __attribute__((__sfr__));
extern volatile unsigned int ADCBUF8 __attribute__((__sfr__));
extern volatile unsigned int ADCBUF9 __attribute__((__sfr__));
extern volatile unsigned int ADCBUFA __attribute__((__sfr__));
extern volatile unsigned int ADCBUFB __attribute__((__sfr__));
extern volatile unsigned int ADCBUFC __attribute__((__sfr__));
extern volatile unsigned int ADCBUFD __attribute__((__sfr__));
extern volatile unsigned int ADCBUFE __attribute__((__sfr__));
extern volatile unsigned int ADCBUFF __attribute__((__sfr__));

/* ADCON1: ADC Control Register 1 */
extern volatile unsigned int ADCON1 __attribute__((__sfr__));
typedef struct tagADCON1BITS {
        unsigned DONE   :1;
        unsigned SAMP   :1;
        unsigned ASAM   :1;
        unsigned SIMSAM :1;
        unsigned        :1;
        unsigned SSRC   :3;
        unsigned FORM   :2;
        unsigned        :3;
        unsigned ADSIDL :1;
        unsigned        :1;
        unsigned ADON   :1;
} ADCON1BITS;
extern volatile ADCON1BITS ADCON1bits __attribute__((__sfr__));

/* ADCON2: ADC Control Register 2 */
extern volatile unsigned int ADCON2 __attribute__((__sfr__));
typedef struct tagADCON2BITS {
        unsigned ALTS   :1;
        unsigned BUFM   :1;
        unsigned SMPI   :4;
        unsigned        :1;
        unsigned BUFS   :1;
        unsigned CHPS   :2;
        unsigned CSCNA  :1;
        unsigned        :2;
        unsigned VCFG   :3;
} ADCON2BITS;
extern volatile ADCON2BITS ADCON2bits __attribute__((__sfr__));

/* ADCON3: ADC Control Register 3 */
extern volatile unsigned int ADCON3 __attribute__((__sfr__));
typedef struct tagADCON3BITS {
        unsigned ADCS   :6;
        unsigned        :1;
        unsigned ADRC   :1;
        unsigned SAMC   :5;
        unsigned        :3;
} ADCON3BITS;
extern volatile ADCON3BITS ADCON3bits __attribute__((__sfr__));

/* ADCHS: ADC Input Channel Select Register */
extern volatile unsigned int ADCHS __attribute__((__sfr__));
typedef struct tagADCHSBITS {
        unsigned CH0SA  :4;
        unsigned CH0NA  :1;
        unsigned CH123SA:1;
        unsigned CH123NA:2;
        unsigned CH0SB  :4;
        unsigned CH0NB  :1;
        unsigned CH123SB:1;
        unsigned CH123NB:2;
} ADCHSBITS;
extern volatile ADCHSBITS ADCHSbits __attribute__((__sfr__));

/* ADPCFG: ADC Port Configuration Register */
extern volatile unsigned int ADPCFG __attribute__((__sfr__));
typedef struct tagADPCFGBITS {
        unsigned PCFG0  :1;
        unsigned PCFG1  :1;
        unsigned PCFG2  :1;
        unsigned PCFG3  :1;
        unsigned PCFG4  :1;
        unsigned PCFG5  :1;
        unsigned PCFG6  :1;
        unsigned PCFG7  :1;
        unsigned PCFG8  :1;
        unsigned PCFG9  :1;
        unsigned PCFG10 :1;
        unsigned PCFG11 :1;
        unsigned PCFG12 :1;
        unsigned PCFG13 :1;
        unsigned PCFG14 :1;
        unsigned PCFG15 :1;
} ADPCFGBITS;
extern volatile ADPCFGBITS ADPCFGbits __attribute__((__sfr__));

/* ADCSSL: ADC Input Scan Select Register */
extern volatile unsigned int ADCSSL __attribute__((__sfr__));
typedef struct tagADCSSLBITS {
        unsigned CSSL0  :1;
        unsigned CSSL1  :1;
        unsigned CSSL2  :1;
        unsigned CSSL3  :1;
        unsigned CSSL4  :1;
        unsigned CSSL5  :1;
        unsigned CSSL6  :1;
        unsigned CSSL7  :1;
        unsigned CSSL8  :1;
        unsigned CSSL9  :1;
        unsigned CSSL10 :1;
        unsigned CSSL11 :1;
        unsigned CSSL12 :1;
        unsigned CSSL13 :1;
        unsigned CSSL14 :1;
        unsigned CSSL15 :1;
} ADCSSLBITS;
extern volatile ADCSSLBITS ADCSSLbits __attribute__((__sfr__));


/* ------------------------------ */
/* I/O Ports register definitions */
/* ------------------------------ */

/* TRISA: Port A Direction Control Register */
extern volatile unsigned int TRISA __attribute__((__sfr__));
typedef struct tagTRISABITS {
        unsigned        :9;
        unsigned TRISA9 :1;
        unsigned TRISA10:1;
        unsigned        :3;
        unsigned TRISA14:1;
        unsigned TRISA15:1;
} TRISABITS;
extern volatile TRISABITS TRISAbits __attribute__((__sfr__));

/* PORTA: Port A Pin Register */
extern volatile unsigned int PORTA __attribute__((__sfr__));
typedef struct tagPORTABITS {
        unsigned        :9;
        unsigned RA9    :1;
        unsigned RA10   :1;
        unsigned        :3;
        unsigned RA14   :1;
        unsigned RA15   :1;
} PORTABITS;
extern volatile PORTABITS PORTAbits __attribute__((__sfr__));

/* LATA: Port A Latch Register */
extern volatile unsigned int LATA __attribute__((__sfr__));
typedef struct tagLATABITS {
        unsigned        :9;
        unsigned LATA9  :1;
        unsigned LATA10 :1;
        unsigned        :3;
        unsigned LATA14 :1;
        unsigned LATA15 :1;
} LATABITS;
extern volatile LATABITS LATAbits __attribute__((__sfr__));

/* TRISB: Port B Direction Control Register */
extern volatile unsigned int TRISB __attribute__((__sfr__));
typedef struct tagTRISBBITS {
        unsigned TRISB0 :1;
        unsigned TRISB1 :1;
        unsigned TRISB2 :1;
        unsigned TRISB3 :1;
        unsigned TRISB4 :1;
        unsigned TRISB5 :1;
        unsigned TRISB6 :1;
        unsigned TRISB7 :1;
        unsigned TRISB8 :1;
        unsigned TRISB9 :1;
        unsigned TRISB10:1;
        unsigned TRISB11:1;
        unsigned TRISB12:1;
        unsigned TRISB13:1;
        unsigned TRISB14:1;
        unsigned TRISB15:1;
} TRISBBITS;
extern volatile TRISBBITS TRISBbits __attribute__((__sfr__));

/* PORTB: Port B Pin Register */
extern volatile unsigned int PORTB __attribute__((__sfr__));
typedef struct tagPORTBBITS {
        unsigned RB0    :1;
        unsigned RB1    :1;
        unsigned RB2    :1;
        unsigned RB3    :1;
        unsigned RB4    :1;
        unsigned RB5    :1;
        unsigned RB6    :1;
        unsigned RB7    :1;
        unsigned RB8    :1;
        unsigned RB9    :1;
        unsigned RB10   :1;
        unsigned RB11   :1;
        unsigned RB12   :1;
        unsigned RB13   :1;
        unsigned RB14   :1;
        unsigned RB15   :1;
} PORTBBITS;
extern volatile PORTBBITS PORTBbits __attribute__((__sfr__));

/* LATB: Port B Latch Register */
extern volatile unsigned int LATB __attribute__((__sfr__));
typedef struct tagLATBBITS {
        unsigned LATB0  :1;
        unsigned LATB1  :1;
        unsigned LATB2  :1;
        unsigned LATB3  :1;
        unsigned LATB4  :1;
        unsigned LATB5  :1;
        unsigned LATB6  :1;
        unsigned LATB7  :1;
        unsigned LATB8  :1;
        unsigned LATB9  :1;
        unsigned LATB10 :1;
        unsigned LATB11 :1;
        unsigned LATB12 :1;
        unsigned LATB13 :1;
        unsigned LATB14 :1;
        unsigned LATB15 :1;
} LATBBITS;
extern volatile LATBBITS LATBbits __attribute__((__sfr__));

/* TRISC: Port C Direction Control Register */
extern volatile unsigned int TRISC __attribute__((__sfr__));
typedef struct tagTRISCBITS {
        unsigned        :1;
        unsigned TRISC1 :1;
        unsigned        :1;
        unsigned TRISC3 :1;
        unsigned        :9;
        unsigned TRISC13:1;
        unsigned TRISC14:1;
        unsigned TRISC15:1;
} TRISCBITS;
extern volatile TRISCBITS TRISCbits __attribute__((__sfr__));

/* PORTC: Port C Pin Register */
extern volatile unsigned int PORTC __attribute__((__sfr__));
typedef struct tagPORTCBITS {
        unsigned        :1;
        unsigned RC1    :1;
        unsigned        :1;
        unsigned RC3    :1;
        unsigned        :9;
        unsigned RC13   :1;
        unsigned RC14   :1;
        unsigned RC15   :1;
} PORTCBITS;
extern volatile PORTCBITS PORTCbits __attribute__((__sfr__));

/* LATC: Port C Latch Register */
extern volatile unsigned int LATC __attribute__((__sfr__));
typedef struct tagLATCBITS {
        unsigned        :1;
        unsigned LATC1  :1;
        unsigned        :1;
        unsigned LATC3  :1;
        unsigned        :9;
        unsigned LATC13 :1;
        unsigned LATC14 :1;
        unsigned LATC15 :1;
} LATCBITS;
extern volatile LATCBITS LATCbits __attribute__((__sfr__));

/* TRISD: Port D Direction Control Register */
extern volatile unsigned int TRISD __attribute__((__sfr__));
typedef struct tagTRISDBITS {
        unsigned TRISD0 :1;
        unsigned TRISD1 :1;
        unsigned TRISD2 :1;
        unsigned TRISD3 :1;
        unsigned TRISD4 :1;
        unsigned TRISD5 :1;
        unsigned TRISD6 :1;
        unsigned TRISD7 :1;
        unsigned TRISD8 :1;
        unsigned TRISD9 :1;
        unsigned TRISD10:1;
        unsigned TRISD11:1;
        unsigned TRISD12:1;
        unsigned TRISD13:1;
        unsigned TRISD14:1;
        unsigned TRISD15:1;
} TRISDBITS;
extern volatile TRISDBITS TRISDbits __attribute__((__sfr__));

/* PORTD: Port D Pin Register */
extern volatile unsigned int PORTD __attribute__((__sfr__));
typedef struct tagPORTDBITS {
        unsigned RD0    :1;
        unsigned RD1    :1;
        unsigned RD2    :1;
        unsigned RD3    :1;
        unsigned RD4    :1;
        unsigned RD5    :1;
        unsigned RD6    :1;
        unsigned RD7    :1;
        unsigned RD8    :1;
        unsigned RD9    :1;
        unsigned RD10   :1;
        unsigned RD11   :1;
        unsigned RD12   :1;
        unsigned RD13   :1;
        unsigned RD14   :1;
        unsigned RD15   :1;
} PORTDBITS;
extern volatile PORTDBITS PORTDbits __attribute__((__sfr__));

/* LATD: Port D Latch Register */
extern volatile unsigned int LATD __attribute__((__sfr__));
typedef struct tagLATDBITS {
        unsigned LATD0  :1;
        unsigned LATD1  :1;
        unsigned LATD2  :1;
        unsigned LATD3  :1;
        unsigned LATD4  :1;
        unsigned LATD5  :1;
        unsigned LATD6  :1;
        unsigned LATD7  :1;
        unsigned LATD8  :1;
        unsigned LATD9  :1;
        unsigned LATD10 :1;
        unsigned LATD11 :1;
        unsigned LATD12 :1;
        unsigned LATD13 :1;
        unsigned LATD14 :1;
        unsigned LATD15 :1;
} LATDBITS;
extern volatile LATDBITS LATDbits __attribute__((__sfr__));

/* TRISE: Port E Direction Control Register */
extern volatile unsigned int TRISE __attribute__((__sfr__));
typedef struct tagTRISEBITS {
        unsigned TRISE0 :1;
        unsigned TRISE1 :1;
        unsigned TRISE2 :1;
        unsigned TRISE3 :1;
        unsigned TRISE4 :1;
        unsigned TRISE5 :1;
        unsigned TRISE6 :1;
        unsigned TRISE7 :1;
        unsigned TRISE8 :1;
        unsigned TRISE9 :1;
        unsigned        :6;
} TRISEBITS;
extern volatile TRISEBITS TRISEbits __attribute__((__sfr__));

/* PORTE: Port E Pin Register */
extern volatile unsigned int PORTE __attribute__((__sfr__));
typedef struct tagPORTEBITS {
        unsigned RE0    :1;
        unsigned RE1    :1;
        unsigned RE2    :1;
        unsigned RE3    :1;
        unsigned RE4    :1;
        unsigned RE5    :1;
        unsigned RE6    :1;
        unsigned RE7    :1;
        unsigned RE8    :1;
        unsigned RE9    :1;
        unsigned        :6;
} PORTEBITS;
extern volatile PORTEBITS PORTEbits __attribute__((__sfr__));

/* LATE: Port E Latch Register */
extern volatile unsigned int LATE __attribute__((__sfr__));
typedef struct tagLATEBITS {
        unsigned LATE0  :1;
        unsigned LATE1  :1;
        unsigned LATE2  :1;
        unsigned LATE3  :1;
        unsigned LATE4  :1;
        unsigned LATE5  :1;
        unsigned LATE6  :1;
        unsigned LATE7  :1;
        unsigned LATE8  :1;
        unsigned LATE9  :1;
        unsigned        :6;
} LATEBITS;
extern volatile LATEBITS LATEbits __attribute__((__sfr__));

/* TRISF: Port F Direction Control Register */
extern volatile unsigned int TRISF __attribute__((__sfr__));
typedef struct tagTRISFBITS {
        unsigned TRISF0 :1;
        unsigned TRISF1 :1;
        unsigned TRISF2 :1;
        unsigned TRISF3 :1;
        unsigned TRISF4 :1;
        unsigned TRISF5 :1;
        unsigned TRISF6 :1;
        unsigned TRISF7 :1;
        unsigned TRISF8 :1;
        unsigned        :7;
} TRISFBITS;
extern volatile TRISFBITS TRISFbits __attribute__((__sfr__));

/* PORTF: Port F Pin Register */
extern volatile unsigned int PORTF __attribute__((__sfr__));
typedef struct tagPORTFBITS {
        unsigned RF0    :1;
        unsigned RF1    :1;
        unsigned RF2    :1;
        unsigned RF3    :1;
        unsigned RF4    :1;
        unsigned RF5    :1;
        unsigned RF6    :1;
        unsigned RF7    :1;
        unsigned RF8    :1;
        unsigned        :7;
} PORTFBITS;
extern volatile PORTFBITS PORTFbits __attribute__((__sfr__));

/* LATF: Port F Latch Register */
extern volatile unsigned int LATF __attribute__((__sfr__));
typedef struct tagLATFBITS {
        unsigned LATF0  :1;
        unsigned LATF1  :1;
        unsigned LATF2  :1;
        unsigned LATF3  :1;
        unsigned LATF4  :1;
        unsigned LATF5  :1;
        unsigned LATF6  :1;
        unsigned LATF7  :1;
        unsigned LATF8  :1;
        unsigned        :7;
} LATFBITS;
extern volatile LATFBITS LATFbits __attribute__((__sfr__));

/* TRISG: Port G Direction Control Register */
extern volatile unsigned int TRISG __attribute__((__sfr__));
typedef struct tagTRISGBITS {
        unsigned TRISG0 :1;
        unsigned TRISG1 :1;
        unsigned TRISG2 :1;
        unsigned TRISG3 :1;
        unsigned        :2;
        unsigned TRISG6 :1;
        unsigned TRISG7 :1;
        unsigned TRISG8 :1;
        unsigned TRISG9 :1;
        unsigned        :6;
} TRISGBITS;
extern volatile TRISGBITS TRISGbits __attribute__((__sfr__));

/* PORTG: Port G Pin Register */
extern volatile unsigned int PORTG __attribute__((__sfr__));
typedef struct tagPORTGBITS {
        unsigned RG0    :1;
        unsigned RG1    :1;
        unsigned RG2    :1;
        unsigned RG3    :1;
        unsigned        :2;
        unsigned RG6    :1;
        unsigned RG7    :1;
        unsigned RG8    :1;
        unsigned RG9    :1;
        unsigned        :6;
} PORTGBITS;
extern volatile PORTGBITS PORTGbits __attribute__((__sfr__));

/* LATG: Port G Latch Register */
extern volatile unsigned int LATG __attribute__((__sfr__));
typedef struct tagLATGBITS {
        unsigned LATG0  :1;
        unsigned LATG1  :1;
        unsigned LATG2  :1;
        unsigned LATG3  :1;
        unsigned        :2;
        unsigned LATG6  :1;
        unsigned LATG7  :1;
        unsigned LATG8  :1;
        unsigned LATG9  :1;
        unsigned        :6;
} LATGBITS;
extern volatile LATGBITS LATGbits __attribute__((__sfr__));


/* ------------------------- */
/* CAN1 register definitions */
/* ------------------------- */

/* Generic structure of entire SFR area for each CAN module */
typedef struct tagCAN {
        unsigned int cxrxf0sid;
        unsigned int cxrxf0eidh;
        unsigned int cxrxf0eidl;
        unsigned int reserved0;
        unsigned int cxrxf1sid;
        unsigned int cxrxf1eidh;
        unsigned int cxrxf1eidl;
        unsigned int reserved1;
        unsigned int cxrxf2sid;
        unsigned int cxrxf2eidh;
        unsigned int cxrxf2eidl;
        unsigned int reserved2;
        unsigned int cxrxf3sid;
        unsigned int cxrxf3eidh;
        unsigned int cxrxf3eidl;
        unsigned int reserved3;
        unsigned int cxrxf4sid;
        unsigned int cxrxf4eidh;
        unsigned int cxrxf4eidl;
        unsigned int reserved4;
        unsigned int cxrxf5sid;
        unsigned int cxrxf5eidh;
        unsigned int cxrxf5eidl;
        unsigned int reserved5;
        unsigned int cxrxm0sid;
        unsigned int cxrxm0eidh;
        unsigned int cxrxm0eidl;
        unsigned int reserved6;
        unsigned int cxrxm1sid;
        unsigned int cxrxm1eidh;
        unsigned int cxrxm1eidl;
        unsigned int reserved7;
        unsigned int cxtx2sid;
        unsigned int cxtx2eid;
        unsigned int cxtx2dlc; 
        unsigned int cxtx2b1;
        unsigned int cxtx2b2;
        unsigned int cxtx2b3;
        unsigned int cxtx2b4;
        unsigned int cxtx2con;
        unsigned int cxtx1sid;
        unsigned int cxtx1eid;
        unsigned int cxtx1dlc; 
        unsigned int cxtx1b1;
        unsigned int cxtx1b2;
        unsigned int cxtx1b3;
        unsigned int cxtx1b4;
        unsigned int cxtx1con;
        unsigned int cxtx0sid;
        unsigned int cxtx0eid;
        unsigned int cxtx0dlc; 
        unsigned int cxtx0b1;
        unsigned int cxtx0b2;
        unsigned int cxtx0b3;
        unsigned int cxtx0b4;
        unsigned int cxtx0con;
        unsigned int cxrx1sid;
        unsigned int cxrx1eid;
        unsigned int cxrx1dlc;
        unsigned int cxrx1b1;
        unsigned int cxrx1b2;
        unsigned int cxrx1b3;
        unsigned int cxrx1b4;
        unsigned int cxrx1con;
        unsigned int cxrx0sid;
        unsigned int cxrx0eid;
        unsigned int cxrx0dlc;
        unsigned int cxrx0b1;
        unsigned int cxrx0b2;
        unsigned int cxrx0b3;
        unsigned int cxrx0b4;
        unsigned int cxrx0con;
        unsigned int cxctrl;
        unsigned int cxcfg1;
        unsigned int cxcfg2;
        unsigned int cxintf;
        unsigned int cxinte;
        unsigned int cxec;
        unsigned int reserved8[50];
} CAN, *PCAN;

/* SFR blocks for each CAN module */
extern volatile CAN CAN1 __attribute__((__sfr__));
extern volatile CAN CAN2 __attribute__((__sfr__));

/* Generic structure for CAN Receive Filter Standard Identifier Register */
typedef struct tagCxRXFxSIDBITS {
        unsigned EXIDE  :1;
        unsigned        :1; 
        unsigned SID    :11;
        unsigned        :3;
} CxRXFxSIDBITS;

/* C1RXF0SID: CAN1 Receive Filter 0 SID Register */
extern volatile unsigned int C1RXF0SID __attribute__((__sfr__));
extern volatile CxRXFxSIDBITS C1RXF0SIDbits __attribute__((__sfr__));

/* C1RXF0EIDH: CAN1 Receive Filter 0 EIDH Register */
extern volatile unsigned int C1RXF0EIDH __attribute__((__sfr__));

/* C1RXF0EIDL: CAN1 Receive Filter 0 EIDL Register */
extern volatile unsigned int C1RXF0EIDL __attribute__((__sfr__));

/* C1RXF1SID: CAN1 Receive Filter 1 SID Register */
extern volatile unsigned int C1RXF1SID __attribute__((__sfr__));
extern volatile CxRXFxSIDBITS C1RXF1SIDbits __attribute__((__sfr__));

/* C1RXF1EIDH: CAN1 Receive Filter 1 EIDH Register */
extern volatile unsigned int C1RXF1EIDH __attribute__((__sfr__));

/* C1RXF1EIDL: CAN1 Receive Filter 1 EIDL Register */
extern volatile unsigned int C1RXF1EIDL __attribute__((__sfr__));

/* C1RXF2SID: CAN1 Receive Filter 2 SID Register */
extern volatile unsigned int C1RXF2SID __attribute__((__sfr__));
extern volatile CxRXFxSIDBITS C1RXF2SIDbits __attribute__((__sfr__));

/* C1RXF2EIDH: CAN1 Receive Filter 2 EIDH Register */
extern volatile unsigned int C1RXF2EIDH __attribute__((__sfr__));

/* C1RXF2EIDL: CAN1 Receive Filter 2 EIDL Register */
extern volatile unsigned int C1RXF2EIDL __attribute__((__sfr__));

/* C1RXF3SID: CAN1 Receive Filter 3 SID Register */
extern volatile unsigned int C1RXF3SID __attribute__((__sfr__));
extern volatile CxRXFxSIDBITS C1RXF3SIDbits __attribute__((__sfr__));

/* C1RXF3EIDH: CAN1 Receive Filter 3 EIDH Register */
extern volatile unsigned int C1RXF3EIDH __attribute__((__sfr__));

/* C1RXF3EIDL: CAN1 Receive Filter 3 EIDL Register */
extern volatile unsigned int C1RXF3EIDL __attribute__((__sfr__));

/* C1RXF4SID: CAN1 Receive Filter 4 SID Register */
extern volatile unsigned int C1RXF4SID __attribute__((__sfr__));
extern volatile CxRXFxSIDBITS C1RXF4SIDbits __attribute__((__sfr__));

/* C1RXF4EIDH: CAN1 Receive Filter 4 EIDH Register */
extern volatile unsigned int C1RXF4EIDH __attribute__((__sfr__));

/* C1RXF4EIDL: CAN1 Receive Filter 4 EIDL Register */
extern volatile unsigned int C1RXF4EIDL __attribute__((__sfr__));

/* C1RXF5SID: CAN1 Receive Filter 5 SID Register */
extern volatile unsigned int C1RXF5SID __attribute__((__sfr__));
extern volatile CxRXFxSIDBITS C1RXF5SIDbits __attribute__((__sfr__));

/* C1RXF5EIDH: CAN1 Receive Filter 5 EIDH Register */
extern volatile unsigned int C1RXF5EIDH __attribute__((__sfr__)); 

/* C1RXF5EIDL: CAN1 Receive Filter 5 EIDL Register */
extern volatile unsigned int C1RXF5EIDL __attribute__((__sfr__));

/* Generic structure for CAN Receive Mask Standard Identifier Register */
typedef struct tagCxRXMxSIDBITS {
        unsigned MIDE   :1;
        unsigned        :1; 
        unsigned SID    :11;
        unsigned        :3;
} CxRXMxSIDBITS;

/* C1RXM0SID: CAN1 Receive Mask 0 SID Register */
extern volatile unsigned int C1RXM0SID __attribute__((__sfr__));
extern volatile CxRXMxSIDBITS C1RXM0SIDbits __attribute__((__sfr__));

/* C1RXM0EIDH: CAN1 Receive Mask 0 EIDH Register */
extern volatile unsigned int C1RXM0EIDH __attribute__((__sfr__));

/* C1RXM0EIDL: CAN1 Receive Mask 0 EIDL Register */
extern volatile unsigned int C1RXM0EIDL __attribute__((__sfr__));

/* C1RXM1SID: CAN1 Receive Mask 1 SID Register */
extern volatile unsigned int C1RXM1SID __attribute__((__sfr__));
extern volatile CxRXMxSIDBITS C1RXM1SIDbits __attribute__((__sfr__));

/* C1RXM1EIDH: CAN1 Receive Mask 1 EIDH Register */
extern volatile unsigned int C1RXM1EIDH __attribute__((__sfr__));

/* C1RXM1EIDL: CAN1 Receive Mask 1 EIDL Register */
extern volatile unsigned int C1RXM1EIDL __attribute__((__sfr__));

/* Generic structure for CAN Transmit Standard Identifier Register */
typedef struct tagCxTXxSIDBITS {
        unsigned TXIDE  :1;
        unsigned SRR    :1;
        unsigned SID5_0 :6;
        unsigned        :3;
        unsigned SID10_6:5;
} CxTXxSIDBITS;

/* Generic structure for CAN Transmit Extended Identifier Register */
typedef struct tagCxTXxEIDBITS {
        unsigned EID13_6:8;
        unsigned        :4;
        unsigned EID17_14:4;
} CxTXxEIDBITS;

/* Generic structure for CAN Transmit Data Length Code Register */
typedef struct tagCxTXxDLCBITS {
        unsigned        :3;
        unsigned DLC    :4;
        unsigned TXRB0  :1;
        unsigned TXRB1  :1;
        unsigned TXRTR  :1;
        unsigned EID5_0 :6;
} CxTXxDLCBITS;

/* Generic structure for CAN Transmit Control Register */
typedef struct tagCxTXxCONBITS {
        unsigned TXPRI  :2;
        unsigned        :1;
        unsigned TXREQ  :1;
        unsigned TXERR  :1;
        unsigned TXLARB :1;
        unsigned TXABT  :1;
        unsigned        :9;
} CxTXxCONBITS;

/* C1TX2SID: CAN1 Transmit 2 SID Register */
extern volatile unsigned int C1TX2SID __attribute__((__sfr__));
extern volatile CxTXxSIDBITS C1TX2SIDbits __attribute__((__sfr__));

/* C1TX2EID: CAN1 Transmit 2 EID Register */
extern volatile unsigned int C1TX2EID __attribute__((__sfr__));
extern volatile CxTXxEIDBITS C1TX2EIDbits __attribute__((__sfr__));

/* C1TX2DLC: CAN1 Transmit 2 DLC Register */
extern volatile unsigned int C1TX2DLC __attribute__((__sfr__));
extern volatile CxTXxDLCBITS C1TX2DLCbits __attribute__((__sfr__));

/* C1TX2B1: CAN1 Transmit 2 Buffer Word 1 */
extern volatile unsigned int C1TX2B1 __attribute__((__sfr__));

/* C1TX2B2: CAN1 Transmit 2 Buffer Word 2 */
extern volatile unsigned int C1TX2B2 __attribute__((__sfr__));

/* C1TX2B3: CAN1 Transmit 2 Buffer Word 3 */
extern volatile unsigned int C1TX2B3 __attribute__((__sfr__));

/* C1TX2B4: CAN1 Transmit 2 Buffer Word 4 */
extern volatile unsigned int C1TX2B4 __attribute__((__sfr__));

/* C1TX2CON: CAN1 Transmit 2 Control Register */
extern volatile unsigned int C1TX2CON __attribute__((__sfr__));
extern volatile CxTXxCONBITS C1TX2CONbits __attribute__((__sfr__));

/* C1TX1SID: CAN1 Transmit 1 SID Register */
extern volatile unsigned int C1TX1SID __attribute__((__sfr__));
extern volatile CxTXxSIDBITS C1TX1SIDbits __attribute__((__sfr__));

/* C1TX1EID: CAN1 Transmit 1 EID Register */
extern volatile unsigned int C1TX1EID __attribute__((__sfr__));
extern volatile CxTXxEIDBITS C1TX1EIDbits __attribute__((__sfr__));

/* C1TX1DLC: CAN1 Transmit 1 DLC Register */
extern volatile unsigned int C1TX1DLC __attribute__((__sfr__));
extern volatile CxTXxDLCBITS C1TX1DLCbits __attribute__((__sfr__));

/* C1TX1B1: CAN1 Transmit 1 Buffer Word 1 */
extern volatile unsigned int C1TX1B1 __attribute__((__sfr__));

/* C1TX1B2: CAN1 Transmit 1 Buffer Word 2 */
extern volatile unsigned int C1TX1B2 __attribute__((__sfr__));

/* C1TX1B3: CAN1 Transmit 1 Buffer Word 3 */
extern volatile unsigned int C1TX1B3 __attribute__((__sfr__));

/* C1TX1B4: CAN1 Transmit 1 Buffer Word 4 */
extern volatile unsigned int C1TX1B4 __attribute__((__sfr__));

/* C1TX1CON: CAN1 Transmit 1 Control Register */
extern volatile unsigned int C1TX1CON __attribute__((__sfr__));
extern volatile CxTXxCONBITS C1TX1CONbits __attribute__((__sfr__));

/* C1TX0SID: CAN1 Transmit 0 SID Register */
extern volatile unsigned int C1TX0SID __attribute__((__sfr__));
extern volatile CxTXxSIDBITS C1TX0SIDbits __attribute__((__sfr__));

/* C1TX0EID: CAN1 Transmit 0 EID Register */
extern volatile unsigned int C1TX0EID __attribute__((__sfr__));
extern volatile CxTXxEIDBITS C1TX0EIDbits __attribute__((__sfr__));

/* C1TX0DLC: CAN1 Transmit 0 DLC Register */
extern volatile unsigned int C1TX0DLC __attribute__((__sfr__));
extern volatile CxTXxDLCBITS C1TX0DLCbits __attribute__((__sfr__));

/* C1TX0B1: CAN1 Transmit 0 Buffer Word 1 */
extern volatile unsigned int C1TX0B1 __attribute__((__sfr__));

/* C1TX0B2: CAN1 Transmit 0 Buffer Word 2 */
extern volatile unsigned int C1TX0B2 __attribute__((__sfr__));

/* C1TX0B3: CAN1 Transmit 0 Buffer Word 3 */
extern volatile unsigned int C1TX0B3 __attribute__((__sfr__));

/* C1TX0B4: CAN1 Transmit 0 Buffer Word 4 */
extern volatile unsigned int C1TX0B4 __attribute__((__sfr__));

/* C1TX0CON: CAN1 Transmit 0 Control Register */
extern volatile unsigned int C1TX0CON __attribute__((__sfr__));
extern volatile CxTXxCONBITS C1TX0CONbits __attribute__((__sfr__));

/* Generic structure for CAN Receive Standard Identifier Register */
typedef struct tagCxRXxSIDBITS {
        unsigned RXIDE  :1;
        unsigned SRR    :1;
        unsigned SID    :11;
        unsigned        :3;
} CxRXxSIDBITS;

/* Generic structure for CAN Receive Data Length Code Register */
typedef struct tagCxRXxDLCBITS {
        unsigned DLC    :4;
        unsigned RXRB0  :1;
        unsigned        :3;
        unsigned RXRB1  :1;
        unsigned RXRTR  :1;
        unsigned EID5_0 :6;
} CxRXxDLCBITS;

/* Generic structure for CAN Receive 1 Control Register */
typedef struct tagCxRX1CONBITS {
        unsigned FILHIT :3;
        unsigned RXRTRRO:1;
        unsigned        :3;
        unsigned RXFUL  :1;
        unsigned        :8;
} CxRX1CONBITS;

/* C1RX1SID: CAN1 Receive 1 SID Register */
extern volatile unsigned int C1RX1SID __attribute__((__sfr__));
extern volatile CxRXxSIDBITS C1RX1SIDbits __attribute__((__sfr__));

/* C1RX1EID: CAN1 Receive 1 EID Register */
extern volatile unsigned int C1RX1EID __attribute__((__sfr__));

/* C1RX1DLC: CAN1 Receive 1 DLC Register */
extern volatile unsigned int C1RX1DLC __attribute__((__sfr__));
extern volatile CxRXxDLCBITS C1RX1DLCbits __attribute__((__sfr__));

/* C1RX1B1: CAN1 Receive 1 Buffer Word 1 */
extern volatile unsigned int C1RX1B1 __attribute__((__sfr__));

/* C1RX1B2: CAN1 Receive 1 Buffer Word 2 */
extern volatile unsigned int C1RX1B2 __attribute__((__sfr__));

/* C1RX1B3: CAN1 Receive 1 Buffer Word 3 */
extern volatile unsigned int C1RX1B3 __attribute__((__sfr__));

/* C1RX1B4: CAN1 Receive 1 Buffer Word 4 */
extern volatile unsigned int C1RX1B4 __attribute__((__sfr__));

/* C1RX1CON: CAN1 Receive 1 Control Register */
extern volatile unsigned int C1RX1CON __attribute__((__sfr__));
extern volatile CxRX1CONBITS C1RX1CONbits __attribute__((__sfr__));

/* Generic structure for CAN Receive 0 Control Register */
typedef struct tagCxRX0CONBITS {
        unsigned FILHIT0:1;
        unsigned JTOFF  :1;
        unsigned DBEN   :1;
        unsigned RXRTRRO:1;
        unsigned        :3;
        unsigned RXFUL  :1;
        unsigned        :8;
} CxRX0CONBITS;

/* C1RX0SID: CAN1 Receive 0 SID Register */
extern volatile unsigned int C1RX0SID __attribute__((__sfr__));
extern volatile CxRXxSIDBITS C1RX0SIDbits __attribute__((__sfr__));

/* C1RX0EID: CAN1 Receive 0 EID Register */
extern volatile unsigned int C1RX0EID __attribute__((__sfr__));

/* C1RX0DLC: CAN1 Receive 0 DLC Register */
extern volatile unsigned int C1RX0DLC __attribute__((__sfr__));
extern volatile CxRXxDLCBITS C1RX0DLCbits __attribute__((__sfr__));

/* C1RX0B1: CAN1 Receive 0 Buffer Word 1 */
extern volatile unsigned int C1RX0B1 __attribute__((__sfr__));

/* C1RX0B2: CAN1 Receive 0 Buffer Word 2 */
extern volatile unsigned int C1RX0B2 __attribute__((__sfr__));

/* C1RX0B3: CAN1 Receive 0 Buffer Word 3 */
extern volatile unsigned int C1RX0B3 __attribute__((__sfr__));

/* C1RX0B4: CAN1 Receive 0 Buffer Word 4 */
extern volatile unsigned int C1RX0B4 __attribute__((__sfr__));

/* C1RX0CON: CAN1 Receive 0 Control Register */
extern volatile unsigned int C1RX0CON __attribute__((__sfr__));
extern volatile CxRX0CONBITS C1RX0CONbits __attribute__((__sfr__));

/* C1CTRL: CAN1 Control Register */
extern volatile unsigned int C1CTRL __attribute__((__sfr__));
typedef struct tagCxCTRLBITS {
        unsigned        :1;
        unsigned ICODE  :3;
        unsigned        :1;
        unsigned OPMODE :3;
        unsigned REQOP  :3;
        unsigned CANCKS :1;
        unsigned ABAT   :1;
        unsigned CSIDL  :1;
        unsigned        :1;
        unsigned CANCAP :1;
} CxCTRLBITS;
extern volatile CxCTRLBITS C1CTRLbits __attribute__((__sfr__));

/* C1CFG1: CAN1 Baud Rate Control Register 1 */
extern volatile unsigned int C1CFG1 __attribute__((__sfr__));
typedef struct tagCxCFG1BITS {
        unsigned BRP    :6;
        unsigned SJW    :2;
        unsigned        :8;
} CxCFG1BITS;
extern volatile CxCFG1BITS C1CFG1bits __attribute__((__sfr__));

/* C1CFG2: CAN1 Baud Rate Control Register 2 */
extern volatile unsigned int C1CFG2 __attribute__((__sfr__));
typedef struct tagCxCFG2BITS {
        unsigned PRSEG  :3;
        unsigned SEG1PH :3;
        unsigned SAM    :1;
        unsigned SEG2PHTS:1;
        unsigned SEG2PH :3;
        unsigned        :3;
        unsigned WAKFIL :1;
        unsigned        :1;
} CxCFG2BITS;
extern volatile CxCFG2BITS C1CFG2bits __attribute__((__sfr__));

/* C1INTF: CAN1 Interrupt Flag Status Register */
extern volatile unsigned int C1INTF __attribute__((__sfr__));
typedef struct tagCxINTFBITS {
        unsigned RX0IF  :1;
        unsigned RX1IF  :1;
        unsigned TX0IF  :1;
        unsigned TX1IF  :1;
        unsigned TX2IF  :1;
        unsigned ERRIF  :1;
        unsigned WAKIF  :1;
        unsigned IVRIF  :1;
        unsigned EWARN  :1;
        unsigned RXWAR  :1;
        unsigned TXWAR  :1;
        unsigned RXEP   :1;
        unsigned TXEP   :1;
        unsigned TXBO   :1;
        unsigned RX1OVR :1;
        unsigned RX0OVR :1;
} CxINTFBITS;
extern volatile CxINTFBITS C1INTFbits __attribute__((__sfr__));

/* C1INTE: CAN1 Interrupt Enable Control Register */
extern volatile unsigned int C1INTE __attribute__((__sfr__));
typedef struct tagCxINTEBITS {
        unsigned RX0IE  :1;
        unsigned RX1IE  :1;
        unsigned TX0IE  :1;
        unsigned TX1IE  :1;
        unsigned TX2IE  :1;
        unsigned ERRIE  :1;
        unsigned WAKIE  :1;
        unsigned IVRIE  :1;
        unsigned        :8;
} CxINTEBITS;
extern volatile CxINTEBITS C1INTEbits __attribute__((__sfr__));

/* C1EC: CAN1 Error Count Register */
extern volatile unsigned int C1EC __attribute__((__sfr__));

/* C1RERRCNT: CAN1 Receive Error Count (C1EC low byte) */
extern volatile unsigned char C1RERRCNT __attribute__((__sfr__));

/* C1TERRCNT: CAN1 Transmit Error Count (C1EC high byte) */
extern volatile unsigned char C1TERRCNT __attribute__((__sfr__));


/* ------------------------- */
/* CAN2 register definitions */
/* ------------------------- */

/* The registers in the CAN2 module (with prefix 'C2') are identical    */
/* to the corresponding registers in the CAN1 (with prefix 'C1') module */

extern volatile unsigned int C2RXF0SID __attribute__((__sfr__));
extern volatile CxRXFxSIDBITS C2RXF0SIDbits __attribute__((__sfr__));
extern volatile unsigned int C2RXF0EIDH __attribute__((__sfr__));
extern volatile unsigned int C2RXF0EIDL __attribute__((__sfr__));

extern volatile unsigned int C2RXF1SID __attribute__((__sfr__));
extern volatile CxRXFxSIDBITS C2RXF1SIDbits __attribute__((__sfr__));
extern volatile unsigned int C2RXF1EIDH __attribute__((__sfr__));
extern volatile unsigned int C2RXF1EIDL __attribute__((__sfr__));

extern volatile unsigned int C2RXF2SID __attribute__((__sfr__));
extern volatile CxRXFxSIDBITS C2RXF2SIDbits __attribute__((__sfr__));
extern volatile unsigned int C2RXF2EIDH __attribute__((__sfr__));
extern volatile unsigned int C2RXF2EIDL __attribute__((__sfr__));

extern volatile unsigned int C2RXF3SID __attribute__((__sfr__));
extern volatile CxRXFxSIDBITS C2RXF3SIDbits __attribute__((__sfr__));
extern volatile unsigned int C2RXF3EIDH __attribute__((__sfr__));
extern volatile unsigned int C2RXF3EIDL __attribute__((__sfr__));

extern volatile unsigned int C2RXF4SID __attribute__((__sfr__));
extern volatile CxRXFxSIDBITS C2RXF4SIDbits __attribute__((__sfr__));
extern volatile unsigned int C2RXF4EIDH __attribute__((__sfr__));
extern volatile unsigned int C2RXF4EIDL __attribute__((__sfr__));

extern volatile unsigned int C2RXF5SID __attribute__((__sfr__));
extern volatile CxRXFxSIDBITS C2RXF5SIDbits __attribute__((__sfr__));
extern volatile unsigned int C2RXF5EIDH __attribute__((__sfr__)); 
extern volatile unsigned int C2RXF5EIDL __attribute__((__sfr__));
 
extern volatile unsigned int C2RXM0SID __attribute__((__sfr__));
extern volatile CxRXMxSIDBITS C2RXM0SIDbits __attribute__((__sfr__));
extern volatile unsigned int C2RXM0EIDH __attribute__((__sfr__));
extern volatile unsigned int C2RXM0EIDL __attribute__((__sfr__));

extern volatile unsigned int C2RXM1SID __attribute__((__sfr__));
extern volatile CxRXMxSIDBITS C2RXM1SIDbits __attribute__((__sfr__));
extern volatile unsigned int C2RXM1EIDH __attribute__((__sfr__));
extern volatile unsigned int C2RXM1EIDL __attribute__((__sfr__));

extern volatile unsigned int C2TX2SID __attribute__((__sfr__));
extern volatile CxTXxSIDBITS C2TX2SIDbits __attribute__((__sfr__));
extern volatile unsigned int C2TX2EID __attribute__((__sfr__));
extern volatile CxTXxEIDBITS C2TX2EIDbits __attribute__((__sfr__));
extern volatile unsigned int C2TX2DLC __attribute__((__sfr__));
extern volatile CxTXxDLCBITS C2TX2DLCbits __attribute__((__sfr__));
extern volatile unsigned int C2TX2B1 __attribute__((__sfr__));
extern volatile unsigned int C2TX2B2 __attribute__((__sfr__));
extern volatile unsigned int C2TX2B3 __attribute__((__sfr__));
extern volatile unsigned int C2TX2B4 __attribute__((__sfr__));
extern volatile unsigned int C2TX2CON __attribute__((__sfr__));
extern volatile CxTXxCONBITS C2TX2CONbits __attribute__((__sfr__));

extern volatile unsigned int C2TX1SID __attribute__((__sfr__));
extern volatile CxTXxSIDBITS C2TX1SIDbits __attribute__((__sfr__));
extern volatile unsigned int C2TX1EID __attribute__((__sfr__));
extern volatile CxTXxEIDBITS C2TX1EIDbits __attribute__((__sfr__));
extern volatile unsigned int C2TX1DLC __attribute__((__sfr__));
extern volatile CxTXxDLCBITS C2TX1DLCbits __attribute__((__sfr__));
extern volatile unsigned int C2TX1B1 __attribute__((__sfr__));
extern volatile unsigned int C2TX1B2 __attribute__((__sfr__));
extern volatile unsigned int C2TX1B3 __attribute__((__sfr__));
extern volatile unsigned int C2TX1B4 __attribute__((__sfr__));
extern volatile unsigned int C2TX1CON __attribute__((__sfr__));
extern volatile CxTXxCONBITS C2TX1CONbits __attribute__((__sfr__));

extern volatile unsigned int C2TX0SID __attribute__((__sfr__));
extern volatile CxTXxSIDBITS C2TX0SIDbits __attribute__((__sfr__));
extern volatile unsigned int C2TX0EID __attribute__((__sfr__));
extern volatile CxTXxEIDBITS C2TX0EIDbits __attribute__((__sfr__));
extern volatile unsigned int C2TX0DLC __attribute__((__sfr__));
extern volatile CxTXxDLCBITS C2TX0DLCbits __attribute__((__sfr__));
extern volatile unsigned int C2TX0B1 __attribute__((__sfr__));
extern volatile unsigned int C2TX0B2 __attribute__((__sfr__));
extern volatile unsigned int C2TX0B3 __attribute__((__sfr__));
extern volatile unsigned int C2TX0B4 __attribute__((__sfr__));
extern volatile unsigned int C2TX0CON __attribute__((__sfr__));
extern volatile CxTXxCONBITS C2TX0CONbits __attribute__((__sfr__));

extern volatile unsigned int C2RX1SID __attribute__((__sfr__));
extern volatile CxRXxSIDBITS C2RX1SIDbits __attribute__((__sfr__));
extern volatile unsigned int C2RX1EID __attribute__((__sfr__));
extern volatile unsigned int C2RX1DLC __attribute__((__sfr__));
extern volatile CxRXxDLCBITS C2RX1DLCbits __attribute__((__sfr__));
extern volatile unsigned int C2RX1B1 __attribute__((__sfr__));
extern volatile unsigned int C2RX1B2 __attribute__((__sfr__));
extern volatile unsigned int C2RX1B3 __attribute__((__sfr__));
extern volatile unsigned int C2RX1B4 __attribute__((__sfr__));
extern volatile unsigned int C2RX1CON __attribute__((__sfr__));
extern volatile CxRX1CONBITS C2RX1CONbits __attribute__((__sfr__));

extern volatile unsigned int C2RX0SID __attribute__((__sfr__));
extern volatile CxRXxSIDBITS C2RX0SIDbits __attribute__((__sfr__));
extern volatile unsigned int C2RX0EID __attribute__((__sfr__));
extern volatile unsigned int C2RX0DLC __attribute__((__sfr__));
extern volatile CxRXxDLCBITS C2RX0DLCbits __attribute__((__sfr__));
extern volatile unsigned int C2RX0B1 __attribute__((__sfr__));
extern volatile unsigned int C2RX0B2 __attribute__((__sfr__));
extern volatile unsigned int C2RX0B3 __attribute__((__sfr__));
extern volatile unsigned int C2RX0B4 __attribute__((__sfr__));
extern volatile unsigned int C2RX0CON __attribute__((__sfr__));
extern volatile CxRX0CONBITS C2RX0CONbits __attribute__((__sfr__));

extern volatile unsigned int C2CTRL __attribute__((__sfr__));
extern volatile CxCTRLBITS C2CTRLbits __attribute__((__sfr__));

extern volatile unsigned int C2CFG1 __attribute__((__sfr__));
extern volatile CxCFG1BITS C2CFG1bits __attribute__((__sfr__));

extern volatile unsigned int C2CFG2 __attribute__((__sfr__));
extern volatile CxCFG2BITS C2CFG2bits __attribute__((__sfr__));

extern volatile unsigned int C2INTF __attribute__((__sfr__));
extern volatile CxINTFBITS C2INTFbits __attribute__((__sfr__));

extern volatile unsigned int C2INTE __attribute__((__sfr__));
extern volatile CxINTEBITS C2INTEbits __attribute__((__sfr__));

extern volatile unsigned int C2EC __attribute__((__sfr__));
extern volatile unsigned char C2RERRCNT __attribute__((__sfr__));
extern volatile unsigned char C2TERRCNT __attribute__((__sfr__));


/* --------------------------------------- */
/* System Integration register definitions */
/* --------------------------------------- */

/* RCON: Reset Control Register */
extern volatile unsigned int RCON __attribute__((__sfr__));
typedef struct tagRCONBITS {
        unsigned POR    :1;
        unsigned BOR    :1;
        unsigned IDLE   :1;
        unsigned SLEEP  :1;
        unsigned WDTO   :1;
        unsigned SWDTEN :1;
        unsigned SWR    :1;
        unsigned EXTR   :1;
        unsigned        :5;
        unsigned BGST   :1;
        unsigned IOPUWR :1;
        unsigned TRAPR  :1;
} RCONBITS;
extern volatile RCONBITS RCONbits __attribute__((__sfr__));

/* OSCCON: Oscillator Control Register */
extern volatile unsigned int OSCCON __attribute__((__sfr__));
typedef struct tagOSCCONBITS {
        unsigned OSWEN  :1;
        unsigned LPOSCEN:1;
        unsigned        :1;
        unsigned CF     :1;
        unsigned        :1;
        unsigned LOCK   :1;
        unsigned POST   :2;
        unsigned NOSC   :3;
        unsigned        :1;
        unsigned COSC   :3;
        unsigned        :1;
} OSCCONBITS;
extern volatile OSCCONBITS OSCCONbits __attribute__((__sfr__));

/* OSCTUN: FRC Oscillator Tuning Register */
extern volatile unsigned int OSCTUN __attribute__((__sfr__));
typedef struct tagOSCTUNBITS {
        unsigned TUN0   :1;
        unsigned TUN1   :1;
        unsigned TUN2   :1;
        unsigned TUN3   :1;
        unsigned        :12;
} OSCTUNBITS;
extern volatile OSCTUNBITS OSCTUNbits __attribute__((__sfr__));

/* --------------------------------------- */
/* Security register definitions */
/* --------------------------------------- */

/* BSRAM: Boot Segment RAM Control Register */
extern volatile unsigned int BSRAM __attribute__((__sfr__));
typedef struct tagBSRAMBITS {
        unsigned RL_BSR :1;
        unsigned IR_BSR :1;
        unsigned IW_BSR :1;
        unsigned        :13;
} BSRAMBITS;
extern volatile BSRAMBITS BSRAMbits __attribute__((__sfr__));



/* SSRAM: Secure Segment RAM Control Register */
extern volatile unsigned int SSRAM __attribute__((__sfr__));
typedef struct tagSSRAMBITS {
        unsigned RL_SSR :1;
        unsigned IR_SSR :1;
        unsigned IW_SSR :1;
        unsigned        :13;
} SSRAMBITS;
extern volatile SSRAMBITS SSRAMbits __attribute__((__sfr__));


/* ---------------------------------------- */
/* Non-Volatile Memory register definitions */
/* ---------------------------------------- */

/* NVMCON: Non-Volatile Memory Control Register */
extern volatile unsigned int NVMCON __attribute__((__sfr__));
typedef struct tagNVMCONBITS {
        unsigned PROGOP :7;
        unsigned        :1;
        unsigned TWRI   :1;
        unsigned        :4;
        unsigned WRERR  :1;
        unsigned WREN   :1;
        unsigned WR     :1;
} NVMCONBITS;
extern volatile NVMCONBITS NVMCONbits __attribute__((__sfr__));

/* NVM Address bits <15:0> */
extern volatile unsigned int NVMADR __attribute__((__sfr__));

/* NVM Address bits <23:16> */
extern volatile unsigned char NVMADRU __attribute__((__sfr__));

/* NVM Key */
extern volatile unsigned char NVMKEY __attribute__((__sfr__));


/* ---------------------------------------------- */
/* Peripheral Module Disable register definitions */
/* ---------------------------------------------- */

/* PMD1: Peripheral Module Disable Register 1 */
extern volatile unsigned int PMD1 __attribute__((__sfr__));
typedef struct tagPMD1BITS {
        unsigned ADCMD  :1;
        unsigned C1MD   :1;
        unsigned C2MD   :1;
        unsigned SPI1MD :1;
        unsigned SPI2MD :1;
        unsigned U1MD   :1;
        unsigned U2MD   :1;
        unsigned I2CMD  :1;
        unsigned        :1;
        unsigned PWMMD  :1;
        unsigned QEIMD  :1;
        unsigned T1MD   :1;
        unsigned T2MD   :1;
        unsigned T3MD   :1;
        unsigned T4MD   :1;
        unsigned T5MD   :1;
} PMD1BITS;
extern volatile PMD1BITS PMD1bits __attribute__((__sfr__));

/* PMD2: Peripheral Module Disable Register 3 */
extern volatile unsigned int PMD2 __attribute__((__sfr__));
typedef struct tagPMD2BITS {
        unsigned OC1MD  :1;
        unsigned OC2MD  :1;
        unsigned OC3MD  :1;
        unsigned OC4MD  :1;
        unsigned OC5MD  :1;
        unsigned OC6MD  :1;
        unsigned OC7MD  :1;
        unsigned OC8MD  :1;
        unsigned IC1MD  :1;
        unsigned IC2MD  :1;
        unsigned IC3MD  :1;
        unsigned IC4MD  :1;
        unsigned IC5MD  :1;
        unsigned IC6MD  :1;
        unsigned IC7MD  :1;
        unsigned IC8MD  :1;
} PMD2BITS;
extern volatile PMD2BITS PMD2bits __attribute__((__sfr__));


/* -------------------------------------------- */ 
/* Defines for unique SFR bit names             */
/* -------------------------------------------- */

/* SR */
#define _C SRbits.C
#define _Z SRbits.Z
#define _OV SRbits.OV
#define _N SRbits.N
#define _RA SRbits.RA
#define _IPL SRbits.IPL
#define _DC SRbits.DC
#define _DA SRbits.DA
#define _SAB SRbits.SAB
#define _OAB SRbits.OAB
#define _SB SRbits.SB
#define _SA SRbits.SA
#define _OB SRbits.OB
#define _OA SRbits.OA

/* CORCON */
#define _IF CORCONbits.IF
#define _RND CORCONbits.RND
#define _PSV CORCONbits.PSV
#define _IPL3 CORCONbits.IPL3
#define _ACCSAT CORCONbits.ACCSAT
#define _SATDW CORCONbits.SATDW
#define _SATB CORCONbits.SATB
#define _SATA CORCONbits.SATA
#define _DL CORCONbits.DL
#define _EDT CORCONbits.EDT
#define _US CORCONbits.US

/* MODCON */
#define _XWM MODCONbits.XWM
#define _YWM MODCONbits.YWM
#define _BWM MODCONbits.BWM
#define _YMODEN MODCONbits.YMODEN
#define _XMODEN MODCONbits.XMODEN

/* XBREV */
#define _XB XBREVbits.XB
#define _BREN XBREVbits.BREN

/* INTCON1 */
#define _OSCFAIL INTCON1bits.OSCFAIL
#define _STKERR INTCON1bits.STKERR
#define _ADDRERR INTCON1bits.ADDRERR
#define _MATHERR INTCON1bits.MATHERR
#define _COVTE INTCON1bits.COVTE
#define _OVBTE INTCON1bits.OVBTE
#define _OVATE INTCON1bits.OVATE
#define _NSTDIS INTCON1bits.NSTDIS

/* INTCON2 */
#define _INT0EP INTCON2bits.INT0EP
#define _INT1EP INTCON2bits.INT1EP
#define _INT2EP INTCON2bits.INT2EP
#define _INT3EP INTCON2bits.INT3EP
#define _INT4EP INTCON2bits.INT4EP
#define _DISI INTCON2bits.DISI
#define _ALTIVT INTCON2bits.ALTIVT

/* IFS0 */
#define _INT0IF IFS0bits.INT0IF 
#define _IC1IF IFS0bits.IC1IF
#define _OC1IF IFS0bits.OC1IF
#define _T1IF IFS0bits.T1IF
#define _IC2IF IFS0bits.IC2IF
#define _OC2IF IFS0bits.OC2IF
#define _T2IF IFS0bits.T2IF
#define _T3IF IFS0bits.T3IF
#define _SPI1IF IFS0bits.SPI1IF 
#define _U1RXIF IFS0bits.U1RXIF
#define _U1TXIF IFS0bits.U1TXIF
#define _ADIF IFS0bits.ADIF
#define _NVMIF IFS0bits.NVMIF
#define _SI2CIF IFS0bits.SI2CIF
#define _MI2CIF IFS0bits.MI2CIF
#define _CNIF IFS0bits.CNIF

/* IFS1 */
#define _INT1IF IFS1bits.INT1IF 
#define _IC7IF IFS1bits.IC7IF
#define _IC8IF IFS1bits.IC8IF
#define _OC3IF IFS1bits.OC3IF
#define _OC4IF IFS1bits.OC4IF
#define _T4IF IFS1bits.T4IF
#define _T5IF IFS1bits.T5IF
#define _INT2IF IFS1bits.INT2IF
#define _U2RXIF IFS1bits.U2RXIF 
#define _U2TXIF IFS1bits.U2TXIF
#define _SPI2IF IFS1bits.SPI2IF
#define _C1IF IFS1bits.C1IF
#define _IC3IF IFS1bits.IC3IF
#define _IC4IF IFS1bits.IC4IF
#define _IC5IF IFS1bits.IC5IF
#define _IC6IF IFS1bits.IC6IF

/* IFS2 */
#define _OC5IF IFS2bits.OC5IF 
#define _OC6IF IFS2bits.OC6IF
#define _OC7IF IFS2bits.OC7IF
#define _OC8IF IFS2bits.OC8IF
#define _INT3IF IFS2bits.INT3IF
#define _INT4IF IFS2bits.INT4IF
#define _C2IF IFS2bits.C2IF
#define _PWMIF IFS2bits.PWMIF
#define _QEIIF IFS2bits.QEIIF
#define _FLTAIF IFS2bits.FLTAIF 
#define _FLTBIF IFS2bits.FLTBIF

/* IEC0 */
#define _INT0IE IEC0bits.INT0IE 
#define _IC1IE IEC0bits.IC1IE
#define _OC1IE IEC0bits.OC1IE
#define _T1IE IEC0bits.T1IE
#define _IC2IE IEC0bits.IC2IE
#define _OC2IE IEC0bits.OC2IE
#define _T2IE IEC0bits.T2IE
#define _T3IE IEC0bits.T3IE
#define _SPI1IE IEC0bits.SPI1IE 
#define _U1RXIE IEC0bits.U1RXIE
#define _U1TXIE IEC0bits.U1TXIE
#define _ADIE IEC0bits.ADIE
#define _NVMIE IEC0bits.NVMIE
#define _SI2CIE IEC0bits.SI2CIE
#define _MI2CIE IEC0bits.MI2CIE
#define _CNIE IEC0bits.CNIE

/* IEC1 */
#define _INT1IE IEC1bits.INT1IE 
#define _IC7IE IEC1bits.IC7IE
#define _IC8IE IEC1bits.IC8IE
#define _OC3IE IEC1bits.OC3IE
#define _OC4IE IEC1bits.OC4IE
#define _T4IE IEC1bits.T4IE
#define _T5IE IEC1bits.T5IE
#define _INT2IE IEC1bits.INT2IE
#define _U2RXIE IEC1bits.U2RXIE 
#define _U2TXIE IEC1bits.U2TXIE
#define _SPI2IE IEC1bits.SPI2IE
#define _C1IE IEC1bits.C1IE
#define _IC3IE IEC1bits.IC3IE
#define _IC4IE IEC1bits.IC4IE
#define _IC5IE IEC1bits.IC5IE
#define _IC6IE IEC1bits.IC6IE

/* IEC2 */
#define _OC5IE IEC2bits.OC5IE 
#define _OC6IE IEC2bits.OC6IE
#define _OC7IE IEC2bits.OC7IE
#define _OC8IE IEC2bits.OC8IE
#define _INT3IE IEC2bits.INT3IE
#define _INT4IE IEC2bits.INT4IE
#define _C2IE IEC2bits.C2IE
#define _PWMIE IEC2bits.PWMIE
#define _QEIIE IEC2bits.QEIIE
#define _FLTAIE IEC2bits.FLTAIE 
#define _FLTBIE IEC2bits.FLTBIE

/* IPC0 */
#define _INT0IP IPC0bits.INT0IP 
#define _IC1IP IPC0bits.IC1IP
#define _OC1IP IPC0bits.OC1IP
#define _T1IP IPC0bits.T1IP

/* IPC1 */
#define _IC2IP IPC1bits.IC2IP 
#define _OC2IP IPC1bits.OC2IP
#define _T2IP IPC1bits.T2IP
#define _T3IP IPC1bits.T3IP

/* IPC2 */
#define _SPI1IP IPC2bits.SPI1IP 
#define _U1RXIP IPC2bits.U1RXIP
#define _U1TXIP IPC2bits.U1TXIP
#define _ADIP IPC2bits.ADIP

/* IPC3 */
#define _NVMIP IPC3bits.NVMIP 
#define _SI2CIP IPC3bits.SI2CIP
#define _MI2CIP IPC3bits.MI2CIP
#define _CNIP IPC3bits.CNIP

/* IPC4 */
#define _INT1IP IPC4bits.INT1IP 
#define _IC7IP IPC4bits.IC7IP
#define _IC8IP IPC4bits.IC8IP
#define _OC3IP IPC4bits.OC3IP

/* IPC5 */
#define _OC4IP IPC5bits.OC4IP 
#define _T4IP IPC5bits.T4IP
#define _T5IP IPC5bits.T5IP
#define _INT2IP IPC5bits.INT2IP

/* IPC6 */
#define _U2RXIP IPC6bits.U2RXIP 
#define _U2TXIP IPC6bits.U2TXIP
#define _SPI2IP IPC6bits.SPI2IP
#define _C1IP IPC6bits.C1IP

/* IPC7 */
#define _IC3IP IPC7bits.IC3IP 
#define _IC4IP IPC7bits.IC4IP
#define _IC5IP IPC7bits.IC5IP
#define _IC6IP IPC7bits.IC6IP

/* IPC8 */
#define _OC5IP IPC8bits.OC5IP 
#define _OC6IP IPC8bits.OC6IP
#define _OC7IP IPC8bits.OC7IP
#define _OC8IP IPC8bits.OC8IP

/* IPC9 */
#define _INT3IP IPC9bits.INT3IP 
#define _INT4IP IPC9bits.INT4IP
#define _C2IP IPC9bits.C2IP
#define _PWMIP IPC9bits.PWMIP

/* IPC10 */
#define _QEIIP IPC10bits.QEIIP
#define _FLTAIP IPC10bits.FLTAIP

/* IPC11 */
#define _FLTBIP IPC11bits.FLTBIP

/* CNEN1 */
#define _CN0IE CNEN1bits.CN0IE 
#define _CN1IE CNEN1bits.CN1IE
#define _CN2IE CNEN1bits.CN2IE
#define _CN3IE CNEN1bits.CN3IE
#define _CN4IE CNEN1bits.CN4IE
#define _CN5IE CNEN1bits.CN5IE
#define _CN6IE CNEN1bits.CN6IE
#define _CN7IE CNEN1bits.CN7IE
#define _CN8IE CNEN1bits.CN8IE 
#define _CN9IE CNEN1bits.CN9IE
#define _CN10IE CNEN1bits.CN10IE
#define _CN11IE CNEN1bits.CN11IE
#define _CN12IE CNEN1bits.CN12IE
#define _CN13IE CNEN1bits.CN13IE
#define _CN14IE CNEN1bits.CN14IE
#define _CN15IE CNEN1bits.CN15IE

/* CNEN2 */
#define _CN16IE CNEN2bits.CN16IE 
#define _CN17IE CNEN2bits.CN17IE
#define _CN18IE CNEN2bits.CN18IE
#define _CN19IE CNEN2bits.CN19IE
#define _CN20IE CNEN2bits.CN20IE
#define _CN21IE CNEN2bits.CN21IE

/* CNPU1 */
#define _CN0PUE CNPU1bits.CN0PUE 
#define _CN1PUE CNPU1bits.CN1PUE
#define _CN2PUE CNPU1bits.CN2PUE
#define _CN3PUE CNPU1bits.CN3PUE
#define _CN4PUE CNPU1bits.CN4PUE
#define _CN5PUE CNPU1bits.CN5PUE
#define _CN6PUE CNPU1bits.CN6PUE
#define _CN7PUE CNPU1bits.CN7PUE
#define _CN8PUE CNPU1bits.CN8PUE 
#define _CN9PUE CNPU1bits.CN9PUE
#define _CN10PUE CNPU1bits.CN10PUE
#define _CN11PUE CNPU1bits.CN11PUE
#define _CN12PUE CNPU1bits.CN12PUE
#define _CN13PUE CNPU1bits.CN13PUE
#define _CN14PUE CNPU1bits.CN14PUE
#define _CN15PUE CNPU1bits.CN15PUE

/* CNEN2 */
#define _CN16PUE CNPU2bits.CN16PUE 
#define _CN17PUE CNPU2bits.CN17PUE
#define _CN18PUE CNPU2bits.CN18PUE
#define _CN19PUE CNPU2bits.CN19PUE
#define _CN20PUE CNPU2bits.CN20PUE
#define _CN21PUE CNPU2bits.CN21PUE

/* QEICON */
#define _UPDN_SRC QEICONbits.UPDN_SRC
#define _TQCS QEICONbits.TQCS
#define _POSRES QEICONbits.POSRES
#define _TQCKPS QEICONbits.TQCKPS
#define _TQGATE QEICONbits.TQGATE
#define _PCDOUT QEICONbits.PCDOUT
#define _SWPAB QEICONbits.SWPAB
#define _QEIM QEICONbits.QEIM
#define _UPDN QEICONbits.UPDN
#define _INDX QEICONbits.INDX
#define _QEISIDL QEICONbits.QEISIDL
#define _CNTERR QEICONbits.CNTERR

/* DFLTCON */
#define _INDCK DFLTCONbits.INDCK
#define _INDOUT DFLTCONbits.INDOUT
#define _QECK DFLTCONbits.QECK
#define _QEOUT DFLTCONbits.QEOUT
#define _CEID DFLTCONbits.CEID

/* PTCON */
#define _PTMOD PTCONbits.PTMOD
#define _PTCKPS PTCONbits.PTCKPS
#define _PTOPS PTCONbits.PTOPS
#define _PTSIDL PTCONbits.PTSIDL
#define _PTEN PTCONbits.PTEN

/* PTMR */
#define _PTDIR PTMRbits.PTDIR

/* SEVTCMP */
#define _SEVTDIR SEVTCMPbits.SEVTDIR

/* PWMCON1 */
#define _PEN1L PWMCON1bits.PEN1L
#define _PEN2L PWMCON1bits.PEN2L
#define _PEN3L PWMCON1bits.PEN3L
#define _PEN4L PWMCON1bits.PEN4L
#define _PEN1H PWMCON1bits.PEN1H
#define _PEN2H PWMCON1bits.PEN2H
#define _PEN3H PWMCON1bits.PEN3H
#define _PEN4H PWMCON1bits.PEN4H
#define _PMOD1 PWMCON1bits.PMOD1
#define _PMOD2 PWMCON1bits.PMOD2
#define _PMOD3 PWMCON1bits.PMOD3
#define _PMOD4 PWMCON1bits.PMOD4

/* PWMCON2 */
#define _UDIS PWMCON2bits.UDIS
#define _OSYNC PWMCON2bits.OSYNC
#define _SEVOPS PWMCON2bits.SEVOPS

/* DTCON1 */
#define _DTA DTCON1bits.DTA
#define _DTAPS DTCON1bits.DTAPS
#define _DTB DTCON1bits.DTB
#define _DTBPS DTCON1bits.DTBPS

/* DTCON2 */
#define _DTS1I DTCON2bits.DTS1I
#define _DTS1A DTCON2bits.DTS1A
#define _DTS2I DTCON2bits.DTS2I
#define _DTS2A DTCON2bits.DTS2A
#define _DTS3I DTCON2bits.DTS3I
#define _DTS3A DTCON2bits.DTS3A
#define _DTS4I DTCON2bits.DTS4I
#define _DTS4A DTCON2bits.DTS4A

/* FLTACON */
#define _FAEN1 FLTACONbits.FAEN1
#define _FAEN2 FLTACONbits.FAEN2
#define _FAEN3 FLTACONbits.FAEN3
#define _FAEN4 FLTACONbits.FAEN4
#define _FLTAM FLTACONbits.FLTAM
#define _FAOV1L FLTACONbits.FAOV1L
#define _FAOV1H FLTACONbits.FAOV1H
#define _FAOV2L FLTACONbits.FAOV2L
#define _FAOV2H FLTACONbits.FAOV2H
#define _FAOV3L FLTACONbits.FAOV3L
#define _FAOV3H FLTACONbits.FAOV3H
#define _FAOV4L FLTACONbits.FAOV4L
#define _FAOV4H FLTACONbits.FAOV4H

/* FLTBCON */
#define _FBEN1 FLTBCONbits.FBEN1
#define _FBEN2 FLTBCONbits.FBEN2
#define _FBEN3 FLTBCONbits.FBEN3
#define _FBEN4 FLTBCONbits.FBEN4
#define _FLTBM FLTBCONbits.FLTBM
#define _FBOV1L FLTBCONbits.FBOV1L
#define _FBOV1H FLTBCONbits.FBOV1H
#define _FBOV2L FLTBCONbits.FBOV2L
#define _FBOV2H FLTBCONbits.FBOV2H
#define _FBOV3L FLTBCONbits.FBOV3L
#define _FBOV3H FLTBCONbits.FBOV3H
#define _FBOV4L FLTBCONbits.FBOV4L
#define _FBOV4H FLTBCONbits.FBOV4H

/* OVDCON */
#define _POUT1L OVDCONbits.POUT1L
#define _POUT1H OVDCONbits.POUT1H
#define _POUT2L OVDCONbits.POUT2L
#define _POUT2H OVDCONbits.POUT2H
#define _POUT3L OVDCONbits.POUT3L
#define _POUT3H OVDCONbits.POUT3H
#define _POUT4L OVDCONbits.POUT4L
#define _POUT4H OVDCONbits.POUT4H
#define _POVD1L OVDCONbits.POVD1L
#define _POVD1H OVDCONbits.POVD1H
#define _POVD2L OVDCONbits.POVD2L
#define _POVD2H OVDCONbits.POVD2H
#define _POVD3L OVDCONbits.POVD3L
#define _POVD3H OVDCONbits.POVD3H
#define _POVD4L OVDCONbits.POVD4L
#define _POVD4H OVDCONbits.POVD4H

/* I2CCON */
#define _SEN I2CCONbits.SEN
#define _RSEN I2CCONbits.RSEN
#define _PEN I2CCONbits.PEN
#define _RCEN I2CCONbits.RCEN
#define _ACKEN I2CCONbits.ACKEN
#define _ACKDT I2CCONbits.ACKDT
#define _STREN I2CCONbits.STREN
#define _GCEN I2CCONbits.GCEN
#define _SMEN I2CCONbits.SMEN
#define _DISSLW I2CCONbits.DISSLW
#define _A10M I2CCONbits.A10M
#define _IPMIEN I2CCONbits.IPMIEN
#define _SCLREL I2CCONbits.SCLREL
#define _I2CSIDL I2CCONbits.I2CSIDL
#define _I2CEN I2CCONbits.I2CEN

/* I2CSTAT */
#define _TBF I2CSTATbits.TBF
#define _RBF I2CSTATbits.RBF
#define _R_W I2CSTATbits.R_W
#define _S I2CSTATbits.S
#define _P I2CSTATbits.P
#define _D_A I2CSTATbits.D_A
#define _I2COV I2CSTATbits.I2COV
#define _IWCOL I2CSTATbits.IWCOL
#define _ADD10 I2CSTATbits.ADD10
#define _GCSTAT I2CSTATbits.GCSTAT
#define _BCL I2CSTATbits.BCL
#define _TRSTAT I2CSTATbits.TRSTAT
#define _ACKSTAT I2CSTATbits.ACKSTAT

/* ADCON1 */
#define _DONE ADCON1bits.DONE
#define _SAMP ADCON1bits.SAMP
#define _ASAM ADCON1bits.ASAM
#define _SIMSAM ADCON1bits.SIMSAM
#define _SSRC ADCON1bits.SSRC
#define _FORM ADCON1bits.FORM
#define _ADSIDL ADCON1bits.ADSIDL
#define _ADON ADCON1bits.ADON

/* ADCON2 */
#define _ALTS ADCON2bits.ALTS
#define _BUFM ADCON2bits.BUFM
#define _SMPI ADCON2bits.SMPI
#define _BUFS ADCON2bits.BUFS
#define _CSCNA ADCON2bits.CSCNA
#define _VCFG ADCON2bits.VCFG

/* ADCON3 */
#define _ADCS ADCON3bits.ADCS
#define _ADRC ADCON3bits.ADRC
#define _SAMC ADCON3bits.SAMC

/* ADCHS */
#define _CH0SA ADCHSbits.CH0SA
#define _CH0NA ADCHSbits.CH0NA
#define _CH123SA ADCHSbits.CH123SA
#define _CH123NA ADCHSbits.CH123NA
#define _CH0SB ADCHSbits.CH0SB
#define _CH0NB ADCHSbits.CH0NB
#define _CH123SB ADCHSbits.CH123SB
#define _CH123NB ADCHSbits.CH123NB

/* ADPCFG */
#define _PCFG0 ADPCFGbits.PCFG0
#define _PCFG1 ADPCFGbits.PCFG1
#define _PCFG2 ADPCFGbits.PCFG2
#define _PCFG3 ADPCFGbits.PCFG3
#define _PCFG4 ADPCFGbits.PCFG4
#define _PCFG5 ADPCFGbits.PCFG5
#define _PCFG6 ADPCFGbits.PCFG6
#define _PCFG7 ADPCFGbits.PCFG7
#define _PCFG8 ADPCFGbits.PCFG8
#define _PCFG9 ADPCFGbits.PCFG9
#define _PCFG10 ADPCFGbits.PCFG10
#define _PCFG11 ADPCFGbits.PCFG11
#define _PCFG12 ADPCFGbits.PCFG12
#define _PCFG13 ADPCFGbits.PCFG13
#define _PCFG14 ADPCFGbits.PCFG14
#define _PCFG15 ADPCFGbits.PCFG15

/* ADCSSL */
#define _CSSL0 ADCSSLbits.CSSL0
#define _CSSL1 ADCSSLbits.CSSL1
#define _CSSL2 ADCSSLbits.CSSL2
#define _CSSL3 ADCSSLbits.CSSL3
#define _CSSL4 ADCSSLbits.CSSL4
#define _CSSL5 ADCSSLbits.CSSL5
#define _CSSL6 ADCSSLbits.CSSL6
#define _CSSL7 ADCSSLbits.CSSL7
#define _CSSL8 ADCSSLbits.CSSL8
#define _CSSL9 ADCSSLbits.CSSL9
#define _CSSL10 ADCSSLbits.CSSL10
#define _CSSL11 ADCSSLbits.CSSL11
#define _CSSL12 ADCSSLbits.CSSL12
#define _CSSL13 ADCSSLbits.CSSL13
#define _CSSL14 ADCSSLbits.CSSL14
#define _CSSL15 ADCSSLbits.CSSL15

/* TRISA */
#define _TRISA9 TRISAbits.TRISA9
#define _TRISA10 TRISAbits.TRISA10
#define _TRISA14 TRISAbits.TRISA14
#define _TRISA15 TRISAbits.TRISA15

/* PORTA */
#define _RA9 PORTAbits.RA9
#define _RA10 PORTAbits.RA10
#define _RA14 PORTAbits.RA14
#define _RA15 PORTAbits.RA15

/* LATA */
#define _LATA9 LATAbits.LATA9
#define _LATA10 LATAbits.LATA10
#define _LATA14 LATAbits.LATA14
#define _LATA15 LATAbits.LATA15

/* TRISB */
#define _TRISB0 TRISBbits.TRISB0
#define _TRISB1 TRISBbits.TRISB1
#define _TRISB2 TRISBbits.TRISB2
#define _TRISB3 TRISBbits.TRISB3
#define _TRISB4 TRISBbits.TRISB4
#define _TRISB5 TRISBbits.TRISB5
#define _TRISB6 TRISBbits.TRISB6
#define _TRISB7 TRISBbits.TRISB7
#define _TRISB8 TRISBbits.TRISB8
#define _TRISB9 TRISBbits.TRISB9
#define _TRISB10 TRISBbits.TRISB10
#define _TRISB11 TRISBbits.TRISB11
#define _TRISB12 TRISBbits.TRISB12
#define _TRISB13 TRISBbits.TRISB13
#define _TRISB14 TRISBbits.TRISB14
#define _TRISB15 TRISBbits.TRISB15

/* PORTB */
#define _RB0 PORTBbits.RB0
#define _RB1 PORTBbits.RB1
#define _RB2 PORTBbits.RB2
#define _RB3 PORTBbits.RB3
#define _RB4 PORTBbits.RB4
#define _RB5 PORTBbits.RB5
#define _RB6 PORTBbits.RB6
#define _RB7 PORTBbits.RB7
#define _RB8 PORTBbits.RB8
#define _RB9 PORTBbits.RB9
#define _RB10 PORTBbits.RB10
#define _RB11 PORTBbits.RB11
#define _RB12 PORTBbits.RB12
#define _RB13 PORTBbits.RB13
#define _RB14 PORTBbits.RB14
#define _RB15 PORTBbits.RB15

/* LATB */
#define _LATB0 LATBbits.LATB0
#define _LATB1 LATBbits.LATB1
#define _LATB2 LATBbits.LATB2
#define _LATB3 LATBbits.LATB3
#define _LATB4 LATBbits.LATB4
#define _LATB5 LATBbits.LATB5
#define _LATB6 LATBbits.LATB6
#define _LATB7 LATBbits.LATB7
#define _LATB8 LATBbits.LATB8
#define _LATB9 LATBbits.LATB9
#define _LATB10 LATBbits.LATB10
#define _LATB11 LATBbits.LATB11
#define _LATB12 LATBbits.LATB12
#define _LATB13 LATBbits.LATB13
#define _LATB14 LATBbits.LATB14
#define _LATB15 LATBbits.LATB15

/* TRISC */
#define _TRISC1 TRISCbits.TRISC1
#define _TRISC3 TRISCbits.TRISC3
#define _TRISC13 TRISCbits.TRISC13
#define _TRISC14 TRISCbits.TRISC14
#define _TRISC15 TRISCbits.TRISC15

/* PORTC */
#define _RC1 PORTCbits.RC1
#define _RC3 PORTCbits.RC3
#define _RC13 PORTCbits.RC13
#define _RC14 PORTCbits.RC14
#define _RC15 PORTCbits.RC15

/* LATC */
#define _LATC1 LATCbits.LATC1
#define _LATC3 LATCbits.LATC3
#define _LATC13 LATCbits.LATC13
#define _LATC14 LATCbits.LATC14
#define _LATC15 LATCbits.LATC15

/* TRISD */
#define _TRISD0 TRISDbits.TRISD0
#define _TRISD1 TRISDbits.TRISD1
#define _TRISD2 TRISDbits.TRISD2
#define _TRISD3 TRISDbits.TRISD3
#define _TRISD4 TRISDbits.TRISD4
#define _TRISD5 TRISDbits.TRISD5
#define _TRISD6 TRISDbits.TRISD6
#define _TRISD7 TRISDbits.TRISD7
#define _TRISD8 TRISDbits.TRISD8
#define _TRISD9 TRISDbits.TRISD9
#define _TRISD10 TRISDbits.TRISD10
#define _TRISD11 TRISDbits.TRISD11
#define _TRISD12 TRISDbits.TRISD12
#define _TRISD13 TRISDbits.TRISD13
#define _TRISD14 TRISDbits.TRISD14
#define _TRISD15 TRISDbits.TRISD15

/* PORTD */
#define _RD0 PORTDbits.RD0
#define _RD1 PORTDbits.RD1
#define _RD2 PORTDbits.RD2
#define _RD3 PORTDbits.RD3
#define _RD4 PORTDbits.RD4
#define _RD5 PORTDbits.RD5
#define _RD6 PORTDbits.RD6
#define _RD7 PORTDbits.RD7
#define _RD8 PORTDbits.RD8
#define _RD9 PORTDbits.RD9
#define _RD10 PORTDbits.RD10
#define _RD11 PORTDbits.RD11
#define _RD12 PORTDbits.RD12
#define _RD13 PORTDbits.RD13
#define _RD14 PORTDbits.RD14
#define _RD15 PORTDbits.RD15

/* LATD */
#define _LATD0 LATDbits.LATD0
#define _LATD1 LATDbits.LATD1
#define _LATD2 LATDbits.LATD2
#define _LATD3 LATDbits.LATD3
#define _LATD4 LATDbits.LATD4
#define _LATD5 LATDbits.LATD5
#define _LATD6 LATDbits.LATD6
#define _LATD7 LATDbits.LATD7
#define _LATD8 LATDbits.LATD8
#define _LATD9 LATDbits.LATD9
#define _LATD10 LATDbits.LATD10
#define _LATD11 LATDbits.LATD11
#define _LATD12 LATDbits.LATD12
#define _LATD13 LATDbits.LATD13
#define _LATD14 LATDbits.LATD14
#define _LATD15 LATDbits.LATD15

/* TRISE */
#define _TRISE0 TRISEbits.TRISE0
#define _TRISE1 TRISEbits.TRISE1
#define _TRISE2 TRISEbits.TRISE2
#define _TRISE3 TRISEbits.TRISE3
#define _TRISE4 TRISEbits.TRISE4
#define _TRISE5 TRISEbits.TRISE5
#define _TRISE6 TRISEbits.TRISE6
#define _TRISE7 TRISEbits.TRISE7
#define _TRISE8 TRISEbits.TRISE8
#define _TRISE9 TRISEbits.TRISE9

/* PORTE */
#define _RE0 PORTEbits.RE0
#define _RE1 PORTEbits.RE1
#define _RE2 PORTEbits.RE2
#define _RE3 PORTEbits.RE3
#define _RE4 PORTEbits.RE4
#define _RE5 PORTEbits.RE5
#define _RE6 PORTEbits.RE6
#define _RE7 PORTEbits.RE7
#define _RE8 PORTEbits.RE8
#define _RE9 PORTEbits.RE9

/* LATE */
#define _LATE0 LATEbits.LATE0
#define _LATE1 LATEbits.LATE1
#define _LATE2 LATEbits.LATE2
#define _LATE3 LATEbits.LATE3
#define _LATE4 LATEbits.LATE4
#define _LATE5 LATEbits.LATE5
#define _LATE6 LATEbits.LATE6
#define _LATE7 LATEbits.LATE7
#define _LATE8 LATEbits.LATE8
#define _LATE9 LATEbits.LATE9

/* TRISF */
#define _TRISF0 TRISFbits.TRISF0
#define _TRISF1 TRISFbits.TRISF1
#define _TRISF2 TRISFbits.TRISF2
#define _TRISF3 TRISFbits.TRISF3
#define _TRISF4 TRISFbits.TRISF4
#define _TRISF5 TRISFbits.TRISF5
#define _TRISF6 TRISFbits.TRISF6
#define _TRISF7 TRISFbits.TRISF7
#define _TRISF8 TRISFbits.TRISF8

/* PORTF */
#define _RF0 PORTFbits.RF0
#define _RF1 PORTFbits.RF1
#define _RF2 PORTFbits.RF2
#define _RF3 PORTFbits.RF3
#define _RF4 PORTFbits.RF4
#define _RF5 PORTFbits.RF5
#define _RF6 PORTFbits.RF6
#define _RF7 PORTFbits.RF7
#define _RF8 PORTFbits.RF8

/* LATF */
#define _LATF0 LATFbits.LATF0
#define _LATF1 LATFbits.LATF1
#define _LATF2 LATFbits.LATF2
#define _LATF3 LATFbits.LATF3
#define _LATF4 LATFbits.LATF4
#define _LATF5 LATFbits.LATF5
#define _LATF6 LATFbits.LATF6
#define _LATF7 LATFbits.LATF7
#define _LATF8 LATFbits.LATF8

/* TRISG */
#define _TRISG0 TRISGbits.TRISG0
#define _TRISG1 TRISGbits.TRISG1
#define _TRISG2 TRISGbits.TRISG2
#define _TRISG3 TRISGbits.TRISG3
#define _TRISG6 TRISGbits.TRISG6
#define _TRISG7 TRISGbits.TRISG7
#define _TRISG8 TRISGbits.TRISG8
#define _TRISG9 TRISGbits.TRISG9

/* PORTG */
#define _RG0 PORTGbits.RG0
#define _RG1 PORTGbits.RG1
#define _RG2 PORTGbits.RG2
#define _RG3 PORTGbits.RG3
#define _RG6 PORTGbits.RG6
#define _RG7 PORTGbits.RG7
#define _RG8 PORTGbits.RG8
#define _RG9 PORTGbits.RG9

/* LATG */
#define _LATG0 LATGbits.LATG0
#define _LATG1 LATGbits.LATG1
#define _LATG2 LATGbits.LATG2
#define _LATG3 LATGbits.LATG3
#define _LATG6 LATGbits.LATG6
#define _LATG7 LATGbits.LATG7
#define _LATG8 LATGbits.LATG8
#define _LATG9 LATGbits.LATG9

/* RCON */
#define _POR RCONbits.POR
#define _BOR RCONbits.BOR
#define _IDLE RCONbits.IDLE
#define _SLEEP RCONbits.SLEEP
#define _WDTO RCONbits.WDTO
#define _SWDTEN RCONbits.SWDTEN
#define _SWR RCONbits.SWR
#define _EXTR RCONbits.EXTR
#define _BGST RCONbits.BGST
#define _IOPUWR RCONbits.IOPUWR
#define _TRAPR RCONbits.TRAPR

/* OSCCON */
#define _OSWEN OSCCONbits.OSWEN
#define _LPOSCEN OSCCONbits.LPOSCEN
#define _CF OSCCONbits.CF
#define _LOCK OSCCONbits.LOCK
#define _POST OSCCONbits.POST
#define _NOSC OSCCONbits.NOSC
#define _COSC OSCCONbits.COSC

/* OSCTUN */
#define _TUN0 OSCTUNbits.TUN0
#define _TUN1 OSCTUNbits.TUN1
#define _TUN2 OSCTUNbits.TUN2
#define _TUN3 OSCTUNbits.TUN3

/* NVMCON */
#define _PROGOP NVMCONbits.PROGOP
#define _TWRI NVMCONbits.TWRI
#define _WRERR NVMCONbits.WRERR
#define _WREN NVMCONbits.WREN
#define _WR NVMCONbits.WR

/* PMD1 */
#define _ADCMD PMD1bits.ADCMD
#define _C1MD PMD1bits.C1MD
#define _C2MD PMD1bits.C2MD
#define _SPI1MD PMD1bits.SPI1MD
#define _SPI2MD PMD1bits.SPI2MD
#define _U1MD PMD1bits.U1MD
#define _U2MD PMD1bits.U2MD
#define _I2CMD PMD1bits.I2CMD
#define _PWMMD PMD1bits.PWMMD
#define _QEIMD PMD1bits.QEIMD
#define _T1MD PMD1bits.T1MD
#define _T2MD PMD1bits.T2MD
#define _T3MD PMD1bits.T3MD
#define _T4MD PMD1bits.T4MD
#define _T5MD PMD1bits.T5MD

/* PMD2 */
#define _OC1MD PMD2bits.OC1MD
#define _OC2MD PMD2bits.OC2MD
#define _OC3MD PMD2bits.OC3MD
#define _OC4MD PMD2bits.OC4MD
#define _OC5MD PMD2bits.OC5MD
#define _OC6MD PMD2bits.OC6MD
#define _OC7MD PMD2bits.OC7MD
#define _OC8MD PMD2bits.OC8MD
#define _IC1MD PMD2bits.IC1MD
#define _IC2MD PMD2bits.IC2MD
#define _IC3MD PMD2bits.IC3MD
#define _IC4MD PMD2bits.IC4MD
#define _IC5MD PMD2bits.IC5MD
#define _IC6MD PMD2bits.IC6MD
#define _IC7MD PMD2bits.IC7MD
#define _IC8MD PMD2bits.IC8MD


/* -------------------------------------------- */ 
/* Macros for Device Configuration Registers    */
/* -------------------------------------------- */

/* FOSC */
#define _FOSC(x) __attribute__((section("__FOSC.sec,code"))) int _FOSC = (x);

#define CSW_FSCM_OFF    0xFFFF
#define CSW_ON_FSCM_OFF 0x7FFF
#define CSW_FSCM_ON     0x3FFF
#define LP              0xF8FF
#define FRC             0xF9FF
#define LPRC            0xFAFF
#define EXT             0xFBFF
#define ECIO_PLL4       0xFFED
#define ECIO_PLL8       0xFFEE
#define ECIO_PLL16      0xFFEF
#define FRC_PLL4        0xFFE1
#define FRC_PLL8        0xFFEA
#define FRC_PLL16       0xFFE3
#define XT_PLL4         0xFFE5
#define XT_PLL8         0xFFE6
#define XT_PLL16        0xFFE7
#define HS2_PLL4        0xFFF1
#define HS2_PLL8        0xFFF2
#define HS2_PLL16       0xFFF3
#define HS3_PLL4        0xFFF5
#define HS3_PLL8        0xFFF6
#define HS3_PLL16       0xFFF7
#define ECIO            0xFBEC
#define XT              0xFBE4
#define HS              0xFBE2
#define EC              0xFBEB
#define ERC             0xFBE9
#define ERCIO           0xFBE8
#define XTL             0xFBE0

/* FWDT */
#define _FWDT(x) __attribute__((section("__FWDT.sec,code"))) int _FWDT = (x);

#define WDT_ON         0xFFFF
#define WDT_OFF        0x7FFF
#define WDTPSA_1       0xFFCF
#define WDTPSA_8       0xFFDF
#define WDTPSA_64      0xFFEF
#define WDTPSA_512     0xFFFF
#define WDTPSB_1       0xFFF0
#define WDTPSB_2       0xFFF1
#define WDTPSB_3       0xFFF2
#define WDTPSB_4       0xFFF3
#define WDTPSB_5       0xFFF4
#define WDTPSB_6       0xFFF5
#define WDTPSB_7       0xFFF6
#define WDTPSB_8       0xFFF7
#define WDTPSB_9       0xFFF8
#define WDTPSB_10      0xFFF9
#define WDTPSB_11      0xFFFA
#define WDTPSB_12      0xFFFB
#define WDTPSB_13      0xFFFC
#define WDTPSB_14      0xFFFD
#define WDTPSB_15      0xFFFE
#define WDTPSB_16      0xFFFF

/* FBORPOR */
#define _FBORPOR(x) __attribute__((section("__FBORPOR.sec,code"))) int _FBORPOR = (x);

#define MCLR_EN        0xFFFF
#define MCLR_DIS       0x7FFF
#define RST_IOPIN      0xFFFF
#define RST_PWMPIN     0xFBFF
#define PWMxH_ACT_HI   0xFFFF
#define PWMxH_ACT_LO   0xFDFF
#define PWMxL_ACT_HI   0xFFFF
#define PWMxL_ACT_LO   0xFEFF
#define PBOR_ON        0xFFFF
#define PBOR_OFF       0xFF7F
#define BORV_20        0xFFFF
#define BORV_27        0xFFEF
#define BORV_42        0xFFDF
#define BORV_45        0xFFCF
#define PWRT_OFF       0xFFFC
#define PWRT_4         0xFFFD
#define PWRT_16        0xFFFE
#define PWRT_64        0xFFFF


/* FBS */
#define _FBS(x) __attribute__((section("__FBS.sec,code"))) int _FBS = (x);

#define NO_BOOT_RAM           0xFFFF
#define SMALL_BOOT_RAM        0xEFFF
#define MED_BOOT_RAM          0xDFFF
#define LAR_BOOT_RAM          0xCFFF

#define NO_BOOT_EEPROM        0xFFFF
#define SMALL_BOOT_EEPROM     0xFEFF
	

#define NO_BOOT_CODE          0xFFFF
#define STRD_SMALL_BOOT_CODE  0xFFFD
#define STRD_MEDIUM_BOOT_CODE 0xFFFB
#define STRD_LARGE_BOOT_CODE  0xFFF9

#define HIGH_SMALL_BOOT_CODE  0xFFF5
#define HIGH_MEDIUM_BOOT_CODE 0xFFF3
#define HIGH_LARGE_BOOT_CODE  0xFFF1

#define WR_PROT_BOOT_OFF      0xFFFF
#define WR_PROT_BOOT_ON       0xFFFE


/* FSS */
#define _FSS(x) __attribute__((section("__FSS.sec,code"))) int _FSS = (x);
#define NO_SEC_RAM           0xFFFF
#define SMALL_SEC_RAM        0xEFFF
#define MED_SEC_RAM          0xDFFF
#define LAR_SEC_RAM          0xCFFF

#define NO_SEC_EEPROM        0xFFFF
#define SMALL_SEC_EEPROM     0xFEFF
#define MED_SEC_EEPROM       0xFDFF
#define LAR_SEC_EEPROM       0xFCFF


#define NO_SEC_CODE          0xFFFF
#define STRD_SMALL_SEC_CODE  0xFFFD
#define STRD_MED_SEC_CODE    0xFFFB
#define STRD_LAR_SEC_CODE    0xFFF9

#define HIGH_SMALL_SEC_CODE  0xFFF5
#define HIGH_MED_SEC_CODE    0xFFF3
#define HIGH_LARGE_SEC_CODE  0xFFF1


#define WR_PROT_SEC_OFF      0xFFFF
#define WR_PROT_SEC_ON       0xFFFE

/* FGS */
#define _FGS(x) __attribute__((section("__FGS.sec,code"))) int _FGS = (x);

#define CODE_PROT_OFF  0xFFFF
#define CODE_PROT_ON   0xFFFD

#define GSS_OFF        0xFFFF
#define GSS_STD        0xFFFD
#define GSS_HIGH       0xFFFB
#define GWRP_OFF  0xFFFF
#define GWRP_ON   0xFFFE


#define _FUID0(x) __attribute__((section("__FUID0.sec,code"))) int _FUID0 = (x);
#define _FUID1(x) __attribute__((section("__FUID1.sec,code"))) int _FUID1 = (x);
#define _FUID2(x) __attribute__((section("__FUID2.sec,code"))) int _FUID2 = (x);
#define _FUID3(x) __attribute__((section("__FUID3.sec,code"))) int _FUID3 = (x);


/* --------------------------------------------------------------------------- 
 Setting configuration fuses using macros:
 ==========================================
 Macros are provided which can be used to set configuration fuses:
 For e.g., to set the FOSC fuse using a macro above, the following line of
 code can be pasted before the beginning of the C source code.

        _FOSC(CSW_FSCM_ON & ECIO_PLL16);

 This would enable the external clock with the PLL set to 16x and further,
 enable clock switching and failsafe clock monitoring.

 Similarly, to set the FBORPOR fuse, paste the following :

        _FBORPOR(PBOR_ON & BORV_27 & PWRT_ON_64 & MCLR_DIS);

 This would enable Brown-out Reset at 2.7 Volts and initialize the Power-up
 timer to 64 milliseconds and configure the use of the MCLR pin for I/O.
 Given below, is a complete list of settings valid to each of the fuses:
 (Paste the ones relevant to your application before the beginning of C
 source code.)

               FOSC:
               ======
               _FOSC(CSW_FSCM_OFF & EC);
               _FOSC(CSW_FSCM_OFF & ECIO);
               _FOSC(CSW_FSCM_OFF & ECIO_PLL4);
               _FOSC(CSW_FSCM_OFF & ECIO_PLL8);
               _FOSC(CSW_FSCM_OFF & ECIO_PLL16);
               _FOSC(CSW_FSCM_OFF & ERC);
               _FOSC(CSW_FSCM_OFF & ERCIO);
               _FOSC(CSW_FSCM_OFF & XT);
               _FOSC(CSW_FSCM_OFF & XT_PLL4);
               _FOSC(CSW_FSCM_OFF & XT_PLL8);
               _FOSC(CSW_FSCM_OFF & XT_PLL16);
               _FOSC(CSW_FSCM_OFF & XTL);
               _FOSC(CSW_FSCM_OFF & FRC_PLL4);
               _FOSC(CSW_FSCM_OFF & FRC_PLL8);
               _FOSC(CSW_FSCM_OFF & FRC_PLL16);
               _FOSC(CSW_FSCM_OFF & HS);
               _FOSC(CSW_FSCM_OFF & HS2_PLL4);
               _FOSC(CSW_FSCM_OFF & HS2_PLL8);
               _FOSC(CSW_FSCM_OFF & HS2_PLL16);
               _FOSC(CSW_FSCM_OFF & HS3_PLL4);
               _FOSC(CSW_FSCM_OFF & HS3_PLL8);
               _FOSC(CSW_FSCM_OFF & HS3_PLL16);
               _FOSC(CSW_FSCM_OFF & LP & EC);
               _FOSC(CSW_FSCM_OFF & LP & ECIO);
               _FOSC(CSW_FSCM_OFF & LP & ECIO_PLL4);
               _FOSC(CSW_FSCM_OFF & LP & ECIO_PLL8);
               _FOSC(CSW_FSCM_OFF & LP & ECIO_PLL16);
               _FOSC(CSW_FSCM_OFF & LP & ERC);
               _FOSC(CSW_FSCM_OFF & LP & ERCIO);
               _FOSC(CSW_FSCM_OFF & LP & XT);
               _FOSC(CSW_FSCM_OFF & LP & XT_PLL4);
               _FOSC(CSW_FSCM_OFF & LP & XT_PLL8);
               _FOSC(CSW_FSCM_OFF & LP & XT_PLL16);
               _FOSC(CSW_FSCM_OFF & LP & XTL);
               _FOSC(CSW_FSCM_OFF & LP & FRC_PLL4);
               _FOSC(CSW_FSCM_OFF & LP & FRC_PLL8);
               _FOSC(CSW_FSCM_OFF & LP & FRC_PLL16);
               _FOSC(CSW_FSCM_OFF & LP & HS);
               _FOSC(CSW_FSCM_OFF & LP & HS2_PLL4);
               _FOSC(CSW_FSCM_OFF & LP & HS2_PLL8);
               _FOSC(CSW_FSCM_OFF & LP & HS2_PLL16);
               _FOSC(CSW_FSCM_OFF & LP & HS3_PLL4);
               _FOSC(CSW_FSCM_OFF & LP & HS3_PLL8);
               _FOSC(CSW_FSCM_OFF & LP & HS3_PLL16);
               _FOSC(CSW_FSCM_OFF & FRC & EC);
               _FOSC(CSW_FSCM_OFF & FRC & ECIO);
               _FOSC(CSW_FSCM_OFF & FRC & ECIO_PLL4);
               _FOSC(CSW_FSCM_OFF & FRC & ECIO_PLL8);
               _FOSC(CSW_FSCM_OFF & FRC & ECIO_PLL16);
               _FOSC(CSW_FSCM_OFF & FRC & ERC);
               _FOSC(CSW_FSCM_OFF & FRC & ERCIO);
               _FOSC(CSW_FSCM_OFF & FRC & XT);
               _FOSC(CSW_FSCM_OFF & FRC & XT_PLL4);
               _FOSC(CSW_FSCM_OFF & FRC & XT_PLL8);
               _FOSC(CSW_FSCM_OFF & FRC & XT_PLL16);
               _FOSC(CSW_FSCM_OFF & FRC & XTL);
               _FOSC(CSW_FSCM_OFF & FRC & FRC_PLL4);
               _FOSC(CSW_FSCM_OFF & FRC & FRC_PLL8);
               _FOSC(CSW_FSCM_OFF & FRC & FRC_PLL16);
               _FOSC(CSW_FSCM_OFF & FRC & HS);
               _FOSC(CSW_FSCM_OFF & FRC & HS2_PLL4);
               _FOSC(CSW_FSCM_OFF & FRC & HS2_PLL8);
               _FOSC(CSW_FSCM_OFF & FRC & HS2_PLL16);
               _FOSC(CSW_FSCM_OFF & FRC & HS3_PLL4);
               _FOSC(CSW_FSCM_OFF & FRC & HS3_PLL8);
               _FOSC(CSW_FSCM_OFF & FRC & HS3_PLL16);
               _FOSC(CSW_FSCM_OFF & LPRC & EC);
               _FOSC(CSW_FSCM_OFF & LPRC & ECIO);
               _FOSC(CSW_FSCM_OFF & LPRC & ECIO_PLL4);
               _FOSC(CSW_FSCM_OFF & LPRC & ECIO_PLL8);
               _FOSC(CSW_FSCM_OFF & LPRC & ECIO_PLL16);
               _FOSC(CSW_FSCM_OFF & LPRC & ERC);
               _FOSC(CSW_FSCM_OFF & LPRC & ERCIO);
               _FOSC(CSW_FSCM_OFF & LPRC & XT);
               _FOSC(CSW_FSCM_OFF & LPRC & XT_PLL4);
               _FOSC(CSW_FSCM_OFF & LPRC & XT_PLL8);
               _FOSC(CSW_FSCM_OFF & LPRC & XT_PLL16);
               _FOSC(CSW_FSCM_OFF & LPRC & XTL);
               _FOSC(CSW_FSCM_OFF & LPRC & FRC_PLL4);
               _FOSC(CSW_FSCM_OFF & LPRC & FRC_PLL8);
               _FOSC(CSW_FSCM_OFF & LPRC & FRC_PLL16);
               _FOSC(CSW_FSCM_OFF & LPRC & HS);
               _FOSC(CSW_FSCM_OFF & LPRC & HS2_PLL4);
               _FOSC(CSW_FSCM_OFF & LPRC & HS2_PLL8);
               _FOSC(CSW_FSCM_OFF & LPRC & HS2_PLL16);
               _FOSC(CSW_FSCM_OFF & LPRC & HS3_PLL4);
               _FOSC(CSW_FSCM_OFF & LPRC & HS3_PLL8);
               _FOSC(CSW_FSCM_OFF & LPRC & HS3_PLL16);
               _FOSC(CSW_FSCM_OFF & EXT & EC);
               _FOSC(CSW_FSCM_OFF & EXT & ECIO);
               _FOSC(CSW_FSCM_OFF & EXT & ECIO_PLL4);
               _FOSC(CSW_FSCM_OFF & EXT & ECIO_PLL8);
               _FOSC(CSW_FSCM_OFF & EXT & ECIO_PLL16);
               _FOSC(CSW_FSCM_OFF & EXT & ERC);
               _FOSC(CSW_FSCM_OFF & EXT & ERCIO);
               _FOSC(CSW_FSCM_OFF & EXT & XT);
               _FOSC(CSW_FSCM_OFF & EXT & XT_PLL4);
               _FOSC(CSW_FSCM_OFF & EXT & XT_PLL8);
               _FOSC(CSW_FSCM_OFF & EXT & XT_PLL16);
               _FOSC(CSW_FSCM_OFF & EXT & XTL);
               _FOSC(CSW_FSCM_OFF & EXT & FRC_PLL4);
               _FOSC(CSW_FSCM_OFF & EXT & FRC_PLL8);
               _FOSC(CSW_FSCM_OFF & EXT & FRC_PLL16);
               _FOSC(CSW_FSCM_OFF & EXT & HS);
               _FOSC(CSW_FSCM_OFF & EXT & HS2_PLL4);
               _FOSC(CSW_FSCM_OFF & EXT & HS2_PLL8);
               _FOSC(CSW_FSCM_OFF & EXT & HS2_PLL16);
               _FOSC(CSW_FSCM_OFF & EXT & HS3_PLL4);
               _FOSC(CSW_FSCM_OFF & EXT & HS3_PLL8);
               _FOSC(CSW_FSCM_OFF & EXT & HS3_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & EC);
               _FOSC(CSW_ON_FSCM_OFF & ECIO);
               _FOSC(CSW_ON_FSCM_OFF & ECIO_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & ECIO_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & ECIO_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & ERC);
               _FOSC(CSW_ON_FSCM_OFF & ERCIO);
               _FOSC(CSW_ON_FSCM_OFF & XT);
               _FOSC(CSW_ON_FSCM_OFF & XT_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & XT_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & XT_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & XTL);
               _FOSC(CSW_ON_FSCM_OFF & FRC_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & FRC_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & FRC_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & HS);
               _FOSC(CSW_ON_FSCM_OFF & HS2_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & HS2_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & HS2_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & HS3_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & HS3_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & HS3_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & LP & EC);
               _FOSC(CSW_ON_FSCM_OFF & LP & ECIO);
               _FOSC(CSW_ON_FSCM_OFF & LP & ECIO_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & LP & ECIO_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & LP & ECIO_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & LP & ERC);
               _FOSC(CSW_ON_FSCM_OFF & LP & ERCIO);
               _FOSC(CSW_ON_FSCM_OFF & LP & XT);
               _FOSC(CSW_ON_FSCM_OFF & LP & XT_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & LP & XT_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & LP & XT_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & LP & XTL);
               _FOSC(CSW_ON_FSCM_OFF & LP & FRC_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & LP & FRC_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & LP & FRC_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & LP & HS);
               _FOSC(CSW_ON_FSCM_OFF & LP & HS2_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & LP & HS2_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & LP & HS2_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & LP & HS3_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & LP & HS3_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & LP & HS3_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & FRC & EC);
               _FOSC(CSW_ON_FSCM_OFF & FRC & ECIO);
               _FOSC(CSW_ON_FSCM_OFF & FRC & ECIO_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & FRC & ECIO_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & FRC & ECIO_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & FRC & ERC);
               _FOSC(CSW_ON_FSCM_OFF & FRC & ERCIO);
               _FOSC(CSW_ON_FSCM_OFF & FRC & XT);
               _FOSC(CSW_ON_FSCM_OFF & FRC & XT_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & FRC & XT_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & FRC & XT_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & FRC & XTL);
               _FOSC(CSW_ON_FSCM_OFF & FRC & FRC_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & FRC & FRC_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & FRC & FRC_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & FRC & HS);
               _FOSC(CSW_ON_FSCM_OFF & FRC & HS2_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & FRC & HS2_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & FRC & HS2_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & FRC & HS3_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & FRC & HS3_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & FRC & HS3_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & EC);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & ECIO);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & ECIO_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & ECIO_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & ECIO_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & ERC);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & ERCIO);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & XT);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & XT_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & XT_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & XT_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & XTL);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & FRC_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & FRC_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & FRC_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & HS);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & HS2_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & HS2_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & HS2_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & HS3_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & HS3_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & LPRC & HS3_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & EXT & EC);
               _FOSC(CSW_ON_FSCM_OFF & EXT & ECIO);
               _FOSC(CSW_ON_FSCM_OFF & EXT & ECIO_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & EXT & ECIO_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & EXT & ECIO_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & EXT & ERC);
               _FOSC(CSW_ON_FSCM_OFF & EXT & ERCIO);
               _FOSC(CSW_ON_FSCM_OFF & EXT & XT);
               _FOSC(CSW_ON_FSCM_OFF & EXT & XT_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & EXT & XT_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & EXT & XT_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & EXT & XTL);
               _FOSC(CSW_ON_FSCM_OFF & EXT & FRC_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & EXT & FRC_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & EXT & FRC_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & EXT & HS);
               _FOSC(CSW_ON_FSCM_OFF & EXT & HS2_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & EXT & HS2_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & EXT & HS2_PLL16);
               _FOSC(CSW_ON_FSCM_OFF & EXT & HS3_PLL4);
               _FOSC(CSW_ON_FSCM_OFF & EXT & HS3_PLL8);
               _FOSC(CSW_ON_FSCM_OFF & EXT & HS3_PLL16);
               _FOSC(CSW_FSCM_ON & EC);
               _FOSC(CSW_FSCM_ON & ECIO);
               _FOSC(CSW_FSCM_ON & ECIO_PLL4);
               _FOSC(CSW_FSCM_ON & ECIO_PLL8);
               _FOSC(CSW_FSCM_ON & ECIO_PLL16);
               _FOSC(CSW_FSCM_ON & ERC);
               _FOSC(CSW_FSCM_ON & ERCIO);
               _FOSC(CSW_FSCM_ON & XT);
               _FOSC(CSW_FSCM_ON & XT_PLL4);
               _FOSC(CSW_FSCM_ON & XT_PLL8);
               _FOSC(CSW_FSCM_ON & XT_PLL16);
               _FOSC(CSW_FSCM_ON & XTL);
               _FOSC(CSW_FSCM_ON & FRC_PLL4);
               _FOSC(CSW_FSCM_ON & FRC_PLL8);
               _FOSC(CSW_FSCM_ON & FRC_PLL16);
               _FOSC(CSW_FSCM_ON & HS);
               _FOSC(CSW_FSCM_ON & HS2_PLL4);
               _FOSC(CSW_FSCM_ON & HS2_PLL8);
               _FOSC(CSW_FSCM_ON & HS2_PLL16);
               _FOSC(CSW_FSCM_ON & HS3_PLL4);
               _FOSC(CSW_FSCM_ON & HS3_PLL8);
               _FOSC(CSW_FSCM_ON & HS3_PLL16);
               _FOSC(CSW_FSCM_ON & LP & EC);
               _FOSC(CSW_FSCM_ON & LP & ECIO);
               _FOSC(CSW_FSCM_ON & LP & ECIO_PLL4);
               _FOSC(CSW_FSCM_ON & LP & ECIO_PLL8);
               _FOSC(CSW_FSCM_ON & LP & ECIO_PLL16);
               _FOSC(CSW_FSCM_ON & LP & ERC);
               _FOSC(CSW_FSCM_ON & LP & ERCIO);
               _FOSC(CSW_FSCM_ON & LP & XT);
               _FOSC(CSW_FSCM_ON & LP & XT_PLL4);
               _FOSC(CSW_FSCM_ON & LP & XT_PLL8);
               _FOSC(CSW_FSCM_ON & LP & XT_PLL16);
               _FOSC(CSW_FSCM_ON & LP & XTL);
               _FOSC(CSW_FSCM_ON & LP & FRC_PLL4);
               _FOSC(CSW_FSCM_ON & LP & FRC_PLL8);
               _FOSC(CSW_FSCM_ON & LP & FRC_PLL16);
               _FOSC(CSW_FSCM_ON & LP & HS);
               _FOSC(CSW_FSCM_ON & LP & HS2_PLL4);
               _FOSC(CSW_FSCM_ON & LP & HS2_PLL8);
               _FOSC(CSW_FSCM_ON & LP & HS2_PLL16);
               _FOSC(CSW_FSCM_ON & LP & HS3_PLL4);
               _FOSC(CSW_FSCM_ON & LP & HS3_PLL8);
               _FOSC(CSW_FSCM_ON & LP & HS3_PLL16);
               _FOSC(CSW_FSCM_ON & FRC & EC);
               _FOSC(CSW_FSCM_ON & FRC & ECIO);
               _FOSC(CSW_FSCM_ON & FRC & ECIO_PLL4);
               _FOSC(CSW_FSCM_ON & FRC & ECIO_PLL8);
               _FOSC(CSW_FSCM_ON & FRC & ECIO_PLL16);
               _FOSC(CSW_FSCM_ON & FRC & ERC);
               _FOSC(CSW_FSCM_ON & FRC & ERCIO);
               _FOSC(CSW_FSCM_ON & FRC & XT);
               _FOSC(CSW_FSCM_ON & FRC & XT_PLL4);
               _FOSC(CSW_FSCM_ON & FRC & XT_PLL8);
               _FOSC(CSW_FSCM_ON & FRC & XT_PLL16);
               _FOSC(CSW_FSCM_ON & FRC & XTL);
               _FOSC(CSW_FSCM_ON & FRC & FRC_PLL4);
               _FOSC(CSW_FSCM_ON & FRC & FRC_PLL8);
               _FOSC(CSW_FSCM_ON & FRC & FRC_PLL16);
               _FOSC(CSW_FSCM_ON & FRC & HS);
               _FOSC(CSW_FSCM_ON & FRC & HS2_PLL4);
               _FOSC(CSW_FSCM_ON & FRC & HS2_PLL8);
               _FOSC(CSW_FSCM_ON & FRC & HS2_PLL16);
               _FOSC(CSW_FSCM_ON & FRC & HS3_PLL4);
               _FOSC(CSW_FSCM_ON & FRC & HS3_PLL8);
               _FOSC(CSW_FSCM_ON & FRC & HS3_PLL16);
               _FOSC(CSW_FSCM_ON & LPRC & EC);
               _FOSC(CSW_FSCM_ON & LPRC & ECIO);
               _FOSC(CSW_FSCM_ON & LPRC & ECIO_PLL4);
               _FOSC(CSW_FSCM_ON & LPRC & ECIO_PLL8);
               _FOSC(CSW_FSCM_ON & LPRC & ECIO_PLL16);
               _FOSC(CSW_FSCM_ON & LPRC & ERC);
               _FOSC(CSW_FSCM_ON & LPRC & ERCIO);
               _FOSC(CSW_FSCM_ON & LPRC & XT);
               _FOSC(CSW_FSCM_ON & LPRC & XT_PLL4);
               _FOSC(CSW_FSCM_ON & LPRC & XT_PLL8);
               _FOSC(CSW_FSCM_ON & LPRC & XT_PLL16);
               _FOSC(CSW_FSCM_ON & LPRC & XTL);
               _FOSC(CSW_FSCM_ON & LPRC & FRC_PLL4);
               _FOSC(CSW_FSCM_ON & LPRC & FRC_PLL8);
               _FOSC(CSW_FSCM_ON & LPRC & FRC_PLL16);
               _FOSC(CSW_FSCM_ON & LPRC & HS);
               _FOSC(CSW_FSCM_ON & LPRC & HS2_PLL4);
               _FOSC(CSW_FSCM_ON & LPRC & HS2_PLL8);
               _FOSC(CSW_FSCM_ON & LPRC & HS2_PLL16);
               _FOSC(CSW_FSCM_ON & LPRC & HS3_PLL4);
               _FOSC(CSW_FSCM_ON & LPRC & HS3_PLL8);
               _FOSC(CSW_FSCM_ON & LPRC & HS3_PLL16);
               _FOSC(CSW_FSCM_ON & EXT & EC);
               _FOSC(CSW_FSCM_ON & EXT & ECIO);
               _FOSC(CSW_FSCM_ON & EXT & ECIO_PLL4);
               _FOSC(CSW_FSCM_ON & EXT & ECIO_PLL8);
               _FOSC(CSW_FSCM_ON & EXT & ECIO_PLL16);
               _FOSC(CSW_FSCM_ON & EXT & ERC);
               _FOSC(CSW_FSCM_ON & EXT & ERCIO);
               _FOSC(CSW_FSCM_ON & EXT & XT);
               _FOSC(CSW_FSCM_ON & EXT & XT_PLL4);
               _FOSC(CSW_FSCM_ON & EXT & XT_PLL8);
               _FOSC(CSW_FSCM_ON & EXT & XT_PLL16);
               _FOSC(CSW_FSCM_ON & EXT & XTL);
               _FOSC(CSW_FSCM_ON & EXT & FRC_PLL4);
               _FOSC(CSW_FSCM_ON & EXT & FRC_PLL8);
               _FOSC(CSW_FSCM_ON & EXT & FRC_PLL16);
               _FOSC(CSW_FSCM_ON & EXT & HS);
               _FOSC(CSW_FSCM_ON & EXT & HS2_PLL4);
               _FOSC(CSW_FSCM_ON & EXT & HS2_PLL8);
               _FOSC(CSW_FSCM_ON & EXT & HS2_PLL16);
               _FOSC(CSW_FSCM_ON & EXT & HS3_PLL4);
               _FOSC(CSW_FSCM_ON & EXT & HS3_PLL8);
               _FOSC(CSW_FSCM_ON & EXT & HS3_PLL16);

               FWDT
               =====
               _FWDT(WDT_OFF);
               _FWDT(WDT_ON & WDTPSA_1 & WDTPSB_1);
               _FWDT(WDT_ON & WDTPSA_1 & WDTPSB_2);
               _FWDT(WDT_ON & WDTPSA_1 & WDTPSB_3);
               _FWDT(WDT_ON & WDTPSA_1 & WDTPSB_4);
               _FWDT(WDT_ON & WDTPSA_1 & WDTPSB_5);
               _FWDT(WDT_ON & WDTPSA_1 & WDTPSB_6);
               _FWDT(WDT_ON & WDTPSA_1 & WDTPSB_7);
               _FWDT(WDT_ON & WDTPSA_1 & WDTPSB_8);
               _FWDT(WDT_ON & WDTPSA_1 & WDTPSB_9);
               _FWDT(WDT_ON & WDTPSA_1 & WDTPSB_10);
               _FWDT(WDT_ON & WDTPSA_1 & WDTPSB_11);
               _FWDT(WDT_ON & WDTPSA_1 & WDTPSB_12);
               _FWDT(WDT_ON & WDTPSA_1 & WDTPSB_13);
               _FWDT(WDT_ON & WDTPSA_1 & WDTPSB_14);
               _FWDT(WDT_ON & WDTPSA_1 & WDTPSB_15);
               _FWDT(WDT_ON & WDTPSA_1 & WDTPSB_16);
               _FWDT(WDT_ON & WDTPSA_8 & WDTPSB_1);
               _FWDT(WDT_ON & WDTPSA_8 & WDTPSB_2);
               _FWDT(WDT_ON & WDTPSA_8 & WDTPSB_3);
               _FWDT(WDT_ON & WDTPSA_8 & WDTPSB_4);
               _FWDT(WDT_ON & WDTPSA_8 & WDTPSB_5);
               _FWDT(WDT_ON & WDTPSA_8 & WDTPSB_6);
               _FWDT(WDT_ON & WDTPSA_8 & WDTPSB_7);
               _FWDT(WDT_ON & WDTPSA_8 & WDTPSB_8);
               _FWDT(WDT_ON & WDTPSA_8 & WDTPSB_9);
               _FWDT(WDT_ON & WDTPSA_8 & WDTPSB_10);
               _FWDT(WDT_ON & WDTPSA_8 & WDTPSB_11);
               _FWDT(WDT_ON & WDTPSA_8 & WDTPSB_12);
               _FWDT(WDT_ON & WDTPSA_8 & WDTPSB_13);
               _FWDT(WDT_ON & WDTPSA_8 & WDTPSB_14);
               _FWDT(WDT_ON & WDTPSA_8 & WDTPSB_15);
               _FWDT(WDT_ON & WDTPSA_8 & WDTPSB_16);
               _FWDT(WDT_ON & WDTPSA_64 & WDTPSB_1);
               _FWDT(WDT_ON & WDTPSA_64 & WDTPSB_2);
               _FWDT(WDT_ON & WDTPSA_64 & WDTPSB_3);
               _FWDT(WDT_ON & WDTPSA_64 & WDTPSB_4);
               _FWDT(WDT_ON & WDTPSA_64 & WDTPSB_5);
               _FWDT(WDT_ON & WDTPSA_64 & WDTPSB_6);
               _FWDT(WDT_ON & WDTPSA_64 & WDTPSB_7);
               _FWDT(WDT_ON & WDTPSA_64 & WDTPSB_8);
               _FWDT(WDT_ON & WDTPSA_64 & WDTPSB_9);
               _FWDT(WDT_ON & WDTPSA_64 & WDTPSB_10);
               _FWDT(WDT_ON & WDTPSA_64 & WDTPSB_11);
               _FWDT(WDT_ON & WDTPSA_64 & WDTPSB_12);
               _FWDT(WDT_ON & WDTPSA_64 & WDTPSB_13);
               _FWDT(WDT_ON & WDTPSA_64 & WDTPSB_14);
               _FWDT(WDT_ON & WDTPSA_64 & WDTPSB_15);
               _FWDT(WDT_ON & WDTPSA_64 & WDTPSB_16);
               _FWDT(WDT_ON & WDTPSA_512 & WDTPSB_1);
               _FWDT(WDT_ON & WDTPSA_512 & WDTPSB_2);
               _FWDT(WDT_ON & WDTPSA_512 & WDTPSB_3);
               _FWDT(WDT_ON & WDTPSA_512 & WDTPSB_4);
               _FWDT(WDT_ON & WDTPSA_512 & WDTPSB_5);
               _FWDT(WDT_ON & WDTPSA_512 & WDTPSB_6);
               _FWDT(WDT_ON & WDTPSA_512 & WDTPSB_7);
               _FWDT(WDT_ON & WDTPSA_512 & WDTPSB_8);
               _FWDT(WDT_ON & WDTPSA_512 & WDTPSB_9);
               _FWDT(WDT_ON & WDTPSA_512 & WDTPSB_10);
               _FWDT(WDT_ON & WDTPSA_512 & WDTPSB_11);
               _FWDT(WDT_ON & WDTPSA_512 & WDTPSB_12);
               _FWDT(WDT_ON & WDTPSA_512 & WDTPSB_13);
               _FWDT(WDT_ON & WDTPSA_512 & WDTPSB_14);
               _FWDT(WDT_ON & WDTPSA_512 & WDTPSB_15);
               _FWDT(WDT_ON & WDTPSA_512 & WDTPSB_16);

               FBORPOR
               ========
               _FBORPOR(PBOR_OFF & MCLR_DIS);
               _FBORPOR(PBOR_OFF & MCLR_EN);
               _FBORPOR(PBOR_ON & BORV_20 & PWRT_OFF & MCLR_DIS);
               _FBORPOR(PBOR_ON & BORV_27 & PWRT_OFF & MCLR_DIS);
               _FBORPOR(PBOR_ON & BORV_42 & PWRT_OFF & MCLR_DIS);
               _FBORPOR(PBOR_ON & BORV_45 & PWRT_OFF & MCLR_DIS);
               _FBORPOR(PBOR_ON & BORV_20 & PWRT_OFF & MCLR_EN);
               _FBORPOR(PBOR_ON & BORV_27 & PWRT_OFF & MCLR_EN);
               _FBORPOR(PBOR_ON & BORV_42 & PWRT_OFF & MCLR_EN);
               _FBORPOR(PBOR_ON & BORV_45 & PWRT_OFF & MCLR_EN);
               _FBORPOR(PBOR_ON & BORV_20 & PWRT_4 & MCLR_DIS);
               _FBORPOR(PBOR_ON & BORV_27 & PWRT_4 & MCLR_DIS);
               _FBORPOR(PBOR_ON & BORV_42 & PWRT_4 & MCLR_DIS);
               _FBORPOR(PBOR_ON & BORV_45 & PWRT_4 & MCLR_DIS);
               _FBORPOR(PBOR_ON & BORV_20 & PWRT_4 & MCLR_EN);
               _FBORPOR(PBOR_ON & BORV_27 & PWRT_4 & MCLR_EN);
               _FBORPOR(PBOR_ON & BORV_42 & PWRT_4 & MCLR_EN);
               _FBORPOR(PBOR_ON & BORV_45 & PWRT_4 & MCLR_EN);
               _FBORPOR(PBOR_ON & BORV_20 & PWRT_16 & MCLR_DIS);
               _FBORPOR(PBOR_ON & BORV_27 & PWRT_16 & MCLR_DIS);
               _FBORPOR(PBOR_ON & BORV_42 & PWRT_16 & MCLR_DIS);
               _FBORPOR(PBOR_ON & BORV_45 & PWRT_16 & MCLR_DIS);
               _FBORPOR(PBOR_ON & BORV_20 & PWRT_16 & MCLR_EN);
               _FBORPOR(PBOR_ON & BORV_27 & PWRT_16 & MCLR_EN);
               _FBORPOR(PBOR_ON & BORV_42 & PWRT_16 & MCLR_EN);
               _FBORPOR(PBOR_ON & BORV_45 & PWRT_16 & MCLR_EN);
               _FBORPOR(PBOR_ON & BORV_20 & PWRT_64 & MCLR_DIS);
               _FBORPOR(PBOR_ON & BORV_27 & PWRT_64 & MCLR_DIS);
               _FBORPOR(PBOR_ON & BORV_42 & PWRT_64 & MCLR_DIS);
               _FBORPOR(PBOR_ON & BORV_45 & PWRT_64 & MCLR_DIS);
               _FBORPOR(PBOR_ON & BORV_20 & PWRT_64 & MCLR_EN);
               _FBORPOR(PBOR_ON & BORV_27 & PWRT_64 & MCLR_EN);
               _FBORPOR(PBOR_ON & BORV_42 & PWRT_64 & MCLR_EN);
               _FBORPOR(PBOR_ON & BORV_45 & PWRT_64 & MCLR_EN);
		
		FBS
               ====
               _FBS(CODE_PROT_OFF);
               _FBS(CODE_PROT_ON);


		FSS
               ====
               _FSS(CODE_PROT_OFF);
               _FSS(CODE_PROT_ON);


               FGS
               ====
               _FGS(CODE_PROT_OFF);
               _FGS(CODE_PROT_ON);

 ---------------------------------------------------------------------------- */


/* -------------------------------------------- */ 
/* Some useful macros for inline assembly stuff */
/* -------------------------------------------- */

#define Nop()    {__asm__ volatile ("nop");}
#define ClrWdt() {__asm__ volatile ("clrwdt");}
#define Sleep()  {__asm__ volatile ("pwrsav #0");}
#define Idle()   {__asm__ volatile ("pwrsav #1");}

/* ---------------------------------------------------------- */ 
/* Some useful macros for allocating data memory              */
/* ---------------------------------------------------------- */

/* The following macros require an argument N that specifies  */
/* alignment. N must a power of two, minimum value = 2.       */
/* For example, to declare an uninitialized array in X memory */
/* that is aligned to a 32 byte address:                      */
/*                                                            */
/* int _XBSS(32) xbuf[16];                                    */
/*                                                            */
/* To declare an initialized array in data EEPROM without     */
/* special alignment:                                         */
/*                                                            */
/* int _EEDATA(2) table1[] = {0, 1, 1, 2, 3, 5, 8, 13, 21};   */
/*                                                            */
#define _XBSS(N)    __attribute__((space(xmemory),aligned(N)))
#define _XDATA(N)   __attribute__((space(xmemory),aligned(N)))
#define _YBSS(N)    __attribute__((space(ymemory),aligned(N)))
#define _YDATA(N)   __attribute__((space(ymemory),aligned(N)))
#define _EEDATA(N)  __attribute__((space(eedata),aligned(N)))

/* The following macros do not require an argument. They can  */
/* be used to locate a variable in persistent data memory or  */
/* in near data memory. For example, to declare two variables */
/* that retain their values across a device reset:            */
/*                                                            */
/* int _PERSISTENT var1,var2;                                 */
/*                                                            */
#define _PERSISTENT __attribute__((persistent))
#define _NEAR       __attribute__((near))

/* ---------------------------------------------------------- */ 
/* Some useful macros for declaring functions                 */
/* ---------------------------------------------------------- */

/* The following macros can be used to declare interrupt      */
/* service routines (ISRs). For example, to declare an ISR    */
/* for the timer1 interrupt:                                  */
/*                                                            */
/* void _ISR _T1Interrupt(void);                            */
/*                                                            */
/* To declare an ISR for the SPI1 interrupt with fast         */
/* context save:                                              */
/*                                                            */
/* void _ISRFAST _SPI1Interrupt(void);                        */
/*                                                            */
/* Note: ISRs will be installed into the interrupt vector     */
/* tables automatically if the reserved names listed in the   */
/* MPLAB C30 Compiler User's Guide (DS51284) are used.        */
/*                                                            */
#define _ISR __attribute__((interrupt))
#define _ISRFAST __attribute__((interrupt, shadow))

/* ---------------------------------------------------------- */
/* Some useful macros for changing the CPU IPL                */
/* ---------------------------------------------------------- */

/* The following macros can be used to modify the current CPU */
/* IPL. The definition of the macro may vary from device to   */
/* device.                                                    */
/*                                                            */
/* To safely set the CPU IPL, use SET_CPU_IPL(ipl); the       */
/* valid range of ipl is 0-7, it may be any expression.       */
/*                                                            */
/* SET_CPU_IPL(7);                                            */
/*                                                            */
/* To preserve the current IPL and save it use                */
/* SET_AND_SAVE_CPU_IPL(save_to, ipl); the valid range of ipl */
/* is 0-7 and may be any expression, save_to should denote    */
/* some temporary storage.                                    */
/*                                                            */
/* int old_ipl;                                               */
/*                                                            */
/* SET_AND_SAVE_CPU_IPL(old_ipl, 7);                              */
/*                                                            */
/* The IPL can be restored with RESTORE_CPU_IPL(saved_to)     */
/*                                                            */
/* RESTORE_CPU_IPL(old_ipl);                                      */

#define SET_CPU_IPL(ipl) SRbits.IPL = ipl;

#define SET_AND_SAVE_CPU_IPL(save_to, ipl) { \
  save_to = SRbits.IPL; \
  SET_CPU_IPL(ipl); } (void) 0;

#define RESTORE_CPU_IPL(saved_to) SET_CPU_IPL(saved_to)

#endif

