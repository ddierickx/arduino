/*
  BlinkingComponent.h - Simple blinking component
*/
#ifndef LedComponent_h
#define LedComponent_h

#include "ArduinoComponent.h"
#include "WProgram.h"

class LedComponent : public ArduinoComponent
{
   public:
     LedComponent(String name, int ledpin);
     void setup();
     void loop();
     void on();
     void off();
     void setOn(boolean on);
     boolean isOn();
   protected:
     int pin;
     boolean state;
};

#endif
