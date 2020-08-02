int R_pin=3;// pin to connect Relay
int val=0;// variable to store serial input
void setup() {
  // put your setup code here, to run once:
pinMode(R_pin,OUTPUT);//declare relay pin as output
Serial.begin(9600);//start serial communication with baud rate 9600
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())
{
  val=Serial.read();
}
 if(val==1)
  {
   digitalWrite(R_pin,HIGH);//Turn on the relay
   Serial.println("Relay IS ON");//prints on the serial monitor
  }
 else if(val==0)
  {
   digitalWrite(R_pin,LOW);//Turn off the relay
   Serial.println("Relay IS OFF");//prints on the serial monitor
  }
 else
  {
   Serial.println("Invalid Input");
  }


}
