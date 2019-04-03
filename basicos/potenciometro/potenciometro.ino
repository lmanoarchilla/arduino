/* 
	Lee el valor del potenciometro y lo muestra por la salida serie
*/

int potentiometer = A0;
int led = 13 ;
int val;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("Reading:...");
}

void loop() {
  val = analogRead(potentiometer);
  digitalWrite(led,HIGH);
  Serial.print("Value: ");
  Serial.println(val);
  delay(1000);  
  
}
