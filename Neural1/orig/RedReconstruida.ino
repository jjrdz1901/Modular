void setup(){
  Serial.begin(9600);
}

void loop(){
  
  double RedNeuronal = RED(-3.7877,4.0795,0.1747,0.6067,10.3);
  Serial.println(RedNeuronal);
  delay(1000);

}

double ConvEntrada1(double Entrada1){
  double maxx = 1;
  double minn = -1;

  double xmaxx = 0.4930;
  double xminn = 0.2936;



  double Scala = (maxx - minn)/(xmaxx - xminn) *(Entrada1 - xminn) + minn;
  return  Scala;  

}

double ConvEntrada2(double Entrada2){
  double maxx = 1;
  double minn = -1;

  double xmaxx = 8.4100;
  double  xminn = 5.1200;



  double Scala = (maxx - minn)/(xmaxx - xminn) *(Entrada2 - xminn) + minn;
  return  Scala;  

}

double ConvSalida(double z){

  double maxx = 3.2133;
  double minn = 2.9140;

  double xmaxx = 1;
  double xminn = -1;



  double Scala = (maxx - minn)/(xmaxx - xminn) *(z - xminn) + minn;
  return  Scala;  

}

double RED (double w1, double w2, double bias, double Ent1, double Ent2){
  double Entrada1 = ConvEntrada1(Ent1);
  double Entrada2 = ConvEntrada2(Ent2);
  double Z = w1*Entrada1 + w2*Entrada2 + bias;
  double Salida = ConvSalida(Z);

  return Salida;
}