#include <Servo.h>

Servo myservo;

void setup()
{
  myservo.attach(2);
  myservo.write(0);
  delay(1000);
}
void loop()
{  
  myservo.write(180);
  delay(500);
  myservo.write(0);
  delay(500);
}
