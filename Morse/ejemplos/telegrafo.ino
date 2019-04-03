/*Telegrafo*/

#include <Morse.h>
 
Morse morse(13,2);
char val; 
void setup()
{  
  Serial.begin(9600);
  Serial.print("Init:");
}
 
void loop()
{
    val= morse.button();       
    if (val>0){
      if (val==1){
       Serial.print("-");
       }else{
        Serial.print(".");
        }
      }
   
        
        

}
