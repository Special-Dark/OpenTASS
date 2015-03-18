LIBS = -lwiringPi
OBJS = getSensorData.o
CFLAGS = -Wall
main: ${OBJS}
	gcc -o getSensorData ${OBJS} ${LIBS}
clean:
	rm -f getSensorData ${OBJS}
