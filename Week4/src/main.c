#include <msp430.h>
#include <include/gpio_lib.h>

int main(void)
{
WDTCTL = WDTPW | WDTHOLD;  	 //stop WDT
PM5CTL0 &= ~LOCKLPM5;		//disable the GPIO power-on default HI-mode

pinSet(1, BIT0, true);

pinSet(1, BIT0, false);


while(1)
{
    
}
}
