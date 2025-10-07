#include <msp430.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef INCLUDE_GPIO_LIB_H_
#define INCLUDE_GPIO_LIB_H_

#define PORT1 0x0000
#define PORT2 0x0001
#define PORT3 0x0020
#define PORT4 0x0021

typedef enum {
    Digital,
    Primary,
    Secondary,
    Tertiary,
} purposeFunction;

//set pin to low(0) or high(1)
void pinSet(uint16_t port, uint16_t bit, bool val);

//toggle pin value
void pinToggle(uint16_t port, uint16_t bit);

//read pin value
bool pinGet(uint16_t port, uint16_t bit);

//configure input pin with pullup(1)/down(0) and interrupt on falling(1)/rising(0) edge and enable interrupt(1)
void pinConfigInput(uint16_t port, uint16_t bit, bool pullResistor, bool pullUP, bool IES, bool IE);

//set a pin to input(0) or output(1)
void pinSetDir(uint16_t port, uint16_t bit, uint16_t val);

void pinConfigFunction(uint16_t port, uint16_t bit, purposeFunction pf);

#endif /* INCLUDE_GPIO_LIB_H_ */
