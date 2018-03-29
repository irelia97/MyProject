#include <windows.h>
#include "gotoxy.h"

int wherex()  //设置光标的位置x 
{  
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);  
    return (pBuffer.dwCursorPosition.Y+1);  
} 


int wherey()  //获取光标的位置y  
{  
    CONSOLE_SCREEN_BUFFER_INFO pBuffer;  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);  
    return (pBuffer.dwCursorPosition.X+1);  
}  


void gotoxy(int x,int y)   //转移光标位置到（x,y) 
{  
    COORD c;  
    c.X=y-1;  
    c.Y=x-1;  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);  
}	
