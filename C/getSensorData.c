/*************************************************************************
	> File Name: getSensorData.c
	> Author: Utopia
	> Mail: lanniaoershi@gmail.com 
	> Created Time: Tue 17 Mar 2015 11:00:41 UTC
 ************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<wiringSerial.h>
#include<signal.h>
#include<string.h>

#define DEVICE "/dev/ttyAMA0"
#define BAUD 115200
#define true 1
#define false 0
#define DEBUG  "--debug"
#define G_scale 32768*16
#define W_scale 32768*2000
//#define G_scale 1
//#define W_scale 1

static int dataFlow = 0;
static short data8bit = 0;
static short dataBuffer[88];
static short dataCount = 0;
static short Gdata[3] = {0};
static short Wdata[3] = {0};
static float G[3] = {0};
static float W[3] = {0};

short readSensorData();
int openSerialPort(char *device, int baud);
void decodeDataTo16Bit(short data);
void showFakeGUI();

void mainProcess() {
	while (true) {
		decodeDataTo16Bit(readSensorData());
		
		G[0] = (float) Gdata[0] / G_scale;
		G[1] = (float) Gdata[1] / G_scale;
		G[2] = (float) Gdata[2] / G_scale;

		W[0] = (float) Wdata[0] / W_scale;
		W[1] = (float) Wdata[1] / W_scale;
		W[2] = (float) Wdata[2] / W_scale;
	}
}

void mainProcessWithDebug() {
	while (true) {
		decodeDataTo16Bit(readSensorData());
		
		G[0] = (float) Gdata[0] / G_scale;
		G[1] = (float) Gdata[1] / G_scale;
		G[2] = (float) Gdata[2] / G_scale;

		W[0] = (float) Wdata[0] / W_scale;
		W[1] = (float) Wdata[1] / W_scale;
		W[2] = (float) Wdata[2] / W_scale;
		showFakeGUI();
	}
}

void signalHandler(int sig) {
	printf("\033[?25h"); // set cursor show 
	printf("\nexit!\n");
	exit(0);
}

int main(int argc, char *argv[]) {
	int mode = 0;

	printf("Start runing...\n");
	signal(SIGINT,signalHandler);
	dataFlow = openSerialPort(DEVICE, BAUD);
	if (argc == 2 && (strcmp(argv[1], DEBUG) == 0)) {
		mode = 1;
	} else {
		mode = 0;
	}

	switch (mode) {
		case 0 : 
			  mainProcess();
			  break;
		case 1 :
			  mainProcessWithDebug();
			  break;
		default : 
			  return -1;
	}
	return 0;
}

void showFakeGUI() {
	printf("G: x = %8.3f\n   y = %8.3f\n   z = %8.3f\n\nW: x = %8.3f\n   y = %8.3f\n   z = %8.3f\n", G[0],G[1],G[2],W[0],W[1],W[2]);
	printf("\033c"); // set clear screen
	printf("\033[?25l"); // set cursor hide
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

