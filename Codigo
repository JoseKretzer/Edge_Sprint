#include <WiFi.h>
#include <WebServer.h>

// Defina suas credenciais de Wi-Fi
const char* ssid = "SEU_SSID";       
const char* password = "SUA_SENHA";

// Pinos onde os sensores de RPM e Velocímetro estão conectados
const int hallPinRPM = 18;  
const int hallPinVelocimetro = 5;  

// Variáveis para o conta-giros (RPM)
int lastStateRPM = HIGH;
unsigned long lastPulseTimeRPM = 0;
unsigned long currentTimeRPM = 0;
float rpm = 0;
unsigned long timeoutRPM = 2000;  

// Variáveis para o velocímetro
int lastStateVelocimetro = HIGH;
unsigned long lastPulseTimeVelocimetro = 0;
unsigned long currentTimeVelocimetro = 0;
float velocidade = 0;
unsigned long timeoutVelocimetro = 2000;  

// Parâmetros do velocímetro
float diameterVelocimetro = 0.5;  // Diâmetro da roda (ajuste conforme necessário)
const float pi = 3.1416;

// Cria um servidor web na porta 80
WebServer server(80);

// Função para calcular o RPM
void calculaRPM() {
  currentTimeRPM = millis();

  int currentStateRPM = digitalRead(hallPinRPM);

  if (lastStateRPM == LOW && currentStateRPM == HIGH) {
    currentTimeRPM = millis();

    if (lastPulseTimeRPM > 0) {
      unsigned long timeDifferenceRPM = currentTimeRPM - lastPulseTimeRPM;
      rpm = (60000.0 / timeDifferenceRPM);

      Serial.print("RPM: ");
      Serial.println(rpm);
    }
    lastPulseTimeRPM = currentTimeRPM;
  }
  lastStateRPM = currentStateRPM;
}

// Função para calcular a velocidade
void calculaVelocidade() {
  currentTimeVelocimetro = millis();

  int currentStateVelocimetro = digitalRead(hallPinVelocimetro);

  if (lastStateVelocimetro == LOW && currentStateVelocimetro == HIGH) {
    currentTimeVelocimetro = millis();

    if (lastPulseTimeVelocimetro > 0) {
      unsigned long timeDifferenceVelocimetro = currentTimeVelocimetro - lastPulseTimeVelocimetro;

      float rpmVelocimetro = (60000.0 / timeDifferenceVelocimetro);
      float circumferenceVelocimetro = pi * diameterVelocimetro;
      float linearVelocity = (circumferenceVelocimetro * rpmVelocimetro) / 60.0;
      velocidade = linearVelocity * 3.6;

      Serial.print("Velocidade: ");
      Serial.print(velocidade);
      Serial.println(" km/h");
    }
    lastPulseTimeVelocimetro = currentTimeVelocimetro;
  }
  lastStateVelocimetro = currentStateVelocimetro;
}

// Função para configurar a rede Wi-Fi e servidor web
void setupWiFi() {
  Serial.begin(115200);
  
  // Conectar ao Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");
  }

  Serial.println("Conectado ao Wi-Fi");
  Serial.println(WiFi.localIP());  // Exibe o IP do ESP32 na rede

  // Configurar rota HTTP para enviar dados de RPM e velocidade
  server.on("/dados", [](){
    String jsonData = "{\"rpm\": " + String(rpm) + ", \"velocidade\": " + String(velocidade) + "}";
    server.send(200, "application/json", jsonData);
  });

  // Iniciar o servidor
  server.begin();
}

void setup() {
  Serial.begin(9600);  // Inicializa a comunicação serial
  pinMode(hallPinRPM, INPUT_PULLUP);
  pinMode(hallPinVelocimetro, INPUT_PULLUP);

  setupWiFi();  // Configura o Wi-Fi e inicia o servidor
}

void loop() {
  calculaRPM();
  calculaVelocidade();
  server.handleClient();  // Lida com as requisições HTTP
  delay(10);  // Pequeno atraso para suavizar as leituras
}
