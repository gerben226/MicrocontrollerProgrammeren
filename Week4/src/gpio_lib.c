#include <msp430.h>
#include <stdint.h>
#include <stdbool.h>
#include <include/gpio_lib.h>

void pinSet(uint16_t port, uint16_t bit, bool val){
    if (val){
        *(&P1OUT + port) |= bit;
    }
    else {
        *(&P1OUT + port) &= ~bit;
    }
}

void pinToggle(uint16_t port, uint16_t bit){
    *(&P1OUT +(port)) ^= bit;
}

bool pinGet(uint16_t port, uint16_t bit){
    return *(&P1IN + port) & bit;
}

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

void pinSetDir(uint16_t port, uint16_t bit, uint16_t val){

}

void pinConfigFunction(uint16_t port, uint16_t bit, purposeFunction pf){

}
