;peak current detect routine
;call function asmADC
;adc no. format is (adcNo. adcNo.)
;read offset value from offset variable
;read current_max variable
;read current_min variable
;Ir,Iy,Ib data remains in W7,W8,W9 on exit

#include "p30f6010A.inc"

.global _asmCurrent_Trip

_asmCurrent_Trip:

;read currents
MOV _offset, W5 ;read 2.5V offset

MOV #0x0808, W0 ;read ILr
CALL _asmADC
SUB W0,W5,W7
MOV W7, _Avalue

MOV #0x0909, W0 ;read ILy
CALL _asmADC
SUB W0,W5,W8
MOV W8, _Bvalue

MOV #0x0909, W0 ;read ILb
CALL _asmADC
SUB W0,W5,W9
MOV W9, _Cvalue
;read currents end

;detect peak and set fault
MOV _current_max, W5 ;read current max trip limit
CP W7,W5
BRA GE,Trip
CP W8,W5
BRA GE,Trip
CP W9,W5
BRA GE,Trip
MOV _current_min, W5 ;read current max trip limit
CP W7,W5
BRA LE,Trip
CP W8,W5
BRA LE,Trip
CP W9,W5
BRA LE,Trip
;peak detect ends

BRA Last 

Trip:
BSET _IFS2+1,#4 ;set fault 

Last:
return
.end
