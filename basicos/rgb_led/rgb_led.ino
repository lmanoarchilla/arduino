/**
  Led que va cambiando de color.
*/

const int RED_LED = 9;
const int GREEN_LED = 10;
const int BLUE_LED = 11;
int r,g,b;
void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Init:");

}

void loop() {
  for(r=0; r<=150; r++){
    analogWrite(RED_LED,r);    
    for(g=0; g<=150; g++){      
      analogWrite(GREEN_LED,g);
      for(b=0; b<=150; b++){         
        analogWrite(BLUE_LED,b);
      }delay(100);
    }delay(100);
  }delay(100);
}
