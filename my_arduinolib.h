#include "Arduino.h"

#define M1_A 5
#define M1_B A2
#define M2_A 6
#define M2_B A3
#define M1 "M1"
#define M2 "M2"
#define forward "forward"
#define backward "backward"

#define Servo_A1 A4
#define Servo_A2 A5

#define Servo_D1 2
#define Servo_D2 10
#define Servo_D4 13

void motor_init();
void motor(char *MM,char *Direction,int pwm);
