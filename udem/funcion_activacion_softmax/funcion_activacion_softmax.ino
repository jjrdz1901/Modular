double n[3] = {1,3,2.5};
double a[3];

void setup() {
  Serial.begin(9600);
  double aux = 0.0;
  for(int s = 0; s<3;s++){aux = aux+exp(n[s]);}
  for(int s = 0; s<3; s++){a[s] = exp(n[s])/aux; Serial.println(a[s],4);}
  
}

void loop() {

}
