const int In1 = 2;
const int In2 = 4;
const int In3 = 5;
const int In4 = 7;
const int EnA = 3;
const int EnB = 6;
const int executeButton = 8;



void initBoard() {
  Serial.begin(9600);
  pinMode(executeButton, INPUT_PULLUP);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);
  pinMode(EnA,OUTPUT);
  pinMode(EnB,OUTPUT); 
}

void setup() {  
  initBoard();
  
}

void loop() {
  if (digitalRead(executeButton) != HIGH) {
    loopDeMotores();  
  }
}

void loopDeMotores() {
  while (true) {
    //girarMotores("CLOCKWISE", 255);
    girarMotor_EnSentido_AVelocidad_("Motor0", "CLOCKWISE", 255);
    girarMotor_EnSentido_AVelocidad_("Motor1", "STOP", 0);
    delay(5000);
    //girarMotores("STOP", 255);
    girarMotor_EnSentido_AVelocidad_("Motor0", "STOP", 0);
    girarMotor_EnSentido_AVelocidad_("Motor1", "STOP", 0);
    delay(3000);
    //girarMotores("COUNTER_CLOCKWISE", 255);
    girarMotor_EnSentido_AVelocidad_("Motor0", "COUNTER_CLOCKWISE", 255);
    girarMotor_EnSentido_AVelocidad_("Motor1", "CLOCKWISE", 255);
    delay(5000);
    //girarMotores("STOP", 255);
    girarMotor_EnSentido_AVelocidad_("Motor0", "STOP", 0);
    girarMotor_EnSentido_AVelocidad_("Motor1", "STOP", 0);
    delay(3000);
    girarMotor_EnSentido_AVelocidad_("Motor0", "CLOCKWISE", 255);
    girarMotor_EnSentido_AVelocidad_("Motor1", "CLOCKWISE", 255);
    delay(5000);
    girarMotor_EnSentido_AVelocidad_("Motor0", "STOP", 0);
    girarMotor_EnSentido_AVelocidad_("Motor1", "STOP", 0);
    delay(3000);
  }
}

/*void girarMotores(int rotation , int SPEED) {
    if (rotation == "CLOCKWISE") {
          digitalWrite(In1, HIGH);
          digitalWrite(In3, LOW);
          digitalWrite(In2, LOW);
          digitalWrite(In4, HIGH);
      } 
     else if (rotation == "COUNTER_CLOCKWISE") {
          digitalWrite(In2, HIGH);
          digitalWrite(In4, LOW);
          digitalWrite(In1, LOW);
          digitalWrite(In3, HIGH);
      } 
     else if (rotation == "STOP") {
          digitalWrite(In1, LOW);
          digitalWrite(In2, LOW);
          digitalWrite(In3, LOW);
          digitalWrite(In4, LOW);
      }
    analogWrite(EnA, SPEED);
    analogWrite(EnB, SPEED);
    
}*/

void girarMotor_EnSentido_AVelocidad_(int motor, int sentidoDeGiro, int SPEED) {

  //"motor0" (EnA, In1, In2);
  //"motor1" (EnB, In3, In4);
  if (motor == "Motor0") {
    EnA;
    In1;
    In2;
  } 
  else if (motor == "Motor1") {
    EnB;
    In3;
    In4;
  }
  
  if (sentidoDeGiro == "CLOCKWISE") {
    digitalWrite(In1, HIGH);
    digitalWrite(In3, LOW);
    digitalWrite(In2, LOW);
    digitalWrite(In4, HIGH);
  }
  else if (sentidoDeGiro == "COUNTER_CLOCKWISE") {
    digitalWrite(In2, HIGH);
    digitalWrite(In4, LOW);
    digitalWrite(In1, LOW);
    digitalWrite(In3, HIGH);
  } 
  else if (sentidoDeGiro == "STOP") {
    digitalWrite(In1, LOW);
    digitalWrite(In2, LOW);
    digitalWrite(In3, LOW);
    digitalWrite(In4, LOW);
  }
    
  if (EnA) {
    analogWrite(EnA,SPEED);
  }
  
  if (EnB) {
    analogWrite(EnB, SPEED);
  }
}


