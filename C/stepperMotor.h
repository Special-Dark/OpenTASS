/*************************************************************************
	> File Name: stepperMotor.h
	> Author: Utopia
	> Mail: lanniaoershi@gmail.com 
	> Created Time: Fri 20 Mar 2015 12:20:51 UTC
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include"getSensorData.h"


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

#define DIRECTION_N 1
#define DIRECTION_P 0

#define BEAT_4 4
#define BEAT_8 8

#define COUNT 64*8

void initalPins();
void motor_1_StepParam(int direction, int delayus, int beat);
void motor_2_StepParam(int direction, int delayus, int beat);
void motor_3_StepParam(int direction, int delayus, int beat);
void *thread1();
void *thread2();
void *thread3();
void thread_create();
void startMotor(int delayus, int direction, int beat);

