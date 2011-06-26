#include "WProgram.h"
#include "LedHeartbeatComponent.h"

const int REFRESH_RATE = 5; //5ms
int past_millis = 0;
int direction = +1;

LedHeartbeatComponent::LedHeartbeatComponent(String component_name, unsigned long period, int ledpin)
                                                              :ArduinoComponent(component_name, REFRESH_RATE)
{
  fade_period = period;
  pin = ledpin;
}

void LedHeartbeatComponent::setup()
{
  pinMode(pin, OUTPUT);
}

void LedHeartbeatComponent::loop()
{
  int value = 0;
  
  past_millis += REFRESH_RATE;
  
  if (past_millis > fade_period)
  {
    direction *= -1;
    past_millis = 0;
  }
  
  value = map(past_millis, 0, fade_period, 0, 255);
  
  if (direction == -1)
     value = 255-value;
  
  analogWrite(pin, value);
}

