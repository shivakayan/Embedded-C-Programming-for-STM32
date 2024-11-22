#include "stm32f401xe.h"

int main()
{
	int count=0;
	int num[10]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
	RCC->AHB1ENR = 0X00000001;
	GPIOA->MODER&=~0XFFFFFFFF;
	GPIOA->MODER|=0x05555555;
	GPIOA->PUPDR&=~0XF0000000;
	GPIOA->PUPDR|=0X50000000;
	while(1)
	{
		if((GPIOA->IDR & 0X00008000)==0)
		{
			while((GPIOA->IDR&0X00008000)== 0);
			count++;
			count%=100;
			GPIOA->ODR = num[(count/10)%10]<<7 | num[count%10];
		}
		if((GPIOA->IDR & 0X00004000)==0)
		{
			while((GPIOA->IDR&0X00004000)== 0);
			count=(count==0)?0:(count-1);
			count%=100;
			GPIOA->ODR = num[(count/10)%10]<<7 | num[count%10];
		}
	}
}