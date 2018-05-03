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

	switch (PORTA)
	{
	case PORT_F:
		return (GPIO_PORTF_DATA_R >> i) & 0x01;

	case PORT_E:
		return (GPIO_PORTE_DATA_R >> i) & 0x01;

	case PORT_D:
		return (GPIO_PORTD_DATA_R >> i) & 0x01;

	case PORT_C:
		return (GPIO_PORTC_DATA_R >> i) & 0x01;

	case PORT_B:
		return (GPIO_PORTB_DATA_R >> i) & 0x01;

	case PORT_A:
		return (GPIO_PORTA_DATA_R >> i) & 0x01;

	default:
		break;
	}
	return 0;
}

void SetPino(int PORTA, int PINO, int set)
{
	switch (PORTA)
	{
	case PORT_F:
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
		break;
	case PORT_E:
		if (set == 1)
		{
			if (LerPino(PORT_E, PINO) == 1)
				return;
			GPIO_PORTE_DATA_R ^= PINO;
		}
		else
		{
			GPIO_PORTE_DATA_R &= ~PINO;
		}
		break;
	case PORT_D:
		if (set == 1)
		{
			if (LerPino(PORT_D, PINO) == 1)
				return;
			GPIO_PORTD_DATA_R ^= PINO;
		}
		else
		{
			GPIO_PORTD_DATA_R &= ~PINO;
		}
		break;
	case PORT_C:
		if (set == 1)
		{
			if (LerPino(PORT_C, PINO) == 1)
				return;
			GPIO_PORTC_DATA_R ^= PINO;
		}
		else
		{
			GPIO_PORTC_DATA_R &= ~PINO;
		}
		break;
	case PORT_B:
		if (set == 1)
		{
			if (LerPino(PORT_B, PINO) == 1)
				return;
			GPIO_PORTB_DATA_R ^= PINO;
		}
		else
		{
			GPIO_PORTB_DATA_R &= ~PINO;
		}
		break;
	case PORT_A:
		if (set == 1)
		{
			if (LerPino(PORT_A, PINO) == 1)
				return;
			GPIO_PORTA_DATA_R ^= PINO;
		}
		else
		{
			GPIO_PORTA_DATA_R &= ~PINO;
		}
		break;

	}
}

// ex GPIOConfig( PORTF , INPUT , P1);
void GPIOConfig(int PORTA, int PINO, int DIR)
{

	switch (PORTA)
	{
	case PORT_F:
		if (DIR == OUTPUT)
		{
			if (LerPino_Dir(PORTA, PINO) == 1)
				break;
			GPIO_PORTF_DIR_R ^= PINO;
		}
		else
		{
			GPIO_PORTF_DIR_R &= ~PINO;
		}
		break;
	case PORT_E:
		if (DIR == OUTPUT)
		{
			if (LerPino_Dir(PORTA, PINO) == 1)
				break;
			GPIO_PORTE_DIR_R ^= PINO;
		}
		else
		{
			GPIO_PORTE_DIR_R &= ~PINO;
		}
		break;
	case PORT_D:
		if (DIR == OUTPUT)
		{
			if (LerPino_Dir(PORTA, PINO) == 1)
				break;
			GPIO_PORTD_DIR_R ^= PINO;
		}
		else
		{
			GPIO_PORTD_DIR_R &= ~PINO;
		}
		break;
	case PORT_C:
		if (DIR == OUTPUT)
		{
			if (LerPino_Dir(PORTA, PINO) == 1)
				break;
			GPIO_PORTC_DIR_R ^= PINO;
		}
		else
		{
			GPIO_PORTC_DIR_R &= ~PINO;
		}
		break;
	case PORT_B:
		if (DIR == OUTPUT)
		{
			if (LerPino_Dir(PORTA, PINO) == 1)
				break;
			GPIO_PORTB_DIR_R ^= PINO;
		}
		else
		{
			GPIO_PORTB_DIR_R &= ~PINO;
		}
		break;
	case PORT_A:
		if (DIR == OUTPUT)
		{
			if (LerPino_Dir(PORTA, PINO) == 1)
				break;
			GPIO_PORTA_DIR_R ^= PINO;
		}
		else
		{
			GPIO_PORTA_DIR_R &= ~PINO;
		}
		break;
	}

}

void SetDen(int PORTA, int PINO)
{
	switch (PORTA)
	{
	case PORT_F:
		GPIO_PORTF_DEN_R ^= PINO;
		break;
	case PORT_E:
		GPIO_PORTE_DEN_R ^= PINO;
		break;
	case PORT_D:
		GPIO_PORTD_DEN_R ^= PINO;
		break;
	case PORT_C:
		GPIO_PORTC_DEN_R ^= PINO;
		break;
	case PORT_B:
		GPIO_PORTB_DEN_R ^= PINO;
		break;
	case PORT_A:
		GPIO_PORTA_DEN_R ^= PINO;
		break;
	default:
		break;
	}

}

int LerPino_Dir(int PORTA, int PINO)
{

	uint32_t i = nPino(PINO);

	switch (PORTA)
	{
	case PORT_F:
		return (GPIO_PORTF_DIR_R >> i) & 0x01;

	case PORT_E:
		return (GPIO_PORTE_DIR_R >> i) & 0x01;

	case PORT_D:
		return (GPIO_PORTD_DIR_R >> i) & 0x01;

	case PORT_C:
		return (GPIO_PORTC_DIR_R >> i) & 0x01;

	case PORT_B:
		return (GPIO_PORTB_DIR_R >> i) & 0x01;

	case PORT_A:
		return (GPIO_PORTA_DIR_R >> i) & 0x01;

	}
	return 0;
}

void TempoSysTick_us(int us) {

	uint32_t t = us * 4;

	NVIC_ST_RELOAD_R = t;
}

void ConfigSysTick()
{
	NVIC_ST_CTRL_R = NVIC_ST_CTRL_INTEN | NVIC_ST_CTRL_ENABLE;
}
