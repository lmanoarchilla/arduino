/*
	Muestra por pantalla el valor de un ldr multiplicado por 4,
	le aplica el valor a un led
*/
const int LED = 9;

int val = 0;
void setup() {
 pinMode(LED,OUTPUT);
 Serial.begin(9600);
 Serial.println("Init");
}

void loop() {
 val = analogRead(0);
 Serial.println(val*4);
 analogWrite(LED,val*4);
 }
