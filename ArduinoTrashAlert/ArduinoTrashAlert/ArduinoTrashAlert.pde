#include <ArduinoApp.h>
#include <ArduinoComponent.h>
#include <LedComponent.h>
#include <TimeSyncComponent.h>
#include <new.cpp>
#include <Time.h>

ArduinoApp app;
LedComponent redLed("RED LED", 3);
LedComponent greenLed("GREEN LED", 4);
LedComponent yellowLed("YELLOW LED", 5);
LedComponent blueLed("BLUE LED", 6);
LedComponent whiteLed("WHITE LED", 7);
TimeSyncComponent timeSyncComponent("TIME SYNC");

void setup()
{
  Serial.begin(9600);
  registerComponents();
  app.setup();
}

void registerComponents()
{   
  app.registerComponent(&redLed);
  app.registerComponent(&greenLed);
  app.registerComponent(&yellowLed);
  app.registerComponent(&blueLed);
  app.registerComponent(&whiteLed);
  app.registerComponent(&timeSyncComponent);
}

void loop()
{
  app.loop();
  char line[] = "0B071A15";
  unsigned long data = strtoul(line, NULL, 16);
  redLed.setOn(!!((data) & (1 << (0))));
  greenLed.setOn(!!((data) & (1 << (1))));
  yellowLed.setOn(!!((data) & (1 << (2))));
  blueLed.setOn(!!((data) & (1 << (3))));
  whiteLed.setOn(!!((data) & (1 << (4))));
}
