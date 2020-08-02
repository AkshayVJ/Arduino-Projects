#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.begin();// initialize the LCD, 
  lcd.backlight();// Turn on the blacklight and print a message.
  Serial.begin(9600);//Begin Serial Communication
}

void loop()
{

if(Serial.available())
{
  String mssg=Serial.readString();//Reads the value from Serial monitor

  lcd.clear();// Clear the Screen
  lcd.setCursor (0,0); // go to start of 1st Line
  lcd.print("THE MESSAGE IS :");
  lcd.setCursor (0,1); // go to start of 2nd line
  lcd.print(mssg);
  delay(500);
}

}
