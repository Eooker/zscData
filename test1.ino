#include<my_arduinolib.h>

void setup() {
    Serial.begin(9600);
    DianJi_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  DianJi(M1,QianJin,95);
  DianJi(M2,QianJin,95);
//  delay(3000);
//  DianJi(M1,HouTui,60);
//  DianJi(M2,HouTui,20);
  delay(2000);
  Serial.println("11111");
  delay(8000);
  Serial.println("22222");
  delay(2000);
  Serial.println("33333");
}
