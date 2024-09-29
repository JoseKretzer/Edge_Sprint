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

## Instruções para Compilação e Upload
###Instale o ESP32 na IDE Arduino:

Vá para Arquivo > Preferências e adicione o seguinte URL na seção de URLs adicionais:
arduino
Copiar código
https://dl.espressif.com/dl/package_esp32_index.json
Em Ferramentas > Gerenciador de Placas, instale o pacote ESP32.
###Instale as bibliotecas necessárias:

Instale as bibliotecas ESPAsyncWebServer e AsyncTCP via o Gerenciador de Bibliotecas da IDE Arduino.
### Compilação e Upload:

Conecte o ESP32 ao computador e selecione a porta correta.
Carregue o código para o ESP32.
### Monitor Serial:

Abra o Monitor Serial para visualizar a conexão WiFi e os dados.
