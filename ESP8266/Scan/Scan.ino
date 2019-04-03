#include <ESP8266WiFi.h>
void setup() {
Serial.begin(115200);
WiFi.mode(WIFI_STA);
WiFi.disconnect();
delay(100);
Serial.println("setup completado");
 Serial.println("Comienza la busqueda de redes WiFi");
 int n = WiFi.scanNetworks();
 Serial.println("Busqueda realizada");
 if (n == 0)
    Serial.print("Redes no encontradas");
 else {
    for (int i = 0; i < n; i++) {
     //Muestra los datos de las redes encontradas
     Serial.print(i+1);
     Serial.print(": ");
     Serial.print(WiFi.SSID(i));
     Serial.print(" (");
     Serial.print(WiFi.RSSI(i));
     Serial.println(")");
     delay(10);
    }
 }

}

void loop() {
  // put your main code here, to run repeatedly:

}
