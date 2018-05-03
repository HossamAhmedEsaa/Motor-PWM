/**
 * main.c
 */

#include <inttypes.h>
#include <tm4c123gh6pm.h>
#include "GPIOConfig.h"
#include "Utils.h"

#define TEMPO_SYSTICK 50

int pwm = 0;
uint32_t temp_total = 0;

void InterruptSystick(void)
{
	pwm++;
	if (pwm == 100)
	{
		pwm = 0;
	}

	temp_total++;
}

void PWM(int PORTA, int PINO, int taxa)
{

	if (pwm < taxa)
	{
		SetPino(PORTA, PINO, HIGH);
		return;
	}

	if (pwm < 100)
	{
		SetPino(PORTA, PINO, LOW);
		return;
	}

}

uint32_t MilliSec(int ms)
{
	ms = (ms / TEMPO_SYSTICK) * 1000;
	int start_temp = temp_total;

}

uint32_t millis()
{
	return temp_total * TEMPO_SYSTICK / 1000;
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

	//MOTOR
	GPIOConfig(PORT_A, P3, OUTPUT);

	// BOTOES
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
	SetDen(PORT_A, P3);

	ConfigSysTick();
	TempoSysTick_us(TEMPO_SYSTICK);

	int rpm = 20;

	int tempo_botao = 0;
	int tempoAntigo = 0;
	int cont_botao = 0;
	int verificaStatus = 0;
	pwm = 0;

	writeNumber(rpm);

	while (1)
	{

		if (LerPino(PORT_C, P6) == 1)
		{
			cont_botao++;
			if (cont_botao)
			{
				tempo_botao = temp_total;
				rpm = (rpm > 98) ? 99 : ++rpm;
				writeNumber(rpm);
			}

			if ((temp_total - tempo_botao) > MilliSec(1000))
			{
				verificaStatus ++;

			}


		}
		else
		{
			cont_botao = 0;
		}

		if (LerPino(PORT_C, P5) == 1)
		{
			rpm = (rpm < 2) ? 1 : --rpm;

			writeNumber(rpm);
		}

		PWM(PORT_A, P3, rpm);
	}

}

