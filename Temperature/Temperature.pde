/*
An open-source LM35DZ Temperature Sensor for Arduino. This project will be enhanced on a regular basis
(cc) by Daniel Spillere Andrade , http://www.danielandrade.net
http://creativecommons.org/license/cc-gpl
*/

int temp_pin = 0;
int sensor_temp = 0;

void setup()
{
  Serial.begin(115200); // start serial communication
}

void loop()
{
  sensor_temp =  calc_temp(analogRead(temp_pin));
  Serial.println(sensor_temp, DEC);
  delay(250);
}

double calc_temp(int RawADC) {
  double value = log(((10240000/RawADC) - 10000));
  value = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * value * value ))* value );
  return ((value - 273.15) * 9.0)/ 5.0 + 32.0;
}
