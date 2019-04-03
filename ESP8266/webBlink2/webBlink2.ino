#include <ESP8266WiFi.h>
const char* ssid ="************************";
const char* password = "***********************";
const int led = 5; //GPIO5 - D1
WiFiServer server(80); //Crea una instancia de Servidor WEB y especifica el puerto que escucha
void setup() {
 //inicializa el puerto serie
 Serial.begin(115200);
 delay(10);
 //inicializa el led
 pinMode(LED_BUILTIN,OUTPUT);
 digitalWrite(LED_BUILTIN,LOW);
 //Inicializa el módulo wifi
 WiFi.mode(WIFI_STA); //Establece el módulo como cliente wifi
 WiFi.disconnect(); //Se desconecta de cualquier WiFi conectado previamente
 Serial.println(); 
 //conecta con la red wifi
 Serial.print("Connecting to ");
 Serial.println(ssid);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {   // Espera por una conexión WiFi
    delay(500);
    Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected");
 Serial.println("IP address: ");
 IPAddress sensor_ip = WiFi.localIP();
 digitalWrite(LED_BUILTIN,HIGH);
 //inicializa el servidor web
 server.begin();
 Serial.print("Servidor WEB activo: ");
 Serial.println(WiFi.localIP()); 
}

void loop() {
 //comprueba si un cliente está conectado
 WiFiClient client = server.available();
 if (!client) {
    return;
 }
 //espera hasta que el cliente envía algún dato
 Serial.println("cliente conectado");
 while(!client.available()) {
    delay(1);
 }
 //lee la primera línea de la petición
 String req =client.readStringUntil('\r');
 Serial.println(req);
 client.flush();
 //busca en las peticiones los comandos de encendido y apagado
 int val;
 if (req.indexOf("/off") != -1){
    val = 1;
    Serial.println("cliente off:");
    Serial.println(req.indexOf("/off"));
    
 }else if (req.indexOf("/on") != -1){
    val = 0;
    Serial.println("cliente on:");
    Serial.println(req.indexOf("/on"));
 }else {
    Serial.print("Petición inválida");
    String n = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nERROR </html>\n ";
   //envía la respuesta
    client.print(n);
    client.stop();
    return;
 }
 digitalWrite(LED_BUILTIN,val);
 client.flush();
 //prepara la respuesta a la petición
 String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nLed ";
 s += (val)?"apagado":"encendido";
 s += "</html>\n";
 //envía la respuesta
 client.print(s);
 delay(1);
 Serial.println("cliente desconectado");
}
