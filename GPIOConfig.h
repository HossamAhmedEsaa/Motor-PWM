/*
 * GPIOConfig.h
 *
 *  Created on: 19 de abr de 2018
 *      Author: Raian
 */

#ifndef GPIOCONFIG_H_
#define GPIOCONFIG_H_

#define INPUT 0
#define OUTPUT 1

#define HIGH 1
#define LOW 0

#define P0 0b00000001
#define P1 0b00000010
#define P2 0b00000100
#define P3 0b00001000
#define P4 0b00010000
#define P5 0b00100000
#define P6 0b01000000
#define P7 0b10000000

#define LED_RED     0x2
#define LED_BLUE    0x4
#define LED_GREEN   0x8

#define PORT_F 32
#define PORT_E 16
#define PORT_D 8
#define PORT_C 4
#define PORT_B 2
#define PORT_A 1

void GPIOConfig(int PORTA, int PINO, int DIR);
void LigarPort(int PORTA);
void SetDen(int PORTA, int PINO);

//LerPino(PORTF, P3)
int LerPino(int PORTA, int PINO);
int LerPino_Dir(int PORTA, int PINO);

//InserirData(PORTF,HIGH,P2);
void SetPino(int PORTA, int PINO, int set);

#endif /* GPIOCONFIG_H_ */
