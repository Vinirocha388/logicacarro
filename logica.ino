// Definição dos pinos de controle dos motores
#define IN1 2  // Pino 2 do Arduino conectado ao IN1
#define IN2 3  // Pino 3 do Arduino conectado ao IN2 
#define IN3 4  // Pino 4 do Arduino conectado ao IN3 
#define IN4 5  // Pino 5 do Arduino conectado ao IN4  
#define ENA 9  // Pino 9 do Arduino conectado ao ENA (PWM)
#define ENB 10 // Pino 10 do Arduino conectado ao ENB (PWM)

void setup() {
  // Configuração dos pinos como saída
  pinMode(IN1, OUTPUT);  // Define o pino IN1 como saída
  pinMode(IN2, OUTPUT);  // Define o pino IN2 como saída
  pinMode(IN3, OUTPUT);  // Define o pino IN3 como saída
  pinMode(IN4, OUTPUT);  // Define o pino IN4 como saída
  pinMode(ENA, OUTPUT);  // Define o pino ENA como saída
  pinMode(ENB, OUTPUT);  // Define o pino ENB como saída
  
  // Inicia a comunicação serial para o módulo Bluetooth
  Serial.begin(9600);  // Define a taxa de transmissão serial em 9600 bps
}

void loop() {
  // Verifica se há dados disponíveis na porta serial
  if (Serial.available() > 0) {
    // Lê o comando recebido via Bluetooth
    char command = Serial.read();  // Lê o caractere do buffer serial
    
    // Verifica qual comando foi recebido e chama a função correspondente
    switch(command) {
      case 'F': // Frente
        moveForward();  // Chama a função para mover o carro para frente
        break;
      case 'B': // Trás
        moveBackward();  // Chama a função para mover o carro para trás
        break;
      case 'L': // Esquerda
        turnLeft();  // Chama a função para virar o carro para a esquerda
        break;
      case 'R': // Direita
        turnRight();  // Chama a função para virar o carro para a direita
        break;
      case 'S': // Parar
        stopCar();  // Chama a função para parar o carro
        break;
    }
  }
}

void moveForward() {
  // Configura os motores para mover o carro para frente
  digitalWrite(IN1, HIGH);  // Motor 1 gira para frente
  digitalWrite(IN2, LOW);   // Motor 1 gira para frente
  digitalWrite(IN3, HIGH);  // Motor 2 gira para frente
  digitalWrite(IN4, LOW);   // Motor 2 gira para frente
  analogWrite(ENA, 255);    // Define a velocidade máxima para os motores conectados 
  analogWrite(ENB, 255);    // Define a velocidade máxima para os motores conectados 
}

void moveBackward() {
  // Configura os motores para mover o carro para trás
  digitalWrite(IN1, LOW);   // Motor 1 gira para trás
  digitalWrite(IN2, HIGH);  // Motor 1 gira para trás
  digitalWrite(IN3, LOW);   // Motor 2 gira para trás
  digitalWrite(IN4, HIGH);  // Motor 2 gira para trás
  analogWrite(ENA, 255);    // Define a velocidade máxima para os motores conectados 
  analogWrite(ENB, 255);    // Define a velocidade máxima para os motores conectados 
}

void turnLeft() {
  // Configura os motores para virar o carro para a esquerda
  digitalWrite(IN1, LOW);   // Motor 1 parado
  digitalWrite(IN2, LOW);   // Motor 1 parado
  digitalWrite(IN3, HIGH);  // Motor 2 gira para frente
  digitalWrite(IN4, LOW);   // Motor 2 gira para frente
  analogWrite(ENA, 255);    // Define a velocidade máxima para os motores conectados (parado)
  analogWrite(ENB, 255);    // Define a velocidade máxima para os motores conectados
}

void turnRight() {
  // Configura os motores para virar o carro para a direita
  digitalWrite(IN1, HIGH);  // Motor 1 gira para frente
  digitalWrite(IN2, LOW);   // Motor 1 gira para frente
  digitalWrite(IN3, LOW);   // Motor 2 parado
  digitalWrite(IN4, LOW);   // Motor 2 parado
  analogWrite(ENA, 255);    // Define a velocidade máxima para os motores conectados 
  analogWrite(ENB, 255);    // Define a velocidade máxima para os motores conectados (parado)
}

void stopCar() {
  // Configura os motores para parar o carro
  digitalWrite(IN1, LOW);   // Motor 1 parado
  digitalWrite(IN2, LOW);   // Motor 1 parado
  digitalWrite(IN3, LOW);   // Motor 2 parado
  digitalWrite(IN4, LOW);   // Motor 2 parado
  analogWrite(ENA, 0);      // Define a velocidade 0 para os motores conectados (parado)
  analogWrite(ENB, 0);      // Define a velocidade 0 para os motores conectados (parado)
}
