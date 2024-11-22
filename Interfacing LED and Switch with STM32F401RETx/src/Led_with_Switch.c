#include "stm32f401xe.h"

int main()
{
	_Bool flag;
	RCC->AHB1ENR = 0X0000001;
	GPIOA->MODER&=~0X0000000F;
	GPIOA->MODER|=0X0000001;
	GPIOA->PUPDR&=~0X0000000C;
	GPIOA->PUPDR|=0X00000004;
	while(1)
	{
		flag = GPIOA->IDR & 0X00000002;
		if(!flag)
			GPIOA->ODR|= 0x00000001;
		else
			GPIOA->ODR &= ~0X0000001;
	}
}