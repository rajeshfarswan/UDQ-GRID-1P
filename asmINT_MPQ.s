/* Q15 multiplication of two Q15 numbers in range -0.9999 to +0.9999 */

/*returns q15 result*/

#include "p30f6010A.inc"

.global _asmINT_MPQ

_asmINT_MPQ:
;disi #0x3FFF

/*multiply*/
MOV W0, W4
MOV W1, W5 
MPY W4*W5, A
SFTAC A,#1
/*multiply*/

/* >>15 */
MOV #0x000F, W6
SFTAC A,W6
/* >>15 */

MOV ACCA, W0 ;final result in Q15

;disi #0x0000
return 
.end
