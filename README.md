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
### Instale o ESP32 na IDE Arduino:

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

## Configuração do Postman
### Passos para Importar a Coleção no Postman
Abra o Postman.
Clique em Import no canto superior esquerdo.
Selecione o arquivo ESP32_Postman_Collection.json.
Após a importação, você verá dois endpoints configurados:
Obter RPM (GET /rpm)
Obter Velocidade (GET /velocidade)
### Exemplo de Requisição GET
URL: http://<ESP32_IP>/rpm

Método: GET
Retorna o valor atual de RPM.
### URL: http://<ESP32_IP>/velocidade

Método: GET
Retorna o valor atual de velocidade.
### Nota: 
Substitua  <ESP32_IP>  pelo endereço IP do ESP32, que será exibido no Monitor Serial após a conexão Wi-Fi.
Certifique-se de que o IP do ESP32 (192.168.1.100) está correto ou altere o IP no Postman conforme o IP do seu ESP32 na sua rede local.

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


