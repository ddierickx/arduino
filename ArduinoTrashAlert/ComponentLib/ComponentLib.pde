#include "ArduinoApp.h"
#include <new.cpp>
#include "BlinkingComponent.h"
#include "LedHeartbeatComponent.h"
#include "LedComponent.h"

ArduinoApp app;
BlinkingComponent blinker ("blinker 1", 1000, 4);
LedComponent redLed ("red led", 3);

void setup()
{
  Serial.begin(9600);
  app.registerComponent(&blinker);
  app.registerComponent(&redLed);
  app.setup();
}

unsigned long prevmillis = 0;

void loop()
{
  app.loop();
   
  if (prevmillis - millis() > 1000) 
    redLed.off();
  else
    redLed.on();
  
  prevmillis = millis();
}

