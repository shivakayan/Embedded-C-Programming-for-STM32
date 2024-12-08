#include <stm32f401xe.h>
void MSDelay(unsigned int);
void KeypadInit(void);
char KeyScan(void);
void MSDelay(unsigned int Times)
{
	unsigned int i,j;
	for(i=0;i<Times;i++)
	{
		for(j=0;j<1400;j++);
	}
}
char KeyScan(void)
{
	int temp;
	while(1)
	{
		GPIOB->ODR&=!0X000000F;
		while((GPIOB->IDR&0X70)==0X70);
		GPIOB->ODR&=~0X00FF;
		GPIOB->ODR|= 0X0E;
		temp = GPIOB->IDR & 0X70;
		switch(temp)
		{
			case 0X60:
				return 1;
				break;
			case 0X50:
				return 2;
				break;
			case 0X30:
				return 3;
				break;
		}
		GPIOB->ODR&=~0X00FF;
		GPIOB->ODR|= 0X0D;
		temp = GPIOB->IDR & 0X70;
		switch(temp)
		{
			case 0X60:
				return 4;
				break;
			case 0X50:
				return 5;
				break;
			case 0X30:
				return 6;
				break;
		}
		GPIOB->ODR&=~0X00FF;
		GPIOB->ODR|= 0X0B;
		temp = GPIOB->IDR & 0X70;
		switch(temp)
		{
			case 0X60:
				return 7;
				break;
			case 0X50:
				return 8;
				break;
			case 0X30:
				return 9;
				break;
		}
		GPIOB->ODR&=~0X00FF;
		GPIOB->ODR|= 0X07;
		temp = GPIOB->IDR & 0X70;
		switch(temp)
		{
			case 0X60:
				return 11;
				break;
			case 0X50:
				return 10;
				break;
			case 0X30:
				return 12;
				break;
		}
	}
}

void KeypadInit(void)
{
	RCC->AHB1ENR|=2;
	GPIOB->MODER&=~(0xFF003FFF);
	GPIOB->MODER|=(0x55000055);
	GPIOB->PUPDR&=~(0X00003F00);
	GPIOB->PUPDR|=0X00001500;
}

int main(void)
{
	char key;
	KeypadInit();
	while(1)
	{
		key=KeyScan();
		GPIOB->ODR&=~0xF000;
		GPIOB->ODR|=key<<12;
		MSDelay(500);
	}
}