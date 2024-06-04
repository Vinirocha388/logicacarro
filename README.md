# Projeto Arduíno DeLorean

O código fornecido é para controlar um carro robô usando um Arduino e um módulo Bluetooth. Ele define pinos específicos no Arduino para controlar os motores e recebe comandos via Bluetooth para mover o carro em diferentes direções. Vamos analisar o código bloco a bloco.

### Definições de Pinos

Primeiro, o código define constantes para os pinos do Arduino que estão conectados aos motores e aos pinos de controle de velocidade. Isso facilita a leitura e manutenção do código, pois usamos nomes significativos em vez de números de pinos diretamente.

### Função `setup`

Na função `setup`, configuramos os pinos definidos anteriormente como saídas. Além disso, iniciamos a comunicação serial com uma taxa de transmissão de 9600 bps para permitir a comunicação com o módulo Bluetooth. Essa configuração é essencial para que o Arduino possa enviar e receber dados do módulo Bluetooth.

### Função `loop`

Na função `loop`, verificamos continuamente se há dados disponíveis na porta serial usando `Serial.available()`. Se houver dados, lemos o comando recebido via Bluetooth com `Serial.read()`, que retorna o caractere recebido. Dependendo do comando recebido ('F', 'B', 'L', 'R', 'S'), chamamos a função correspondente para mover o carro para frente, para trás, virar à esquerda, virar à direita ou parar.

### Funções de Movimento

#### Função `moveForward`

A função `moveForward` configura os pinos de controle dos motores para mover o carro para frente. Define a rotação dos motores para frente e ajusta a velocidade dos motores para a máxima.

#### Função `moveBackward`

A função `moveBackward` configura os motores para mover o carro para trás. A lógica é semelhante à da função `moveForward`, mas os sinais são invertidos para mudar a direção dos motores.

#### Função `turnLeft`

Para virar o carro para a esquerda, a função `turnLeft` para o motor do lado esquerdo enquanto o motor do lado direito gira para frente. Isso é feito configurando os pinos de controle adequadamente.

#### Função `turnRight`

Para virar o carro para a direita, a função `turnRight` gira o motor do lado esquerdo para frente enquanto o motor do lado direito fica parado. Novamente, isso é feito configurando os pinos de controle corretamente.

#### Função `stopCar`

A função `stopCar` para o carro, configurando todos os pinos de controle dos motores para baixo e definindo a velocidade dos motores para zero.

### Resumo

O código completo configura um Arduino para controlar um carro robô através de comandos recebidos via Bluetooth. Dependendo do comando recebido, o Arduino ajusta os motores para mover o carro na direção desejada ou para parar.
