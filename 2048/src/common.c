#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "common.h"

int Get_key(int key)
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

		else
			continue;
			
		return key;
	}
}

int Glb_putstring(char *acStr, int iMaxLen, int iPutType, int isPlaintext)
{
	int  i = 0, key = 0;
	char ch;
	while(1)
	{
		ch = getch();
		if(ch =='\r')					//	����'\r'��ʾΪ�س��������˺����룻		 ��'\n'��������������һ���ǻس���һ���ǻ��С�
			break;
					
		else if(ch == BACKSPACE)				//  '\b'Ϊ�˸�� 
		{							
			if(i > 0)
			{
				i--;
			    acStr[i] = '\0';
				printf("\b \b");	//  "\b \b"�����þ��ǰѹ�������ƶ�һ�񣬴�ӡһ���ո񣨰�֮ǰ��ӡ�����ַ����ǵ�����Ȼ���������ƶ�һ��
									//  ʵ��Ч�����ڹ������һ�񣬲���ɾ�����ǰ���Ǹ��ַ�
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
					
				default:
					break;
			}
		}
	}
	return 0;
}

	

int wherex()  //���ù���λ��x 
{  
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);  
    return (pBuffer.dwCursorPosition.Y+1);  
} 


int wherey()  //��ȡ����λ��y  
{  
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);  
    return (pBuffer.dwCursorPosition.X+1);  
}  


void gotoxy(int x,int y)   //ת�ƹ��λ�õ���x,y) 
{  
    COORD c;  
    c.X=y-1;  
    c.Y=x-1;  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);  
}	

void Get_time()
{
	SYSTEMTIME sys; 
	while(1)
	{
		gotoxy(1,1);
		GetLocalTime( &sys ); 
		printf("%4d/%02d/%02d %02d:%02d:%02d ����%1d\n",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute, sys.wSecond,sys.wDayOfWeek); 
	}
}	
	

void Print_space(int n)
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


void Cls( HANDLE hConsole )
{
	COORD coordScreen = { 0, 0 };    // home for the cursor
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	
	if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
	{
		return;
	}
	
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	
	if( !FillConsoleOutputCharacter( hConsole,        // Handle to console screen buffer
		(TCHAR) ' ',     // Character to write to the buffer
		dwConSize,       // Number of cells to write
		coordScreen,     // Coordinates of first cell
		&cCharsWritten ))// Receive number of characters written
	{
		return;
	}
	
	if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
	{
		return;
	}
	
	if( !FillConsoleOutputAttribute( hConsole,         // Handle to console screen buffer
		csbi.wAttributes, // Character attributes to use
		dwConSize,        // Number of cells to set attribute
		coordScreen,      // Coordinates of first cell
		&cCharsWritten )) // Receive number of characters written
	{
		return;
	}
	
	SetConsoleCursorPosition( hConsole, coordScreen );
}
			
			

	
