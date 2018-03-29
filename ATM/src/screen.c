#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "gotoxy.h"
#include "common.h"
#include "doscreen.h"


char a0[]="│──│                                                              │──│";

char a1[]="┌──┬───────────────────────────────┬──┐";

char a2[]="│──│───────────────────────────────│──│";		

char a3[]="└──┴───────────────────────────────┴──┘";

char a4[]="│──│              	    	     ATM 	   	 	      │──│";

char a5[]="│──│     Esc：返回         			      Enter:确定      │──│";


int Init_sc()			//初始化界面 
{
	int i;

	char b0[]="│──│                       ┌──────┐                       │──│";
	
	char b1[]="│──│                       │            │                       │──│";	
	
	char b2[]="│──│                       │ 1、登录    │                       │──│";
	
	char b3[]="│──│                       │ 2、注册    │                       │──│";
	
	char b4[]="│──│                       │ 3、退出    │                       │──│";		
	
	char b5[]="│──│                       └──────┘                       │──│";		
	
	char b6[]="│──│     【↑↓】选择            	            【Enter】确定     │──│";
	
	color(14);
	
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a1,a4,a2,a0,a0,a0,a0,b0,b2,b5,b3,b5,b4,b5,a0,a0,a0,a0,a0,a0,a0,a2,b6,a3);
	
	i = do_Initsc();
	
	return i;
}

void Enroll_sc(LIST_T *head, USER_T *user)
{	
	char c0[]="│──│             ┌────────────────┐             │──│";
	
	char c1[]="│──│             │            │                  │             │──│";	
	
	char c2[]="│──│             │    账号    │                  │             │──│";
	
	char c4[]="│──│             │    密码    │                  │             │──│";
	
	char c5[]="│──│             │  确认密码  │                  │             │──│";	
	
	char c6[]="│──│             │  中文姓名  │                  │             │──│";	

	char ci[]="│──│             │  预留手机  │                  │             │──│";	
	
	char c7[]="│──│             └────────────────┘             │──│";		
	
	char c8[]="│──│     【ESC】返回            	            【Enter】确定     │──│";
	
	char a9[]="│──│              	    	   用户注册 	   	 	      │──│";	

	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a1,a9,a2,a0,c0,c2,c7,c4,c7,c5,c7,c6,c7,ci,c7,a0,a0,a0,a0,a0,a0,a2,c8,a3);
	
	gotoxy(18,24);
	printf("Tips: 账号为数字和字母的组合"); 
	gotoxy(19,29);
	printf(" 密码只能为数字");
	gotoxy(20,29);
	printf(" 姓名只能为中文 ");
	
	do_Enroll(head,user);
}

void Login_sc(LIST_T *head, LIST_T *rehead, USER_T *user, USER_T *admin)		//登录界面 
{
	
	char a6[]="│──│                输入账号：		      		      │──│";
	
	char a7[]="│──│                输入密码：		      		      │──│";
	
	char a8[]="		管理员账户:irelia(1000)	   初始密码:123456                 ";
	
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",a1,a4,a2,a0,a0,a0,a0,a6,a0,a0,a0,a7,a0,a0,a0,a0,a0,a0,a0,a0,a5,a2,a3,a8);
	gotoxy(16,24);
	printf("Tips: 登录可以使用账号或者ID"); 
	gotoxy(18,30);
	printf("密码输入错误3次将被冻结");
	gotoxy(8,37);
	
	do_Loginsc(head,rehead,user,admin);	
	
}

void Admin_sc(LIST_T *head, USER_T *user, USER_T *admin)
{
	int z = 1;

	char d0[]="│──│                       ┌───────┐                     │──│";
	
	char d1[]="│──│                       │              │                     │──│";	
	
	char d2[]="│──│                       │ 1、管理用户  │                     │──│";
	
	char d3[]="│──│                       │ 2、修改密码  │                     │──│";

	char dz[]="│──│                       │ 3、模糊查询  │                     │──│";
	
	char d4[]="│──│                       │ 4、退出      │                     │──│";		
	
	char d5[]="│──│                       └───────┘                     │──│";		
	
	char d6[]="│──│     【↑↓】选择         【ESC】返回        【Enter】确定    │──│";

	char d7[]="│──│              	    	   管理员界面 	   	 	      │──│";	   

	while(z)
	{
		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a1,d7,a2,a0,a0,a0,a0,d0,d2,d5,d3,d5,dz,d5,d4,d5,a0,a0,a0,a0,a0,a2,d6,a3);
	
		z = do_Admin(head,user,admin);
	}	
}

int Modify_sc(USER_T *admin)
{
	int i;

	char c0[]="│──│             ┌────────────────┐             │──│";
	
	char c1[]="│──│             │            │                  │             │──│";	
	
	char c4[]="│──│             │   新密码   │                  │             │──│";
	
	char c5[]="│──│             │  确认密码  │                  │             │──│";				
	
	char c7[]="│──│             └────────────────┘             │──│";		
	
	char c8[]="│──│     【ESC】返回            	            【Enter】确定     │──│";
	
	char a9[]="│──│              	    	   ATM 	   	 	              │──│";	

	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a1,a9,a2,a0,a0,a0,a0,a0,c0,c4,c7,c5,c7,a0,a0,a0,a0,a0,a0,a0,a0,a2,c8,a3);

	i = do_Modify(admin);

	return i;
}

void Ban_sc()
{
	char b1[]="┌─────────────────────────────────────┐";
	
	char b2[]="│─────────────────────────────────────│";		
	
	char b3[]="└─────────────────────────────────────┘";

	char b5[]="│                                                                          │";

	char e1[]="│                 	    	   管理用户	   	 	            │";

	char b4[]="│        【Esc】返回   【↑↓】移动       【←→】翻页   【Enter】确定     │";

	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",b1,e1,b2,b5,b5,b2,b5,b2,b5,b2,b5,b2,b5,b2,b5,b2,b5,b2,b5,b2,b5,b2,b4,b3);
	
}


void User_sc(LIST_T *head, LIST_T *rehead, USER_T *user)
{
	int i = 1;

	SYSTEMTIME sys;

	char time[5] = {'\0'};
		
	char bi[]="│──│	  		   用户界面	   	              │──│";

	char b0[]="│──│                     ┌───────┐                       │──│";
	
	char b1[]="│──│                     │				│                       │──│";	
	
	char b2[]="│──│                     │ 1、存款      │                       │──│";
	
	char b3[]="│──│                     │ 2、取款      │                       │──│";
	
	char b4[]="│──│                     │ 3、转账      │                       │──│";	
	
	char b5[]="│──│                     │ 4、修改密码  │                       │──│";

	char b6[]="│──│                     │ 5、交易记录  │                       │──│";

	char b9[]="│──│                     │ 6、退出      │                       │──│";
	
	char b7[]="│──│                     └───────┘                       │──│";	
	
	char b8[]="│──│     【Esc】返回            		   【Enter】确定      │──│";


	while(i)
	{
		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a1,bi,a2,a0,a0,a0,a0,b0,b2,b7,b3,b7,b4,b7,b5,b7,b6,b7,b9,b7,a0,a2,b8,a3);
		GetLocalTime(&sys);
		if(sys.wHour > 6 && sys.wHour < 12)
			strcpy(time,"早上");
		else if(sys.wHour > 12 && sys.wHour < 18)
			strcpy(time,"下午");
		else
			strcpy(time,"晚上");
		
		gotoxy(5,28);
		printf("尊敬的 %s 用户,%s好!",user->name,time);
		gotoxy(6,27);
		printf("您目前的余额是: ");
		show_money(user->save);
		printf("元");
		gotoxy(6,43);
		putchar(' ');
		i = do_User(head,rehead,user);
	}

}

void Save_sc()
{
	char ci[]="│──│	  		   用户存款	   	              │──│";

	char c0[]="│──│             ┌┈┈┈┈┈┉┉┉┉┉┉┈┈┈┈┈┐             │──│";
	
	char c1[]="│──│             ┋  存款金额  │                  ┋             │──│";	
	
	char c7[]="│──│             └┈┈┈┈┈┉┉┉┉┉┉┈┈┈┈┈┘             │──│";		

	system("cls");

	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a1,ci,a2,a0,a0,a0,a0,a0,a0,c0,c1,c7,a0,a0,a0,a0,a0,a0,a0,a0,a0,a2,a5,a3);

	gotoxy(15,17);	printf("Tips:单笔存款上限为二十万元");
	gotoxy(17,22);	printf("本行最大支持一百万元整的存款,如需大额存款");
	gotoxy(19,22);	printf("请联系本行刘经理,手机:13015768283");

}

void Draw_sc()
{
	char ci[]="│──│	  		   用户取款	   	              │──│";
	
	char c0[]="│──│             ┌┈┈┈┈┈┉┉┉┉┉┉┈┈┈┈┈┐             │──│";
	
	char c1[]="│──│             ┋  取款金额  │                  ┋             │──│";
	
	char c3[]="│──│             ┋┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┋             │──│";	
	
	char c2[]="│──│             ┋  确认密码  │                  ┋             │──│";	
	
	char c7[]="│──│             └┈┈┈┈┈┉┉┉┉┉┉┈┈┈┈┈┘             │──│";		
	
	system("cls");
	
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a1,ci,a2,a0,a0,a0,a0,a0,c0,c1,c3,c2,c7,a0,a0,a0,a0,a0,a0,a0,a0,a2,a5,a3);
	
	gotoxy(16,30);	printf("Tips:单笔取款上限为五万元");
	
}

void turn_sc()
{
	char ci[]="│──│	  		   用户转账	   	              │──│";
	
	char c0[]="│──│             ┌┈┈┈┈┈┉┉┉┉┉┉┈┈┈┈┈┐             │──│";
	
	char c1[]="│──│             ┋  转账对象  │                  ┋             │──│";

	char c4[]="│──│             ┋  转账金额  │                  ┋             │──│";
	
	char c3[]="│──│             ┋┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┋             │──│";	
	
	char c2[]="│──│             ┋  确认密码  │                  ┋             │──│";	
	
	char c7[]="│──│             └┈┈┈┈┈┉┉┉┉┉┉┈┈┈┈┈┘             │──│";	

	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a1,ci,a2,a0,a0,a0,c0,c1,c3,c4,c3,c2,c7,a0,a0,a0,a0,a0,a0,a0,a0,a2,a5,a3);

	gotoxy(15,20);	printf("Tips:转账对象请填写对方账号或ID");
	gotoxy(17,25);	printf("单笔转账上限为五万元,如需大额转账");
	gotoxy(19,25);	printf("请联系本行刘经理,手机:13015768283");
}

void psw_sc()
{
	char ci[]="│──│	  		   密码修改	   	              │──│";
	
	char c0[]="│──│             ┌┈┈┈┈┈┉┉┉┉┉┉┈┈┈┈┈┐             │──│";
	
	char c1[]="│──│             ┋  手机号码  │                  ┋             │──│";
	
	char c4[]="│──│             ┋  验证码    │                  ┋             │──│";

	char c5[]="│──│             ┋  新密码    │                  ┋             │──│";
	
	char c3[]="│──│             ┋┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┉┋             │──│";	
	
	char c2[]="│──│             ┋  确认密码  │                  ┋             │──│";	
	
	char c7[]="│──│             └┈┈┈┈┈┉┉┉┉┉┉┈┈┈┈┈┘             │──│";	

	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a1,ci,a2,a0,a0,a0,c0,c1,c3,c4,c3,c5,c3,c2,c7,a0,a0,a0,a0,a0,a0,a2,a5,a3);

	gotoxy(17,20);	printf("Tips:为确保您的安全性,请先输入您预留的手机号码");
	gotoxy(19,25);	printf("以获取我们发送的验证码");
}

void Record_sc()
{
	char b1[]="┌─────────────────────────────────────┐";
	
	char b2[]="│─────────────────────────────────────│";		
	
	char b3[]="└─────────────────────────────────────┘";
	
	char b5[]="│                                                                          │";
	
	char e1[]="│                 	    	   交易记录	   	 	            │";
	
	char b4[]="│              【Esc】返回                        【←→】翻页             │";
	
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",b1,e1,b2,b5,b5,b2,b5,b2,b5,b2,b5,b2,b5,b2,b5,b2,b5,b2,b5,b2,b5,b2,b4,b3);
	
}

