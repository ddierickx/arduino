import arduinoSerial
import time

arduino = arduinoSerial.Serial('COM3', timeout=9600)
value = "T" + str(int(time.time()))
print "Sending " + value
arduino.write(value)
arduino.flush()
print "Sent!"

data = " "

while data != "":
	print data
	data = arduino.readline(2000)