#include <EEPROM.h>
 
float sensorValue;
int eeAddress = 0;
 
//Funcion que simula la lectura de un sensor
float ReadSensor()
{
  return 10.0f;
}
 
void setup()
{
}
 
void loop()
{
  sensorValue = ReadSensor(); //Lectura simulada del sensor
  EEPROM.put( eeAddress, sensorValue );  //Grabamos el valor
  eeAddress += sizeof(float);  //Obtener la siguiente posicion para escribir
  if(eeAddress >= EEPROM.length()) eeAddress = 0;  //Comprobar que no hay desbordamiento
 
  delay(30000); //espera 30 segunos
}
