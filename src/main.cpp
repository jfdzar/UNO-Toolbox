#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>


#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature ds(&oneWire);

bool debug = true;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  delay(100);
  Serial.println("Starting");

  ds.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  
  ds.requestTemperatures();

  if(debug){Serial.println(ds.getTempCByIndex(0));}
  //if(debug){Serial.println(ds.getDeviceCount());}

  delay(5000);

}

