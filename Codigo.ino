#include <WiFi.h>
#include <PubSubClient.h>
 
// Configurações - variáveis editáveis
const char* default_SSID = "Wokwi-GUEST"; // Nome da rede Wi-Fi
const char* default_PASSWORD = ""; // Senha da rede Wi-Fi
const char* default_BROKER_MQTT = "46.17.108.113"; // IP do Broker MQTT
const int default_BROKER_PORT = 1883; // Porta do Broker MQTT
const char* default_TOPICO_PUBLISH_RPM = "/TEF/xxx001/attrs/rpm"; // Tópico MQTT para RPM
const char* default_TOPICO_PUBLISH_VELOCIDADE = "/TEF/xxx001/attrs/velocidade"; // Tópico MQTT para Velocidade
const char* default_ID_MQTT = "fiware_001"; // ID MQTT
 
// Pinos dos sensores
const int hallPinRPM = 18;  
const int hallPinVelocimetro = 5;  
 
// Variáveis para o conta-giros
int lastStateRPM = HIGH;  
unsigned long lastPulseTimeRPM = 0;  
float rpm = 0;  
 
// Variáveis para o velocímetro
int lastStateVelocimetro = HIGH;  
unsigned long lastPulseTimeVelocimetro = 0;  
float velocidade = 0;  
float diameterVelocimetro = 0.5; // Diâmetro da roda em metros
const float pi = 3.1416;
 
// Inicializa cliente WiFi e MQTT
WiFiClient espClient;
PubSubClient MQTT(espClient);
 
void setup() {
    Serial.begin(115200);  
    pinMode(hallPinRPM, INPUT_PULLUP);  
    pinMode(hallPinVelocimetro, INPUT_PULLUP);  
 
    // Conecta ao Wi-Fi
    WiFi.begin(default_SSID, default_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Conectando ao Wi-Fi...");
    }
    Serial.println("Conectado ao Wi-Fi!");
 
    // Configura o MQTT
    MQTT.setServer(default_BROKER_MQTT, default_BROKER_PORT);
}
 
void loop() {
    verificaConexoesWiFiEMQTT();
    calculaRPM();
    calculaVelocidade();
    enviaDadosMQTT();
    MQTT.loop();
    delay(100);
}
 
void verificaConexoesWiFiEMQTT() {
    if (!MQTT.connected()) {
        while (!MQTT.connected()) {
            Serial.print("Tentando se conectar ao broker MQTT...");
            if (MQTT.connect(default_ID_MQTT)) {
                Serial.println("Conectado ao broker!");
            } else {
                Serial.print("Falha, rc=");
                Serial.print(MQTT.state());
                Serial.println(" Tentando novamente em 2 segundos...");
                delay(2000);
            }
        }
    }
}
 
void calculaRPM() {
    int currentStateRPM = digitalRead(hallPinRPM);
    if (lastStateRPM == LOW && currentStateRPM == HIGH) {
        unsigned long currentTimeRPM = millis();
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
 
void calculaVelocidade() {
    int currentStateVelocimetro = digitalRead(hallPinVelocimetro);
    if (lastStateVelocimetro == LOW && currentStateVelocimetro == HIGH) {
        unsigned long currentTimeVelocimetro = millis();
        if (lastPulseTimeVelocimetro > 0) {
            unsigned long timeDifferenceVelocimetro = currentTimeVelocimetro - lastPulseTimeVelocimetro;
            float rpmVelocimetro = (60000.0 / timeDifferenceVelocimetro);
            float circumferenceVelocimetro = pi * diameterVelocimetro;
            float linearVelocity = (circumferenceVelocimetro * rpmVelocimetro) / 60.0;
            velocidade = linearVelocity * 3.6; // Converte de m/s para km/h
            Serial.print("Velocidade: ");
            Serial.print(velocidade);
            Serial.println(" km/h");
        }
        lastPulseTimeVelocimetro = currentTimeVelocimetro;
    }
    lastStateVelocimetro = currentStateVelocimetro;
}
 
void enviaDadosMQTT() {
    String mensagemRPM = String(rpm);
    String mensagemVelocidade = String(velocidade);
 
    MQTT.publish(default_TOPICO_PUBLISH_RPM, mensagemRPM.c_str());
    MQTT.publish(default_TOPICO_PUBLISH_VELOCIDADE, mensagemVelocidade.c_str());
 
    Serial.print("Dados enviados - RPM: ");
    Serial.print(mensagemRPM);
    Serial.print(", Velocidade: ");
    Serial.println(mensagemVelocidade);
}
