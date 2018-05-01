/*
 * Utils.c
 *
 *  Created on: 30 de abr de 2018
 *      Author: Igor G. Custodio
 */

#include <inttypes.h>
#include <tm4c123gh6pm.h>
#include "GPIOConfig.h"
#include "Utils.h"

//							  B  A  F  G  C  D  E
uint8_t numeros[10][7] = { 	{ 1, 1, 1, 0, 1, 1, 1 },  // 0
							{ 1, 0, 0, 0, 1, 0, 0 },  // 1
							{ 1, 1, 0, 1, 0, 1, 1 },  // 2
							{ 1, 1, 0, 1, 1, 1, 0 },  // 3
							{ 1, 0, 1, 1, 1, 0, 0 },  // 4
							{ 0, 1, 1, 1, 1, 1, 0 },  // 5
							{ 0, 1, 1, 1, 1, 1, 1 },  // 6
							{ 1, 1, 0, 0, 1, 0, 0 },  // 7
							{ 1, 1, 1, 1, 1, 1, 1 },  // 8
							{ 1, 1, 1, 1, 1, 1, 0 },  // 9
							};

//						  B    A    F    G    C    D    E
uint8_t pins[2][7] = { { PB0, PB1, PB2, PB3, PB4, PB5, PB6 },
					   { PE0, PE1, PE2, PE3, PE4, PE5, PA6 }
};

int countDigits(int i)
{
	int amount = 1;
	if (i < 10)
		return 2;
	while (i /= 10)
		amount++;
	return amount;
}

void writeNumber(int number)
{
	int dig = countDigits(number);
	int arr[2];
	if (number < 10)
	{
		arr[0] = 0;
		arr[1] = number;
	}
	else
	{
		while (dig--)
		{
			arr[dig] = number % 10;
			number /= 10;
		}
	}

	int i = 0;

	for (i = 0; i < 7; i++)
	{
		SetPino(PORT_B, pins[0][i], !numeros[arr[0]][i]);

		SetPino(PORT_E, pins[1][i], !numeros[arr[1]][i]);
		if (i == 6)
		{
			SetPino(PORT_A, pins[1][i], !numeros[arr[1]][i]);
		}
	}

}
