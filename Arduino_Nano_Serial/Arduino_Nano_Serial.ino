void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  while(!Serial){
  //Wait for serial port to connect
  //println("Waiting for Serial to connect");
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  char buffer[16];
  //Receiving a command from the nano to turn on / off the LED

  if (Serial.available() > 0){
    int size = Serial.readBytesUntil('\n', buffer, 12);

    if(buffer[0] == 'Y'){
      digitalWrite(LED_BUILTIN, HIGH);
    }

    if(buffer[0] == 'N'){
      digitalWrite(LED_BUILTIN, LOW);
    }

    
  }


}
