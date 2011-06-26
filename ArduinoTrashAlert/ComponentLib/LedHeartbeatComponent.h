/*
  BlinkingComponent.h - Simple blinking component
*/
#ifndef LedHeartbeatComponent_h
#define LedHeartbeatComponent_h

#include "ArduinoComponent.h"
#include "WProgram.h"

class LedHeartbeatComponent : public ArduinoComponent
{
   public:
     LedHeartbeatComponent(String name, unsigned long period, int ledpin);
     void setup();
     void loop();
   protected:
     int pin;
     unsigned long fade_period;
};

#endif
