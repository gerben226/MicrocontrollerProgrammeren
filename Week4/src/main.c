#include <msp430.h>
#include <include/gpio_lib.h>

int main(void)
{
WDTCTL = WDTPW | WDTHOLD;  	 //stop WDT
PM5CTL0 &= ~LOCKLPM5;		//disable the GPIO power-on default HI-mode

pinSet(PORT4, BIT6, false);
pinToggle(PORT1, BIT0);
pinConfigInput(PORT1, BIT1, 1, 1, 1, 1);


while(1)
{
    if(pinGet(PORT1, BIT1)){
        pinToggle(PORT1, BIT0);
    }
}
}
