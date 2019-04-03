/**************************************************************
 * This example runs directly on ESP8266 chip
 * using the Blynk platform and mobile application.
 *
 * Change WiFi ssid, password, and Blynk auth token to run :)
 *
 **************************************************************/

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define RightMotorSpeed 5
#define RightMotorDir   0
#define LeftMotorSpeed  4
#define LeftMotorDir    2


#define echoPin 12 // Echo Pin
#define trigPin 13 // Trigger Pin
long duration, distance;

WidgetTerminal terminal(V4);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "***************************************";
char ssid[] = "***********************";
char pass[] = "***********************";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  pinMode(RightMotorSpeed, OUTPUT);
  pinMode(RightMotorDir, OUTPUT);
  pinMode(LeftMotorSpeed, OUTPUT);
  pinMode(LeftMotorDir, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  terminal.println(F("Blynk v" BLYNK_VERSION ": Device started"));

}

int distancia(){
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(4); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.54
 distance = duration * 10 / 292/ 2;
 return distance;
}


void loop()
{
 
  Blynk.run();
  
}

void halt()
{
  digitalWrite(RightMotorSpeed, LOW);
  digitalWrite(LeftMotorSpeed, LOW);
}

void forward()
{
  digitalWrite(RightMotorDir, HIGH);
  digitalWrite(LeftMotorDir, HIGH);
  digitalWrite(RightMotorSpeed, HIGH);
  digitalWrite(LeftMotorSpeed, HIGH);
}

void reverse()
{
  digitalWrite(RightMotorDir, LOW);
  digitalWrite(LeftMotorDir, LOW);
  digitalWrite(RightMotorSpeed, HIGH);
  digitalWrite(LeftMotorSpeed, HIGH);
}

void right()
{
  digitalWrite(RightMotorDir, LOW);
  digitalWrite(LeftMotorDir, HIGH);
  digitalWrite(RightMotorSpeed, HIGH);
  digitalWrite(LeftMotorSpeed, HIGH);
}

void left()
{
  digitalWrite(RightMotorDir, HIGH);
  digitalWrite(LeftMotorDir, LOW);
  digitalWrite(RightMotorSpeed, HIGH);
  digitalWrite(LeftMotorSpeed, HIGH);
}

BLYNK_WRITE(V0)
{
 int dis = distancia();
  if (param[0]){
    if (dis > 10) {
       terminal.println("avanza"); 
       forward();       
    }else {
       terminal.println("demasiado cerca"); 
       halt();
    }
  }else  halt();
 terminal.flush();
}

BLYNK_WRITE(V1)
{
  if (param[0])
    reverse();
  else
    halt();
}

BLYNK_WRITE(V2)
{
  if (param[0])
    right();
  else
    halt();
}

BLYNK_WRITE(V3)
{
  if (param[0])
    left();
  else
    halt();
}

