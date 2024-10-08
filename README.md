# ESP32 RPM e Velocidade WebServer com Integração Postman
Este documento descreve os recursos necessários para implementar uma solução IoT que monitora Rotação por Minuto (RPM) e Velocidade de um dispositivo (como um veículo), com coleta de dados via ESP32, envio para um broker MQTT (back-end), e uma interface para monitoramento e controle (front-end).

## Descrição do Projeto
Este projeto tem como objetivo monitorar dados em tempo real de RPM e Velocidade de um dispositivo conectado, enviando as informações coletadas para um broker MQTT via um ESP32. Os dados são então disponibilizados para consumo por um sistema de back-end e podem ser visualizados em uma interface front-end.

## Back-end
### Broker MQTT:

Um broker MQTT (como Mosquitto ou HiveMQ) para receber as publicações dos dados de RPM e Velocidade enviados pelo ESP32.

Exemplo de broker usado: 46.17.108.113 na porta 1883.
### Servidor:

Um servidor para processar as mensagens MQTT e armazenar/monitorar os dados recebidos.

Pode ser configurado com Node.js, Python, ou outras linguagens compatíveis com MQTT.
### Banco de Dados (opcional):

Se necessário, um banco de dados para armazenar os dados históricos de RPM e Velocidade para análise futura.

## Front-end
### Postman (ou outra interface de testes HTTP/MQTT):

Para testar e monitorar as requisições HTTP e as mensagens MQTT.

Pode ser substituído por uma interface web personalizada.
### Dashboard IoT (opcional):

Um dashboard para visualização em tempo real dos dados de RPM e Velocidade, com gráficos e alertas. 

Pode ser construído usando Node-RED, Grafana, ou React.js.

## Requisitos e Dependências:
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
### Baixe o arquivo 

Baixar: FIWARE Descomplicado.postman_collection
### Abra o Postman no seu computador.

### Importe a Coleção:

Na interface do Postman, clique em Import no topo da interface.
Selecione a aba File.
Clique em Choose Files e navegue até o arquivo FIWARE Descomplicado.postman_collection que você baixou.
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


