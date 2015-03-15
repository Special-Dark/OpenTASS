#########################
# Author Utopia
# Date 2015-03-09
# Function :
#           Read data from serial port Txd, and decode data to hex or dec format.
import serial
serialPort = serial.Serial('/dev/ttyAMA0', 9600)
count = 0
array = []
while True :
    try:
        dataStream = serialPort.read()
        hexstr = "%s" % dataStream.encode('hex')
        decnum = (int)(hexstr, 16)
        #f=open('sample.txt','a')
        #f.write(hexstr)
        array.append(decnum)
        count += 1
        if count == 11 :
            if array[1] == 81 :
                print 'G = ', array,
                print '-->Gdecode = %d, %d, %d' % (((array[3]<<8) | array[2]), ((array[5]<<8) | array[4]), ((array[7]<<8) | array[6])) 
            else :
                print 'A = ', array,
                print '-->Adecode = %d, %d, %d' % (((array[3]<<8) | array[2]), ((array[5]<<8) | array[4]), ((array[7]<<8) | array[6])) 
                print
            while len(array) > 0 :
                del array[0]
            count = 0
    except:
        pass
