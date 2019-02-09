//Written 02/09/2019 Nathan Gardner
//Program to control the entire car
#include <Servo.h>
int photocellPin = 0;
int photocellReading;
int transistorPin = 3;
float counter;
boolean firstTime = true;
Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(9); // servo to pin 9
  pinMode(transistorPin, OUTPUT);
}

void loop(void) {
  //sets servo to closed and turns motors off
  photocellReading = analogRead(photocellPin);
  if (firstTime = true) {
     photocellReading = analogRead(photocellPin);
     if (photocellReading > 800){
       firstTime = false;
     }
     myservo.write(180);
     digitalWrite(transistorPin, LOW);
     counter = 0.0;
  }
  else {
     photocellReading = analogRead(photocellPin);
     myservo.write(0);
     Serial.print("Time elapsed: ");
     Serial.println(counter / 20);
     if (photocellReading < 30) {
       firstTime = true;  
     }
     counter = counter + 1;
     delay(50);
     digitalWrite(transistorPin, HIGH);
  }
  
}
