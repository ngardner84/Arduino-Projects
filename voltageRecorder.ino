/*
 * Written 11/15/18 Nathan Gardner
 * 
 * Voltage output to SD file
 * This program measures voltage from a sensor and records it into a text file on an SD card every
 * 5 seconds with a timestamp
 * 
 * SD card is attached to Arduino in the following manner:
 * MISO - pin 12
 * MOSI - pin 11
 * SCK - pin 13
 * CS - pin 4
 */
//SD card library for Arduino
#include <SPI.h>
#include <SD.h>

File voltageFile;
int seconds;
const float maxVolts = 5.0; //maximum amount of volts allowed on Arduino
const int voltagePin = 0; //analog pin for voltage reading


void setup() {
  //Opens serial communications and waits for the port to connect
  Serial.begin(9600);
  while (!Serial) {
    ; 
  }

  Serial.println("Initializing the SD card");

  if (!SD.begin(4)) {
    Serial.println("Initialization failed");
    while (1);
  }
  
}

//gets voltage from the analog port
float getVoltage(){
  int value = analogRead(voltagePin);
  //arduino takes in analog readings as a value between 0 and 1023, convert into actual voltage below
  float voltage = (value / 1023.0) * maxVolts;
  return voltage;
}

//gets voltage and writes it to file
void writeVoltage(){
  //creates and opens the voltage log file
  voltageFile = SD.open("voltage.txt", FILE_WRITE);
  //check to make sure the file opened
  if (voltageFile){
    Serial.println("Writing voltage level");
    voltageFile.println(getVoltage());
    //close file
    voltageFile.close();
    Serial.println("Finished writing");
  }
  else{
    Serial.println("Error opening file");
    while(1);
  }
}

//gets time since the arduino has been running the current program and returns it in seconds
float getTime(){
  seconds = millis() / 1000;
  return seconds;
}



void loop() {
    writeVoltage();
    Serial.println(getVoltage());
    delay(5000);
    
}
