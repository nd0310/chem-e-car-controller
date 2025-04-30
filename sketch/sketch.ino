#include <SPI.h>
#include <SD.h>

const int batteryVoltagePin = A0;
const int chipSelect = 4;
const char* logName = "datalog.txt";
const unsigned long interval = 500;



void setup() {
  Serial.begin(9600);

  while(!Serial);

  Serial.println("Init...");
  
  Serial.print("Init SD card... ");
  if(!SD.begin(chipSelect)) {
    Serial.println("Failed!");
    while(1);
  }

  Serial.println("Done!");
  
  Serial.print("Creating log File... ")
  if(SD.exists(logName)) {
    Serial.print(logName);
    Serial.println("already exists!");
  } else {
    Serial.print("Created ");
    Serial.println(logName);
    File dataFile = SD.open(logName, FILE_WRITE);
  }
}



void loop() {

}
