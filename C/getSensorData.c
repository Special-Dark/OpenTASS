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
#define G_scale 32768*16
#define W_scale 32768*2000

static int dataFlow = 0;
static short data8bit = 0;
static short dataBuffer[88];
static short dataCount = 0;
static short Gdata[3] = {0};
static short Wdata[3] = {0};

short readSensorData();
int openSerialPort(char *device, int baud);
void decodeDataTo16Bit(short data);

void main() {

	short dataArry[11] = {0};
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

		printf("G = %.2f, %.2f, %.2f\n", G[0],G[1],G[2]);
		printf("W = %.2f, %.2f, %.2f\n", W[0],W[1],W[2]);
	}
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
				Gdata[0] = (dataBuffer[3] << 8 | dataBuffer[2]);
				Gdata[1] = (dataBuffer[5] << 8 | dataBuffer[4]);
				Gdata[2] = (dataBuffer[7] << 8 | dataBuffer[6]);
				break;
			case 82:
				Wdata[0] = (dataBuffer[3] << 8 | dataBuffer[2]);
				Wdata[1] = (dataBuffer[5] << 8 | dataBuffer[4]);
				Wdata[2] = (dataBuffer[7] << 8 | dataBuffer[6]);
		 		break;
		}
		dataCount = 0;
	}
	


}