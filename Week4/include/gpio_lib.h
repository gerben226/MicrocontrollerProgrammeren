#include <msp430.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef INCLUDE_GPIO_LIB_H_
#define INCLUDE_GPIO_LIB_H_

void pinSet(uint16_t port, uint16_t bit, bool val);

#endif /* INCLUDE_GPIO_LIB_H_ */
