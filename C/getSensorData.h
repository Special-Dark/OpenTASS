/*************************************************************************
	> File Name: getSensorData.h
	> Author: Utopia
	> Mail: lanniaoershi@gmail.com 
	> Created Time: Fri 20 Mar 2015 04:06:35 UTC
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<wiringPi.h>
#include<wiringSerial.h>
#include<string.h>
#include<signal.h>

#define DEVICE "/dev/ttyAMA0"
#define BAUD 115200
#define true 1
#define false 0
#define DEBUG  "--debug"
#define G_scale 32768*16
#define W_scale 32768*2000
//#define G_scale 1
//#define W_scale 1

short readSensorData();
int openSerialPort(char *device, int baud);
void decodeDataTo16Bit(short data);
void showFakeGUI();
void handleDataScale();
void handleDataScaleWithDebug();
float *getG_OutputData();

