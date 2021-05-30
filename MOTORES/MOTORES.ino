#include <PIDController.h>
//volatile long int encoder_pos[5] = {0,0,0,0,0,0},encoder_pos1 = 0;
volatile long int encoder_pos=0,encoder_pos1 = 0;

PIDController pos_pid; 
PIDController pos1_pid;
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
  ledcAttachPin(motor0A, ledChannel);
  ledcAttachPin(motor0B, ledChannel1);
   ledcAttachPin(motor1A, ledChannel2);
  ledcAttachPin(motor1B, ledChannel3);


ledcWrite(ledChannel, 100);
ledcWrite(ledChannel1, 150);
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
   //pinMode(4, INPUT);
 // pinMode(5, INPUT);
  //pinMode(9, OUTPUT); // 16 corresponds to GPIO1
  //pinMode(10, OUTPUT);
  // pinMode(11, OUTPUT);
  //pinMode(6, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(36), encoder, RISING);
  attachInterrupt(digitalPinToInterrupt(3), encoder1, RISING);
  pos_pid.begin();    
  pos_pid.tune(15, 1, 2000);    
  pos_pid.limit(-255, 255);
  pos1_pid.begin();    
  pos1_pid.tune(15, 1, 2000);    
  pos1_pid.limit(-255, 255);
}


void encoder1(){

  if(digitalRead(5) == HIGH){
    encoder_pos1++;
  }else{
    encoder_pos1--;
  }
}

void encoder( ){
//ledcWrite(ledChannel, 100);
  if(digitalRead(motorSen0B) == HIGH){
    encoder_pos++;
  }else{
    encoder_pos--;
  }
}

void MotorClockwise(int power){
  if(power > 100){
    ledcWrite(ledChannel, 0);
ledcWrite(ledChannel1, power);
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
//  analogWrite(6, power);
  digitalWrite(11, LOW);
  }else{
    digitalWrite(6, LOW);
    digitalWrite(11, LOW);
  }
}

void MotorCounterClockwise(int power){
  if(power > 100){
  ledcWrite(ledChannel, power);
ledcWrite(ledChannel1, 0);
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
//  analogWrite(11, power);
  digitalWrite(6, LOW);
  }else{
    digitalWrite(6, LOW);
    digitalWrite(11, LOW);
  }
}

void loop() {
  
if (Serial.available() > 0) {  
    integerValue = 0;        
    while(1) {           
      incomingByte = Serial.read();
      if (incomingByte == '\n') break;   
      if (incomingByte == -1) continue;  
      integerValue *= 10;  
      integerValue = ((incomingByte - 48) + integerValue);
      pos_pid.setpoint(integerValue);
      pos1_pid.setpoint(integerValue);
    }
}

   motor_value = pos_pid.compute(encoder_pos);
if(motor_value > 0){
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
  Serial.println((String)encoder_pos+","+(String)encoder_pos1);
  //Serial.println(digitalRead(motorSen1B));
//   Serial.println(",");
  // Serial.println(encoder_pos1);
  delay(10);
}
