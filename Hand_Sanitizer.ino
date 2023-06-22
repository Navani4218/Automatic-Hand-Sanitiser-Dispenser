#include <Servo.h>

const int trigPin = 10;
const int echoPin = 11;
long duration;
int distance;
 
Servo myServo;
void setup() {
 
myServo.attach(12);
pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
Serial.begin(9600);

}

void loop() {

distance = calculateDistance();

  
myServo.write(0);
if ( distance < 10)
{ myServo.attach(12);
myServo.write(160);
delay(500);
myServo.write(0);
delay(1000);

}
else{
  myServo.detach();
}
Serial.println(distance);
}
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);
 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}
