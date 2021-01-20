#include<my_arduinolib.h>
#define Left  M1
#define Right M2
int Fpwm=120;    //前进速度pwm
int Bpwm=120;    //后退速度pwm
String pi_data="";
void setup() {
  Serial.begin(9600);
  motor_init();
}

void loop() {
  if(Serial.available())
  {
    delay(50);
    Serial.write("收到指令：");
    while(Serial.available())
    {
      pi_data=pi_data+char(Serial.read());
      delay(10);
    }
    Serial.println(pi_data);
    //Serial.println(Serial.available());
    if(pi_data=="前进")
    {
      Serial.println("执行指令：前进");
      motor_motion(Left,forward,Fpwm);
      motor_motion(Right,forward,Fpwm);
    }
    else if(pi_data=="后退")
    {
      Serial.println("执行指令：后退");
      motor_motion(Left,forward,Bpwm);
      motor_motion(Right,forward,Bpwm);
    }
    else if(pi_data=="停止")
    {
      Serial.println("执行指令：停止");
      motor_stop(Left);
      motor_stop(Right);
    }
    else if(pi_data=="加速")
    {
      if(Fpwm<=240)
      {
        Serial.println("执行指令：加速");
        Fpwm=Fpwm+10; 
      }
      else
      {
        Serial.println("速度已达到最大");
      }
      if(Bpwm>=20)
      {
        Serial.println("执行指令：加速");
        Bpwm=Bpwm-10; 
      }
      else
      {
        Serial.println("速度已达到最大");
      }
    }
    else if(pi_data=="减速")
    {
      if(Fpwm>=100)
      {
        Serial.println("执行指令：减速");
        Fpwm=Fpwm-10; 
      }
      else
      {
        Serial.println("速度已减到最小");
      }
      if(Bpwm<=150)
      {
        Serial.println("执行指令：减速");
        Bpwm=Bpwm+10; 
      }
      else
      {
        Serial.println("速度已减到最小");
      }
    }
    else
    {
      Serial.println("无效指令");
    }
    pi_data="";
  }
}
