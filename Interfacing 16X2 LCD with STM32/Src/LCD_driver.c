#include "stm32f401xe.h"
void MSDelay(unsigned int);
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
	GPIOA->ODR&=~0x01;//making RS low to tell its cmd.
	GPIOA->ODR|=0x02;//Making enable high
	MSDelay(5);
	GPIOA->ODR&=~0x0002;//making enable low;
}
void lcdinit(void)
{
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
int main()
{
	RCC->AHB1ENR = 1;
	GPIOA->MODER&=~0XFFFF000F;
	GPIOA->MODER|=0X55550005;
	lcdinit();
	sendcmd(0x80);
	printstr("   Welcome to   ");
	sendcmd(0xc0);
	printstr("   TechTalks!   ");
	while(1);
}