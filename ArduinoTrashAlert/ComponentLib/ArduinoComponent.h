/*
  ArduinoComponent.h - Library for Arduino Application Development
*/
#ifndef ArduinoComponent_h
#define ArduinoComponent_h

#include "WProgram.h"

class ArduinoComponent
{
  public: 
    ArduinoComponent(String name, unsigned long loop_interval);
    virtual void setup() {};
    virtual void loop() {};
    String getName();
    unsigned long getInterval();
    unsigned long getLastExec();
    void setInterval(unsigned long value);
    void setLastExec(unsigned long value);
  protected:
    unsigned long interval;
    unsigned long lastexec;
    String name;
};

#endif
