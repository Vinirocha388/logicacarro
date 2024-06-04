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

