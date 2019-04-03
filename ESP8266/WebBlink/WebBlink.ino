#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h> 
const char* ssid = "xxxxxxxxx";
const char* password = "xxxxxxxxx";

IPAddress ip(192,168,0,200);     
IPAddress gateway(192,168,0,1);   
IPAddress subnet(255,255,255,0);

int ledPin = 16; // GPIO13
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.println("Connecting to access point");
  ///Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Keep calm!!!");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  int value;
  if (request.indexOf("/LED=OFF") != -1)  {   
    value = 0;
  }else if (request.indexOf("/LED=ON") != -1) value = 1;
  else{
    Serial.print("Invalid request");
    client.stop();
    return;
    }
 
// Set ledPin according to the request
  digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>"); 
  client.print("Led pin is now:"); 
  client.print(value);
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn Off </button></a><br />");   
  client.println("</html>");
 
  delay(100);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
 
