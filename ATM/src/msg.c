#include <stdio.h>
#include <conio.h>
#include "list.h"
#include "screen.h"
#include "common.h"
#include "gotoxy.h"
#include "msg.h"


void window()
{
	char b1[]="┌───────────────────────┐";
	
	char b2[]="│───────────────────────│";	
	
	char b5[]="│                                              │";
	
	char b3[]="└───────────────────────┘";
	
	int x = 8, n = 9;
	color(12);
	gotoxy(x,15);
	puts(b1);
	while(n--)
	{
		x++;
		gotoxy(x,15);
		if(x == 10)
		{
			puts(b2);
			continue;
		}
		puts(b5);
	}
	gotoxy(x+1,15);
	puts(b3);
}

void ok()
{
	char b1[]="┌───────────────────────┐";
	
	char b2[]="│───────────────────────│";	
	
	char b5[]="│                                              │";
	
	char b3[]="└───────────────────────┘";
	
	int x = 8, n = 9;
	color(11);
	gotoxy(x,15);
	puts(b1);
	while(n--)
	{
		x++;
		gotoxy(x,15);
		if(x == 10)
		{
			puts(b2);
			continue;
		}
		puts(b5);
	}
	gotoxy(x+1,15);
	puts(b3);
	gotoxy(9,37);
	printf("恭喜");
	gotoxy(17,31);
	printf("按任意键继续......");
}

void roll_ok(USER_T *user)
{
	ok();	
	gotoxy(12,35);
	printf("注册成功!");
	gotoxy(14,23);
	printf("%s,您的账号是%s,ID为%s",user->name,user->acc,user->id);	
	getch();
	color(14);
}

int acc_fz()
{
	gotoxy(5,26);
	color(12);
	printf("This account has been frozen!");
	getch();
	Clear_msg(5,26,30,0);
	color(14);
	return 0;
}

void acc_unexist()
{
	color(12);
	gotoxy(5,32);
	printf("No this account!");
	getch();
	Clear_msg(5,32,20,0);
	color(14);
}

void psw_fz()
{
	color(12);
	gotoxy(5,22);
	printf("密码输入错误超过3次，账号已被冻结!!!");
	gotoxy(6,30);
	printf("请联系管理员解冻!");
	getch();
	color(14);
}

void psw_err()
{	
	color(12);
	gotoxy(5,30);
	printf("Password is Error!");
	getch();
	Clear_msg(5,30,25,0);
	color(14);
}

void psw_chg()
{
	system("cls");
	gotoxy(10,17);
	printf("Detect your password changes.Please login again!\n\n");
	system("pause");
}

void login_msg()
{
	int n = 6;
	system("cls");
	gotoxy(12,33);
	printf("正在登录中");
	while(n--)
	{
		putchar('.');
		Sleep(1000);
	}
	system("cls");
	fflush(stdin);
}

void user_msg()
{
	system("cls");
	Ban_sc();
	gotoxy(5,5);
	printf("ID\t\t 账号\t\t密码\t      手机\t    余额\t状态");
}

void admin_psw(USER_T *admin)
{	
	system("cls");
	gotoxy(10,20);
	printf("OK!Now your password is %s,Remember it!\n\n\n",admin->psw);
	system("pause");
}

void user_dowhat(USER_T *user)
{	
	gotoxy(9,33);
	printf("用户管理操作");
	gotoxy(11,19);
	printf("您打算对用户 %s(%s) 执行什么操作？",user->name,user->id);
	gotoxy(13,30);
	printf("1、冻结 2、解冻");
	gotoxy(15,30);
	printf("3、销户 4、修改密码");
	gotoxy(17,51);
	printf("【ESC】返回");	
}

void try_fz()
{
	window();
	gotoxy(9,33);
	printf("是否冻结用户");
	gotoxy(13,30);
	printf("1、确认 2、取消");
}

void fz_msg()
{
	window();
	gotoxy(17,51);
	printf("【ESC】返回");
	gotoxy(9,33);
	printf("您正在冻结用户");
	gotoxy(13,26);
	printf("请输入管理员密码: ");
}


void fz_ok()
{
	ok();
	gotoxy(13,35);
	printf("冻结成功!");
	getch();
	color(14);
}

void has_fz()
{
	window();
	gotoxy(9,37);
	printf("警告");
	gotoxy(13,32);
	printf("用户已经被冻结!");
	gotoxy(17,31);
	printf("按任意键继续......");
	getch();
}

void psw_ero()
{
	gotoxy(13,44);
	printf("  密码错误!!!");
	gotoxy(15,30);
	printf("按任意键重新输入......");
	getch();
	Clear_msg(15,30,30,0);
	Clear_msg(13,44,19,1);
}

void free_msg()
{
	window();
	gotoxy(9,33);
	printf("是否解冻用户");
	gotoxy(13,30);
	printf("1、确认 2、取消");
}

void free_psw()
{
	window();
	gotoxy(17,51);
	printf("【ESC】返回");
	gotoxy(9,33);
	printf("您正在解冻用户");
	gotoxy(13,26);
	printf("请输入管理员密码: ");
}

void free_ok()
{
	ok();
	gotoxy(13,35);
	printf("解冻成功!");
	getch();
	color(14);
}

void hasnot_fz()
{
	window();
	gotoxy(9,37);
	printf("警告");

	gotoxy(13,32);
	printf("用户没有被冻结!");
	gotoxy(17,31);
	printf("按任意键继续......");
	getch();
}

void try_del()
{
	window();
	gotoxy(9,33);
	printf("是否删除用户");
	gotoxy(13,30);
	printf("1、确认 2、取消");
}

void del_psw()
{
	window();
	gotoxy(17,51);
	printf("【ESC】返回");
	gotoxy(9,33);
	printf("您正在删除用户");
	gotoxy(13,26);
	printf("请输入管理员密码: ");
}

void del_ok()
{
	ok();
	gotoxy(13,35);
	printf("删除成功!");
	getch();
	color(14);
}

void not_del()
{
	window();
	gotoxy(9,37);
	printf("警告");
	gotoxy(13,28);
	printf("用户尚有存款，无法删除 ");
	gotoxy(17,31);
	printf("按任意键继续......");
	getch();
}

void try_chg()
{
	window();
	gotoxy(9,33);
	printf("更改用户密码");
	gotoxy(13,30);
	printf("1、确认 2、取消");
}

void chg_psw()
{
	window();
	gotoxy(17,51);
	printf("【ESC】返回");
	gotoxy(9,33);
	printf("修改用户密码");
	gotoxy(13,26);
	printf("请输入管理员密码: ");
}

void chg_newpsw()
{
	window();
	gotoxy(17,51);
	printf("【ESC】返回");
	gotoxy(9,33);
	printf("修改用户密码");
	gotoxy(13,23);
	printf("请输入用户新密码: ");
}

void chg_ok()
{
	ok();
	gotoxy(13,35);
	printf("修改成功!");
	getch();
	color(14);
}

void find_err()
{
	printf("\n\n查询失败!请重新输入查询信息!\n\n");
	getch();
	system("cls");
}

void save_now(USER_T *user)
{
	gotoxy(4,29);
	printf("您目前的余额是: ");
	show_money(user->save);
	printf("元");
	gotoxy(5,43);
	putchar(' ');
}

void mustbe_100()
{
	color(12);
	gotoxy(6,25);
	printf("不能存入非整百的金额!请重新输入!");
	getch();
	Clear_msg(6,25,32,0);
	color(14);
}

void onesave_max()
{
	color(12);
	gotoxy(6,30);
	printf("单笔不能超过二十万!");
	getch();
	Clear_msg(6,30,20,0);
	color(14);
}

void save_max()
{
	color(12);
	gotoxy(6,20);
	printf("尊敬的用户,本支行最多支持一百万以下存款");
	getch();
	Clear_msg(6,20,40,0);
	color(14);
}

void save_ok(int save, USER_T *user)
{
	ok();
	gotoxy(12,35);
	printf("存款成功!");
	gotoxy(14,23);
	printf("存入%d元成功!您当前的余额是%d",save,user->save);
	getch();
	color(14);
}

void sava_few()
{
	color(12);
	gotoxy(7,34);
	printf("您的余额不足!");
	getch();
	Clear_msg(7,34,15,0);
	color(14);
}

void onedraw_max()
{
	color(12);
	gotoxy(6,32);
	printf("单笔不能超过五万!");
	getch();
	Clear_msg(6,32,18,0);
	color(14);
}

void draw_psw()
{
	color(12);
	gotoxy(6,36);
	printf("密码错误!");
	getch();
	color(14);
}

void draw_ok(int draw, USER_T *user)
{
	ok();
	gotoxy(12,35);
	printf("取款成功!");
	gotoxy(14,23);
	printf("取出%d元成功!您当前的余额是%d",draw,user->save);
	getch();
	color(14);
}

void no_man()
{
	color(12);
	gotoxy(6,36);
	printf("查无此人!");
	getch();
	color(14);
}

void turn_fz()
{
	color(12);
	printf("此用户已被冻结!!!");
	getch();
	color(14);
}

void turn_self()
{
	color(12);
	printf("不能向自己转账!!!");
	getch();
	color(14);
}

void turn_ok(int money, USER_T *user)
{
	ok();
	gotoxy(12,35);
	printf("转账成功!");
	gotoxy(14,23);
	printf("转出%d元成功!您当前的余额是%d元",money,user->save);
	gotoxy(17,31);
	getch();
	color(14);
}

void tel_pk()
{
	color(12);
	gotoxy(5,20);
	printf("您输入的手机号码与预留的不匹配,请重新输入!");
	getch();
	color(14);
}

int check_md5()
{
	int i, n = 6;

	i = Get_rand();

	Clear_msg(5,20,40,0);
	gotoxy(5,30);
	printf("验证码获取中");
	while(n--)
	{
		putchar('.');
		Sleep(1000);
	}
	
	Clear_msg(5,20,30,1);
	printf("【ATM】验证码为: %d, 请在3分钟之内输入",i);
	
	Clear_msg(10,40,4,1);

	return i;
}

void md5_err()
{
	color(12);
	Clear_msg(6,30,30,1);
	printf("验证码错误!请重新输入!");
	getch();
	Clear_msg(6,30,30,0);
	Clear_msg(10,40,6,0);
	color(14);
}

void psw_differ()
{
	color(12);
	Clear_msg(4,30,26,1);
	printf("二次密码输入不同!");
	getch();
	color(14);
	Clear_msg(12,40,6,0);
	Clear_msg(14,40,6,0);
	Clear_msg(4,30,26,0);
}

void psw_ok(char *newpsw)
{
	ok();
	gotoxy(12,35);
	printf("修改成功!");
	gotoxy(14,23);
	printf("恭喜您!您的密码已经成功修改为 %s!",newpsw);
	color(14);
	getch();
	system("cls");
}

void too_long()
{
	color(12);
	gotoxy(15,30);
	printf("查询的记录太过遥远!\n");
	getch();
	color(14);
}

void over_now()
{
	color(12);
	gotoxy(15,30);
	printf("不能超过当前时间!\n");
	getch();
	color(14);
}

void month_err()
{
	color(12);
	gotoxy(15,30);
	printf("月份输入错误!\n");
	getch();
	color(14);
}

void over_three()
{
	color(12);
	gotoxy(15,30);
	printf("只能查询最近三个月的记录!\n");
	getch();
	color(14);
}

void input_err()
{
	color(12);
	gotoxy(15,30);
	printf("日期输入错误!\n");
	getch();
	color(14);
}

void endyear_err()
{
	color(12);
	gotoxy(15,30);
	printf("终止年份输入错误!\n");
	getch();
	color(14);
}

void less4()
{
	color(12);
	gotoxy(4,30);
	printf("Can't less than 4 bits!");
	getch();
	Clear_msg(4,30,25,0);
	color(14);
}

void tel_same()
{
	color(12);
	gotoxy(4,22);
	printf("This mobile number has been resgiter!");
	getch();
	Clear_msg(4,22,40,0);
	color(14);
}

void u_exit()
{
	window();
	gotoxy(17,51);
	printf("【ESC】返回");
	gotoxy(9,31);
	printf("您确定要退出系统吗");
	gotoxy(13,32);
	printf("1、确认 2、取消");
}

void u_back()
{
	window();
	gotoxy(17,51);
	printf("【ESC】返回");
	gotoxy(9,29);
	printf("您确定要退出当前用户吗");
	gotoxy(13,30);
	printf("1、确认     2、取消");
}

void nozero()
{
	color(12);
	gotoxy(6,30);
	printf("金额不能为0!请重新输入!");
	getch();
	Clear_msg(6,25,32,0);
	color(14);
}

void psw_dif()
{
	color(12);
	gotoxy(4,32);
	printf("不能和旧密码相同!");
	getch();
	Clear_msg(4,27,32,0);
	color(14);
}