int led_pin=2;// pin to connect led
int ondelay=1000;//on delay time in milli sec
int offdelay=1000;//off delay time in milli sec

void setup() {
  // put your setup code here, to run once:
pinMode(led_pin,OUTPUT);//declare led_pin as output
Serial.begin(9600);//start serial communication with baud rate 9600
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led_pin,HIGH);//Turn on the led
Serial.println("LED IS ON");//prints on the serial monitor
delay(ondelay);
digitalWrite(led_pin,LOW);//Turn off the led
Serial.println("LED IS OFF");//prints on the serial monitor
delay(offdelay);

}
