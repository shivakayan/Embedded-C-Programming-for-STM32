#include "stm32f401xe.h"

int main()
{
	int count=0;
	int num[10]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
	RCC->AHB1ENR = 0X00000001;
	GPIOA->MODER&=~0X00033FFF;
	GPIOA->MODER|=0x00001555;
	GPIOA->PUPDR&=~0X00030000;
	GPIOA->PUPDR|=0X00010000;
	while(1)
	{
		if((GPIOA->IDR & 0X00000100)==0)
		{
			while((GPIOA->IDR&0X00000100)== 0);
			count++;
			count%=10;
			GPIOA->ODR = num[count];
		}
	}
}