#include <include/gpio_lib.h>

int main(void)
{
WDTCTL = WDTPW | WDTHOLD;  	 //stop WDT
PM5CTL0 &= ~LOCKLPM5;		//disable the GPIO power-on default HI-mode

pinSetDir(PORT1, BIT0, 1);
pinConfigInput(PORT1, BIT1, 1, 1, 1, 1);
pinSet(PORT1, BIT0, false);
__bis_SR_register(GIE);
while(1)
{
// if(!(pinGet(PORT1, BIT1))){
//     pinSet(PORT1, BIT0, 1);
// }
// else{
//     pinSet(PORT1, BIT0, 0);
// }

}

}

#pragma vector = PORT1_VECTOR
__interrupt void pushbutton_ISR(void) {
    switch(__even_in_range(P1IV, 0x10)){
        case 0x00: break; //none
        case 0x02: break; //pin 0
        case 0x04:        //pin 1
         P1OUT ^= BIT0;
        break;
        case 0x06: break; //pin 2
        case 0x08: break; //pin 3
        case 0x0A: break; //pin 4
        case 0x0C: break; //pin 5
        case 0x0E: break; //pin 6
        case 0x10: break; //pin 7
        default: _never_executed();
    }
}
