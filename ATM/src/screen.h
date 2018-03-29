#ifndef		_SCREEN_H_
#define 	_SCREEN_H_

#include "list.h"

int  Init_sc();
void Enroll_sc(LIST_T *head, USER_T *user);
void Login_sc(LIST_T *head, LIST_T *rehead, USER_T *user, USER_T  *admin);
void Admin_sc(LIST_T *head, USER_T *user,  USER_T *admin);
int  Modify_sc(USER_T *admin);
void Ban_sc();
void User_sc(LIST_T *head, LIST_T *rehead, USER_T *user);
void Save_sc();
void Draw_sc();
void turn_sc();
void psw_sc();
void Record_sc();

#endif