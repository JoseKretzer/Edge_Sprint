# ESP32 RPM e Velocidade WebServer com Integração Postman
Este projeto utiliza um ESP32 para monitorar a Rotação por Minuto (RPM) e a Velocidade de um sistema com sensores Hall. Os dados são enviados para um broker MQTT e podem ser acessados e gerenciados via Postman ou outros clientes MQTT.

## Componentes Necessários:
### Hardware
ESP32: O microcontrolador que executa o código.
Sensores Hall: Para medir a rotação (RPM) e a velocidade.
Protoboard e Jumpers: Para fazer as conexões.
Resistores: Para uso com os sensores, conforme necessário.

### Software
Arduino IDE: Para programar o ESP32.
Postman: Para realizar testes e monitorar as requisições.
Broker MQTT: Um broker MQTT (por exemplo, Mosquitto ou o IP 46.17.108.113 usado no código).

### Bibliotecas Necessárias
WiFi.h: Para conectar o ESP32 à rede Wi-Fi.
PubSubClient.h: Para comunicação via MQTT.

## Configuração do Hardware
### Componentes Principais
Pino 18 (ESP32): Conectado ao sensor Hall para medir o RPM.
Pino 5 (ESP32): Conectado ao sensor Hall para medir a Velocidade.
### Diagrama de Ligação
As conexões devem ser feitas com os sensores ligados aos pinos apropriados e, se necessário, com resistores para garantir leituras adequadas.

## Configuração do Postman
O Postman será usado para testar as requisições e as respostas do broker MQTT. Para configurar o Postman e simular a comunicação com o ESP32, siga os passos abaixo:
### Passo a Passo:
Abra o Postman e clique em Import.
Importe o arquivo Postman Collection que contém os endpoints de publicação e monitoramento de RPM e Velocidade.
Configure as variáveis necessárias, como a URL do broker MQTT e os tópicos (/TEF/xxx001/attrs/rpm e /TEF/xxx001/attrs/velocidade).
Envie requisições GET para os tópicos e verifique as respostas dos valores de RPM e Velocidade.

## Passo a Passo para Importar o Arquivo JSON no Postman:
### Baixe o arquivo:

Baixar: ESP32_Postman_Collection.json
### Abra o Postman no seu computador.

### Importe a Coleção:

Na interface do Postman, clique em Import no topo da interface.
Selecione a aba File.
Clique em Choose Files e navegue até o arquivo ESP32_Postman_Collection.json que você baixou.
Clique em Open e, em seguida, em Import.
### Use a Coleção:

Após a importação, você verá dois endpoints configurados na sua coleção:
Obter RPM (GET /rpm)
Obter Velocidade (GET /velocidade)
Basta clicar em qualquer um dos endpoints e depois clicar em Send para enviar a requisição ao ESP32.

### Integrantes do grupo:
JOSE ANTONIO KRETZER RODRIGUEZ (RM: 555523)

VICTOR ALVES DE SOUZA (RM: 555761)

GUSTAVO YUJI OSUGI (RM:555034)

RENATO DUTRA FERREIRA DE AGUIAR (RM:554716)


