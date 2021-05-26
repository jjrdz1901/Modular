#include <Wire.h>
//#include <MPU6050.h>
#define EMG_PIN 0
//MPU6050 mpu;
#define umbral 250
//double accelX = 0, accelY =0, accelZ;
//double gyroX = 0, gyroY =0, gyroZ;
double valor;
unsigned long lastTime = 0, sampleTime = 100;

void setup() {
  Serial.begin(115200);
  
  while(!analogRead(EMG_PIN))
  {
    delay(100);
  }
}

void loop() {
  
  if(millis()-lastTime>=sampleTime)
  {
    lastTime = millis();  
valor = analogRead(EMG_PIN);
Serial.println(valor);
    
/*    Vector normAccel = mpu.readNormalizeAccel();
    Vector normGyro = mpu.readNormalizeGyro();
    accelX = normAccel.XAxis;
    accelY = normAccel.YAxis;
    accelZ = normAccel.ZAxis;
    gyroX = normGyro.XAxis;
    gyroY = normGyro.YAxis;
    gyroZ = normGyro.ZAxis;

    Serial.println(accelX);
    Serial.println(accelY);
    Serial.println(accelZ);
//    Serial.println(gyroX);
//    Serial.println(gyroY);
//    Serial.println(gyroZ);
  */  
  }
}
