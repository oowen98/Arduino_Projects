#include <Servo.h>

Servo Servo1;

int PWM = 0;
int PWM_return = 0;

void setup() {
  // put your setup code here, to run once:

  Servo1.attach(5, 1000, 2000);

  Serial.begin(9600);

  while(!Serial){}

}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available() > 0){
    PWM = Serial.parseInt();
  }

//75-80 = Centre, 180 = Fully Right, 0 = Fully Left
  Servo1.write(PWM);
  

}
