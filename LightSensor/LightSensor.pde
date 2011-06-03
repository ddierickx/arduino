#include <SdFat.h>

long current_delay = 0;

//Analog
int lsr_pin = 3;
int tem_pin = 4;
long MEASURE_DELAY = 1000;
long previous_millis = 0;

//Digital
int pauseled_pin = 7;
int pausebtn_pin = 8;

int lsr_value = 0;
double tem_value = 0.0;
char fileName[] = "LOG.TXT";

boolean paused = false;
int previous_btnPauseState = 0;

SdFat sd;

void setup(){
  pinMode(lsr_pin, INPUT);
  pinMode(tem_pin, INPUT);

  pinMode(pauseled_pin, OUTPUT);
  pinMode(pausebtn_pin, INPUT);
 
  sd.init(SPI_HALF_SPEED);
  
  Serial.begin(9600);
}

void loop(){

  current_delay += millis() - previous_millis;
  previous_millis = millis();
/*    
  int current_btnPauseState = digitalRead(pausebtn_pin);
  
  if (previous_btnPauseState != current_btnPauseState)
  {
      if (current_btnPauseState == HIGH)
      {
        paused = !paused;
        Serial.println("State changed");
      }
      
      previous_btnPauseState = current_btnPauseState;
  }

  if (paused)
  {
      digitalWrite(pauseled_pin, HIGH);
  } else
  {
      digitalWrite(pauseled_pin, LOW);
  }
*/   
  if ( (current_delay >= MEASURE_DELAY) && (!paused) )
  {
    readSensors();
    current_delay = 0;
  }
}

void readSensors()
{
  lsr_value = analogRead(lsr_pin);
  tem_value = calc_temp(analogRead(tem_pin));
 
  Serial.print(lsr_value, DEC);
  Serial.print(" ");
  Serial.print(tem_value, 2);
  Serial.print("\n");
  
  writeToSd();
}

void writeToSd()
{
  ofstream sdout(fileName, ios::out | ios::app);
  unsigned long time = millis();
  sdout << time << " " << lsr_value << " " << tem_value << "\n";
  sdout.close();
}


double calc_temp(int RawADC) {
  return (RawADC / 4.0) - 20.5;
}
