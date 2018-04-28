/*
 * GPIOConfig.c
 *
 *  Created on: 19 de abr de 2018
 *      Author: Raian
 */

#include <inttypes.h>
#include <tm4c123gh6pm.h>
#include "GPIOConfig.h"

void LigarPort(int PORTA)
{

    SYSCTL_RCGCGPIO_R ^= PORTA;

}

int nPino(int PINO)
{

    if (PINO == 0x01)
    {
        return 0;
    }
    int i;
    for (i = 1; i < 7; i++)
    {
        PINO = PINO >> 1;
        if (PINO == 0x01)
        {
            return i;
        }
    }
    return 0;
}

int LerPino(int PORTA, int PINO)
{

    uint32_t i = nPino(PINO);

    if (PORTA == PORT_F)
    {
        return (GPIO_PORTF_DATA_R >> i) & 0x01;
    }
    return 0;
}

void SetPino(int PORTA, int PINO, int set)
{
    if (PORTA == PORT_F)
    {
        if (set == 1)
        {
            if (LerPino(PORT_F, PINO) == 1)
                return;
            GPIO_PORTF_DATA_R ^= PINO;
        }
        else
        {
            GPIO_PORTF_DATA_R &= ~PINO;
        }
    }
}

// ex GPIOConfig( PORTF , INPUT , P1);
void GPIOConfig(int PORTA, int PINO, int DIR)
{

    if (PORTA == PORT_F)
    {
        if (DIR == OUTPUT)
        {
            if (LerPino_Dir(PORTA, PINO) == 1)
                return;
            GPIO_PORTF_DIR_R ^= PINO;
        }
        else
        {
            GPIO_PORTF_DIR_R &= ~PINO;
        }
        return;

    }

}

void SetDen(int PORTA, int PINO)
{
    if (PORTA == PORT_F)
    {
        GPIO_PORTF_DEN_R ^= PINO;
        return;
    }

}

int LerPino_Dir(int PORTA, int PINO)
{

    uint32_t i = nPino(PINO);

    if (PORTA == PORT_F)
    {
        return (GPIO_PORTF_DIR_R >> i) & 0x01;
    }
    return 0;
}
