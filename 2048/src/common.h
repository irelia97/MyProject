#include <windows.h>

#define BACKSPACE 8
#define ENTER 13
#define ESC   27
#define SPACE 32
#define UP    72
#define DOWN  80
#define LEFT  75
#define RIGHT 77

#ifndef _COMMON_H_
#define _COMMON_H_

int  Get_key(int key);
int  Glb_putstring(char acStr[10], int iMaxLen, int iPutType, int isPlaintext);
int  wherex();
int  wherey();
void gotoxy(int x,int y);
void Get_time();
void Print_space(int n);
void Clear_msg(int x, int y, int n, int flag);
void Cls( HANDLE hConsole );

#endif
