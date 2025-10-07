#include <include/gpio_lib.h>

int main(void)
{
WDTCTL = WDTPW | WDTHOLD;  	 //stop WDT
PM5CTL0 &= ~LOCKLPM5;		//disable the GPIO power-on default HI-mode

pinSetDir(PORT1, BIT0, 1);
pinConfigInput(PORT1, BIT1, 1, 1, 0, 0);
pinSet(PORT1, BIT0, false);

while(1)
{

if(!(pinGet(PORT1, BIT1))){
    pinSet(PORT1, BIT0, 1);
}
else{
    pinSet(PORT1, BIT0, 0);
}

}
}
