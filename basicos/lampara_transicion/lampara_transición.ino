/*
  Lampara transición, enciende y apaga el led con un boton,
  cambia de estado ddisminuyedo o aumentando gradualmente la potencia
*/

const int LED = 9;
const int BUTTON = 7;
int val;
int state;
int i;
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
         for (i = 0; i < 255; i++) { /
            analogWrite(LED, i);
            delay(10); 
          }
        state=1;
      }else{
        for (i = 255; i > 0; i--) { 
          delay(10);
        }
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
