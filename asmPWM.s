/* PWM generating routine for Half-bridge inverter */

;use variable Avalue, Bvalue, Cvalue
;alter processor dependent duty cycle registers
;use variable PWM_max as offset


#include "p30f6010A.inc"

.global _asmPWM

_asmPWM:
disi #0x3FFF

MOV _PWM_offset, W5  ;PWM ofsset value

MOV _Avalue, W0      ;read PI output
ADD W0,W5,W0
CALL _asmLT0         ;check less than zero
MOV W0, PDC1         ;program duty1

BRA Last2

;check value for less than zero
_asmLT0:
CP0 W0
BRA GT,Last1
MOV #0x0000,W0

Last1:
return
;less than zero function ends

Last2:
disi #0x0000
return
.end



