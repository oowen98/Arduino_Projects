#include <Servo.h>

Servo ESC;

int PWM = 100; //Neutral Value
int PWM_prev = 100;
int neutral = 100;

void setup() {
  // put your setup code here, to run once:

  ESC.attach(4, 1000, 2000);

  Serial.begin(9600);
  while(!Serial){}


}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()>0){
    PWM = Serial.parseInt();
  }

  //180 = Maximum Forward Direction
  //100 = Neutral -> Need to be in neutral for 2 seconds before entering reverse
  //0   = Maximum Reverse Direction

  //Need to seperate wanting to brake only and wanting to reverse
  
  //Logic to prevent forward -> Reverse rightaway
  //Max brakes, and then 2 second pause, then reverse
  //Reverse Module
  /*
  if(PWM < 100 and PWM_prev >= 100){
    ESC.write(20);
    delay(500);
    ESC.write(neutral);
    delay(1000);
  }*/

  //Smooth Braking Module (Linear Function)
  if(PWM < 100 and PWM_prev >= 100){
    int Brake_Power = (100 - PWM); //0 (Full Brakes) - 100 (Coast)
    int count = 0;
    
    for(count = 0; count <= Brake_Power; (10*count++) ){
      ESC.write(100 - (PWM*count));
      delay(100); 
    }
  }



  //Logic to prevent Reverse -> Forward rightaway

  else if (PWM > 100 and PWM_prev <= 100){
    ESC.write(neutral);
    delay(500);
  }

  ESC.write(PWM);
  PWM_prev = PWM;

  Serial.println(PWM);

}
