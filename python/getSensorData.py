# Author Utopia
# Date 2015-03-09
# Function:
#          Read data from serial port Txd, and decode data to hex or dec format.
import serial
serialPort = serial.Serial('/dev/ttyAMA0', 9600)
while True :
    try:
        dataStream = serialPort.read()
        hexstr = "%s" % dataStream.encode('hex')
        decnum = (int)(hexstr, 16)
        print(decnum)
    except:
        pass
