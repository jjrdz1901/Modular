#include <math.h>
const int PatternCount=10;
const int InputNodes=7;
const int HiddenNodes=8;
const int OutputNodes=4;

const float LearningRate=0.3;
const float Momentum = 0.9;
const float InitialWeightMax=0.5;
const float Success = 0.0004;

const byte Input[PatternCount][InputNodes]={
  {1,1,1,1,1,1,0},//0
  {0,1,1,0,0,0,0},//1
  {1,1,0,1,1,0,1},//2
  {1,1,1,1,1,1,0},//3
  {0,1,1,0,0,1,1},//4
  {1,0,1,1,0,1,1},//5
  {0,0,1,1,1,1,1},//6
  {1,1,1,0,0,0,0},//7
  {1,1,1,1,1,1,1},//8
  {1,1,1,0,0,1,1},//9
  
  };


const byte Target[PatternCount][OutputNodes]=
{
  {0,0,0,0},
  {0,0,0,1},
  {0,0,1,0},
  {0,0,1,1},
  {0,1,0,0},
  {0,1,0,1},
  {0,1,1,0},
  {0,1,1,1},
  {1,0,0,0},
  {1,0,0,1},
    };


    
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
