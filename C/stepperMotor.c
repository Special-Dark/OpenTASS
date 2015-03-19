/*************************************************************************
	> File Name: stepperMotor.c
	> Author: Utopia
	> Mail: lanniaoershi@gmail.com 
	> Created Time: Thu 19 Mar 2015 19:55:39 UTC
 ************************************************************************/

#include<stdio.h>
#include<wiringPi.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define IN0 0
#define IN1 1
#define IN2 2
#define IN3 3

void initalPins() {
	int i = 0;
	int pins[4] = {IN0, IN1, IN2, IN3};
	int step[4][8] = {0};	
	wiringPiSetup();

	for (i=0;i<4;i++) {
		pinMode(pins[i], OUTPUT);
	}

}

void baseRunAnticlockwise(int delayus) {

	while (true) {
		digitalWrite(IN0, HIGH);
		digitalWrite(IN2, LOW);
		digitalWrite(IN2, LOW);
		digitalWrite(IN3, HIGH);
		delayMicroseconds(delayus);

		digitalWrite(IN0, LOW);
		digitalWrite(IN1, LOW);
		digitalWrite(IN2, LOW);
		digitalWrite(IN3, HIGH);
		delayMicroseconds(delayus);
	
		digitalWrite(IN0, LOW);
		digitalWrite(IN1, LOW);
		digitalWrite(IN2, HIGH);
		digitalWrite(IN3, HIGH);
		delayMicroseconds(delayus);
	
		digitalWrite(IN0, LOW);
		digitalWrite(IN1, LOW);
		digitalWrite(IN2, HIGH);
		digitalWrite(IN3, LOW);
		delayMicroseconds(delayus);
		
		digitalWrite(IN0, LOW);
		digitalWrite(IN1, HIGH);
		digitalWrite(IN2, HIGH);
		digitalWrite(IN3, LOW);
		delayMicroseconds(delayus);
	
		digitalWrite(IN0, LOW);
		digitalWrite(IN1, HIGH);
		digitalWrite(IN2, LOW);
		digitalWrite(IN3, LOW);
		delayMicroseconds(delayus);
	
		digitalWrite(IN0, HIGH);
		digitalWrite(IN1, HIGH);
		digitalWrite(IN2, LOW);
		digitalWrite(IN3, LOW);
		delayMicroseconds(delayus);
	
		digitalWrite(IN0, HIGH);
		digitalWrite(IN1, LOW);
		digitalWrite(IN2, LOW);
		digitalWrite(IN3, LOW);
		delayMicroseconds(delayus);

	}
}

void baseRunClockwise(int delayus) {
	while (true) {
		digitalWrite(IN0, HIGH);
		digitalWrite(IN1, LOW);
		digitalWrite(IN2, LOW);
		digitalWrite(IN3, LOW);
		delayMicroseconds(delayus);

		digitalWrite(IN0, HIGH);
		digitalWrite(IN1, HIGH);
		digitalWrite(IN2, LOW);
		digitalWrite(IN3, LOW);
		delayMicroseconds(delayus);

		digitalWrite(IN0, LOW);
		digitalWrite(IN1, HIGH);
		digitalWrite(IN2, LOW);
		digitalWrite(IN3, LOW);
		delayMicroseconds(delayus);

		digitalWrite(IN0, LOW);
		digitalWrite(IN1, HIGH);
		digitalWrite(IN2, HIGH);
		digitalWrite(IN3, LOW);
		delayMicroseconds(delayus);
	
		digitalWrite(IN0, LOW);
		digitalWrite(IN1, LOW);
		digitalWrite(IN2, HIGH);
		digitalWrite(IN3, LOW);
		delayMicroseconds(delayus);

		digitalWrite(IN0, LOW);
		digitalWrite(IN1, LOW);
		digitalWrite(IN2, HIGH);
		digitalWrite(IN3, HIGH);
		delayMicroseconds(delayus);

		digitalWrite(IN0, LOW);
		digitalWrite(IN1, LOW);
		digitalWrite(IN2, LOW);
		digitalWrite(IN3, HIGH);
		delayMicroseconds(delayus);

		digitalWrite(IN0, HIGH);
		digitalWrite(IN1, LOW);
		digitalWrite(IN2, LOW);
		digitalWrite(IN3, HIGH);
		delayMicroseconds(delayus);
	}
}
void main(int argc, char *argv[]) {
	int delay = 0;
	int direction = 0;
	delay = atoi(argv[1]);
	initalPins();
    if (strcmp(argv[2],"p")==0) {
		direction = 1;
	} else if (strcmp(argv[2],"n")==0) {
		direction = 0;
	} else
		direction = 1;

	switch (direction) {
		case 1:
			baseRunClockwise(delay);
			break;
		case 0:
			baseRunAnticlockwise(delay);
			break;
		default:
			return;
	}
}


