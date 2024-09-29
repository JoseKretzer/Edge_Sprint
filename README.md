# ESP32 RPM e Velocidade WebServer com Integração Postman
Este projeto utiliza um ESP32 para medir e monitorar a Rotação por Minuto (RPM) e a Velocidade de um sistema com sensores. Os dados são expostos via um servidor web, permitindo acessá-los através de uma interface HTTP.

## Componentes Necessários:
### Hardware
ESP32: O microcontrolador que executa o código.
Sensores Hall: Para medir a rotação (RPM) e a velocidade.
Protoboard e Jumpers: Para fazer as conexões.
Resistores: Para uso com os sensores, conforme necessário.

### Software
Arduino IDE: Para programar o ESP32.
#### Bibliotecas:
WiFi.h: Para gerenciar a conexão Wi-Fi.
WebServer.h: Para criar o servidor HTTP.

## Configuração do Hardware
### Componentes Principais
Pino 18: Conectado ao sensor Hall do RPM.
Pino 5: Conectado ao sensor Hall do Velocímetro.
### Diagrama de Ligação
As conexões devem ser feitas com os sensores ligados aos pinos apropriados e, se necessário, com resistores para garantir leituras adequadas.
