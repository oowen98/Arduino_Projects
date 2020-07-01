#Python Code to Run Serial Communication between Jetson Nano and Arduino to the Servo of RC
import serial
import time

#Change ttyUSB1 depending on which USB Port the Arduino is connected to.
ser =  serial.Serial('/dev/ttyUSB1', 9600, timeout=10) 

while True:
	ServoAngle = input('Servo Angle: 0 - 180: ')
	print(ServoAngle)
	ser.write(ServoAngle.encode('utf-8'))


