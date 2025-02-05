# Semáforo com Raspberry Pi Pico

Este projeto simula um semáforo utilizando um Raspberry Pi Pico e LEDs de cores vermelho, azul e verde. O sistema alterna as luzes a cada 3 segundos, simulando o comportamento de um semáforo de trânsito.

## Como Usar

### 1. **Hardware Necessário**

- 1x Raspberry Pi Pico
- 3x LEDs (vermelho, azul e verde)
- 3x resistores de 330 ohms
- Fios de conexão (jumpers)

### 2. **Conexões**

- **LED Vermelho**: Conecte no pino GPIO 13 (GP13).
- **LED Azul**: Conecte no pino GPIO 12 (GP12).
- **LED Verde**: Conecte no pino GPIO 11 (GP11).

**Nota**: Os resistores devem ser conectados em série com os LEDs para limitar a corrente.

### 3. **Passos para Compilação e Carregamento**

1. **Configuração do Ambiente**
   - Instale o [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk) no seu computador.
   - Configure seu ambiente de desenvolvimento para compilar o código.

2. **Compilar o Código**
   - Baixe ou clone o repositório contendo o código.
   - Use a ferramenta `make` para compilar o código e gerar o arquivo `.uf2`.

3. **Carregar no Raspberry Pi Pico**
   - Conecte o Raspberry Pi Pico ao computador mantendo pressionado o botão **BOOTSEL**.
   - O dispositivo aparecerá como um dispositivo de armazenamento USB. 
   - Copie o arquivo `.uf2` gerado para o Pico. O Raspberry Pi Pico será reiniciado automaticamente e o semáforo começará a funcionar.

### 4. **Funcionamento do Semáforo**

O sistema vai alternar as cores dos LEDs em sequência:

- **Vermelho → Azul → Verde → Vermelho → ...**
  
Cada troca de cor ocorre a cada 3 segundos. O código imprime uma mensagem a cada segundo dizendo "Semáforo funcionando...".

### 5. **Ajustes**

- **Tempo de Troca de Cores**: Para alterar o intervalo de troca das luzes, basta ajustar o tempo configurado no código (3000 milissegundos por padrão).
- **Pinos GPIO**: Se preferir usar outros pinos, basta alterar as configurações de pinos no código.

## Conclusão

Esse projeto oferece uma maneira simples e eficiente de simular o funcionamento de um semáforo com o Raspberry Pi Pico. Pode ser facilmente adaptado para diferentes aplicações e é uma boa introdução ao controle de LEDs e temporizadores com microcontroladores.