#include "WProgram.h"
#include "BlinkingComponent.h"

BlinkingComponent::BlinkingComponent(String component_name, unsigned long interval, int ledpin):ArduinoComponent(component_name, interval)
{
  pin = ledpin;
  on = false;
}

void BlinkingComponent::setup()
{
  pinMode(pin, OUTPUT);
}

void BlinkingComponent::loop()
{
   digitalWrite(pin, (on ? HIGH : LOW));
   on = !on;
}
