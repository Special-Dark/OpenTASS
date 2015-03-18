/*************************************************************************
	> File Name: getSensorData.c
	> Author: Utopia
	> Mail: lanniaoershi@gmail.com 
	> Created Time: Tue 17 Mar 2015 11:00:41 UTC
 ************************************************************************/

#include<stdio.h>
#include<wiringSerial.h>

#define DEVICE "/dev/ttyAMA0"
#define BAUD 9600
#define true 1
#define false 0
#define DEBUG  0 // still have bugs when set to 1
#define G_scale 32768*16
#define W_scale 32768*2000
// #define G_scale 1
// #define W_scale 1

static int dataFlow = 0;
static short data8bit = 0;
static short dataBuffer[88];
static short dataCount = 0;
static short Gdata[3] = {0};
static short Wdata[3] = {0};

short readSensorData();
int openSerialPort(char *device, int baud);
void decodeDataTo16Bit(short data);
void watchData();
int main() {

	float G[3] = {0};
	float W[3] = {0};

	dataFlow = openSerialPort(DEVICE, BAUD);

	while (true) {
		//printf("data = %d\n", readSensorData());
		decodeDataTo16Bit(readSensorData());
		
		G[0] = (float) Gdata[0] / G_scale;
		G[1] = (float) Gdata[1] / G_scale;
		G[2] = (float) Gdata[2] / G_scale;

		W[0] = (float) Wdata[0] / W_scale;
		W[1] = (float) Wdata[1] / W_scale;
		W[2] = (float) Wdata[2] / W_scale;

		printf("G = %.3f, %.3f, %.3f\n", G[0],G[1],G[2]);
		printf("W = %.3f, %.3f, %.3f\n", W[0],W[1],W[2]);
		
		if (DEBUG == true) {
			watchData();
		}
	}
	return 0;
}


short readSensorData() {
	data8bit = serialGetchar(dataFlow);
	return data8bit;
}

int openSerialPort(char *device, int baud) {
	return serialOpen(device, baud);
}

void decodeDataTo16Bit(short data) {
	dataBuffer[dataCount++] = data;
	if (dataBuffer[0] != 85) {
		dataCount = 0;
		return;
	}
	if (dataCount < 11) {
		return;
	} else {
		switch (dataBuffer[1]) {
			case 81:
				Gdata[0] = ((unsigned short)dataBuffer[3] << 8 | dataBuffer[2]);
				Gdata[1] = ((unsigned short)dataBuffer[5] << 8 | dataBuffer[4]);
				Gdata[2] = ((unsigned short)dataBuffer[7] << 8 | dataBuffer[6]);
				break;
			case 82:
				Wdata[0] = ((unsigned short)dataBuffer[3] << 8 | dataBuffer[2]);
				Wdata[1] = ((unsigned short)dataBuffer[5] << 8 | dataBuffer[4]);
				Wdata[2] = ((unsigned short)dataBuffer[7] << 8 | dataBuffer[6]);
		 		break;
		}
		dataCount = 0;
	}
	

}

void watchData() {
	char command[40];
	sprintf(command, "echo G = %d, %d, %d  @@@  W = %d,%d,%d > data.txt",Gdata[0],Gdata[1],Gdata[2],Wdata[0],Wdata[1],Wdata[2]);
	system(command);

}
