int R_pin=3;// pin to connect Relay
int s_pin=A0;//pin to connect LM35

void setup() {
  // put your setup code here, to run once:
pinMode(R_pin,OUTPUT);//declare relay pin as output
pinMode(s_pin,INPUT);//declare sensor pin as input
Serial.begin(9600);//start serial communication with baud rate 9600
}

void loop() {
  // put your main code here, to run repeatedly:
int temp_val=digitalRead(s_pin);//reads value from spin to sensorvalue
 float temp=temp_val/2.048;
 Serial.print("The Temperature is :");//prints on the serial monitor
 Serial.println(temp);
 if(temp>=30)
  {
   digitalWrite(R_pin,HIGH);//Turn on the relay
   Serial.println("Relay IS ON");//prints on the serial monitor
  }
 else if(temp<30)
  {
   digitalWrite(R_pin,LOW);//Turn off the relay
   Serial.println("Relay IS OFF");//prints on the serial monitor
  }

}
