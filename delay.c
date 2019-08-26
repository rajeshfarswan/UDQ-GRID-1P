/* general purpose delay routine */

/* input argument is integer */

#include "p30f6010A.h"

void delay(unsigned int count)
{
	unsigned int i;
	unsigned int j;
	for(j=0;j<count;j++)
	{
	for(i=0;i<=26670;i++) ClrWdt();
     }
} //end delay
