import serial
import time
import eeml

API_KEY = 'lN2sJ05rlgivbMGnIRVel8NBMKJtVwHH2_ngHq-O_D8'
API_URL = '/v2/feeds/25975.xml'

def run(measure_delay, transmit_delay):
	arduino = serial.Serial('COM3', 9600)
	temps = []
	lights = []
	delay = 0.0

	while True:
		try:
			start = time.clock()
			parseData(arduino.readline(), temps, lights)
			delay += (time.clock() - start)
			
			if (delay >= transmit_delay):
				pachube(sensors(temps, lights))
				# RESET
				delay = 0
				temps = []
				lights = []
		except Exception as e:
			print e
		else:
			time.sleep(measure_delay)
			delay += measure_delay

#Submit data to pachube.com
def pachube(sensors):
	temp, light = sensors
	print str(temp) + " C - " + str(light)
	pac = eeml.Pachube(API_URL, API_KEY)
	pac.update([eeml.Data(1, temp, 'C'), eeml.Data(2, light, '')])
	pac.put()
		
def parseData(data, temps, lights):
	lights.append(float(data.strip().split(" ")[0]))
	temps.append(float(data.strip().split(" ")[1]))
	
def sensors(temps, lights):
	return (sum(temps) / len(temps)), (sum(lights) / len(lights))
	

run(0.2, 35)