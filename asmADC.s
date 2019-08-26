/* Function to read and convert ADC to Q15 result */

;input argument format 0x00(adc channel no.)
;return value is integer or Q15 adc result

#include "p30f6010A.inc"

.global _asmADC

_asmADC:
;disi #0x3FFF

MOV W0, ADCHS    ;select adc channel
BSET ADCON1,#1   ;start converstion
LOOP:
BTSS ADCON1,#0   ;wait for converstion
BRA LOOP

BTG ADCON1,#0 

MOV ADCBUF0, W0
LSR W0,#1,W0     ;return q15 result

;disi #0x0000
return 
.end
