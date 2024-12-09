#include <stm32f401xe.h>
void MSDelay(unsigned int);
void KeypadInit(void);
char KeyScan(void);
void lcdprint(char);
void lcdinit(void);
void sendcmd(char);
void printstr(char*);
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
	GPIOB->MODER&=~(0xFF003FFF);
	GPIOB->MODER|=(0x55000055);
	GPIOB->PUPDR&=~(0X00003F00);
	GPIOB->PUPDR|=0X00001500;
}
void lcdprint(char ch)
{
	GPIOA->ODR&=~0XFF03;
	GPIOA->ODR|=ch<<8;
	GPIOA->ODR|=0x01;//making RS high to tell its data.
	GPIOA->ODR|=0x02;//Making enable high
	MSDelay(5);
	GPIOA->ODR&=~0x0002;//making enable low;
}
void sendcmd(char ch)
{
	GPIOA->ODR&=~0XFF03;
	GPIOA->ODR|=ch<<8;
	GPIOA->ODR|=0x02;//Making enable high
	MSDelay(5);
	GPIOA->ODR&=~0x0002;//making enable low;
}
void lcdinit(void)
{
	GPIOA->MODER&=~0XFFFF000F;
	GPIOA->MODER|=0X55550005;
	sendcmd(0x38);//16 column 2 row mode
	sendcmd(0x0F);//display on cursor blinking
	sendcmd(0x06);//auto increment
	sendcmd(0x01);//clear display
}
void printstr(char *ch)
{
	int i;
	for(i=0;ch[i]!='\0';i++)
	{
		lcdprint(ch[i]);
	}
}
int main(void)
{
	char key;
	RCC->AHB1ENR|=3;
	KeypadInit();
	lcdinit();
	while(1)
	{
		key=KeyScan();
		GPIOB->ODR&=~0xF000;
		GPIOB->ODR|=key<<12;
		if(key==11)
			sendcmd(0xc0);
		else if(key==12)
			sendcmd(0x01);
		else if(key==10)
			printstr("10");
		else
			lcdprint(key+48);
		MSDelay(500);
	}
}