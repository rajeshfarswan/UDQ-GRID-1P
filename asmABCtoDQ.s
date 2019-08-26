/* single phase reference to unbalance DQ transfromation */

/* this function uses integer variables Avalue, Bvalue 
   and Cvalue in main **************************************/
/* alters integer variables Dvalue and Qvalue in main ******/
/* passing and return arguments are void *******************/
/* calls assembly function asmINT_MPQ **********************/
/* all operating vaiables are in q15 value,
   -0.999 <= value <= +0.999 *******************************/

#include "p30f6010A.inc" ;include processor header file

.global _asmABCtoDQ

_asmABCtoDQ:
disi #0x3FFF

MOV _Avalue, W7 ;copy Avalue ref to temp register

;ref to unbalanced d conversion
;D = (ref*Cos);
MOV W7,W0       ;copy Avalue ref to temp register
MOV _qCos, W1
CALL _asmINT_MPQ

MOV W0, _Dvalue ;return unbalanced d value
;

;ref to unbalaced Q conversion
;Q = (-ref*Sine);
MOV #0x0000, W9 ;reset temp register

MOV W7,W0        ;copy ref to temp regsiter
MOV _qSin, W1    ;copy sine to temp regsiter
CALL _asmINT_MPQ 

SUB W9,W0,W0
MOV W0, _Qvalue  ;return unbalaced q value
;
disi #0x0000
return 
.end
