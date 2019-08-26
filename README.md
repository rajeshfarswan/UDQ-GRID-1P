# UDQ-GRID-1P

Full-bridge single phase inverter unbalanced DQ control in grid connected mode. Please refer Matlab simulink file for system and control description: https://www.mathworks.com/matlabcentral/fileexchange/72533-grid-connected-single-phase-inverter-control-using-udq

The codes are developed and compiled on using IDE provided by microchip MPLAB IDE v8.46

Latest IDE from microchip can be found here: http://www.microchip.com/mplab/mplab-x-ide

The codes are developed for DSPIC30f6010A controller from Microchip. Detailed datasheet and information about this processor could be found here: https://www.microchip.com/wwwproducts/en/dsPIC30F6010A

The codes can be burned to the processor using suitable programmers/debuggers from microchip. Several of them could be found here: http://www.microchip.com/developmenttools/listing/bc05135f-75a9-4aa6-a6c5-82bdc9903a4c.

Key files for programming are listed here. All the files can be opened directly in the project environment of IDE itself and are burned to the processor after compilation or debugging. Also, these files can be opened directly as text or word document for viewing. Apart from below files some files are generated during compilation and are not relevant for understanding the codes.
More detailed description and functionalities about the various files are written on the files itself. Some files have codes written in C and some files have codes written in assembly. For assembly codes, inline assembly coding within c language is used. 

“main.c”: File contains the main code. 
“init.c”: File Contains processor initializations. 
“delay.c”: A generic code for generating delay time function. 
“main.h”: Contains processor dependent register definitions and functions used by main program. “user.h”: Contains definition and initialization of local variables used by the main program. 
“asmMATH.h”: Contains definition of Maths functions used by main program.

These files are math library files and are used for a variety of mathematical operations. These files are written in in-line assembly for fastest and optimized execution of math functions within C codes. 

“asmABCtoDQ.s”: Synchronous reference frame transformation of three phase quantities to d-q frame. 
“asmADC.s”: Reading of all ADC values and converting them directly to Q15 format. 
“asmDClink.s”: Reading of inverter DC link measuring ADC values and use them for fault detection or feed-forward in the case of inverter control. 
“asmDQtoABC.s”: Synchronous reference frame transformation of d-q quantities to three phase a-b-c. 
“asmFO_Filter.s”: First order low pass filter implementation. 
“asmHARMONIC.s”: First order harmonic oscillator implementation. 
“asmINT_MPQ.s”: Q15 multiplication of two numbers. 
“asmPIcontroller.s”: First order PI (Proportional Integral) control implementation. 
“asmPWM.s”: PWM processing and generating block.

These files are provided by the compiler and are processor dependent. These files must be included while compilation of code. These files are already provided with each group of code files. “p30f6010A.h”: MPLAB-C30 dsPIC30F6010A processor headers file for C. 

“p30f6010A.inc”: MPLAB-C30 dsPIC30F6010A processor headers file for assembly. 
“p30f6010A.gld”: MPLAB-C30 dsPIC30F6010A processor linkers file.

The file named with extension “.mcp” or “.mcw” is MPLAB IDE project file. After installing the MPLAB IDE, either of the file can be directly used for opening the entire project for direct compilation or burning code to the processor. However, for successful compilation of the project the compiler tool-suite path must be given properly (it must have some default path set previously) in MPLAB IDE. In MPLAB IDE v8.46 it can be done as: in project tab, select language tool-suite; set active tool-suite (here it is MICROCHIP C30 Tool-suite); set paths for each contents of tool-suit e.g. C:\Program Files \Microchip\MPLAB C30\bin___*.

Other Information: Files or functions used in each group of projects may be same. However, depending on the project objective they may have different contents and have altered function. For e.g. “asmABCtoDQ.s” gives synchronous frame transformation of three phase input quantities, but for single phase objectives the same file has been modified for unbalanced d-q frame transformation. Thus avoid mixing or replacing of the files from other projects or exercise caution. All variables for changing program settings like inverter output voltage or current are listed in “user.h” file.
