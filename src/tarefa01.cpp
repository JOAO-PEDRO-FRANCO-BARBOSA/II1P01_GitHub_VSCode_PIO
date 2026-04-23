#include <Arduino.h>

// Teste minimo: pisca LED RGB no pino 48 (ESP32-S3-DevKitC-1)
#define RGB_PIN 48

// Variáveis para o controle de tempo
unsigned long previousMillis = 0; 
const long interval = 500; // Intervalo de 500ms

// Variável para controlar a etapa atual da cor
int ledState = 0; 

void setup()
{
  Serial.begin(115200);
  delay(2000);
  Serial.println("=== ESP32-S3 Teste Com Millis ===");
}

void loop()
{
  unsigned long currentMillis = millis();

  // Verifica se já se passaram 500ms desde a última alteração
  if (currentMillis - previousMillis >= interval)
  {
    // Salva o tempo atual para a próxima contagem
    previousMillis = currentMillis;

    // Executa a ação correspondente ao estado atual
    switch (ledState)
    {
      case 0:
        neopixelWrite(RGB_PIN, 255, 0, 0); // Vermelho
        Serial.println("VERMELHO");
        break;
      
      case 1:
        neopixelWrite(RGB_PIN, 0, 0, 0);   // Apagado
        Serial.println("APAGADO");
        break;
      
      case 2:
        neopixelWrite(RGB_PIN, 0, 255, 0); // Verde
        Serial.println("VERDE");
        break;
      
      case 3:
        neopixelWrite(RGB_PIN, 0, 0, 0);   // Apagado
        Serial.println("APAGADO");
        break;
    }

    // Avança para o próximo estado
    ledState++;
    
    // Se passou do último estado (3), reinicia o ciclo
    if (ledState > 3)
    {
      ledState = 0;
    }
  }
}