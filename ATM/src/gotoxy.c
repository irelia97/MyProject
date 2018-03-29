#include <windows.h>
#include "gotoxy.h"

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
