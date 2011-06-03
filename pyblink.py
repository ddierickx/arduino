import serial
import time

arduino = serial.Serial('COM3', 9600)

while True:
	for i in range(1, 4):
		arduino.write(str(i))
		time.sleep(0.5)
		
	time.sleep(1)