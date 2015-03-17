#########################
# Author Utopia
# Date 2015-03-09
# Function :
#           Read data from serial port Txd, and decode data to hex or dec format.
import serial
import os
import ctypes
serialPort = serial.Serial('/dev/ttyAMA0', 9600)
array = []
#coefficientG = 32768 * 16 + 0.00 
coefficientG = 1
#coefficientA = 32768 * 2000+ 0.00
coefficientA = 1
while True :
    #print os.system("echo \"G data\" > ff.txt")
    os.system("echo \"hello world 11111\"")
    serialPort.open()
    
    try:
        if(len(array)>0) : 
            array[:] = [] 
        else :  
            while(len(array)<22) : 
                dataStream = serialPort.read()
                hexstr = "%s" % dataStream.encode('hex')
                decnum = (int)(hexstr, 16)
                f=open('sample.txt','a')
                #f.write(hexstr)
                array.append(decnum)
            #print "---> array len : %d . array conent : %s " %(len(array),array)
            g1 = ((array[3]<<8) | array[2]) / coefficientG
            g2 = ((array[5]<<8) | array[4]) / coefficientG
            g3 = ((array[7]<<8) | array[6]) / coefficientG
		    ctypes.c_int16(g1).value
			ctypes.c_int16(g2).value
			ctypes.c_int16(g3).value

            a1 = ((array[14]<<8) | array[13])/coefficientG
            a2 = ((array[16]<<8) | array[15])/coefficientG
            a3 = ((array[18]<<8) | array[17])/coefficientG
			ctypes.c_int16(a1).value
			ctypes.c_int16(a2).value
			ctypes.c_int16(a3).value

            #print os.system("echo \"G data\" {0} , {1} , {2} > aa.txt".format(g1,g2,g3))
            #print os.system("echo \"G data\" {0} , {1} , {2} >> aa.txt".format(a1,a2,a3))
            if array[1] == 81 :
                #print '-->Gdecode = %2f, %2f, %2f' % (g1, g2 ,g3)
                print os.system("echo \"G data\" {0} , {1} , {2} > aa.txt".format(g1,g2,g3))
            if array[12] == 82 :
                #print '-->Adecode = %2f, %2f, %2f' % (a1, a2 ,a3)
                print os.system("echo \"G data\" {0} , {1} , {2} >> aa.txt".format(a1,a2,a3))
                
    except:
        pass
    finally :
        serialPort.close()
