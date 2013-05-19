#include <Servo.h> 

const byte BUTTON_PIN = 7;
const byte SERVO_PIN = 9;

const int SERVO_MIN_PULSE = 650;
const int SERVO_MAX_PULSE = 2400;
const byte SERVO_CLOSED_ANGLE = 0;
const byte SERVO_OPEN_ANGLE = 180;
const int SERVO_OPEN_TIME = 500;

Servo trebuchetServo;
 
void setup() 
{ 
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);  
  trebuchetServo.attach(SERVO_PIN, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
  trebuchetServo.write(SERVO_CLOSED_ANGLE);
} 
 
 
void loop() 
{ 
  int buttonState = digitalRead(BUTTON_PIN);
  
  if (buttonState == HIGH) {
    Serial.println("Down");
    trebuchetServo.write(SERVO_OPEN_ANGLE);
    delay(SERVO_OPEN_TIME);
    trebuchetServo.write(SERVO_CLOSED_ANGLE);
  } 
}
