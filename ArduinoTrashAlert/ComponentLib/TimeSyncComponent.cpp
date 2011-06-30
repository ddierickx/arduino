#include "WProgram.h"
#include "TimeSyncComponent.h"
#include "Time.h"


#define TIME_MSG_LEN  11   // time sync to PC is HEADER followed by unix time_t as ten ascii digits
#define TIME_HEADER  'T'   // Header tag for serial time sync message
#define TIME_PRINT_REQUEST 'P'
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 

TimeSyncComponent::TimeSyncComponent(String component_name):ArduinoComponent(component_name, 1)
{
}

void TimeSyncComponent::setup()
{
}

void TimeSyncComponent::loop()
{
  if (Serial.available())
  {
    processSyncMessage();
  }
}

void TimeSyncComponent::processSyncMessage() {
  // if time sync available from serial port, update time and return true
  while(Serial.available() >=  TIME_MSG_LEN ){  // time message consists of a header and ten ascii digits
    char c = Serial.read() ; 
    Serial.print(c);  
    if( c == TIME_HEADER ) {       
      time_t pctime = 0;
      for(int i=0; i < TIME_MSG_LEN -1; i++){   
        c = Serial.read();          
        if( c >= '0' && c <= '9'){   
          pctime = (10 * pctime) + (c - '0') ; // convert digits to a number    
        }
	
	Serial.println("Time received, thx!");
	printTime();
      } else if (c == TIME_PRINT_REQUEST)
      {
	printTime();
      }
	
      setTime(pctime);   // Sync Arduino clock to the time received on the serial port
    }  
  }
}

void printTime()
{
	time_t = now();
	String timeString = (String)year(now) 
                            + "-" + (String)month(now) 
                            + "-" + (String)day(now) 
                            + " " + (String)hour(now) 
                            + ":" + (String)minute(now) 
                            + ":" + (String)second(now);
	Serial.println("Current time: " + timeString);
}
