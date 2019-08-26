/*Fractional division of two signed integers in Q15 format
  (-0.999 to +0.999), Returns value in Q15*/

#include "p30f6010A.inc"

.global _asmINT_DIVQ

_asmINT_DIVQ:
;disi #0x3FFF

MOV W0,W4 ;copy int 1
MOV W1,W5 ;copy int 2

CP0 W5    ;check division by zero
BRA Z, Div_0
BRA Div
Div_0:
XOR W4,#0x0,W4
BRA N, negativeFlow
BRA positiveFlow

Div:
REPEAT #18      ;perform int 1/int 2
DIVF W4,W5

BRA OV, FLOW    ;check overflow

MOV #0x8021,W1  ;clamp negative result
CP W0,W1
BRA LE, negativeFlow 
BRA LAST6

FLOW:
XOR W4,#0x0,W4
BRA N, next
XOR W5,#0x0,W5
BRA N, negativeFlow
BRA next1
next:
XOR W5,#0x0,W5
BRA NN, negativeFlow

next1:
BRA positiveFlow

negativeFlow:
MOV #0x8021, W0
BRA LAST6

positiveFlow:
MOV #0x7fdf, W0

LAST6:
;disi #0x0000
return 

.end
