/* Photocell simple testing sketch.

  Connect one end of the photocell to 5V, the other end to Analog 0.
  Then connect one end of a 10K resistor from Analog 0 to ground
  Connect LED from pin 11 through a resistor to ground
  For more information see http://learn.adafruit.com/photocells */
#include <Servo.h>
int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
int photocellReading;     // the analog reading from the sensor divider
int LEDpin = 11;          // connect Red LED to pin 11 (PWM pin)
int LEDbrightness;        //
int val; // for mapping the direction of the potentiomiter.
int potPin = 1;
int buttonState;
float counter;

Servo myservo; // initializing servo variable
void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);
  myservo.attach(9); // servo to pin 9
}

void loop(void) {
  
  buttonState = analogRead(potPin);
  Serial.println(buttonState);
 counter=0;
 myservo.write(0);
  while (buttonState >1000) {
     counter=counter+1;
     buttonState = analogRead(potPin);
     photocellReading = analogRead(photocellPin);
     myservo.write(180);
     Serial.println("on");
    //Serial.print("Analog reading = ");
    //Serial.println(photocellReading);     // the raw analog reading
    if (photocellReading < 20) {
      Serial.print("Time elapsed: ");
      Serial.println(counter/100);
    }
  delay(10);


    
  }
  delay(100);
}
