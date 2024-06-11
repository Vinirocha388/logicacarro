#define pinMotor1A 2 // Pino do Motor 1A
#define pinMotor1B 3 // Pino do Motor 1B
#define pinMotor2A 4  // Pino do Motor 2A
#define pinMotor2B 5 // Pino do Motor 2B
#define pinBtRx 6     // Pino Rx do módulo Bluetooth
#define pinBtTx 7     // Pino Tx do módulo Bluetooth

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(pinBtRx, pinBtTx); // Cria uma instância de SoftwareSerial

void setup() {
  // Configura o estado das portas do Arduino como saídas para controlar os motores
  pinMode(pinMotor1A, OUTPUT);
  pinMode(pinMotor1B, OUTPUT);
  pinMode(pinMotor2A, OUTPUT);
  pinMode(pinMotor2B, OUTPUT);

  // Inicializa os pinos dos motores com LOW para garantir que os motores estejam desligados inicialmente
  digitalWrite(pinMotor1A, LOW);
  digitalWrite(pinMotor1B, LOW);
  digitalWrite(pinMotor2A, LOW);
  digitalWrite(pinMotor2B, LOW);

  // Inicia a comunicação serial para monitorar o que está acontecendo pelo monitor serial
  Serial.begin(9600);

  // Inicia a comunicação serial com o módulo Bluetooth
  bluetooth.begin(9600);
}

void loop() {
  // Variável para armazenar o dado recebido via Bluetooth
  char recebido;

  // Verifica se há dados disponíveis no módulo Bluetooth
  if (bluetooth.available()) {
    recebido = bluetooth.read(); // Lê o dado recebido via Bluetooth
    Serial.write(recebido);      // Envia o dado recebido para o monitor serial
    Serial.println("- ");        // Adiciona uma nova linha para facilitar a leitura no monitor serial
  }

  // Verifica o comando recebido e controla os motores
  if (recebido == 'F') {           // Se o comando for 'F' (frente)
    digitalWrite(pinMotor1A, LOW); // Ativa o Motor 1A
    digitalWrite(pinMotor1B, HIGH);  // Desativa o Motor 1B
    digitalWrite(pinMotor2A, HIGH); // Ativa o Motor 2A
    digitalWrite(pinMotor2B, LOW);  // Desativa o Motor 2B
  } else if (recebido == 'B') {    // Se o comando for 'B' (trás)
    digitalWrite(pinMotor1A, HIGH);  // Desativa o Motor 1A
    digitalWrite(pinMotor1B, LOW); // Ativa o Motor 1B
    digitalWrite(pinMotor2A, LOW);  // Desativa o Motor 2A
    digitalWrite(pinMotor2B, HIGH); // Ativa o Motor 2B
  } else if (recebido == 'L') {    // Se o comando for 'L' (esquerda)
    digitalWrite(pinMotor1A, HIGH);  // Desativa o Motor 1A
    digitalWrite(pinMotor1B, LOW); // Ativa o Motor 1B
    digitalWrite(pinMotor2A, HIGH); // Ativa o Motor 2A
    digitalWrite(pinMotor2B, LOW);  // Desativa o Motor 2B
  } else if (recebido == 'R') {    // Se o comando for 'R' (direita)
    digitalWrite(pinMotor1A, LOW); // Ativa o Motor 1A
    digitalWrite(pinMotor1B, HIGH);  // Desativa o Motor 1B
    digitalWrite(pinMotor2A, LOW);  // Desativa o Motor 2A
    digitalWrite(pinMotor2B, HIGH); // Ativa o Motor 2B
  } else if (recebido == 'S') {    // Se o comando for 'S' (parado)
    digitalWrite(pinMotor1A, LOW);  // Desativa o Motor 1A
    digitalWrite(pinMotor1B, LOW);  // Desativa o Motor 1B
    digitalWrite(pinMotor2A, LOW);  // Desativa o Motor 2A
    digitalWrite(pinMotor2B, LOW);  // Desativa o Motor 2B
  }
}
