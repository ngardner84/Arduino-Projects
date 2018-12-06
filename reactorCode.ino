//Written 12/5/2018 Nathan Gardner, Andres Aguilar
//Program to control the reactor on the chemical engineering car
#include <Servo.h>
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor
int LEDpin = 11;          // connect LED to pin 11 (PWM pin)        
int buttonState;
boolean firstTime=true;
float timeValue;
float newTimeValue;
float lastTimeValue=0.0;
float counter;
int motorPin = 5;

Servo myservo; // initializing servo variable
void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);
  myservo.attach(9); // servo to pin 9
  pinMode(motorPin, OUTPUT);
  
}

void loop(void) {
  while (firstTime == true) {
    myservo.write(180);
     photocellReading = analogRead(photocellPin);
     Serial.println(photocellReading);
     digitalWrite(motorPin, LOW);
     if(photocellReading > 30){
      firstTime = false;
      counter = 0.0;
     }
  }
  while (firstTime == false) {
    photocellReading = analogRead(photocellPin);
    myservo.write(0);
    Serial.print("Time elapsed: ");
    Serial.println(counter / 20);
    if (photocellReading < 30) {
      firstTime = true;  
    }
    counter = counter + 1;
    delay(50);
    digitalWrite(motorPin, HIGH);
    
  }
  
}
