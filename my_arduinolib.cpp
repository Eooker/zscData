#include "my_arduinolib.h"
#include "Arduino.h"

void DianJi_init()
{
    pinMode(M1_A,OUTPUT);
    pinMode(M1_B,OUTPUT);
    pinMode(M2_A,OUTPUT);
    pinMode(M2_B,OUTPUT);
}


void DianJi(char *MM,char *fangxiang,int pwm)     //电机控制函数，参数：MM电机选择（M1、M2） fangxiang电机转动方向（QianJin、HouTui）  pwm电机转速(0-255)
{
  if(pwm>=0&&pwm<=255)
  {
      if(fangxiang=="QianJin")
    {
      if(MM=="M1")
      {
        analogWrite(M1_A,pwm);
        digitalWrite(M1_B,LOW);
      }
      else if(MM=="M2")
      {
        digitalWrite(M2_A,pwm);
        digitalWrite(M2_B,LOW);

      }
       else
      {
        Serial.println("错误：电机选择参数错误");
      }
    }
    else if(fangxiang=="HouTui")
    {
      if(MM=="M1")
      {
        digitalWrite(M1_A,pwm);
        digitalWrite(M1_B,HIGH);
      }
      else if(MM=="M2")
      {
        digitalWrite(M2_A,pwm);
        digitalWrite(M2_B,HIGH);
      }
      else
      {
        Serial.println("错误：电机选择参数错误");
      }
    }
    else
    {
      Serial.println("错误：fangxiang参数错误");
      Serial.print("fangxiang参数为：");
      Serial.println(fangxiang);
    }
  }
  else
  {
    Serial.println("错误：pwm设置数据超出范围");
  }
}