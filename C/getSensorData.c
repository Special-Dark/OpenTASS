/*************************************************************************
	> File Name: getSensorData.c
	> Author: Utopia
	> Mail: lanniaoershi@gmail.com 
	> Created Time: Tue 17 Mar 2015 11:00:41 UTC
 ************************************************************************/


#include"getSensorData.h"

static int dataFlow = 0;
static short data8bit = 0;
static short dataBuffer[88];
static short dataCount = 0;
static short Gdata[3] = {0};
static short Wdata[3] = {0};
static float G_Output[3] = {0};
static float W_Output[3] = {0};

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
			  handleDataScale();
			  break;
		case 1 :
			  handleDataScaleWithDebug();
			  break;
		default : 
			  return -1;
	}
	return 0;
}




void handleDataScale() {
	while (true) {
		decodeDataTo16Bit(readSensorData());
		
		G_Output[0] = (float) Gdata[0] / G_scale;
		G_Output[1] = (float) Gdata[1] / G_scale;
		G_Output[2] = (float) Gdata[2] / G_scale;

		W_Output[0] = (float) Wdata[0] / W_scale;
		W_Output[1] = (float) Wdata[1] / W_scale;
		W_Output[2] = (float) Wdata[2] / W_scale;
	}
}

void handleDataScaleWithDebug() {
	while (true) {
		decodeDataTo16Bit(readSensorData());
		
		G_Output[0] = (float) Gdata[0] / G_scale;
		G_Output[1] = (float) Gdata[1] / G_scale;
		G_Output[2] = (float) Gdata[2] / G_scale;

		W_Output[0] = (float) Wdata[0] / W_scale;
		W_Output[1] = (float) Wdata[1] / W_scale;
		W_Output[2] = (float) Wdata[2] / W_scale;
		showFakeGUI();
	}
}

void showFakeGUI() {
	printf("G: x = %8.3f\n   y = %8.3f\n   z = %8.3f\n\nW: x = %8.3f\n   y = %8.3f\n   z = %8.3f\n", G_Output[0],G_Output[1],G_Output[2],W_Output[0],W_Output[1],W_Output[2]);
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

