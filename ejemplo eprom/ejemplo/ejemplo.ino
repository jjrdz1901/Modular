#include <EEPROM.h>        // libreria EEPROM

void setup() {
  Serial.begin(9600);       // inicializa monitor serie a 9600 bps
  pinMode(13, OUTPUT);
  pinMode(7, INPUT);
  
  if(digitalRead(7)==0){
     Serial.println("Datos Almacenados");  // imprime texto
     for (int i = 0; i <= 3; i++) {   
        Serial.println( EEPROM.read(i) );   // Lee los datos de la memoria EEPROM
        delay (100);
    }  
  }else {
      Serial.println("Guardando Datos .... ");  // imprime texto 
      for (int i = 0; i <= 3; i++) {   
         digitalWrite(13, HIGH);
         delay (100);     
         long  dato = analogRead(0);      
         dato = map(dato,0,1024,0,255); 
         EEPROM.put(i, dato);           // Escribe datos de la memoria EEPROM
         Serial.println(dato);
         digitalWrite(13, LOW); 
        delay (500);
      }
   }
}
void loop() { 
}
