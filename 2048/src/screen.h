#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "doscreen.h"

void Login_sc(Add *point, int n);
int  Init_sc(int n);
int  Enroll_sc(Add *point);
void Game_ready(char *nick);
void Game_sc(int *old, int a[][4], char *nick);
void Game_help();


#endif
