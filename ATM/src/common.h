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
int  Glb_putstring(char *acStr, int iMaxLen, int iPutType, int isPlaintext);
void real_time();
char *gettime(char *buffer);
void color(const unsigned short color1);
void Print_space(int n);
void Clear_msg(int x, int y, int n, int flag);
int	 Move_arrow(int x, int y, int z);
int  Test_empty(char ch);
int  Test_admin(char *s);
int  Test_same(char *s1, char *s2);
int  Test_passwd(char *s1, char *s2);
int  Test_len(char *s1, int n);
void Clear_arrow(int x, int y);
void show_money(int n);
int  Get_rand();
void Welcome();
void byebye();

#endif
