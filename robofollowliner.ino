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

  digitalWrite(MotorA_sentido1, HIGH);
  digitalWrite(MotorA_sentido2, LOW);
  digitalWrite(MotorB_sentido1, HIGH);
  digitalWrite(MotorB_sentido2, LOW);

   direita = digitalRead(Sensor_direita);
  esquerda = digitalRead(Sensor_esquerda);  

 if (direita == false && esquerda == false) {
  analogWrite(MotorA_PWM, veloc2);
  analogWrite(MotorB_PWM, veloc2);
  
 }else if (direita == true && esquerda == false){
  analogWrite(MotorA_PWM, veloc2);
  analogWrite(MotorB_PWM, 0);
 
 }else if(direita == false && esquerda == true) {
  analogWrite(MotorA_PWM, 0);
  analogWrite(MotorB_PWM, veloc2);
 }
   

  

  
}
