/**
 * main.c
 */

#include <inttypes.h>
#include <tm4c123gh6pm.h>
#include "GPIOConfig.h"

int main(void)
{

    LigarPort(PORT_F);

    GPIOConfig(PORT_F, LED_RED, OUTPUT);
    GPIOConfig(PORT_F, LED_BLUE, OUTPUT);
    GPIOConfig(PORT_F, LED_GREEN, OUTPUT);

    SetDen(PORT_F, LED_GREEN);
    SetDen(PORT_F, LED_RED);
    SetDen(PORT_F, LED_BLUE);

    SetPino(PORT_F, LED_GREEN, HIGH);
    SetPino(PORT_F, LED_RED, HIGH);
    SetPino(PORT_F, LED_BLUE, HIGH);
    SetPino(PORT_F, LED_RED, LOW);
    SetPino(PORT_F, LED_GREEN, LOW);

    while (1)
    {

    }

}
