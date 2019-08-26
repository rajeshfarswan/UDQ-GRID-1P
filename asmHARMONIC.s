/* harmonic oscilator for Power PLL to generate sine and cosine references*/

;void return and void argument
;access and modify these integer variables in main
;qSin, qCos
;int OSC_F is the input to harmonic oscillator -0.999<=OSC_F<=+0.999
;function calls asmINT_MPQ
;all variables are in between -0.999 to +0.999
;initial value of qSin = 0, qCos = 0.999;

;Xnew = Cos ref
;Ynew = Sin ref
;Xnew = Xn+wT*Yn  
;Ynew = Yn-wT*Xnew 

#include "p30f6010A.inc"

.global _asmHARMONIC

_asmHARMONIC:

disi #0x3FFF

MOV _qSin, W9     ;copy Xn to temp register
MOV _qCos, W0     ;copy Yn to temp register
MOV _OSC_F, W1    ;copy angular frequency wT to temp register
CALL _asmINT_MPQ  ;wT*Yn 
ADD W9,W0,W0      ;Xn+wT*Yn

MOV W0, _qCos     ;copy Ynew ref

MOV _qCos, W9     ;copy Yn to temp resgiter
MOV _OSC_F, W1    ;copy angular frequency wT to temp register
CALL _asmINT_MPQ  ;wT*Xnew 
SUB W9,W0,W0      ;Yn-wT*Xnew 

MOV W0, _qSin     ;copy Xnew ref

disi #0x0000

return 
.end
