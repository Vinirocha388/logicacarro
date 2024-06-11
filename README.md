# Projeto Arduíno DeLorean

Controle de Quatro Motores via Bluetooth
Este projeto Arduino permite controlar quatro motores DC utilizando um módulo Bluetooth. O código recebe comandos via Bluetooth para mover os motores em diferentes direções: frente, trás, esquerda, direita e parada. A comunicação entre o Arduino e o módulo Bluetooth é feita utilizando a biblioteca SoftwareSerial.

# Funcionalidades
Controle de quatro motores DC
Recebimento de comandos via Bluetooth
Comandos suportados: Frente (F), Trás (B), Esquerda (L), Direita (R), Parado (S)
Monitoramento da comunicação via Serial Monitor
Componentes Necessários
1 Arduino (Uno, Mega, etc.)
4 Motores DC
1 Módulo Bluetooth (HC-05 ou HC-06)
2 Pontes H (L298N ou similar) para controle dos motores
Cabos Jumper
Fonte de Alimentação (se necessário)
Conexões
Pinos do Arduino
pinMotor1A (Pino 2): Conectado ao Motor 1A na Ponte H
pinMotor1B (Pino 3): Conectado ao Motor 1B na Ponte H
pinMotor2A (Pino 4): Conectado ao Motor 2A na Ponte H
pinMotor2B (Pino 5): Conectado ao Motor 2B na Ponte H
pinMotor3A (Pino 8): Conectado ao Motor 3A na Ponte H
pinMotor3B (Pino 9): Conectado ao Motor 3B na Ponte H
pinMotor4A (Pino 10): Conectado ao Motor 4A na Ponte H
pinMotor4B (Pino 11): Conectado ao Motor 4B na Ponte H
pinBtRx (Pino 6): Conectado ao Tx do Módulo Bluetooth
pinBtTx (Pino 7): Conectado ao Rx do Módulo Bluetooth
Conexão do Módulo Bluetooth
Rx do Bluetooth -> pinBtTx (Pino 7 do Arduino)
Tx do Bluetooth -> pinBtRx (Pino 6 do Arduino)
VCC do Bluetooth -> 5V do Arduino
GND do Bluetooth -> GND do Arduino
Conexão das Pontes H (L298N)
Para cada Ponte H:

Ponte H 1:

IN1 -> pinMotor1A (Pino 2 do Arduino)
IN2 -> pinMotor1B (Pino 3 do Arduino)
IN3 -> pinMotor2A (Pino 4 do Arduino)
IN4 -> pinMotor2B (Pino 5 do Arduino)
VCC -> Fonte de Alimentação (se necessário)
GND -> GND do Arduino e Fonte de Alimentação
Ponte H 2:

IN1 -> pinMotor3A (Pino 8 do Arduino)
IN2 -> pinMotor3B (Pino 9 do Arduino)
IN3 -> pinMotor4A (Pino 10 do Arduino)
IN4 -> pinMotor4B (Pino 11 do Arduino)
VCC -> Fonte de Alimentação (se necessário)
GND -> GND do Arduino e Fonte de Alimentação
Como Usar
Carregar o Código:

Conecte seu Arduino ao computador.
Abra o Arduino IDE.
Copie e cole o código no editor da IDE.
Carregue o código no Arduino.
Configurar o Bluetooth:

Conecte o módulo Bluetooth aos pinos especificados.
Emparelhe o módulo Bluetooth com seu dispositivo (smartphone, tablet, etc.).
Enviar Comandos:

Utilize um aplicativo de terminal Bluetooth no seu dispositivo emparelhado.
Envie os comandos (F, B, L, R, S) para controlar os motores.
Monitoramento
Abra o Serial Monitor na Arduino IDE para ver os comandos recebidos e monitorar a operação do sistema.

### Resumo

O código completo configura um Arduino para controlar um carro robô através de comandos recebidos via Bluetooth. Dependendo do comando recebido, o Arduino ajusta os motores para mover o carro na direção desejada ou para parar.

![image](https://github.com/Vinirocha388/logicacarro/assets/158187426/92c3f3c6-2e47-4e8d-80f4-9e602e998be7)

![image](https://github.com/Vinirocha388/logicacarro/assets/158187426/c0166e30-2e0b-4512-b498-44499d03708c)




