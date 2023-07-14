const int In1 = 2;
const int In2 = 4;
const int In3 = 5;
const int In4 = 7;
const int EnA = 3;
const int EnB = 6;
const int executeButton = 8;

//Para ambos casos de motores ya sea programacion en dúo o unitaria se van a programar tres direcciones de giro,
//éstas son en "sentido horario" (giran hacia adelante), sentido "anti horario" (giran hacia atras) y "parar" (para ambos motores).


//La función initBoard() inicializa los pines que van conectados al driver de motores de la placa DuinoBot, aunque podria
//aprovecharse para conectar a cualquier placa, esta debe ir obligatoriamente dentro del "setup" y mismo esta debe ser declarada
//antes que el "setup" de lo contrario fallaria. 
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
  
  //Para que la placa DuinoBot utilice el boton de ejecución hay que programarle un
  //"if" con la condición de que si no se presiona el boton asignado al boton de ejecución (pin 8 de Arduino Nano),
  //no se comience a ejecutar el programa que subimos a la placa,  de lo contario el programa subido iniciaria ni bien se le entregue 
  //la tension y corriente suficiente a la placa (cabe aclarar que se puede utilizar en cualquier placa pero es obligatorio utilizar esto en la placa DuinoBot).
  //El "if" con su respectiva condicion deben ir obligatoriamente en el "loop" ya que si se coloca en el "setup" fallaria el boton de ejecución
  if (digitalRead(executeButton) != HIGH) {
    loopDeMotores();  
  }
  
}


void loopDeMotores() {

  //El "while(true)" está puesto para que su cuerpo se ejecute en bucle de no estar puesto esto solo se ejecutaria una sola vez lo que pongamos en el cuerpo del "loop"
  while (true) {
    //girarMotores("CLOCKWISE", 255);
    girarMotor_EnSentido_AVelocidad_("Motor0", "CLOCKWISE", 255);
    girarMotor_EnSentido_AVelocidad_("Motor1", "COUNTER_CLOCKWISE", 200);
    delay(5000);
    //girarMotores("STOP", 255);
    girarMotor_EnSentido_AVelocidad_("Motor0", "STOP", 0);
    girarMotor_EnSentido_AVelocidad_("Motor1", "STOP", 0);
    delay(3000);
    //girarMotores("COUNTER_CLOCKWISE", 255);
    girarMotor_EnSentido_AVelocidad_("Motor0", "COUNTER_CLOCKWISE", 150);
    girarMotor_EnSentido_AVelocidad_("Motor1", "CLOCKWISE", 150);
    delay(5000);
    //girarMotores("STOP", 255);
    girarMotor_EnSentido_AVelocidad_("Motor0", "STOP", 0);
    girarMotor_EnSentido_AVelocidad_("Motor1", "STOP", 0);
    delay(3000);
    girarMotor_EnSentido_AVelocidad_("Motor0", "CLOCKWISE", 100);
    girarMotor_EnSentido_AVelocidad_("Motor1", "CLOCKWISE", 100);
    delay(5000);
    girarMotor_EnSentido_AVelocidad_("Motor0", "STOP", 0);
    girarMotor_EnSentido_AVelocidad_("Motor1", "STOP", 0);
    delay(3000);
  }
  
}

//En este caso se activan ambos motores al mismo tiempo por eso no es necesario asignar valores distintos a los motores
void girarMotores(int rotation , int SPEED) {
    
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
    
}

//En este caso es necesario diferenciar los amotores ya que se van a utilizar a programar uno a la vez
void girarMotor_EnSentido_AVelocidad_(int motor, int sentidoDeGiro, int SPEED) {
  
  //MOTOR0 = EnB, In3, In4
  if (motor == "Motor0") {
    if (sentidoDeGiro == "CLOCKWISE") {
    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);
    }
    else if (sentidoDeGiro == "COUNTER_CLOCKWISE") {
      digitalWrite(In4, HIGH);
      digitalWrite(In3, LOW);
    } 
    else if (sentidoDeGiro == "STOP") {
      digitalWrite(In3, LOW);
      digitalWrite(In4, LOW);
    }
    analogWrite(EnB,SPEED);
  } 

  //MOTOR1 = EnA, In1, In2
  if (motor == "Motor1") {
    if (sentidoDeGiro == "CLOCKWISE") {
    digitalWrite(In1, LOW);
    digitalWrite(In2, HIGH);
    }
    else if (sentidoDeGiro == "COUNTER_CLOCKWISE") {
      digitalWrite(In2, LOW);
      digitalWrite(In1, HIGH);
    } 
    else if (sentidoDeGiro == "STOP") {
      digitalWrite(In1, LOW);
      digitalWrite(In2, LOW);
    }
    analogWrite(EnA, SPEED);
  }
  
}  


  /*if (sentidoDeGiro == "CLOCKWISE") {
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
  }*/
