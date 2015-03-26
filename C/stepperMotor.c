/*************************************************************************
	> File Name: stepperMotor.c
	> Author: Utopia
	> Mail: lanniaoershi@gmail.com 
	> Created Time: Thu 19 Mar 2015 19:55:39 UTC
 ************************************************************************/

#include"stepperMotor.h"

static int delay_g = 0;
static int beat_g = 8;
static int direction_g = 0;

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
			case DIRECTION_N:
				while (true) {
					motor_1_StepParam(DIRECTION_N, delay_g, beat_g);	
				}
				break;
			case DIRECTION_P:
				while (true) {
					motor_1_StepParam(DIRECTION_P, delay_g, beat_g);	
				}
				break;
		}
	}

	void *thread2() {
		switch (direction_g) {
			case DIRECTION_N:
				while (true) {
					motor_2_StepParam(DIRECTION_N, delay_g, beat_g);	
				}
				break;
			case DIRECTION_P:
				while (true) {
					motor_2_StepParam(DIRECTION_P, delay_g, beat_g);	
				}
				break;
		}
	}


	void *thread3() {
		switch (direction_g) {
			case DIRECTION_N:
 				while (true) {
					motor_3_StepParam(DIRECTION_N, delay_g, beat_g);	
				}
				break;
			case DIRECTION_P:
				while (true) {
					motor_3_StepParam(DIRECTION_P, delay_g, beat_g);	
				}
				break;
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



void startMotor(int delayus, int direction, int beat) {

	delay_g = delayus;
	beat_g = beat;
	initalPins();


    if (direction == 0) {
		direction_g = 0;
	} else if (direction==1) {
		direction_g = 1;
	} else
		direction_g = 0;
	
	thread_create();

}



