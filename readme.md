# Semáforo com Raspberry Pi Pico

Este projeto simula um semáforo usando o Raspberry Pi Pico com LEDs de cores vermelho, azul e verde. O semáforo alterna entre diferentes configurações de LEDs e pode ser controlado por um botão.

## Funcionalidade

- O semáforo começa com **todos os LEDs acesos**.
- Depois de 3 segundos, ele passa para **dois LEDs acesos**.
- Após mais 3 segundos, apenas **um LED (vermelho) fica aceso**.
- O botão permite alterar o estado do semáforo, mas só pode ser pressionado após o último LED ser desligado.

## Como Usar

### 1. **Hardware Necessário**

- 1x Raspberry Pi Pico
- 3x LEDs (vermelho, azul e verde)
- 1x Botão (pushbutton)
- 3x resistores de 330 ohms
- Fios de conexão (jumpers)

### 2. **Conexões**

- **LED Vermelho**: Conecte no pino **GPIO 13**.
- **LED Azul**: Conecte no pino **GPIO 12**.
- **LED Verde**: Conecte no pino **GPIO 11**.
- **Botão**: Conecte ao pino **GPIO 5** e adicione um resistor de pull-up.

### 3. **Passos para Compilação e Carregamento**

1. **Configuração do Ambiente**
   - Instale o [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk).
   - Configure seu ambiente de desenvolvimento para compilar o código.

2. **Compilar o Código**
   - Baixe ou clone o repositório.
   - Use a ferramenta `make` para compilar o código e gerar o arquivo `.uf2`.

3. **Carregar no Raspberry Pi Pico**
   - Conecte o Raspberry Pi Pico ao computador enquanto mantém pressionado o botão **BOOTSEL**.
   - O Pico aparecerá como uma unidade de armazenamento. Copie o arquivo `.uf2` para o Pico. O dispositivo será reiniciado automaticamente.

### 4. **Funcionamento**

- Quando o semáforo for ligado, ele começará com todos os LEDs acesos.
- Após 3 segundos, ele passa para dois LEDs acesos e, em seguida, para apenas o LED vermelho.
- O botão pode ser pressionado para alterar o estado, mas apenas após o último LED ser desligado.

## Detalhes do Código

- **Enumeração `TrafficLightState`**: Controla os diferentes estados do semáforo (todos os LEDs acesos, dois LEDs acesos e um LED aceso).
- **Temporizador de 3 segundos**: A cada 3 segundos, o semáforo alterna de estado.
- **Debounce de Botão**: O código implementa um debounce de software para evitar leituras erradas do botão.

## Conclusão

Este projeto demonstra o controle básico de LEDs com o Raspberry Pi Pico e a implementação de um semáforo simples com controle por botão. Ele pode ser facilmente modificado para adicionar novos comportamentos ou usar diferentes pinos GPIO.