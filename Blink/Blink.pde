/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

int pin = 4;

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(pin, OUTPUT);     
  Serial.begin(9600);
}

void loop() {
  
  if (Serial.available() > 0)
  {
    int new_pin = Serial.read() - 47;
    Serial.println(new_pin, DEC);
    Serial.flush();
    
    pin = new_pin;
    pinMode(pin, OUTPUT);     
  }
  
  digitalWrite(pin, HIGH);   // set the LED on
  delay(100);              // wait for a second
  digitalWrite(pin, LOW);    // set the LED off
  delay(100);              // wait for a second
  
}
