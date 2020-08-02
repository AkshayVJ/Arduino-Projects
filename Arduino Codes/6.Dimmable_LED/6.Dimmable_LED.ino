int l_pin=9;// PWM pin to connect led
int s_pin=A0;//pin to connect POT

void setup() {
  // put your setup code here, to run once:
pinMode(l_pin,OUTPUT);//declare led pin as output
pinMode(s_pin,INPUT);//declare sensor pin as input
Serial.begin(9600);//start serial communication with baud rate 9600
}

void loop() {
  // put your main code here, to run repeatedly:
int s_val=digitalRead(s_pin);//reads value from spin to sensorvalue
int l_val=map(s_val,0,1024,0,255);//function to map potentiometer range to led voltage range
analogWrite(l_pin,l_val);//Control the brightness of the led
}
