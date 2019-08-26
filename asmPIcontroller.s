/* Q15 proportional integral (PI) control */

;input integer argument1 is reference value
;input integer argument2 is feedback value
;input argument3 is integer Pgain
;input argument4 is integer Igain
;modifies variable integer IPreError
;return value is integer PIout
;all passing varaibles -0.499 <=value<= +0.499
;return value is Q15 integer -0.999<=value<= +0.999

#include "p30f6010A.inc"

.global _asmPIcontroller

_asmPIcontroller:
disi #0x3FFF

;calculate error
SUB W0,W1,W0        ;ref - feedback
CALL _asmSaturation
MOV W0, W4          ;Error is in W4

;calculate Pterm
MOV W2,W5           ;copy Pgain
MPY W4*W5, A        ;calculate Pgain*error
SFTAC A,#1
CALL _asmCheckFlow
CALL _asmSaturation
MOV W0,W8           ;Pterm in w8
;

;calculate Iterm
MOV _IPreError, W9  ;copy prev error integral
ADD W4,W9,W0        ;integrate error
CALL _asmSaturation
MOV W0, W4          ;Integrated Error is in W4

MOV W0, _IPreError  ;copy accumulated error in previous error
MOV W3,W5           ;copy Igain
MPY W4*W5, A        ;calculate Igain*integrated error
SFTAC A,#1
CALL _asmCheckFlow
CALL _asmSaturation
MOV W0,W9           ;Iterm in W9

;calculate PI output
ADD W8,W9,W0      ;Pterm+

MOV _PWM_max, W10 ;max value of PI saturation +1777*2^3
MOV _PWM_min, W11 ;min value of PI saturation -1777*2^3

CPSLT W0,W10
MOV W10, W0
CPSGT W0,W11
MOV W11, W0

ASR W0,#3,W0 ;divide by 2^3

BRA Last7

;overflow routine for gain multiplication
;clamp output if exceeds +0.999 and -0.999
;pre entry data should be in A,W4,W5
;error should be in w4
_asmCheckFlow:
CLR SR
XOR W4,#0,W4
BRA N, negative

positive:
MOV ACCAH, W10
CP0 W10
BRA NZ, positiveflow
MOV ACCAL, W10
CP0 W10
BRA Z,Output 
REPEAT #2
LSR W10,#5,W10
BRA NZ, positiveflow

BRA Output

negative:
MOV ACCAH, W10
MOV #0xffff, W11
CP0 W10
BRA NZ,next
BRA Output
next:
CP W10,W11
BRA NZ,negativeflow
MOV ACCAL, W10
CP0 W10
BRA Z,Output
REPEAT #2
LSR W10,#5,W10
BRA Z, negativeflow

BRA Output

negativeflow:
MOV #0x8021, W10 ;min overflow -0.999
MOV W10, ACCA
BRA Output

positiveflow:
MOV #0x7fdf, W10 ;max overflow +0.999
MOV W10, ACCA
BRA Output

Output:
MOV ACCAL, W0 ;return W0

return 
;overflow routine end

;saturation logic
_asmSaturation:
MOV #0x3fdf, W10 ;max value of saturation +0.499
MOV #0xc021, W11 ;min value of saturation -0.499
CP W0, W10
BRA GE, MAX_SAT
CP W0, W11
BRA LE, MIN_SAT

BRA SKIP1

MAX_SAT:
MOV W10, W0
BRA SKIP1

MIN_SAT:
MOV W11, W0

SKIP1:
return ;saturation logic ends

Last7:
disi #0x0000
return 
.end



