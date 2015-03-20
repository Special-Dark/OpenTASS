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
#include<pthread.h>

#define true 1
#define false 0

// pin for stepper motor 1
#define IN0_1 0
#define IN1_1 1
#define IN2_1 2
#define IN3_1 3

// pin for stepper motor 2
#define IN0_2 4
#define IN1_2 5
#define IN2_2 6
#define IN3_2 7

// pin for stepper motor 3
#define IN0_3 8
#define IN1_3 9
#define IN2_3 10
#define IN3_3 11

#define MOTOR_1 1
#define MOTOR_2 2
#define MOTOR_3 3

#define DIRECTION_N 0
#define DIRECTION_P 1

#define BEAT_4 4
#define BEAT_8 8


#define COUNT 64*8

static int delay_g = 0;
static int beat_g = 8;
static int direction_g = 0;
static int count = 0;
static struct Motor {
	int direction;
	int speed;
	int beat;
	int duration;
}motor[3];

pthread_t motor_thread[3];

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
void resetPosition() {

}


void motor_1_setParam_Run(int direction, int speed, int beat, int duration) {
	motor[0].direction = direction;
	motor[0].speed = speed;
	motor[0].beat = beat;
	motor[0].duration = duration;
}

void motor_2_setParam_Run(int direction, int speed, int beat, int duration) {
	motor[1].direction = direction;
	motor[1].speed = speed;
	motor[1].beat = beat;
	motor[1].duration = duration;
}

void motor_3_setParam_Run(int direction, int speed, int beat, int duration) {
	motor[2].direction = direction;
	motor[2].speed = speed;
	motor[2].beat = beat;
	motor[2].duration = duration;
}

void motor_1_StepParam(int direction, int delayus, int beat){
	switch(direction) {
		case DIRECTION_P:
			switch(beat) {
				case BEAT_8:

					// beat 1
					digitalWrite(IN0_1, HIGH);
					digitalWrite(IN2_1, LOW);
					digitalWrite(IN2_1, LOW);
					digitalWrite(IN3_1, HIGH);
					delayMicroseconds(delayus);
					
					// beat 2
					digitalWrite(IN0_1, LOW);
					digitalWrite(IN1_1, LOW);
					digitalWrite(IN2_1, LOW);
					digitalWrite(IN3_1, HIGH);
					delayMicroseconds(delayus);
					
					// beat 3
					digitalWrite(IN0_1, LOW);
					digitalWrite(IN1_1, LOW);
					digitalWrite(IN2_1, HIGH);
					digitalWrite(IN3_1, HIGH);
					delayMicroseconds(delayus);
					
					// beat 4
					digitalWrite(IN0_1, LOW);
					digitalWrite(IN1_1, LOW);
					digitalWrite(IN2_1, HIGH);
					digitalWrite(IN3_1, LOW);
					delayMicroseconds(delayus);
					
					// beat 5
					digitalWrite(IN0_1, LOW);
					digitalWrite(IN1_1, HIGH);
					digitalWrite(IN2_1, HIGH);
					digitalWrite(IN3_1, LOW);
					delayMicroseconds(delayus);
					
					// beat6	
					digitalWrite(IN0_1, LOW);
					digitalWrite(IN1_1, HIGH);
					digitalWrite(IN2_1, LOW);
					digitalWrite(IN3_1, LOW);
					delayMicroseconds(delayus);
					
					// beat7
					digitalWrite(IN0_1, HIGH);
					digitalWrite(IN1_1, HIGH);
					digitalWrite(IN2_1, LOW);
					digitalWrite(IN3_1, LOW);
					delayMicroseconds(delayus);
					
					// beat 8
					digitalWrite(IN0_1, HIGH);
					digitalWrite(IN1_1, LOW);
					digitalWrite(IN2_1, LOW);
					digitalWrite(IN3_1, LOW);
					delayMicroseconds(delayus);

	 				break;

				case BEAT_4:

					// beat 1
					digitalWrite(IN0_1, HIGH);
					digitalWrite(IN1_1, LOW);
					digitalWrite(IN2_1, LOW);
					digitalWrite(IN3_1, HIGH);
					delayMicroseconds(delayus);

					// beat 2
					digitalWrite(IN0_1, LOW);
					digitalWrite(IN1_1, LOW);
					digitalWrite(IN2_1, HIGH);
					digitalWrite(IN3_1, HIGH);
					delayMicroseconds(delayus);
					
					//beat 3
					digitalWrite(IN0_1, LOW);
					digitalWrite(IN1_1, HIGH);
					digitalWrite(IN2_1, HIGH);
					digitalWrite(IN3_1, LOW);
					delayMicroseconds(delayus);
					
					// beat 4	
					digitalWrite(IN0_1, HIGH);
					digitalWrite(IN1_1, HIGH);
					digitalWrite(IN2_1, LOW);
					digitalWrite(IN3_1, LOW);
					delayMicroseconds(delayus);

	 				break;
			}

			break;

		case DIRECTION_N:
			switch(beat) {
	 			case BEAT_8:

					// beat 1
					digitalWrite(IN0_1, HIGH);
					digitalWrite(IN1_1, LOW);
					digitalWrite(IN2_1, LOW);
					digitalWrite(IN3_1, LOW);
					delayMicroseconds(delayus);

					// beat 2
					digitalWrite(IN0_1, HIGH);
					digitalWrite(IN1_1, HIGH);
					digitalWrite(IN2_1, LOW);
					digitalWrite(IN3_1, LOW);
					delayMicroseconds(delayus);

					// beat 3
					digitalWrite(IN0_1, LOW);
					digitalWrite(IN1_1, HIGH);
					digitalWrite(IN2_1, LOW);
					digitalWrite(IN3_1, LOW);
					delayMicroseconds(delayus);

					// beat 4
					digitalWrite(IN0_1, LOW);
					digitalWrite(IN1_1, HIGH);
					digitalWrite(IN2_1, HIGH);
					digitalWrite(IN3_1, LOW);
					delayMicroseconds(delayus);
	
					// beat 5
					digitalWrite(IN0_1, LOW);
					digitalWrite(IN1_1, LOW);
					digitalWrite(IN2_1, HIGH);
					digitalWrite(IN3_1, LOW);
					delayMicroseconds(delayus);

					// beat 6
					digitalWrite(IN0_1, LOW);
					digitalWrite(IN1_1, LOW);
					digitalWrite(IN2_1, HIGH);
					digitalWrite(IN3_1, HIGH);
					delayMicroseconds(delayus);

					// beat 7
					digitalWrite(IN0_1, LOW);
					digitalWrite(IN1_1, LOW);
					digitalWrite(IN2_1, LOW);
					digitalWrite(IN3_1, HIGH);
					delayMicroseconds(delayus);

					// beat 8
					digitalWrite(IN0_1, HIGH);
					digitalWrite(IN1_1, LOW);
					digitalWrite(IN2_1, LOW);
					digitalWrite(IN3_1, HIGH);
					delayMicroseconds(delayus);

					break;

				case BEAT_4:

	 			 	// beat 1
					digitalWrite(IN0_1, HIGH);
					digitalWrite(IN1_1, HIGH);
					digitalWrite(IN2_1, LOW);
					digitalWrite(IN3_1, LOW);
					delayMicroseconds(delayus);

					// beat 2
					digitalWrite(IN0_1, LOW);
					digitalWrite(IN1_1, HIGH);
					digitalWrite(IN2_1, HIGH);
					digitalWrite(IN3_1, LOW);
					delayMicroseconds(delayus);
		
					// beat 3
					digitalWrite(IN0_1, LOW);
					digitalWrite(IN1_1, LOW);
					digitalWrite(IN2_1, HIGH);
					digitalWrite(IN3_1, HIGH);
					delayMicroseconds(delayus);
		
					//beat 4
					digitalWrite(IN0_1, HIGH);
					digitalWrite(IN1_1, LOW);
					digitalWrite(IN2_1, LOW);
					digitalWrite(IN3_1, HIGH);
					delayMicroseconds(delayus);

					break;
			}
			break;

	}
	
}

void motor_2_StepParam(int direction, int delayus, int beat){
	switch(direction) {
		case DIRECTION_P:
			switch(beat) {
				case BEAT_8:

					// beat 1
					digitalWrite(IN0_2, HIGH);
					digitalWrite(IN2_2, LOW);
					digitalWrite(IN2_2, LOW);
					digitalWrite(IN3_2, HIGH);
					delayMicroseconds(delayus);
					
					// beat 2
					digitalWrite(IN0_2, LOW);
					digitalWrite(IN1_2, LOW);
					digitalWrite(IN2_2, LOW);
					digitalWrite(IN3_2, HIGH);
					delayMicroseconds(delayus);
					
					// beat 3
					digitalWrite(IN0_2, LOW);
					digitalWrite(IN1_2, LOW);
					digitalWrite(IN2_2, HIGH);
					digitalWrite(IN3_2, HIGH);
					delayMicroseconds(delayus);
					
					// beat 4
					digitalWrite(IN0_2, LOW);
					digitalWrite(IN1_2, LOW);
					digitalWrite(IN2_2, HIGH);
					digitalWrite(IN3_2, LOW);
					delayMicroseconds(delayus);
					
					// beat 5
					digitalWrite(IN0_2, LOW);
					digitalWrite(IN1_2, HIGH);
					digitalWrite(IN2_2, HIGH);
					digitalWrite(IN3_2, LOW);
					delayMicroseconds(delayus);
					
					// beat6	
					digitalWrite(IN0_2, LOW);
					digitalWrite(IN1_2, HIGH);
					digitalWrite(IN2_2, LOW);
					digitalWrite(IN3_2, LOW);
					delayMicroseconds(delayus);
					
					// beat7
					digitalWrite(IN0_2, HIGH);
					digitalWrite(IN1_2, HIGH);
					digitalWrite(IN2_2, LOW);
					digitalWrite(IN3_2, LOW);
					delayMicroseconds(delayus);
					
					// beat 8
					digitalWrite(IN0_2, HIGH);
					digitalWrite(IN1_2, LOW);
					digitalWrite(IN2_2, LOW);
					digitalWrite(IN3_2, LOW);
					delayMicroseconds(delayus);

	 				break;

				case BEAT_4:

					// beat 1
					digitalWrite(IN0_2, HIGH);
					digitalWrite(IN1_2, LOW);
					digitalWrite(IN2_2, LOW);
					digitalWrite(IN3_2, HIGH);
					delayMicroseconds(delayus);

					// beat 2
					digitalWrite(IN0_2, LOW);
					digitalWrite(IN1_2, LOW);
					digitalWrite(IN2_2, HIGH);
					digitalWrite(IN3_2, HIGH);
					delayMicroseconds(delayus);
					
					//beat 3
					digitalWrite(IN0_2, LOW);
					digitalWrite(IN1_2, HIGH);
					digitalWrite(IN2_2, HIGH);
					digitalWrite(IN3_2, LOW);
					delayMicroseconds(delayus);
					
					// beat 4	
					digitalWrite(IN0_2, HIGH);
					digitalWrite(IN1_2, HIGH);
					digitalWrite(IN2_2, LOW);
					digitalWrite(IN3_2, LOW);
					delayMicroseconds(delayus);

	 				break;
			}

			break;

		case DIRECTION_N:
			switch(beat) {
	 			case BEAT_8:

					// beat 1
					digitalWrite(IN0_2, HIGH);
					digitalWrite(IN1_2, LOW);
					digitalWrite(IN2_2, LOW);
					digitalWrite(IN3_2, LOW);
					delayMicroseconds(delayus);

					// beat 2
					digitalWrite(IN0_2, HIGH);
					digitalWrite(IN1_2, HIGH);
					digitalWrite(IN2_2, LOW);
					digitalWrite(IN3_2, LOW);
					delayMicroseconds(delayus);

					// beat 3
					digitalWrite(IN0_2, LOW);
					digitalWrite(IN1_2, HIGH);
					digitalWrite(IN2_2, LOW);
					digitalWrite(IN3_2, LOW);
					delayMicroseconds(delayus);

					// beat 4
					digitalWrite(IN0_2, LOW);
					digitalWrite(IN1_2, HIGH);
					digitalWrite(IN2_2, HIGH);
					digitalWrite(IN3_2, LOW);
					delayMicroseconds(delayus);
	
					// beat 5
					digitalWrite(IN0_2, LOW);
					digitalWrite(IN1_2, LOW);
					digitalWrite(IN2_2, HIGH);
					digitalWrite(IN3_2, LOW);
					delayMicroseconds(delayus);

					// beat 6
					digitalWrite(IN0_2, LOW);
					digitalWrite(IN1_2, LOW);
					digitalWrite(IN2_2, HIGH);
					digitalWrite(IN3_2, HIGH);
					delayMicroseconds(delayus);

					// beat 7
					digitalWrite(IN0_2, LOW);
					digitalWrite(IN1_2, LOW);
					digitalWrite(IN2_2, LOW);
					digitalWrite(IN3_2, HIGH);
					delayMicroseconds(delayus);

					// beat 8
					digitalWrite(IN0_2, HIGH);
					digitalWrite(IN1_2, LOW);
					digitalWrite(IN2_2, LOW);
					digitalWrite(IN3_2, HIGH);
					delayMicroseconds(delayus);

					break;

				case BEAT_4:

	 			 	// beat 1
					digitalWrite(IN0_2, HIGH);
					digitalWrite(IN1_2, HIGH);
					digitalWrite(IN2_2, LOW);
					digitalWrite(IN3_2, LOW);
					delayMicroseconds(delayus);

					// beat 2
					digitalWrite(IN0_2, LOW);
					digitalWrite(IN1_2, HIGH);
					digitalWrite(IN2_2, HIGH);
					digitalWrite(IN3_2, LOW);
					delayMicroseconds(delayus);
		
					// beat 3
					digitalWrite(IN0_2, LOW);
					digitalWrite(IN1_2, LOW);
					digitalWrite(IN2_2, HIGH);
					digitalWrite(IN3_2, HIGH);
					delayMicroseconds(delayus);
		
					//beat 4
					digitalWrite(IN0_2, HIGH);
					digitalWrite(IN1_2, LOW);
					digitalWrite(IN2_2, LOW);
					digitalWrite(IN3_2, HIGH);
					delayMicroseconds(delayus);

					break;
			}
			break;

	}
	
}

void motor_3_StepParam(int direction, int delayus, int beat){
	switch(direction) {
		case DIRECTION_P:
			switch(beat) {
				case BEAT_8:

					// beat 1
					digitalWrite(IN0_3, HIGH);
					digitalWrite(IN2_3, LOW);
					digitalWrite(IN2_3, LOW);
					digitalWrite(IN3_3, HIGH);
					delayMicroseconds(delayus);
					
					// beat 2
					digitalWrite(IN0_3, LOW);
					digitalWrite(IN1_3, LOW);
					digitalWrite(IN2_3, LOW);
					digitalWrite(IN3_3, HIGH);
					delayMicroseconds(delayus);
					
					// beat 3
					digitalWrite(IN0_3, LOW);
					digitalWrite(IN1_3, LOW);
					digitalWrite(IN2_3, HIGH);
					digitalWrite(IN3_3, HIGH);
					delayMicroseconds(delayus);
					
					// beat 4
					digitalWrite(IN0_3, LOW);
					digitalWrite(IN1_3, LOW);
					digitalWrite(IN2_3, HIGH);
					digitalWrite(IN3_3, LOW);
					delayMicroseconds(delayus);
					
					// beat 5
					digitalWrite(IN0_3, LOW);
					digitalWrite(IN1_3, HIGH);
					digitalWrite(IN2_3, HIGH);
					digitalWrite(IN3_3, LOW);
					delayMicroseconds(delayus);
					
					// beat6	
					digitalWrite(IN0_3, LOW);
					digitalWrite(IN1_3, HIGH);
					digitalWrite(IN2_3, LOW);
					digitalWrite(IN3_3, LOW);
					delayMicroseconds(delayus);
					
					// beat7
					digitalWrite(IN0_3, HIGH);
					digitalWrite(IN1_3, HIGH);
					digitalWrite(IN2_3, LOW);
					digitalWrite(IN3_3, LOW);
					delayMicroseconds(delayus);
					
					// beat 8
					digitalWrite(IN0_3, HIGH);
					digitalWrite(IN1_3, LOW);
					digitalWrite(IN2_3, LOW);
					digitalWrite(IN3_3, LOW);
					delayMicroseconds(delayus);

	 				break;

				case BEAT_4:

					// beat 1
					digitalWrite(IN0_3, HIGH);
					digitalWrite(IN1_3, LOW);
					digitalWrite(IN2_3, LOW);
					digitalWrite(IN3_3, HIGH);
					delayMicroseconds(delayus);

					// beat 2
					digitalWrite(IN0_3, LOW);
					digitalWrite(IN1_3, LOW);
					digitalWrite(IN2_3, HIGH);
					digitalWrite(IN3_3, HIGH);
					delayMicroseconds(delayus);
					
					//beat 3
					digitalWrite(IN0_3, LOW);
					digitalWrite(IN1_3, HIGH);
					digitalWrite(IN2_3, HIGH);
					digitalWrite(IN3_3, LOW);
					delayMicroseconds(delayus);
					
					// beat 4	
					digitalWrite(IN0_3, HIGH);
					digitalWrite(IN1_3, HIGH);
					digitalWrite(IN2_3, LOW);
					digitalWrite(IN3_3, LOW);
					delayMicroseconds(delayus);

	 				break;
			}

			break;

		case DIRECTION_N:
			switch(beat) {
	 			case BEAT_8:

					// beat 1
					digitalWrite(IN0_3, HIGH);
					digitalWrite(IN1_3, LOW);
					digitalWrite(IN2_3, LOW);
					digitalWrite(IN3_3, LOW);
					delayMicroseconds(delayus);

					// beat 2
					digitalWrite(IN0_3, HIGH);
					digitalWrite(IN1_3, HIGH);
					digitalWrite(IN2_3, LOW);
					digitalWrite(IN3_3, LOW);
					delayMicroseconds(delayus);

					// beat 3
					digitalWrite(IN0_3, LOW);
					digitalWrite(IN1_3, HIGH);
					digitalWrite(IN2_3, LOW);
					digitalWrite(IN3_3, LOW);
					delayMicroseconds(delayus);

					// beat 4
					digitalWrite(IN0_3, LOW);
					digitalWrite(IN1_3, HIGH);
					digitalWrite(IN2_3, HIGH);
					digitalWrite(IN3_3, LOW);
					delayMicroseconds(delayus);
	
					// beat 5
					digitalWrite(IN0_3, LOW);
					digitalWrite(IN1_3, LOW);
					digitalWrite(IN2_3, HIGH);
					digitalWrite(IN3_3, LOW);
					delayMicroseconds(delayus);

					// beat 6
					digitalWrite(IN0_3, LOW);
					digitalWrite(IN1_3, LOW);
					digitalWrite(IN2_3, HIGH);
					digitalWrite(IN3_3, HIGH);
					delayMicroseconds(delayus);

					// beat 7
					digitalWrite(IN0_3, LOW);
					digitalWrite(IN1_3, LOW);
					digitalWrite(IN2_3, LOW);
					digitalWrite(IN3_3, HIGH);
					delayMicroseconds(delayus);

					// beat 8
					digitalWrite(IN0_3, HIGH);
					digitalWrite(IN1_3, LOW);
					digitalWrite(IN2_3, LOW);
					digitalWrite(IN3_3, HIGH);
					delayMicroseconds(delayus);

					break;

				case BEAT_4:

	 			 	// beat 1
					digitalWrite(IN0_3, HIGH);
					digitalWrite(IN1_3, HIGH);
					digitalWrite(IN2_3, LOW);
					digitalWrite(IN3_3, LOW);
					delayMicroseconds(delayus);

					// beat 2
					digitalWrite(IN0_3, LOW);
					digitalWrite(IN1_3, HIGH);
					digitalWrite(IN2_3, HIGH);
					digitalWrite(IN3_3, LOW);
					delayMicroseconds(delayus);
		
					// beat 3
					digitalWrite(IN0_3, LOW);
					digitalWrite(IN1_3, LOW);
					digitalWrite(IN2_3, HIGH);
					digitalWrite(IN3_3, HIGH);
					delayMicroseconds(delayus);
		
					//beat 4
					digitalWrite(IN0_3, HIGH);
					digitalWrite(IN1_3, LOW);
					digitalWrite(IN2_3, LOW);
					digitalWrite(IN3_3, HIGH);
					delayMicroseconds(delayus);

					break;
			}
			break;

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




	void *thread1() {
		
		switch (direction_g) {
			case 2:
				while (true) {
					for (count=1;count<=COUNT;count++) {
						motor_1_StepParam(DIRECTION_P, delay_g, beat_g);	
					}
					delayMicroseconds(5000);
					for (count=COUNT;count>=1;count--) {
						motor_1_StepParam(DIRECTION_N, delay_g, beat_g);	
					}
					delayMicroseconds(5000);
				}
				break;
			case 1:
				while (true) {
					baseRunAnticlockwise(delay_g, beat_g);
				}
				break;
			case 0:
				while (true) {
					baseRunClockwise(delay_g, beat_g);
				}
				break;
			default:
				return;
		}
	}

	void *thread2() {
		
		switch (direction_g) {
			case 2:
				while (true) {
					for (count=1;count<=COUNT;count++) {
						motor_2_StepParam(DIRECTION_N, 1500, beat_g);	
					}
					delayMicroseconds(5000);
					for (count=COUNT;count>=1;count--) {
						motor_2_StepParam(DIRECTION_P, 1500, beat_g);	
					}
					delayMicroseconds(5000);
				}
				break;
			case 1:
				while (true) {
					baseRunAnticlockwise(delay_g, beat_g);
				}
				break;
			case 0:
				while (true) {
					baseRunClockwise(delay_g, beat_g);
				}
				break;
			default:
				return;
		}
	}


	void *thread3() {
		
		switch (direction_g) {
			case 2:
				while (true) {
					for (count=1;count<=COUNT;count++) {
						motor_3_StepParam(DIRECTION_N, 5000, beat_g);	
					}
					delayMicroseconds(5000);
					for (count=COUNT;count>=1;count--) {
						motor_3_StepParam(DIRECTION_P, 5000, beat_g);	
					}
					delayMicroseconds(5000);
				}
				break;
			case 1:
				while (true) {
					baseRunAnticlockwise(delay_g, beat_g);
				}
				break;
			case 0:
				while (true) {
					baseRunClockwise(delay_g, beat_g);
				}
				break;
			default:
				return;
		}
	}

	void thread_create() {
		int temp;
		memset(&motor_thread, 0, sizeof(motor_thread));
		if ((temp = pthread_create(&motor_thread[0], NULL, thread1, NULL)) != 0)
			printf("failed to create thread1\n");
		else
			printf("create thread1 done\n");
			
		if ((temp = pthread_create(&motor_thread[1], NULL, thread2, NULL)) != 0)
			printf("failed to create thread2\n");
		else
			printf("create thread2 done\n");
			
		if ((temp = pthread_create(&motor_thread[2], NULL, thread3, NULL)) != 0)
			printf("failed to create thread3\n");
		else
			printf("create thread3 done\n");
		pthread_join(motor_thread[0], NULL);
		pthread_join(motor_thread[1], NULL);
		pthread_join(motor_thread[2], NULL);
	}



void main(int argc, char *argv[]) {

	delay_g = atoi(argv[1]);
	beat_g = atoi(argv[3]);
	initalPins();


    if (strcmp(argv[2],"p")==0) {
		direction_g = 0;
	} else if (strcmp(argv[2],"n")==0) {
		direction_g = 1;
	} else if (strcmp(argv[2],"a")==0) {
		direction_g = 2;
	} else
		direction_g = 0;
	thread_create();

}

/*	switch (direction) {
		case 2:
			while (true) {
				for (count=1;count<=COUNT;count++) {
					
				}
				delayMicroseconds(5000);
				for (count=COUNT;count>=1;count--) {
					
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
*/


