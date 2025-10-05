#include <msp430.h>
#include <include/gpio_lib.h>

int main(void)
{
WDTCTL = WDTPW | WDTHOLD;  	 //stop WDT
PM5CTL0 &= ~LOCKLPM5;		//disable the GPIO power-on default HI-mode

P4DIR |= BIT6;
pinSet(PORT4, BIT6, true);



while(1)
{
}

}
