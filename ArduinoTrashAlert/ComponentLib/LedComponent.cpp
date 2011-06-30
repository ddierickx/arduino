#include "WProgram.h"
#include "LedComponent.h"

LedComponent::LedComponent(String component_name, int ledpin):ArduinoComponent(component_name, 1)
{
  pin = ledpin;
  state = false;
}

void LedComponent::setup()
{
  pinMode(pin, OUTPUT);
}

void LedComponent::loop()
{
   digitalWrite(pin, (state ? HIGH : LOW));
}

void LedComponent::on()
{
  state = true;
}

void LedComponent::off()
{
  state = false;
}

boolean LedComponent::isOn()
{
  return state;
}

void LedComponent::setOn(boolean on)
{
  state = on;
}
