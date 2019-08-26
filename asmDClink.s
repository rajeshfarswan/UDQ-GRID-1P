/* function to read and monitor inverter dc-link and dc feeforward feedback generation */

;use variable VDC1 and VDC2
;use variable DC_balanceP and DC_balanceN
;use variable DCLINK_MAX
;use variable VDC
;use variable VDC_const
;use variable Vgrid_Dvalue
;use variable PWM_max 
;use variable ffd_max and ffd_min

#include "p30f6010A.inc"

.global _asmDClink

_asmDClink:
disi #0x3FFF

MOV #0x0303, W0   ;read VDC1 adc channel 3
CALL _asmADC
MOV W0, W7        ;VDC1 in W7

MOV #0x0202, W0   ;read VDC2 adc channel 2
CALL _asmADC
MOV W0, W8        ;VDC2 in W8

;detect peak and set fault
MOV _DCLINK_MAX, W5 ;read VDC max trip limit
CP W7,W5            ;compare VDC1 or initiate trip
BRA GT,Trip111
CP W8,W5            ;compare VDC2 or initiate trip
BRA GT,Trip111

;calculate total DClink voltage
ASR W7,#1,W7
ASR W8,#1,W8
ADD W7,W8,W0        ;Vdc1+Vdc2
ASR W0,#1,W0        ;take vdc/2 in W0

MOV _VDC_const, W1 ;normalise VDC voltage
CALL _asmINT_MPQ
MOV W0,W1          ;normalise VDC voltage in W1

;calculate feedforward feedback value
MOV _Vgrid_Dvalue, W0 ;copy Grid voltage peak value 
CALL _asmINT_DIVQ     ;Grid voltage peak/Vdc
MOV _PWM_offset, W1
CALL _asmINT_MPQ      ;normalise ffd value
MOV W0, _ffd_value    ;copy feedforward feedback value

BRA Last3

Trip111:
BSET _IFS2+1,#4       ;set if fault 

Last3:
disi #0x0000

return 
.end

