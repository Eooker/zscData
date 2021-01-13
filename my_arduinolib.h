#include "Arduino.h"

#define M1_A 5
#define M1_B A2
#define M2_A 6
#define M2_B A3
#define M1 "M1"
#define M2 "M2"
#define QianJin "QianJin"
#define HouTui "HouTui"

#define Servo_A1 A4
#define Servo_A2 A5

#define Servo_D1 2
#define Servo_D2 10
#define Servo_D4 13

void DianJi_init();
void DianJi(char *MM,char *fangxiang,int pwm);
