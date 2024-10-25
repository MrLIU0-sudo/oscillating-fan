#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.h"
#include "Motor.h"
#include "PWM.h"

#include "Servo.h"
//#include "Buzzer.h"

int16_t Num;
float i;

int main()
{
	Motor_Init();
	Servo_Init();
	OLED_Init();
	Encoder_Init();
	OLED_ShowString(1,1,"Speed:");
//	Servo_SetAngle(10);
	
//	OLED_ShowChar(1,1,'A');
//	OLED_ShowString(1,3,"HelloWorld!");
//	OLED_ShowNum(2,1,12345,5);
////	OLED_ShowSignedNum(2,7,12345,5);
//	OLED_ShowSignedNum(2,7,-66,2);
//	OLED_ShowHexNum(3,1,0xAA55,4);
//	OLED_ShowBinNum(4,1,0xAA55,16);
//	
//	OLED_Clear();
//	
	while(1)
	{

//		Num+=Encoder_Get();
//		if(Num<=-180 | Num>=180)
//		{
//			Num=0;
//		}

//		PWM_SetCompare1(Num); 
//		PWM_SetCompare2(Num);
//		Motor_SetSpeed(Num);
//		for(i=0;i<=180;i++)
//		{
//			Num+=Encoder_Get();

//            if(Num<=-180 | Num>=180)
//			{
//				Num=0;
//			}

//			PWM_SetCompare1(Num); 
//			PWM_SetCompare2(Num);
//			Motor_SetSpeed(Num);
//			Servo_SetAngle(i);
//			OLED_ShowSignedNum(1,7,Num,6);
//			Delay_ms(50);
//		}
//		for(i=180;i>=0;i--)
//		{
//			Num+=Encoder_Get();
//            if(Num<=-180 | Num>=180)
//			{
//				Num=0;
//			}
//			PWM_SetCompare1(Num); 
//			PWM_SetCompare2(Num);
//			Motor_SetSpeed(Num);
//			Servo_SetAngle(i);
//			OLED_ShowSignedNum(1,7,Num,6);
//			Delay_ms(50);
//		}
//		OLED_ShowSignedNum(1,5,Num,6);
		


//		if(Num>=0)
//		{
//			Servo_SetAngle((float)Num);
//		}
//		else
//		{
//			Servo_SetAngle((float)-Num);
//		}
//		OLED_ShowSignedNum(1,5,Num,6);
//		for(i=0;i<=100;i++)
//		{
//			PWM_SetCompare1(i);
//			Delay_ms(10);
//		}
//		for(i=0;i<=100;i++)
//		{
//			PWM_SetCompare1(100-i);
//			Delay_ms(10);
//		}

	}
}	
