#include "WProgram.h"
#include "ArduinoComponent.h"

ArduinoComponent::ArduinoComponent(String component_name, unsigned long loop_interval)
{
  name = component_name;
  interval = loop_interval; 
  lastexec = 0; 
}

unsigned long ArduinoComponent::getInterval()
{
  return interval;
}

unsigned long ArduinoComponent::getLastExec()
{
  return lastexec;
}

void ArduinoComponent::setInterval(unsigned long value)
{
  interval = value;
}

void ArduinoComponent::setLastExec(unsigned long value)
{
  lastexec = value;
}

String ArduinoComponent::getName()
{
  return name;
}
