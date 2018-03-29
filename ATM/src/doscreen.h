#ifndef		_DOSCREEN_H_
#define		_DOSCREEN_H_

#include"list.h"

int  do_Initsc();
void do_Enroll(LIST_T *head, USER_T *user);
void do_Loginsc(LIST_T *head, LIST_T *rehead, USER_T *user, USER_T  *admin);
int  do_Admin(LIST_T *head, USER_T *user, USER_T *admin);
void Ban_user(LIST_T *head, USER_T *user, USER_T *admin);
int  do_Modify(USER_T *admin);
LIST_T *list_printusers(LIST_T *head, int n, int *count);		//打印用户链表信息
LIST_T *list_printrecord(LIST_T *rehead, int n, int *count);
void User_record(LIST_T *rehead, USER_T *user);
void deal_user(LIST_T *head, USER_T *user, USER_T *admin, int index);
int  do_User(LIST_T *head, LIST_T *rehead, USER_T *user);
void User_save(LIST_T *head, LIST_T *rehead, USER_T *user);
void User_draw(LIST_T *head, LIST_T *rehead, USER_T *user);
void User_turn(LIST_T *head, LIST_T *rehead, USER_T *user);
int  User_psw(LIST_T *head, USER_T *user);
void find_user(LIST_T *head, USER_T *admin);

#endif