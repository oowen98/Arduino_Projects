#Python Code to Run Serial Communication between Jetson Nano and Arduino to the ESC of RC
import serial
import time

#Change ttyUSB1 depending on which USB Port the Arduino is connected to.
ser =  serial.Serial('/dev/ttyUSB1', 9600, timeout=10) 

while True:
	ThrottlePower = input('Throttle Power 0-180: ')
	print(ThrottlePower)
	ser.write(ThrottlePower.encode('utf-8'))


