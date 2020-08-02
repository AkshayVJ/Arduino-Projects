#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 3, TXPin = 4;
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps; // The TinyGPS++ object
SoftwareSerial ss(RXPin, TXPin);// The serial connection to the GPS device

void setup()
{
  Serial.begin(115200);// Setting Serial baud rate to 115200
  ss.begin(GPSBaud);// Begining GPS communication
}

void loop()
{
 // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }
 delay(100);
}

void displayInfo()
{
  Serial.print("Location: "); 
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 6);
    Serial.print(",");
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print("  Date/Time: ");
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.print(gps.date.year());
  }
  else
  {
    Serial.print("INVALID");
  }

  Serial.print(" ");
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print("0");
    Serial.print(gps.time.hour());
    Serial.print(":");
    if (gps.time.minute() < 10) Serial.print("0");
    Serial.print(gps.time.minute());
    Serial.print(":");
    if (gps.time.second() < 10) Serial.print("0");
    Serial.print(gps.time.second());
    Serial.print(".");
    if (gps.time.centisecond() < 10) Serial.print("0");
    Serial.print(gps.time.centisecond());
  }
  else
  {
    Serial.print("INVALID");
  }

  Serial.println();
}

 
