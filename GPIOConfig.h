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

#define PA0 0b00000001
#define PA1 0b00000010
#define PA2 0b00000100
#define PA3 0b00001000
#define PA4 0b00010000
#define PA5 0b00100000
#define PA6 0b01000000
#define PA7 0b10000000

#define PB0 0b00000001
#define PB1 0b00000010
#define PB2 0b00000100
#define PB3 0b00001000
#define PB4 0b00010000
#define PB5 0b00100000
#define PB6 0b01000000
#define PB7 0b10000000

#define PC0 0b00000001
#define PC1 0b00000010
#define PC2 0b00000100
#define PC3 0b00001000
#define PC4 0b00010000
#define PC5 0b00100000
#define PC6 0b01000000
#define PC7 0b10000000

#define PD0 0b00000001
#define PD1 0b00000010
#define PD2 0b00000100
#define PD3 0b00001000
#define PD4 0b00010000
#define PD5 0b00100000
#define PD6 0b01000000
#define PD7 0b10000000

#define PE0 0b00000001
#define PE1 0b00000010
#define PE2 0b00000100
#define PE3 0b00001000
#define PE4 0b00010000
#define PE5 0b00100000

#define PF0 0b00000001
#define PF1 0b00000010
#define PF2 0b00000100
#define PF3 0b00001000
#define PF4 0b00010000

//void InterruptSysTick(void);
void ConfigSysTick();
void TempoSysTick_us(int t);

//void PWM(int PORTA, int PINO, int taxa);

void GPIOConfig(int PORTA, int PINO, int DIR);
void LigarPort(int PORTA);
void SetDen(int PORTA, int PINO);

//LerPino(PORTF, P3)
int LerPino(int PORTA, int PINO);
int LerPino_Dir(int PORTA, int PINO);

//InserirData(PORTF,HIGH,P2);
void SetPino(int PORTA, int PINO, int set);

#endif /* GPIOCONFIG_H_ */
