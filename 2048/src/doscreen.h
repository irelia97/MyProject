#ifndef _DOSCREEN_H_
#define _DOSCREEN_H_


typedef struct accpsw
{
	char acc[10];
	char psw[10];
	char nick[10];
	int  flag;
}Add;

Add user[100];



int  do_Initsc(int n);
void do_Loginsc(Add *point,int n);
int  do_Enroll(	Add *point);
int Test_empty(char ch);
int Test_admin(char *s);
int Test_same(char *s1, char *s2);
int Test_passwd(char *s1, char *s2);
void do_Record();
void do_Admin(Add *point,int n);


#endif
