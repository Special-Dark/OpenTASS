LIBS = -lwiringPi -lpthread
OBJS = getSensorData.o stepperMotor.o
CFLAGS = -Wall
main: ${OBJS}
	gcc -o getSensorData ${OBJS} ${LIBS}
clean:
	rm -f getSensorData ${OBJS}
