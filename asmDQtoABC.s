/* Unbalanced DQ to single phase reference transfromation */

;this function access integer variables Dvalue and Qvalue in main
;alters integer variables Avalue, Bvalue and Cvalue in main
;use variable PWM_max and PWM_min for limitng DQ value
;passing and return arguments are void
;calls assembly function asmINT_MPQ
;all operating vaiables are in q15 value, -0.999 <= value <= +0.999

#include "p30f6010A.inc"

.global _asmDQtoABC

_asmDQtoABC:
disi #0x3FFF
;uDQ to single phase reference
;ref = (D*Cos - Q*Sine);
MOV _Dvalue, W0

MOV _qCos, W1
CALL _asmINT_MPQ    ;D*Cos = A
MOV W0,W9

MOV _Qvalue, W0

MOV _qSin, W1
CALL _asmINT_MPQ    ;Q*Sine = B

SUB W9,W0,W7        ; ref = A - B

MOV W7, _Avalue     ;ref copied to Avalue

disi #0x0000
return 
.end
