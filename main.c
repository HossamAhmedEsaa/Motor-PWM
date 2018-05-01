/**
 * main.c
 */

#include <inttypes.h>
#include <tm4c123gh6pm.h>
#include "GPIOConfig.h"
#include "Utils.h"

int cont = 0;
uint32_t temp_total = 0;

void InterruptSystick(void)
{
	cont++;
	if (cont == 100)
	{
		cont = 0;
	}
	temp_total++;
}

void PWM(int PORTA, int PINO, int taxa)
{

	if (cont < taxa)
	{
		SetPino(PORTA, PINO, HIGH);
		return;
	}

	if (cont < 100)
	{
		SetPino(PORTA, PINO, LOW);
		return;
	}

}

void delay(int ms)
{
	int start_temp = temp_total;
	while ((temp_total - start_temp) < ms)
		;

}

int main(void)
{
	LigarPort(PORT_F);
	LigarPort(PORT_B);
	LigarPort(PORT_E);
	LigarPort(PORT_A);
	LigarPort(PORT_C);

	GPIOConfig(PORT_F, LED_RED, OUTPUT);
	GPIOConfig(PORT_F, LED_BLUE, OUTPUT);
	GPIOConfig(PORT_F, LED_GREEN, OUTPUT);

	// DISPLAY DEZENAS
	GPIOConfig(PORT_B, P0, OUTPUT);
	GPIOConfig(PORT_B, P1, OUTPUT);
	GPIOConfig(PORT_B, P2, OUTPUT);
	GPIOConfig(PORT_B, P3, OUTPUT);
	GPIOConfig(PORT_B, P4, OUTPUT);
	GPIOConfig(PORT_B, P5, OUTPUT);
	GPIOConfig(PORT_B, P6, OUTPUT);

	// DISPLAY UNIDADES
	GPIOConfig(PORT_E, P0, OUTPUT);
	GPIOConfig(PORT_E, P1, OUTPUT);
	GPIOConfig(PORT_E, P2, OUTPUT);
	GPIOConfig(PORT_E, P3, OUTPUT);
	GPIOConfig(PORT_E, P4, OUTPUT);
	GPIOConfig(PORT_E, P5, OUTPUT);
	GPIOConfig(PORT_A, P6, OUTPUT);

	GPIOConfig(PORT_C, P6, INPUT);
	GPIOConfig(PORT_C, P5, INPUT);

	SetDen(PORT_F, LED_GREEN);
	SetDen(PORT_F, LED_RED);
	SetDen(PORT_F, LED_BLUE);

	SetDen(PORT_B, P0);
	SetDen(PORT_B, P1);
	SetDen(PORT_B, P2);
	SetDen(PORT_B, P3);
	SetDen(PORT_B, P4);
	SetDen(PORT_B, P5);
	SetDen(PORT_B, P6);
	SetDen(PORT_E, P0);
	SetDen(PORT_E, P1);
	SetDen(PORT_E, P2);
	SetDen(PORT_E, P3);
	SetDen(PORT_E, P4);
	SetDen(PORT_E, P5);
	SetDen(PORT_A, P6);
	SetDen(PORT_C, P6);
	SetDen(PORT_C, P5);

	ConfigSysTick();
	TempoSysTick_us(30);

	int brilho = 0;
	int rpm = 20;
	uint32_t temp = 0;

	cont = 0;
	writeNumber(rpm);
	while (1)
	{

		if (LerPino(PORT_C, P6) == 1)
		{
			rpm = (rpm > 98) ? 99 : ++rpm;

			writeNumber(rpm);
			delay(5000);
		}

		if (LerPino(PORT_C, P5) == 1)
		{
			rpm = (rpm < 2) ? 1 : --rpm;

			writeNumber(rpm);
			delay(5000);
		}

		if ((temp_total - temp) == 1000)
		{
			temp = temp_total;
			brilho++;
		}

		if (brilho == 100)
		{
			brilho = 0;
		}

		PWM(PORT_F, LED_GREEN, brilho);
	}

}

