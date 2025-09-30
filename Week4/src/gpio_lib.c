#include <msp430.h>
#include <stdint.h>
#include <stdbool.h>
#include <include/gpio_lib.h>

void pinSet(uint16_t port, uint16_t bit, bool val){
    if (val){
        *(&P1OUT + (port - 1)) |= bit;
    }
    else {
        *(&P1OUT + (port - 1)) &= ~bit;
    }
}

void pinToggle(uint16_t port, uint16_t bit){

}

void pinGet(uint16_t port, uint16_t bit){

}

void pinConfigInput(uint16_t port, uint16_t bit, bool pullResistor, bool pullUP, bool IES, bool IE){

}

void pinSetDir(uint16_t port, uint16_t bit, uint16_t val){

}

void pinConfigFunction(uint16_t port, uint16_t bit, purposeFunction pf){

}
