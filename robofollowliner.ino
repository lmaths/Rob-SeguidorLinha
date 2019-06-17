/*DECLARAÇÃO DE VARIAVEIS*/



#define MotorA_sentido1 2 //esquerda
#define MotorA_sentido2 4  //esquerda
#define MotorB_sentido1 8 // direita
#define MotorB_sentido2 9 //direita
#define MotorA_PWM 3  
#define MotorB_PWM 10  
 
#define veloc0 0
#define veloc1 90
#define veloc2 180    
#define veloc3 255
 
#define Sensor_direita 7
#define Sensor_esquerda 5
bool direita, esquerda;

unsigned long time;

 
void setup() {
  Serial.begin(9600);
  pinMode(MotorA_sentido1, OUTPUT);
  pinMode(MotorA_sentido2, OUTPUT);
  pinMode(MotorB_sentido1, OUTPUT);
  pinMode(MotorB_sentido2, OUTPUT);
  pinMode(MotorA_PWM, OUTPUT);
  pinMode(MotorB_PWM, OUTPUT);
  pinMode(Sensor_direita, INPUT);
  pinMode(Sensor_esquerda, INPUT);
  
}


void loop() {

  time = millis();

  int tempo = time / 1000;
  Serial.println(tempo);
  delay(1000);


  digitalWrite(MotorA_sentido1, HIGH);
  digitalWrite(MotorA_sentido2, LOW);
  digitalWrite(MotorB_sentido1, HIGH);
  digitalWrite(MotorB_sentido2, LOW);

   direita = digitalRead(Sensor_direita);
  esquerda = digitalRead(Sensor_esquerda);  

 if (direita == false && esquerda == false) {   //false == branco, true == preto inverter para true pois a pista será preta
  analogWrite(MotorA_PWM, veloc2);
  analogWrite(MotorB_PWM, veloc2);
  
 }else if (direita == true && esquerda == false){ // direita == false , esquerda == true
  analogWrite(MotorA_PWM, veloc2);
  analogWrite(MotorB_PWM, 0);
 
 }else if(direita == false && esquerda == true) { // direita == true , esquerda == false
  analogWrite(MotorA_PWM, 0);
  analogWrite(MotorB_PWM, veloc2);
 }//else if (direita == true && esquerda == true) { condição caso seja necessario que os dois sensores sejam branco nas encruzilhadas = trocar pra false 
  
  //analogWrite(MotorA_PWM, veloc2);  // continua andando
  //analogWrite(MotorB_PWM, veloc2);
 //}//else if(tempo == 20) { condição pra parar de acordo com a volta na chegada, trocar o tempo
   // analogWrite(MotorA_PWM, 0); // para os dois motores
 // analogWrite(MotorB_PWM, 0); para os dois motores
 //}
   

  

  
}
