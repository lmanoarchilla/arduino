/*
 Recoge la lectura de un ldr y aplica el valor al delay
*/
const int LED = 13;
int val = 0;
void setup() {
 pinMode(LED,OUTPUT);
}

void loop() {
 val = analogRead(0);
 digitalWrite(LED,HIGH);
 delay(val);
 digitalWrite(LED,LOW);
 delay(val);
}
