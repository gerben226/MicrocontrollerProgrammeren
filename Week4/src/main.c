#include <msp430.h>
#include <include/gpio_lib.h>

int main(void)
{
WDTCTL = WDTPW | WDTHOLD;  	 //stop WDT
PM5CTL0 &= ~LOCKLPM5;		//disable the GPIO power-on default HI-mode

pinSet(4, BIT6, false);

pinToggle(1, BIT0);

while(1)
{
    pinToggle(1, BIT0);
}
}
