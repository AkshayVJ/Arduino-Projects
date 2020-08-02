int l_pin=3;// pin to connect led
int s_pin=A0;//pin to connect LDR

void setup() {
  // put your setup code here, to run once:
pinMode(l_pin,OUTPUT);//declare buzzer pin as output
pinMode(s_pin,INPUT);//declare sensor pin as input
Serial.begin(9600);//start serial communication with baud rate 9600
}

void loop() {
  // put your main code here, to run repeatedly:
int s_val=digitalRead(s_pin);//reads value from spin to sensorvalue
 if(s_val<=200)
 {
   digitalWrite(b_pin,HIGH);//Turn on the buzzer
   Serial.println("Led is ON");//prints on the serial monitor
 }
 else
 {
   digitalWrite(b_pin,LOW);//Turn off the buzzer
   Serial.println("Led is OFF");//prints on the serial monitor
 }

}
