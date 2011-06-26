#include "ArduinoApp.h"
#include <new.cpp>
#include "BlinkingComponent.h"
#include "LedHeartbeatComponent.h"

ArduinoApp app;
BlinkingComponent blinker ("blinker 1", 1000, 4);
LedHeartbeatComponent fader ("fader 1", 5000, 3);

void setup()
{
  Serial.begin(9600);
  app.registerComponent(&blinker);
  app.registerComponent(&fader);
  app.setup();
}

void loop()
{  
  app.loop();
}

