int motor1 [2] = {7,8};
int motor2 [2] = {9,10};


#include <SoftwareSerial.h> //INCLUSÃO DE BIBLIOTECA






const int pinoRX = 2; //PINO DIGITAL 2 (RX)
const int pinoTX = 3; //PINO DIGITAL 3 (TX)
int dadoBluetooth = 0; //VARIÁVEL QUE ARMAZENA O VALOR ENVIADO PELO BLUETOOTH
 
SoftwareSerial bluetooth(pinoRX, pinoTX); //PINOS QUE EMULAM A SERIAL, ONDE
//O PINO 2 É O RX E O PINO 3 É O TX
 
void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600); //INICIALIZA A SERIAL DO BLUETOOTH
 

     

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  delay(100); 
  
}
 
void loop(){
 
    if(bluetooth.available())
    {
      dadoBluetooth = bluetooth.read(); 
      
      if(dadoBluetooth == '4'){ // Botão x no joystic
        Serial.println("Frente");
        motorAndaFrente(motor1);
        motorAndaFrente(motor2);
      }
      else if(dadoBluetooth == '1') // Botão quadrado no joystick
      {
        Serial.println("Trás");
        motorAndaAtras(motor1);
        motorAndaAtras(motor2);
      }
      else if(dadoBluetooth == 'W')// Botão setinha esquerda
      {
        
        Serial.println("Esquerda");
        motorAndaAtras(motor1);
        motorAndaFrente(motor2);
      }
      else if (dadoBluetooth == 'E') // Botão setinha direita
      {
        motorAndaAtras(motor2);
        motorAndaFrente(motor1);
      }
      else{
        desligaMotor(motor1);
        desligaMotor(motor2);
      }
  
      delay(10);
    }   
     else{
        desligaMotor(motor1);
        desligaMotor(motor2);
      }
  
}


void desligaMotor(int motor[2])
{
    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], LOW);
}

void motorAndaFrente(int motor [2]) //so um motor
{
    digitalWrite(motor[0], LOW);
    digitalWrite(motor[1], HIGH);
}


void motorAndaAtras(int motor[2]) //so um motor
{
  digitalWrite(motor[0], HIGH);
    digitalWrite(motor[1], LOW);
}
