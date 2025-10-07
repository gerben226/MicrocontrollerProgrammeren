#include <msp430.h>
#include <stdint.h>
#include <stdbool.h>
#include <include/gpio_lib.h>

//set pin to low(0) or high(1)
void pinSet(uint16_t port, uint16_t bit, bool val){
    if (val){
        *(&P1OUT + port) |= bit;
    }
    else {
        *(&P1OUT + port) &= ~bit;
    }
}

//toggle pin value
void pinToggle(uint16_t port, uint16_t bit){
    *(&P1OUT +(port)) ^= bit;
}

//read pin value
bool pinGet(uint16_t port, uint16_t bit){
    return (*(&P1IN + port) & bit) != 0;
}

//configure input pin with pullup(1)/down(0) and interrupt on falling(1)/rising(0) edge and enable interrupt(1)
void pinConfigInput(uint16_t port, uint16_t bit, bool pullResistor, bool pullUP, bool IES, bool IE){
    *(&P1DIR + port) &= ~bit;
    if(pullResistor){
        *(&P1REN + port) |= bit;
        if(pullUP){
            *(&P1OUT + port) |= bit;
        }
        else {
            *(&P1OUT + port) &= ~bit;
        }
    }
    if(IE){
        *(&P1IE + port) |= bit;
    }
    else if(!IE){
        *(&P1IE + port) &= ~bit;
    }
    if(IES){
        *(&P1IES + port) |= bit;
    }
    else if(!IES){
        *(&P1IES + port) &= ~bit;
    }
}

//set a pin to input(0) or output(1)
void pinSetDir(uint16_t port, uint16_t bit, uint16_t val){
    if (val){
        *(&P1DIR + port) |= bit;
    }
    else {
        *(&P1OUT + port) &= ~bit;
    }
}

void pinConfigFunction(uint16_t port, uint16_t bit, purposeFunction pf){
    
}
