#include <msp430.h>
#include <include/gpio_lib.h>

int main(void)
{
WDTCTL = WDTPW | WDTHOLD;  	 //stop WDT
PM5CTL0 &= ~LOCKLPM5;		//disable the GPIO power-on default HI-mode

pinSetDir(PORT1, BIT0, 1);
pinSetDir(PORT4, BIT6, 1);
pinSetDir(PORT1, BIT1, 0);
pinSet(PORT1, BIT0, true);
pinSet(PORT4, BIT6, false);
P1REN |= BIT1;
P1OUT |= BIT1;

while(1)
{
    if(pinGet(PORT1, BIT1)){
        pinToggle(PORT1, BIT0);
    }
}
}
