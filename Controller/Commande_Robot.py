import serial

n = 50
ser = serial.Serial('COM12',115200,timeout=0.01)

for j in range(n):
    ser.write(b"2367")
    s = ser.read(100)
    print(s)



for i in range(10):

    for j in range(n):
        ser.write(b"15dg")
        s = ser.read(100)
        print(s)

    for j in range(n):
        ser.write(b"04dg")
        s = ser.read(100)
        print(s)

    for j in range(n):
        ser.write(b"bfch")
        s = ser.read(100)
        print(s)

    for j in range(n):
        ser.write(b"bf36")
        s = ser.read(100)
        print(s)

    for j in range(n):
        ser.write(b"ae36")
        s = ser.read(100)
        print(s)

    for j in range(n):
        ser.write(b"1527")
        s = ser.read(100)
        print(s)


ser.close()

##

import serial

n = 180
ser = serial.Serial('COM12',115200,timeout=0.01)




for i in range(3):

    for j in range(n):
        ser.write(b"0123efgh")
        s = ser.read(100)
        print(s)

    for j in range(n):
        ser.write(b"abcd4567")
        s = ser.read(100)
        print(s)


ser.close()

##
import serial
a = 0
ser = serial.Serial('COM12',115200,timeout=0.01)
while a < 100:
    i = input("=")
    ser.write(str.encode(i))
    s = ser.read(100)
    a += 1
ser.close()