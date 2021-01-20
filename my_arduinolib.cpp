#include "my_arduinolib.h"
#include "Arduino.h"

void motor_init()                   //电机初始化函数
{
    pinMode(M1_A,OUTPUT);
    pinMode(M1_B,OUTPUT);
    pinMode(M2_A,OUTPUT);
    pinMode(M2_B,OUTPUT);
}

void motor_stop(char *MM)           //电机停止函数，参数：MM电机选择（M1、M2）
{
  if(MM=="M1")
  {
    digitalWrite(M1_A,LOW);
    digitalWrite(M1_B,LOW);
  }
  else if(MM=="M2")
  {
    digitalWrite(M2_A,LOW);
    digitalWrite(M2_B,LOW);
  }
  else
  {
    Serial.println("错误：电机选择参数错误");
  }
}

void motor_motion(char *MM,char *Direction,int pwm)     //电机运动控制函数，参数：MM电机选择（M1、M2） Direction电机转动方向（forward、backward）  pwm电机转速(forward:90-250、backward:10-160)
{
  if(Direction=="forward")            //pwm:90-250
  {
    if(pwm>=90&&pwm<=250)
    {
      if(MM=="M1")
      {
        analogWrite(M1_A,pwm);
        digitalWrite(M1_B,LOW);
      }
      else if(MM=="M2")
      {
        analogWrite(M2_A,pwm);
        digitalWrite(M2_B,LOW);

      }
       else
      {
        Serial.println("错误：电机选择参数错误");
      }
    }
    else
    {
      Serial.println("错误：pwm设置数据超出范围");
    }
  }
  else if(Direction=="backward")       //pwm:10-160
  {
    if(pwm>=10&&pwm<=160)
    {
      if(MM=="M1")
      {
        analogWrite(M1_A,pwm);
        digitalWrite(M1_B,HIGH);
      }
      else if(MM=="M2")
      {
        analogWrite(M2_A,pwm);
        digitalWrite(M2_B,HIGH);
      }
      else
      {
        Serial.println("错误：电机选择参数错误");
      }
    }
    else
    {
      Serial.println("错误：pwm设置数据超出范围");
    }
  }
  else
  {
    Serial.println("错误：Direction参数错误");
  }
}
