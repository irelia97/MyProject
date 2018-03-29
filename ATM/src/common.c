#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include "gotoxy.h"
#include "common.h"
#pragma comment(lib,"winmm.lib") 

int Get_key(int key)		//��ȡ��ֵ
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

int Glb_putstring(char *acStr, int iMaxLen, int iPutType, int isPlaintext)		//���������ַ���
{
	int  i = 0, key = 0, count = 0;
	char ch;
	while(1)
	{
		ch = getch();
		if(ch =='\r')					//	����'\r'��ʾΪ�س��������˺����룻		 ��'\n'��������������һ���ǻس���һ���ǻ��С�
			break;
					
		else if(ch == BACKSPACE)				//  '\b'Ϊ�˸�� 
		{							
			if(i > 0  && iPutType != 5)
			{
				i--;
			    acStr[i] = '\0';
				printf("\b \b");	//  "\b \b"�����þ��ǰѹ�������ƶ�һ�񣬴�ӡһ���ո񣨰�֮ǰ��ӡ�����ַ����ǵ�����Ȼ���������ƶ�һ��
									//  ʵ��Ч�����ڹ������һ�񣬲���ɾ�����ǰ���Ǹ��ַ�
			}
			else if(i > 0 && iPutType == 5)
			{
				acStr[--i] = '\0';
				acStr[--i] = '\0';
				printf("\b \b");
				printf("\b \b");
			}
		}
		
		else if(ch == ESC)			//��ESC					 
		{
			key = 1;
			return key;
		}
		
		else if(ch == -32)			//����д���жϣ�������ڶ�����ֵ 72,80,75,77 �������ĸ H,P,M,K
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

void real_time()			//��ʾʱ��ĺ������õ��˹���ƶ�������X��Y��ʾ����
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
		gotoxy(x,y);   //��껹ԭ
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
	/*��ɫ��Ӧֵ��

����0=��ɫ                   8=��ɫ����
  ��1=����ɫ                 9=��ɫ                                        
����2=����ɫ                10=��ɫ          0xa        
����3=����ɫ				11=����ɫ        0xb��
����4=����ɫ                12=��ɫ			 0xc����
����5=����ɫ                13=��ɫ          0xd        ��
����6=����ɫ                14=��ɫ          0xe        
����7=����ɫ                15=��ɫ		     0xf

����Ҳ���԰���Щֵ���óɳ�����
	*/

	/*���޸ı�0-15����ɫ;�����0-15��ôʵ��������ɫ   ��Ϊ�������15����ĸı�����ı�����ɫ��*/
	if(color1>=0&&color1<=15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
	/*�������0-15�ķ�Χ��ɫ����ô��ΪĬ�ϵ���ɫ��ɫ��*/
    else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}	

void Print_space(int n)		//��ӡ�ո����ڸ�����Ϣ
{
	char ch = ' ';
	while(n--)
	{
		putchar(ch);
	}
}


void Clear_msg(int x, int y, int n, int flag)	//	��(x,y)����ʼ����ʾ��Ϣ���ǣ���������Ҫ,�ɰѹ���ٶ�λ��(x,y) 
{
	gotoxy(x,y);
	Print_space(n);
	
	if(flag == 1)
		gotoxy(x,y);
}
		
			
int Move_arrow(int x, int y, int z)		//��ͷ�ƶ�
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

		else if(key == 3)	//��
		{
			Clear_arrow(x,y);
			return 30;
		}

		else if(key == 4)	//�ҷ�
		{
			Clear_arrow(x,y);
			return 40;
		}
		
		else if(key == 6)	//�س�
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

	
/*************************����ע�ᡢ�޸�*************************/

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
	if(strcmp(s1,s2) != 0)						//	ȷ������
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
	if((int)(strlen(s1)) < n)						//	ȷ������
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
	printf("��ܰ��ʾ:���ڶ��̲߳���ִ�еĲ��ɿ���");
	gotoxy(18,28);
	printf("��ϵͳ���ܳ�����ʾ���ҵ����");
	gotoxy(20,28);
	printf("�����������,�밴ESC������ˢ�½��漴��");
	gotoxy(22,28);
	printf("�ɴ˸��������Ĳ��㣬�����½�!");
	gotoxy(10,28);
	printf("��ӭʹ���й�ũҵ����ATM����\n");
	gotoxy(12,31);
	printf("�����������");
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
	gotoxy(11,19);	printf("��ܰ��ʾ:��л����ʹ��!�뿪��̨ǰ");
	gotoxy(13,28);	printf("���������Ĺ�����Ʒ,ȡ�����Ŀ����ֽ�");
	gotoxy(15,28);	printf("�ڴ��´��ټ�");
	while(n--)
	{
		putchar('.');
		Sleep(1000);
	}
	exit(0);
}
