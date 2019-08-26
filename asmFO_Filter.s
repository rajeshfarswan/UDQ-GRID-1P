/* first order filter */

;all variables are in between +0.5 to -0.5
;modify _FOF_PreOut int variable
;return is int
;input argument1 is input value
;input argument2 is filter constant

;Ynew = Yn+k(Un-Yn)
;filter constant k = e-(2*3.14*Fc*Ts)
;Fc is desired cutt-off frequency
;Ts is sampling time of this function (from main code)


#include "p30f6010A.inc"

.global _asmFO_Filter

_asmFO_Filter:
disi #0x3FFF

MOV _FOF_PreOut, W2 ;prevalue value Yn in w2
SUB W0,W2,W0        ;Un-Yn

CALL _asmINT_MPQ    ;k(Un-Yn)
ADD W0,W2,W0        ;Yn+k(Un-Yn)

disi #0x0000        ;return Ynew

return 
.end
