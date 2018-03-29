#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include "gotoxy.h"
#include "common.h"
#pragma comment(lib,"winmm.lib") 

int Get_key(int key)		//获取键值
{
	char ch;
	while(1)
	{
		ch = getch();
		if(ch == -32)
		{
			ch = getch();
			
			if(ch == UP)
				key = 1;
				
			if(ch == DOWN)
				key = 2;

			if(ch == LEFT)
				key = 3;

			if(ch == RIGHT)
				key = 4;
		}
		
		else if(ch == BACKSPACE)
			key = 5;
		
		else if(ch == ENTER)
			key = 6;
		
		else if(ch == ESC)
			key = 7;

		else if(ch == SPACE)
			key = 8;

		else if(ch == 82 || ch == 114)
			key = 9;

		else if(ch == 49)
			key = 11;

		else if(ch == 50)
			key = 12;

		else if(ch == 51)
			key = 13;

		else if(ch == 52)
			key = 14;

		else
			continue;
			
		return key;
	}
}

int Glb_putstring(char *acStr, int iMaxLen, int iPutType, int isPlaintext)		//控制输入字符串
{
	int  i = 0, key = 0, count = 0;
	char ch;
	while(1)
	{
		ch = getch();
		if(ch =='\r')					//	这里'\r'表示为回车，结束账号输入；		 而'\n'包含两个动作，一个是回车，一个是换行。
			break;
					
		else if(ch == BACKSPACE)				//  '\b'为退格键 
		{							
			if(i > 0  && iPutType != 5)
			{
				i--;
			    acStr[i] = '\0';
				printf("\b \b");	//  "\b \b"的作用就是把光标往回移动一格，打印一个空格（把之前打印过的字符覆盖掉），然后再往回移动一格
									//  实际效果等于光标往回一格，并且删掉光标前的那个字符
			}
			else if(i > 0 && iPutType == 5)
			{
				acStr[--i] = '\0';
				acStr[--i] = '\0';
				printf("\b \b");
				printf("\b \b");
			}
		}
		
		else if(ch == ESC)			//按ESC					 
		{
			key = 1;
			return key;
		}
		
		else if(ch == -32)			//若不写该判断，方向键第二个键值 72,80,75,77 将输出字母 H,P,M,K
		{
			ch = getch();
			continue;
		}
		
		else
		{		
			switch(iPutType)
			{
				case 0:
					if(i < iMaxLen)
					{
						acStr[i] = ch;
						if(isPlaintext == 0)
							putchar(ch);
						if(isPlaintext == 1)
							putchar('*');
						i++;
					}
					break;
					
				case 1:
					if(i < iMaxLen && (ch >= '0' && ch <= '9'))
					{
						acStr[i] = ch;
						if(isPlaintext == 0)
							putchar(ch);
						if(isPlaintext == 1)
							putchar('*');
						i++;
					}
					break;
					
				case 2:
					if(i < iMaxLen && ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <='Z')))
					{
						acStr[i] = ch;
						if(isPlaintext == 0)
							putchar(ch);
						if(isPlaintext == 1)
							putchar('*');
						i++;
					}
					break;
					
				case 3:
					if(i < iMaxLen && ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <='Z') || (ch >= '0' && ch <= '9')) && ch != -32)
					{
						acStr[i] = ch;
						if(isPlaintext == 0)
							putchar(ch);
						if(isPlaintext == 1)
							putchar('*');
						i++;
					}
					break;
					
				case 4:
					if(i < iMaxLen && ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <='Z') || (ch >= '0' && ch <= '9')||(ch == '_')))
					{
						acStr[i] = ch;
						if(isPlaintext == 0)
							putchar(ch);
						if(isPlaintext == 1)
							putchar('*');
						i++;
					}
					break;	
					
				case 5:
					if(i < iMaxLen-1 && ch > 0x80000000)
					{
						acStr[i++] = ch;
						count++;
						if(count % 2 == 0)
						{
							gotoxy(12,43);	
							printf("%s",acStr);
							count = 0;
						}
					}
					break;
					
				default:
					break;
			}
		}
	}
	return 0;
}

void real_time()			//显示时间的函数，用到了光标移动函数，X，Y表示坐标
{
	int x, y;
	SYSTEMTIME sys; 

	while(1)
	{
		x = wherex();
		y = wherey();		
		gotoxy(2,51);
		GetLocalTime(&sys);
		printf("%4d/%02d/%02d %02d:%02d:%02d\n",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute, sys.wSecond);
		gotoxy(x,y);   //光标还原
		Sleep(1000);
	}	
}	

char *gettime(char *buffer)
{
    time_t rawtime;
    struct tm * timeinfo;

	
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,15,"%Y%m%d%H%M%S",timeinfo);
	return buffer;
}

void color(const unsigned short color1)
{
	/*颜色对应值：

　　0=黑色                   8=灰色　　
  　1=淡蓝色                 9=蓝色                                        
　　2=淡绿色                10=绿色          0xa        
　　3=湖蓝色				11=淡绿色        0xb　
　　4=淡红色                12=红色			 0xc　　
　　5=淡紫色                13=紫色          0xd        　
　　6=淡黄色                14=黄色          0xe        
　　7=亮白色                15=白色		     0xf

　　也可以吧这些值设置成常量。
	*/

	/*仅限改变0-15的颜色;如果在0-15那么实现他的颜色   因为如果超过15后面的改变的是文本背景色。*/
	if(color1>=0&&color1<=15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
	/*如果不在0-15的范围颜色，那么改为默认的颜色白色；*/
    else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}	

void Print_space(int n)		//打印空格，用于覆盖信息
{
	char ch = ' ';
	while(n--)
	{
		putchar(ch);
	}
}


void Clear_msg(int x, int y, int n, int flag)	//	把(x,y)处开始的提示信息覆盖，并根据需要,可把光标再定位到(x,y) 
{
	gotoxy(x,y);
	Print_space(n);
	
	if(flag == 1)
		gotoxy(x,y);
}
		
			
int Move_arrow(int x, int y, int z)		//箭头移动
{
	int i = 1, key = 0, arrow = 26;	
	gotoxy(x,y); 	
	while(1)
	{
		key = Get_key(key);
		
		if(key == 1)
		{
			if(i > 1)
			{
				Clear_msg(x,y,1,0);
				
				i -- ;
				x = x - 2 ;
				
				gotoxy(x,y);
				printf("%c",arrow);				
				continue;
			}
			else if(i == 1)
			{
				if(z != 0)
				{
					Clear_msg(x,y,1,0);
					i = z;
					x = x + 2 * (z-1);
					gotoxy(x,y);
					printf("%c",arrow);	
					continue;
				}
				else
				{
					gotoxy(x,y);
					printf("%c",arrow);	
					continue;
				}

			}
		}
		
		else if(key == 2)
		{			
			if(i < z)
			{
				Clear_msg(x,y,1,0);
				
				i ++ ;
				x = x + 2 ;
				
				gotoxy(x,y);
				printf("%c",arrow);				
				continue;
			}
			else if(i == z)
			{
				Clear_msg(x,y,1,0);
				i = 1;
				x = x - 2 * (z - 1) ;
				
				gotoxy(x,y);
				printf("%c",arrow);				
				continue;
			}
		}

		else if(key == 3)	//左翻
		{
			Clear_arrow(x,y);
			return 30;
		}

		else if(key == 4)	//右翻
		{
			Clear_arrow(x,y);
			return 40;
		}
		
		else if(key == 6)	//回车
		{
			return i;
		}

		else if(key == 7)	//ESC
		{
			Clear_arrow(x,y);
			return 0;
		}
		
		else
		{
			continue;
		}
	}
}	

	
/*************************用于注册、修改*************************/

int Test_empty(char ch)
{
	if(ch == '\0')
	{
		color(12);
		gotoxy(4,33);
		printf("can't be empty!");
		getch();
		color(14);
		Clear_msg(4,25,32,0);
		return 1;
	}		
	else
		return 0;
}

int Test_admin(char *s)
{	
	if(strcmp(s,"irelia") == 0)
	{
		color(12);
		gotoxy(4,25);
		printf("Admin account can't be resgiter!");
		getch();
		Clear_msg(4,25,32,0);
		color(14);
		return 1;
	}
	else
		return 0;
}


int Test_same(char *s1, char *s2)
{	
	if(strcmp(s1,s2) == 0)
	{
		color(12);
		gotoxy(4,25);
		printf("This account has been resgiter!");
		getch();
		Clear_msg(4,25,32,0);
		color(14);
		return 1;		
	}
	else
		return 0;
	
}

int Test_passwd(char *s1, char *s2)
{
	if(strcmp(s1,s2) != 0)						//	确认密码
	{
		color(12);
		gotoxy(4,27);
		printf("Entered passwords differ!");
		getch();
		color(14);
		Clear_msg(4,27,32,0);
		
		Clear_msg(8,43,6,0);
		
		Clear_msg(10,43,6,0);
		
		return 1;
	}	
	else
		return 0;
}

int Test_len(char *s1, int n)
{
	if((int)(strlen(s1)) < n)						//	确认密码
	{
		color(12);
		gotoxy(4,32);
		printf("Must be %d bits!",n);
		getch();
		Clear_msg(4,27,32,0);
		color(14);
		return 1;
	}	
	else
		return 0;
}

void Clear_arrow(int x, int y)
{
	gotoxy(x,y);
	printf(" ");
}

void show_money(int n)
{
	int i = 0, temp;
	char s[10];
	if(n == 0)
	{
		printf("%d",n);
		return ;
	}

	if(n < 0)
	{
		putchar('-');
		n = abs(n);
	}
	else
		putchar('+');

	while(n!=0)
	{
		temp = n % 10;
		s[i] = temp + '0';
		n /= 10;
		i++;
	}

	n = i;
	temp = 0;
	for(i = i - 1; i >= 0; i--)
	{
		putchar(s[i]);
		temp++;
		if((n-temp) % 3 == 0 && (n-temp)!=0)
			putchar(',');
	}
}

int Get_rand()
{
	int n = 0;

	srand(time(0));
	while(1)
	{
		n = rand() % 9999; 
		if(n>=1000)
			break;
	}

	return n;
}

void Welcome()
{
	int n = 9;
	color(12);	
	gotoxy(16,19);
	printf("温馨提示:由于多线程并发执行的不可控性");
	gotoxy(18,28);
	printf("本系统可能出现显示混乱的情况");
	gotoxy(20,28);
	printf("如遇此种情况,请按ESC键返回刷新界面即可");
	gotoxy(22,28);
	printf("由此给您带来的不便，敬请谅解!");
	gotoxy(10,28);
	printf("欢迎使用中国农业银行ATM服务！\n");
	gotoxy(12,31);
	printf("正在载入界面");
	while(n--)
	{
		putchar('.');
		Sleep(1000);
	}
	PlaySound ("1.wav",NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void byebye()
{
	int n = 6;
	gotoxy(11,19);	printf("温馨提示:感谢您的使用!离开柜台前");
	gotoxy(13,28);	printf("请清点好您的贵重物品,取走您的卡和现金");
	gotoxy(15,28);	printf("期待下次再见");
	while(n--)
	{
		putchar('.');
		Sleep(1000);
	}
	exit(0);
}
