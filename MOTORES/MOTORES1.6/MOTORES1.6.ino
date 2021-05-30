#include <PIDController.h>
//volatile long int encoder_pos[5] = {0,0,0,0,0,0},encoder_pos1 = 0,;
volatile long int encoder_pos=0,encoder_pos1 = 0,encoder_pos2 = 0,encoder_pos3 = 0,encoder_pos4 = 0,encoder_pos5 = 0,encoder_pos6 = 0;
volatile long int cal[5]={0,0,0,0,0}; //calibracion de punto 0
volatile int cont = 0; 
int minimo =115;//valor min de calibracion
//////////////////////////////////
PIDController pos_pid; 
PIDController pos1_pid;
PIDController pos2_pid; 
PIDController pos3_pid;
PIDController pos4_pid; 
PIDController pos5_pid;
////////////////////////////////////////
//entradas motores
const int motor0A=32;
const int motor0B=33;
const int motor1A=25;
const int motor1B=26;
const int motor2A=12;
const int motor2B=13;
const int motor3A=22;
const int motor3B=21;
const int motor4A=18;
const int motor4B=5;
const int motor5A=2;
const int motor5B=15;
//pines de sensor
const int motorSen0A=36;
const int motorSen0B=39;
const int motorSen1A=34;
const int motorSen1B=35;
const int motorSen2A=27;
const int motorSen2B=14;
const int motorSen3A=2;
const int motorSen3B=15;
const int motorSen4A=1;
const int motorSen4B=3;
const int motorSen5A=4;
const int motorSen5B=0;

 //PWM
const int freq = 9000;
const int ledChannel = 0;
const int ledChannel1 = 1;
const int ledChannel2 = 2;
const int ledChannel3 = 3;
const int ledChannel4= 4;
const int ledChannel5 = 5;
const int ledChannel6 = 6;
const int ledChannel7 = 7;
const int ledChannel8 = 8;
const int ledChannel9= 9;
const int ledChannel10 = 10;
const int ledChannel11 = 11;


const int resolution = 8;
//

int motor_value = 255;
unsigned int integerValue=0;  // Max value is 65535
char incomingByte;
void setup() {

  Serial.begin(9600);
  ledcSetup(ledChannel, freq, resolution);
  ledcSetup(ledChannel1, freq, resolution);
  ledcSetup(ledChannel2, freq, resolution);
  ledcSetup(ledChannel3, freq, resolution);
  ledcSetup(ledChannel4, freq, resolution);
  ledcSetup(ledChannel5, freq, resolution);
  ledcSetup(ledChannel6, freq, resolution);
  ledcSetup(ledChannel7, freq, resolution);
  ledcSetup(ledChannel8, freq, resolution);
  ledcSetup(ledChannel9, freq, resolution);
  ledcSetup(ledChannel10, freq, resolution);
  ledcSetup(ledChannel11, freq, resolution);
  
  ledcAttachPin(motor0A, ledChannel);
  ledcAttachPin(motor0B, ledChannel1);
   ledcAttachPin(motor1A, ledChannel2);
  ledcAttachPin(motor1B, ledChannel3);
  ledcAttachPin(motor2A, ledChannel4);
  ledcAttachPin(motor2B, ledChannel5);
  ledcAttachPin(motor3A, ledChannel6);
  ledcAttachPin(motor3B, ledChannel7);
  ledcAttachPin(motor4A, ledChannel8);
  ledcAttachPin(motor4B, ledChannel9);
  ledcAttachPin(motor5A, ledChannel10);
  ledcAttachPin(motor5B, ledChannel11);

  
  
  


//ledcWrite(ledChannel2, 190);
//ledcWrite(ledChannel3, 0);
//delay(1000);
//ledcWrite(ledChannel2, 0);
//ledcWrite(ledChannel3, 0);
///delay(1000);
//ledcWrite(ledChannel2, 0);
//ledcWrite(ledChannel3, 190);
//delay(1000);
//ledcWrite(ledChannel2, 0);
//ledcWrite(ledChannel3, 0);
//ledcWrite(ledChannel2, 0);
//ledcWrite(ledChannel3, 255);
  
  pinMode(motorSen0A, INPUT);
  pinMode(motorSen0B, INPUT);
  pinMode(motorSen1A, INPUT);
  pinMode(motorSen1B, INPUT);
   pinMode(motorSen2A, INPUT);
  pinMode(motorSen2B, INPUT);
  pinMode(motorSen3A, INPUT);
  pinMode(motorSen3B, INPUT); 
    
  pinMode(motorSen4A, INPUT);
  pinMode(motorSen4B, INPUT);
  pinMode(motorSen5A, INPUT);
  pinMode(motorSen5B, INPUT);
  
   //pinMode(4, INPUT);
  // pinMode(5, INPUT);
  //pinMode(9, OUTPUT); // 16 corresponds to GPIO1
  //pinMode(10, OUTPUT);
  // pinMode(11, OUTPUT);
  //pinMode(6, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(motorSen0A), encoder, RISING);
  attachInterrupt(digitalPinToInterrupt(motorSen1A), encoder1, RISING);
   attachInterrupt(digitalPinToInterrupt(motorSen2A), encoder2, RISING);
  attachInterrupt(digitalPinToInterrupt(motorSen3A), encoder3, RISING);
   attachInterrupt(digitalPinToInterrupt(motorSen4A), encoder4, RISING);
  attachInterrupt(digitalPinToInterrupt(motorSen5A), encoder5, RISING);
 // 1 & 2
  pos_pid.begin();    
  pos_pid.tune(15, 1, 2000);    
  pos_pid.limit(-255, 255);
  pos1_pid.begin();    
  pos1_pid.tune(15, 1, 2000);    
  pos1_pid.limit(-255, 255);
  // 3 & 4
    pos2_pid.begin();    
  pos2_pid.tune(15, 1, 2000);    
  pos2_pid.limit(-255, 255);
  pos3_pid.begin();    
  pos3_pid.tune(15, 1, 2000);    
  pos3_pid.limit(-255, 255);
  // 5 & 6
    pos4_pid.begin();    
  pos4_pid.tune(15, 1, 2000);    
  pos4_pid.limit(-255, 255);
  pos5_pid.begin();    
  pos5_pid.tune(15, 1, 2000);    
  pos5_pid.limit(-255, 255);
  
}

//  Motor 1 & 2
void encoder1(){

  if(digitalRead(motorSen1B) == HIGH){
    encoder_pos1++;
  }else{
    encoder_pos1--;
  }
   if (cont==1){
    cal[1] ++;           
    }

  
}

void encoder(){
//ledcWrite(ledChannel, 100);
  if(digitalRead(motorSen0B) == HIGH){
    encoder_pos++;
  }else{
    encoder_pos--;
  }

  if (cont==1){
    cal[0] ++;           
    }
}

void MotorClockwise(int power){//motor0
  if(power > 100){
    ledcWrite(ledChannel, power);
ledcWrite(ledChannel1, 0);
//  analogWrite(9, power);
  //digitalWrite(10, LOW);
  }else{
    ledcWrite(ledChannel, 0);
ledcWrite(ledChannel1, 0);
    //digitalWrite(9, LOW);
    //digitalWrite(10, LOW);
  }
}
void MotorClockwise1(int power){
  if(power > 100){
 ledcWrite(ledChannel2, power);
ledcWrite(ledChannel3, 0);
  }else{ 
    ledcWrite(ledChannel2, 0);
ledcWrite(ledChannel3, 0);
  }
}

void MotorCounterClockwise(int power){
  if(power > 100){
 ledcWrite(ledChannel, 0);
ledcWrite(ledChannel1, power);
  //analogWrite(10, power);
  //digitalWrite(9, LOW);
  }else{
    ledcWrite(ledChannel, 0);
ledcWrite(ledChannel1, 0);
    //digitalWrite(9, LOW);
    //digitalWrite(10, LOW);
  }
}
void MotorCounterClockwise1(int power){
  if(power > 100){
     ledcWrite(ledChannel2, 0);
ledcWrite(ledChannel3, power);
//  analogWrite(11, power);
 // digitalWrite(6, LOW);
  }else{
     ledcWrite(ledChannel2, 0);
ledcWrite(ledChannel3, 0);
   // digitalWrite(6, LOW);
  //  digitalWrite(11, LOW);
  }
}

// Motor 3 & 4

void encoder2( ){
//ledcWrite(ledChannel, 100);
  if(digitalRead(motorSen2B) == HIGH){
    encoder_pos2++;
  }else{
    encoder_pos2--;
  }
}

void MotorClockwise2(int power){
  if(power > 100){
     ledcWrite(ledChannel4, 0);
     ledcWrite(ledChannel5, power);
  }
  else{
      ledcWrite(ledChannel4, 0);
      ledcWrite(ledChannel5, 0);
  }
}
void MotorClockwise3(int power){
  if(power > 100){
 ledcWrite(ledChannel6, 0);
ledcWrite(ledChannel7, power);
  }else{
  ledcWrite(ledChannel6, 0);
ledcWrite(ledChannel7, 0);
  }
}

void MotorCounterClockwise2(int power){
  if(power > 100){
  ledcWrite(ledChannel4, power);
ledcWrite(ledChannel5, 0);
  //analogWrite(10, power);
  //digitalWrite(9, LOW);
  }else{
    ledcWrite(ledChannel4, 0);
ledcWrite(ledChannel5, 0);
   
  }
}
void MotorCounterClockwise3(int power){
  if(power > 100){
     ledcWrite(ledChannel6, power);
ledcWrite(ledChannel7, 0);
  }else{
     ledcWrite(ledChannel6, 0);
ledcWrite(ledChannel7, 0);
  }
}

void encoder3(){

  if(digitalRead(motorSen3B) == HIGH){
    encoder_pos3++;
  }else{
    encoder_pos3--;
  }
}


// Motor 5 & 6
void encoder4( ){
//ledcWrite(ledChannel, 100);
  if(digitalRead(motorSen4B) == HIGH){
    encoder_pos4++;
  }else{
    encoder_pos4--;
  }
}
void encoder5( ){
//ledcWrite(ledChannel, 100);
  if(digitalRead(motorSen5B) == HIGH){
    encoder_pos5++;
  }else{
    encoder_pos5--;
  }
}
void MotorClockwise4(int power){
  if(power > 100){
    ledcWrite(ledChannel8, 0);
ledcWrite(ledChannel9, power);
//  analogWrite(9, power);
  //digitalWrite(10, LOW);
  }else{
    ledcWrite(ledChannel8, 0);
ledcWrite(ledChannel9, 0);
  }
}
void MotorClockwise5(int power){
  if(power > 100){
 ledcWrite(ledChannel10, 0);
ledcWrite(ledChannel11, power);
  }else{
 ledcWrite(ledChannel10, 0);
ledcWrite(ledChannel11, power);
  }
}

void MotorCounterClockwise4(int power){
  if(power > 100){ 
  ledcWrite(ledChannel8, power);
ledcWrite(ledChannel9, 0);
  //analogWrite(10, power);
  //digitalWrite(9, LOW);
  }else{
    ledcWrite(ledChannel8, 0);
ledcWrite(ledChannel9, 0);
    //digitalWrite(9, LOW);
    //digitalWrite(10, LOW);
  }
}
void MotorCounterClockwise5(int power){
  if(power > 100){
 ledcWrite(ledChannel10, power);
ledcWrite(ledChannel11, 0);
  }
  else{
     ledcWrite(ledChannel10, 0);
     ledcWrite(ledChannel11, 0);
  }
}


void loop(){
  int finale=0;
 while(1){
  ledcWrite(ledChannel, 245);
   ledcWrite(ledChannel1, 0);
  ledcWrite(ledChannel2, 0);
  ledcWrite(ledChannel3, 245);
  
  delay(3000);
  ledcWrite(ledChannel, 150);
  ledcWrite(ledChannel1, 0);
  ledcWrite(ledChannel2, 150);
ledcWrite(ledChannel3, 0);

  delay(3000);
  cont=1;
  int calant[5]={0,0,0,0,0};
  int x[5]={0,0,0,0,0};
  delay(100);

 while(1){
  
  for(int u=0; u<5;u++){
    //Serial.println(x[0]);
    if(cal[u]==calant[u]){
    delay(1);
     if(cal[u]==calant[u]){
    Serial.println(x[0]);
    Serial.println(calant[0]);
     x[u]++;
     }
     
 }
  if(cal[u]>calant[u]){
   calant[u]=cal[u];    // Serial.println(x[0]);
Serial.println("d");
  }
  
  
  //Serial.println(x);
  if(x[u]==20){
   switch (u){
   case 0:
 ledcWrite(ledChannel, 0);
 ledcWrite(ledChannel1, 0);
 finale++;
  break;
  case 1:
 ledcWrite(ledChannel2, 0);
 ledcWrite(ledChannel3, 0);
 finale++;
  break;
  case 2:
 ledcWrite(ledChannel4, 0);
 ledcWrite(ledChannel5, 0);
 finale++;
  break;
  case 3:
 ledcWrite(ledChannel6, 0);
 ledcWrite(ledChannel7, 0);
 finale++;
  break;
  case 4:
 ledcWrite(ledChannel8, 0);
 ledcWrite(ledChannel9, 0);
 finale++;
  break;
  default:
   ;}
  }
  }
  
  }
  
 
  if (finale==4)
  {
    
    
    break;
    }
 cal[0]=0;
 cont=0;
 

 }

if (Serial.available() > 0) {  
    integerValue = 0;        
    while(1) {           
      incomingByte = Serial.read();
      if (incomingByte == '\n') break;   
      if (incomingByte == -1) continue;  
      integerValue *= 10;  
      integerValue = ((incomingByte - 48) + integerValue);
     
    }
     pos_pid.setpoint(integerValue);
      pos1_pid.setpoint(integerValue);
       pos2_pid.setpoint(integerValue);
      pos3_pid.setpoint(integerValue);
       pos4_pid.setpoint(integerValue);
      pos5_pid.setpoint(integerValue);
     // Serial.println(integerValue);
}

   motor_value = pos_pid.compute(encoder_pos);
   Serial.println(motor_value);
if(motor_value >= 0){
  MotorCounterClockwise(motor_value);
}else{
  MotorClockwise(abs(motor_value));
}
 motor_value = pos1_pid.compute(encoder_pos1);

if(motor_value > 0){
  MotorCounterClockwise1(motor_value);
}else{
  MotorClockwise1(abs(motor_value));
}
motor_value = pos2_pid.compute(encoder_pos2);
if(motor_value > 0){
  MotorCounterClockwise2(motor_value);
}else{
  MotorClockwise2(abs(motor_value));
}
motor_value = pos3_pid.compute(encoder_pos3);
if(motor_value > 0){
  MotorCounterClockwise3(motor_value);
}else{
  MotorClockwise3(abs(motor_value));
}
motor_value = pos4_pid.compute(encoder_pos4);
if(motor_value > 0){
  MotorCounterClockwise4(motor_value);
}else{
  MotorClockwise4(abs(motor_value));
}
motor_value = pos5_pid.compute(encoder_pos5);
if(motor_value > 0){
  MotorCounterClockwise5(motor_value);
}
else{
  MotorClockwise5(abs(motor_value));
}
  Serial.println((String)encoder_pos+","+(String)encoder_pos1);
  //Serial.println(digitalRead(motorSen1B));
//   Serial.println(",");
  // Serial.println(encoder_pos1);
  delay(10);
}
