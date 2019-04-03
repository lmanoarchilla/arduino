#define infrad  14
#define infrai  13

#define RightMotorSpeed 5
#define RightMotorDir   0
#define LeftMotorSpeed  4
#define LeftMotorDir    2

int dch = 0;
int izq = 0;


int Speed = 500; 
void setup() {
  
  Serial.begin(115200);   //iniciar puerto serie
  Serial.println("NodeMCU funcionando");
  pinMode(infrad, INPUT);  //definir pin como entrada
  pinMode(infrai, INPUT);

  pinMode(RightMotorSpeed, OUTPUT);
  pinMode(RightMotorDir, OUTPUT);
  pinMode(LeftMotorSpeed, OUTPUT);
  pinMode(LeftMotorDir, OUTPUT);  
}
 
void loop(){
  Serial.print("infrad:");
  Serial.println(digitalRead(infrad));
  Serial.print("infrai:");
  Serial.println(digitalRead(infrai)); 
   dch = digitalRead(infrad);
   izq = digitalRead(infrai);
 if (!dch && !izq){
    //Serial.println("Todo recto");
    forward();
 }else if (!digitalRead(infrad) && digitalRead(infrai)){
   //Serial.println("Todo izquierda");
   left();
 }else if (digitalRead(infrad) && !digitalRead(infrai)){
   //Serial.println("Todo derecha");
   right();
 }else{
   //Serial.println("PARA!");
   halt();
   }

}
void halt()
{
  digitalWrite(RightMotorSpeed, LOW);
  digitalWrite(LeftMotorSpeed, LOW);

  analogWrite(RightMotorSpeed, 0);
  analogWrite(LeftMotorSpeed, 0);
}
void forward()
{
  digitalWrite(RightMotorDir, HIGH);
  digitalWrite(LeftMotorDir, HIGH);

  analogWrite(RightMotorSpeed, Speed);
  analogWrite(LeftMotorSpeed, Speed);
}

void right()
{
  digitalWrite(RightMotorDir, LOW);
  digitalWrite(LeftMotorDir, HIGH);
 


  analogWrite(RightMotorSpeed, Speed);
  analogWrite(LeftMotorSpeed, Speed);
}

void left()
{
  digitalWrite(RightMotorDir, HIGH);
  digitalWrite(LeftMotorDir, LOW);
  
  analogWrite(RightMotorSpeed, Speed);
  analogWrite(LeftMotorSpeed, Speed);
}



