int s_pin=A0;//pin to connect LDR
int dt=100;//delay tim in milli sec 
void setup() {
  // put your setup code here, to run once:
pinMode(s_pin,INPUT);//declare sensor pin as input
Serial.begin(9600);//start serial communication with baud rate 9600
}

void loop() {
  // put your main code here, to run repeatedly:
int temp_val=digitalRead(s_pin);//reads value from spin to sensorvalue
 float temp=temp_val/2.048;
 Serial.print("The Temperature is :");//prints on the serial monitor
 Serial.println(temp);
 delay(dt);
 
}
