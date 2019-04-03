/*
  Utiliza un boton para encender o apagar un led,
  el led cambia la intensidad proporcionalmente 
  al valor recogido por un ldr
*/

const int LED = 9;
const int BUTTON = 7;
const int SENSOR = 0;

int val;
int state;
void setup() {
 pinMode(LED,OUTPUT);
 Serial.begin(9600);
 Serial.println("Init");
 val = 0;
 state = 0;
}

void loop() {
  val= digitalRead(BUTTON);
  Serial.print(val);
  Serial.print(state);
    if (val==HIGH){    
      if (state==0){
        //digitalWrite(LED,LOW);
        light_on();
        state=1;
      }else{
        digitalWrite(LED,HIGH);  
        digitalWrite(11,HIGH);       
        state=0;
        }  
        delay(500);           
    }else{
      if (state==1){
         //digitalWrite(LED,LOW);
         light_on();         
        }else{
         digitalWrite(LED,HIGH);   
         digitalWrite(11,HIGH);    
        }        
    } 
   
}

void light_on(){
 int ldr = analogRead(SENSOR); 
 analogWrite(9,0);
 analogWrite(11,ldr*4); 
  }
