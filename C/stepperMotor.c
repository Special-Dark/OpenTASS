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
#define false 0

// stepper motor 1
#define IN0_1 0
#define IN1_1 1
#define IN2_1 2
#define IN3_1 3

// stepper motor 2
#define IN0_2 4
#define IN1_2 5
#define IN2_2 6
#define IN3_2 7

// stepper motor 3
#define IN0_3 8
#define IN1_3 9
#define IN2_3 10
#define IN3_3 11

#define COUNT 64*8

static int  count = 0;
static int motor[3] = {1,2,3};


void initalPins() {
	int i = 0;
	int pins_motor_1[4] = {IN0_1, IN1_1, IN2_1, IN3_1};
	int pins_motor_2[4] = {IN0_2, IN1_2, IN2_2, IN3_2};
	int pins_motor_3[4] = {IN0_3, IN1_3, IN2_3, IN3_3};
	wiringPiSetup(); // must be call at first

	for (i=0;i<4;i++) {
		pinMode(pins_motor_1[i], OUTPUT);
		pinMode(pins_motor_2[i], OUTPUT);
		pinMode(pins_motor_3[i], OUTPUT);
	}

}

void baseRunAnticlockwise(int delayus, int beat) {

//	while (true) {
	if (beat == 8) {
		digitalWrite(IN0_1, HIGH);
		digitalWrite(IN2_1, LOW);
		digitalWrite(IN2_1, LOW);
		digitalWrite(IN3_1, HIGH);
		digitalWrite(IN0_2, HIGH);
		digitalWrite(IN2_2, LOW);
		digitalWrite(IN2_2, LOW);
		digitalWrite(IN3_2, HIGH);
		digitalWrite(IN0_3, HIGH);
		digitalWrite(IN2_3, LOW);
		digitalWrite(IN2_3, LOW);
		digitalWrite(IN3_3, HIGH);
		delayMicroseconds(delayus);

		digitalWrite(IN0_1, LOW);
		digitalWrite(IN1_1, LOW);
		digitalWrite(IN2_1, LOW);
		digitalWrite(IN3_1, HIGH);
		digitalWrite(IN0_2, LOW);
		digitalWrite(IN1_2, LOW);
		digitalWrite(IN2_2, LOW);
		digitalWrite(IN3_2, HIGH);
		digitalWrite(IN0_3, LOW);
		digitalWrite(IN1_3, LOW);
		digitalWrite(IN2_3, LOW);
		digitalWrite(IN3_3, HIGH);
		delayMicroseconds(delayus);
	
		digitalWrite(IN0_1, LOW);
		digitalWrite(IN1_1, LOW);
		digitalWrite(IN2_1, HIGH);
		digitalWrite(IN3_1, HIGH);
		digitalWrite(IN0_2, LOW);
		digitalWrite(IN1_2, LOW);
		digitalWrite(IN2_2, HIGH);
		digitalWrite(IN3_2, HIGH);
		digitalWrite(IN0_3, LOW);
		digitalWrite(IN1_3, LOW);
		digitalWrite(IN2_3, HIGH);
		digitalWrite(IN3_3, HIGH);
		delayMicroseconds(delayus);
	
		digitalWrite(IN0_1, LOW);
		digitalWrite(IN1_1, LOW);
		digitalWrite(IN2_1, HIGH);
		digitalWrite(IN3_1, LOW);
		digitalWrite(IN0_2, LOW);
		digitalWrite(IN1_2, LOW);
		digitalWrite(IN2_2, HIGH);
		digitalWrite(IN3_2, LOW);
		digitalWrite(IN0_3, LOW);
		digitalWrite(IN1_3, LOW);
		digitalWrite(IN2_3, HIGH);
		digitalWrite(IN3_3, LOW);
		delayMicroseconds(delayus);
		
		digitalWrite(IN0_1, LOW);
		digitalWrite(IN1_1, HIGH);
		digitalWrite(IN2_1, HIGH);
		digitalWrite(IN3_1, LOW);
		digitalWrite(IN0_2, LOW);
		digitalWrite(IN1_2, HIGH);
		digitalWrite(IN2_2, HIGH);
		digitalWrite(IN3_2, LOW);
		digitalWrite(IN0_3, LOW);
		digitalWrite(IN1_3, HIGH);
		digitalWrite(IN2_3, HIGH);
		digitalWrite(IN3_3, LOW);
		delayMicroseconds(delayus);
	
		digitalWrite(IN0_1, LOW);
		digitalWrite(IN1_1, HIGH);
		digitalWrite(IN2_1, LOW);
		digitalWrite(IN3_1, LOW);
		digitalWrite(IN0_2, LOW);
		digitalWrite(IN1_2, HIGH);
		digitalWrite(IN2_2, LOW);
		digitalWrite(IN3_2, LOW);
		digitalWrite(IN0_3, LOW);
		digitalWrite(IN1_3, HIGH);
		digitalWrite(IN2_3, LOW);
		digitalWrite(IN3_3, LOW);
		delayMicroseconds(delayus);
	
		digitalWrite(IN0_1, HIGH);
		digitalWrite(IN1_1, HIGH);
		digitalWrite(IN2_1, LOW);
		digitalWrite(IN3_1, LOW);
		digitalWrite(IN0_2, HIGH);
		digitalWrite(IN1_2, HIGH);
		digitalWrite(IN2_2, LOW);
		digitalWrite(IN3_2, LOW);
		digitalWrite(IN0_3, HIGH);
		digitalWrite(IN1_3, HIGH);
		digitalWrite(IN2_3, LOW);
		digitalWrite(IN3_3, LOW);
		delayMicroseconds(delayus);
	
		digitalWrite(IN0_1, HIGH);
		digitalWrite(IN1_1, LOW);
		digitalWrite(IN2_1, LOW);
		digitalWrite(IN3_1, LOW);
		digitalWrite(IN0_2, HIGH);
		digitalWrite(IN1_2, LOW);
		digitalWrite(IN2_2, LOW);
		digitalWrite(IN3_2, LOW);
		digitalWrite(IN0_3, HIGH);
		digitalWrite(IN1_3, LOW);
		digitalWrite(IN2_3, LOW);
		digitalWrite(IN3_3, LOW);
		delayMicroseconds(delayus);
	} else  {

		digitalWrite(IN0_1, HIGH);
		digitalWrite(IN1_1, LOW);
		digitalWrite(IN2_1, LOW);
		digitalWrite(IN3_1, HIGH);
		digitalWrite(IN0_2, HIGH);
		digitalWrite(IN1_2, LOW);
		digitalWrite(IN2_2, LOW);
		digitalWrite(IN3_2, HIGH);
		digitalWrite(IN0_3, HIGH);
		digitalWrite(IN1_3, LOW);
		digitalWrite(IN2_3, LOW);
		digitalWrite(IN3_3, HIGH);
		delayMicroseconds(delayus);

		digitalWrite(IN0_1, LOW);
		digitalWrite(IN1_1, LOW);
		digitalWrite(IN2_1, HIGH);
		digitalWrite(IN3_1, HIGH);
		digitalWrite(IN0_2, LOW);
		digitalWrite(IN1_2, LOW);
		digitalWrite(IN2_2, HIGH);
		digitalWrite(IN3_2, HIGH);
		digitalWrite(IN0_3, LOW);
		digitalWrite(IN1_3, LOW);
		digitalWrite(IN2_3, HIGH);
		digitalWrite(IN3_3, HIGH);
		delayMicroseconds(delayus);
		
		digitalWrite(IN0_1, LOW);
		digitalWrite(IN1_1, HIGH);
		digitalWrite(IN2_1, HIGH);
		digitalWrite(IN3_1, LOW);
		digitalWrite(IN0_2, LOW);
		digitalWrite(IN1_2, HIGH);
		digitalWrite(IN2_2, HIGH);
		digitalWrite(IN3_2, LOW);
		digitalWrite(IN0_3, LOW);
		digitalWrite(IN1_3, HIGH);
		digitalWrite(IN2_3, HIGH);
		digitalWrite(IN3_3, LOW);
		delayMicroseconds(delayus);
		
		digitalWrite(IN0_1, HIGH);
		digitalWrite(IN1_1, HIGH);
		digitalWrite(IN2_1, LOW);
		digitalWrite(IN3_1, LOW);
		digitalWrite(IN0_2, HIGH);
		digitalWrite(IN1_2, HIGH);
		digitalWrite(IN2_2, LOW);
		digitalWrite(IN3_2, LOW);
		digitalWrite(IN0_3, HIGH);
		digitalWrite(IN1_3, HIGH);
		digitalWrite(IN2_3, LOW);
		digitalWrite(IN3_3, LOW);
		delayMicroseconds(delayus);
	}
//	}
}

void baseRunClockwise(int delayus, int beat) {

//	while (true) {
	if (beat == 8) {
		digitalWrite(IN0_1, HIGH);
		digitalWrite(IN1_1, LOW);
		digitalWrite(IN2_1, LOW);
		digitalWrite(IN3_1, LOW);
		digitalWrite(IN0_2, HIGH);
		digitalWrite(IN1_2, LOW);
		digitalWrite(IN2_2, LOW);
		digitalWrite(IN3_2, LOW);
		digitalWrite(IN0_3, HIGH);
		digitalWrite(IN1_3, LOW);
		digitalWrite(IN2_3, LOW);
		digitalWrite(IN3_3, LOW);
		delayMicroseconds(delayus);

		digitalWrite(IN0_1, HIGH);
		digitalWrite(IN1_1, HIGH);
		digitalWrite(IN2_1, LOW);
		digitalWrite(IN3_1, LOW);
		digitalWrite(IN0_2, HIGH);
		digitalWrite(IN1_2, HIGH);
		digitalWrite(IN2_2, LOW);
		digitalWrite(IN3_2, LOW);
		digitalWrite(IN0_3, HIGH);
		digitalWrite(IN1_3, HIGH);
		digitalWrite(IN2_3, LOW);
		digitalWrite(IN3_3, LOW);
		delayMicroseconds(delayus);

		digitalWrite(IN0_1, LOW);
		digitalWrite(IN1_1, HIGH);
		digitalWrite(IN2_1, LOW);
		digitalWrite(IN3_1, LOW);
		digitalWrite(IN0_2, LOW);
		digitalWrite(IN1_2, HIGH);
		digitalWrite(IN2_2, LOW);
		digitalWrite(IN3_2, LOW);
		digitalWrite(IN0_3, LOW);
		digitalWrite(IN1_3, HIGH);
		digitalWrite(IN2_3, LOW);
		digitalWrite(IN3_3, LOW);
		delayMicroseconds(delayus);

		digitalWrite(IN0_1, LOW);
		digitalWrite(IN1_1, HIGH);
		digitalWrite(IN2_1, HIGH);
		digitalWrite(IN3_1, LOW);
		digitalWrite(IN0_2, LOW);
		digitalWrite(IN1_2, HIGH);
		digitalWrite(IN2_2, HIGH);
		digitalWrite(IN3_2, LOW);
		digitalWrite(IN0_3, LOW);
		digitalWrite(IN1_3, HIGH);
		digitalWrite(IN2_3, HIGH);
		digitalWrite(IN3_3, LOW);
		delayMicroseconds(delayus);
	
		digitalWrite(IN0_1, LOW);
		digitalWrite(IN1_1, LOW);
		digitalWrite(IN2_1, HIGH);
		digitalWrite(IN3_1, LOW);
		digitalWrite(IN0_2, LOW);
		digitalWrite(IN1_2, LOW);
		digitalWrite(IN2_2, HIGH);
		digitalWrite(IN3_2, LOW);
		digitalWrite(IN0_3, LOW);
		digitalWrite(IN1_3, LOW);
		digitalWrite(IN2_3, HIGH);
		digitalWrite(IN3_3, LOW);
		delayMicroseconds(delayus);

		digitalWrite(IN0_1, LOW);
		digitalWrite(IN1_1, LOW);
		digitalWrite(IN2_1, HIGH);
		digitalWrite(IN3_1, HIGH);
		digitalWrite(IN0_2, LOW);
		digitalWrite(IN1_2, LOW);
		digitalWrite(IN2_2, HIGH);
		digitalWrite(IN3_2, HIGH);
		digitalWrite(IN0_3, LOW);
		digitalWrite(IN1_3, LOW);
		digitalWrite(IN2_3, HIGH);
		digitalWrite(IN3_3, HIGH);
		delayMicroseconds(delayus);

		digitalWrite(IN0_1, LOW);
		digitalWrite(IN1_1, LOW);
		digitalWrite(IN2_1, LOW);
		digitalWrite(IN3_1, HIGH);
		digitalWrite(IN0_2, LOW);
		digitalWrite(IN1_2, LOW);
		digitalWrite(IN2_2, LOW);
		digitalWrite(IN3_2, HIGH);
		digitalWrite(IN0_3, LOW);
		digitalWrite(IN1_3, LOW);
		digitalWrite(IN2_3, LOW);
		digitalWrite(IN3_3, HIGH);
		delayMicroseconds(delayus);

		digitalWrite(IN0_1, HIGH);
		digitalWrite(IN1_1, LOW);
		digitalWrite(IN2_1, LOW);
		digitalWrite(IN3_1, HIGH);
		digitalWrite(IN0_2, HIGH);
		digitalWrite(IN1_2, LOW);
		digitalWrite(IN2_2, LOW);
		digitalWrite(IN3_2, HIGH);
		digitalWrite(IN0_3, HIGH);
		digitalWrite(IN1_3, LOW);
		digitalWrite(IN2_3, LOW);
		digitalWrite(IN3_3, HIGH);
		delayMicroseconds(delayus);
	} else {

		digitalWrite(IN0_1, HIGH);
		digitalWrite(IN1_1, HIGH);
		digitalWrite(IN2_1, LOW);
		digitalWrite(IN3_1, LOW);
		digitalWrite(IN0_2, HIGH);
		digitalWrite(IN1_2, HIGH);
		digitalWrite(IN2_2, LOW);
		digitalWrite(IN3_2, LOW);
		digitalWrite(IN0_3, HIGH);
		digitalWrite(IN1_3, HIGH);
		digitalWrite(IN2_3, LOW);
		digitalWrite(IN3_3, LOW);
		delayMicroseconds(delayus);

		digitalWrite(IN0_1, LOW);
		digitalWrite(IN1_1, HIGH);
		digitalWrite(IN2_1, HIGH);
		digitalWrite(IN3_1, LOW);
		digitalWrite(IN0_2, LOW);
		digitalWrite(IN1_2, HIGH);
		digitalWrite(IN2_2, HIGH);
		digitalWrite(IN3_2, LOW);
		digitalWrite(IN0_3, LOW);
		digitalWrite(IN1_3, HIGH);
		digitalWrite(IN2_3, HIGH);
		digitalWrite(IN3_3, LOW);
		delayMicroseconds(delayus);
		
		digitalWrite(IN0_1, LOW);
		digitalWrite(IN1_1, LOW);
		digitalWrite(IN2_1, HIGH);
		digitalWrite(IN3_1, HIGH);
		digitalWrite(IN0_2, LOW);
		digitalWrite(IN1_2, LOW);
		digitalWrite(IN2_2, HIGH);
		digitalWrite(IN3_2, HIGH);
		digitalWrite(IN0_3, LOW);
		digitalWrite(IN1_3, LOW);
		digitalWrite(IN2_3, HIGH);
		digitalWrite(IN3_3, HIGH);
		delayMicroseconds(delayus);
		
		digitalWrite(IN0_1, HIGH);
		digitalWrite(IN1_1, LOW);
		digitalWrite(IN2_1, LOW);
		digitalWrite(IN3_1, HIGH);
		digitalWrite(IN0_2, HIGH);
		digitalWrite(IN1_2, LOW);
		digitalWrite(IN2_2, LOW);
		digitalWrite(IN3_2, HIGH);
		digitalWrite(IN0_3, HIGH);
		digitalWrite(IN1_3, LOW);
		digitalWrite(IN2_3, LOW);
		digitalWrite(IN3_3, HIGH);
		delayMicroseconds(delayus);

	}
//	}
}



void main(int argc, char *argv[]) {
	int delay = 0;
	int beat = 8;
	int direction = 0;
	delay = atoi(argv[1]);
	beat = atoi(argv[3]);
	initalPins();
    if (strcmp(argv[2],"p")==0) {
		direction = 0;
	} else if (strcmp(argv[2],"n")==0) {
		direction = 1;
	} else if (strcmp(argv[2],"a")==0) {
		direction = 2;
	} else
		direction = 0;

	switch (direction) {
		case 2:
			while (true) {
				for (count=1;count<=COUNT;count++) {
					baseRunClockwise(delay, beat);
				}
				delayMicroseconds(5000);
				for (count=COUNT;count>=1;count--) {
					baseRunAnticlockwise(delay, beat);
				}
				delayMicroseconds(5000);
			}
			break;
		case 1:
			while (true) {
				baseRunAnticlockwise(delay, beat);
			}
			break;
		case 0:
			while (true) {
				baseRunClockwise(delay, beat);
			}
			break;
		default:
			return;
	}
}


