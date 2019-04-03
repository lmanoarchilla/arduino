/*
  Lampara se mantiene en el estado actual hasta que se pulsa el boton.
  (Encendido/apagado)
*/

const int LED = 13;
const int BUTTON = 7;
int val;
int state;

void setup() {
 pinMode(LED,OUTPUT);
 pinMode(BUTTON,INPUT);
  val = 0;
  state = 0;

}

void loop() {
  val= digitalRead(BUTTON);
  if (val==HIGH){    
      if (state==0){
        digitalWrite(LED,HIGH);
        state=1;
      }else{
        digitalWrite(LED,LOW);
        state=0;
        }    
      delay(500);  
    }else{
      if (state==1){
         digitalWrite(LED,HIGH);         
        }else{
         digitalWrite(LED,LOW);         
        }
    }
}
