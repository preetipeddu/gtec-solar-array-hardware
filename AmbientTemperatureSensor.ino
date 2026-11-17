#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

/*#include <SPI.h>
  #define BME_SCK 18
  #define BME_MISO 19
  #define BME_MOSI 23
  #define BME_CS 5*/

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("BME280 Test!"));

  bool status; 

  status = bme.begin(0x76);
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor - check wiring!");
    while (1);
  }

  Serial.println("-- Default Test! --");
  delayTime = 1000;

  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  printValues();
  delay(delayTime);
}

void printValues() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" degC");

  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.println();
}
