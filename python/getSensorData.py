# Author Utopia
# Create Date 2015-03-09
# Function:
#          Read data from serial port Txd, and decode data to hex or dec format.

import serial
serialPort = serial.Serial('/dev/ttyAMA0', 9600)

count = 0
dataArray = []
while True :
    try:
        dataStream = serialPort.read()
        hexstr = "%s" % dataStream.encode('hex')
        #decnum = (int)(hexstr, 16)
        #print(decnum)
        dataArray.append(hexstr)
        count += 1
        if count == 11 :
            if dataArray[1] == '51' :
                print 'G = ', dataArray
            else :
                print 'A = ', dataArray
                print
            while len(dataArray) > 0 :
                del dataArray[0]
            count = 0
 
    except:
        pass
