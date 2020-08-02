int lmf=l3;// pin to connect left motor forward
int lmr=l2;// pin to connect left motor reverse
int rmf=11;// pin to connect right motor forward
int rmr=10;// pin to connect right motor reverse
int x_pin=A0;// pin to connect x of accelerometer
int y_pin=A1;// pin to connect y of accelerometer

void setup() {
pinMode(lmf,OUTPUT);   //left motors forward
pinMode(lmr,OUTPUT);   //left motors reverse
pinMode(rmf,OUTPUT);   //right motors forward
pinMode(rmr,OUTPUT);   //right motors reverse
pinMode(x_pin,INPUT); 
pinMode(y_pin,INPUT);   

Serial.begin(9600);
 
}
void loop() {
int x=analogRead(x_pin);
int y=analogRead(y_pin);
Serial.print(x);
Serial.print(",");
Serial.println(y);

if( x>300 && y>300){            //move forward(all motors rotate in forward direction)
  digitalWrite(lmf,HIGH);
  digitalWrite(rmf,HIGH);
  digitalWrite(lmr,LOW);
  digitalWrite(rmr,LOW);
}
 
else if(x<200 && y<200){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(lmr,HIGH);
  digitalWrite(rmr,HIGH);
  digitalWrite(lmf,LOW);
  digitalWrite(rmf,LOW);
}
 
else if(x>300 && y>300){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(rmf,HIGH);
  digitalWrite(lmr,LOW);
  digitalWrite(rmr,LOW);
  digitalWrite(lmf,LOW);
}
 
else if(x>300 && y>300){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(lmf,HIGH);
  digitalWrite(lmr,LOW);
  digitalWrite(rmr,LOW);
  digitalWrite(rmf,LOW);
}
 
else if(x=300 && y=300){      //STOP (all motors stop)
  digitalWrite(lmf,LOW);
  digitalWrite(lmr,LOW);
  digitalWrite(rmf,LOW);
  digitalWrite(rmr,LOW);
}
delay(100);
}
