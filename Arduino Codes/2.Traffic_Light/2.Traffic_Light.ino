int led_1=2;// pin to connect red led
int led_2=3;// pin to connect yellow led
int led_3=4;// pin to connect green led
int delaytime=1000;//delay time in milli sec


void setup() {
  // put your setup code here, to run once:
pinMode(led_1,OUTPUT);//declare led_1 as output
pinMode(led_2,OUTPUT);//declare led_2 as output
pinMode(led_3,OUTPUT);//declare led_3 as output
Serial.begin(9600);//start serial communication with baud rate 9600
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led_3,LOW);//Turn off the green led
digitalWrite(led_1,HIGH);//Turn on the red led
Serial.println("RED LED IS ON");//prints on the serial monitor
delay(delaytime);
digitalWrite(led_1,LOW);//Turn off red the led
digitalWrite(led_2,HIGH);//Turn on the yellow led
Serial.println("YELLOW LED IS ON");//prints on the serial monitor
delay(delaytime);
digitalWrite(led_2,LOW);//Turn off the yellow led
digitalWrite(led_3,HIGH);//Turn on the green led
Serial.println("GREEN LED IS ON");//prints on the serial monitor
delay(delaytime);
}
