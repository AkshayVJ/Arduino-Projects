int b_pin=12;// pin to connect buzzer
int s_pin=3;//pin to connect ir sensor
void setup() {
  // put your setup code here, to run once:
pinMode(b_pin,OUTPUT);//declare led pin as output
pinMode(s_pin,INPUT);//declare sensor pin as input
Serial.begin(9600);//start serial communication with baud rate 9600
}

void loop() {
  // put your main code here, to run repeatedly:
int s_val=digitalRead(s_pin);//reads value from spin to sensorvalue
 if(s_val==1)
 {
   digitalWrite(b_pin,HIGH);//Turn on the buzzer
   Serial.println("Buzzer is ON");//prints on the serial monitor
 }
 else
 {
   digitalWrite(b_pin,LOW);//Turn off the buzzer
   Serial.println("Buzzer is OFF");//prints on the serial monitor
 }

}
