#include <stdio.h>
#include <conio.h>
#include "list.h"
#include "screen.h"
#include "common.h"
#include "gotoxy.h"
#include "msg.h"


void window()
{
	char b1[]="��������������������������������������������������";
	
	char b2[]="��������������������������������������������������";	
	
	char b5[]="��                                              ��";
	
	char b3[]="��������������������������������������������������";
	
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
	char b1[]="��������������������������������������������������";
	
	char b2[]="��������������������������������������������������";	
	
	char b5[]="��                                              ��";
	
	char b3[]="��������������������������������������������������";
	
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
	printf("��ϲ");
	gotoxy(17,31);
	printf("�����������......");
}

void roll_ok(USER_T *user)
{
	ok();	
	gotoxy(12,35);
	printf("ע��ɹ�!");
	gotoxy(14,23);
	printf("%s,�����˺���%s,IDΪ%s",user->name,user->acc,user->id);	
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
	printf("����������󳬹�3�Σ��˺��ѱ�����!!!");
	gotoxy(6,30);
	printf("����ϵ����Ա�ⶳ!");
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
	printf("���ڵ�¼��");
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
	printf("ID\t\t �˺�\t\t����\t      �ֻ�\t    ���\t״̬");
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
	printf("�û��������");
	gotoxy(11,19);
	printf("��������û� %s(%s) ִ��ʲô������",user->name,user->id);
	gotoxy(13,30);
	printf("1������ 2���ⶳ");
	gotoxy(15,30);
	printf("3������ 4���޸�����");
	gotoxy(17,51);
	printf("��ESC������");	
}

void try_fz()
{
	window();
	gotoxy(9,33);
	printf("�Ƿ񶳽��û�");
	gotoxy(13,30);
	printf("1��ȷ�� 2��ȡ��");
}

void fz_msg()
{
	window();
	gotoxy(17,51);
	printf("��ESC������");
	gotoxy(9,33);
	printf("�����ڶ����û�");
	gotoxy(13,26);
	printf("���������Ա����: ");
}


void fz_ok()
{
	ok();
	gotoxy(13,35);
	printf("����ɹ�!");
	getch();
	color(14);
}

void has_fz()
{
	window();
	gotoxy(9,37);
	printf("����");
	gotoxy(13,32);
	printf("�û��Ѿ�������!");
	gotoxy(17,31);
	printf("�����������......");
	getch();
}

void psw_ero()
{
	gotoxy(13,44);
	printf("  �������!!!");
	gotoxy(15,30);
	printf("���������������......");
	getch();
	Clear_msg(15,30,30,0);
	Clear_msg(13,44,19,1);
}

void free_msg()
{
	window();
	gotoxy(9,33);
	printf("�Ƿ�ⶳ�û�");
	gotoxy(13,30);
	printf("1��ȷ�� 2��ȡ��");
}

void free_psw()
{
	window();
	gotoxy(17,51);
	printf("��ESC������");
	gotoxy(9,33);
	printf("�����ڽⶳ�û�");
	gotoxy(13,26);
	printf("���������Ա����: ");
}

void free_ok()
{
	ok();
	gotoxy(13,35);
	printf("�ⶳ�ɹ�!");
	getch();
	color(14);
}

void hasnot_fz()
{
	window();
	gotoxy(9,37);
	printf("����");

	gotoxy(13,32);
	printf("�û�û�б�����!");
	gotoxy(17,31);
	printf("�����������......");
	getch();
}

void try_del()
{
	window();
	gotoxy(9,33);
	printf("�Ƿ�ɾ���û�");
	gotoxy(13,30);
	printf("1��ȷ�� 2��ȡ��");
}

void del_psw()
{
	window();
	gotoxy(17,51);
	printf("��ESC������");
	gotoxy(9,33);
	printf("������ɾ���û�");
	gotoxy(13,26);
	printf("���������Ա����: ");
}

void del_ok()
{
	ok();
	gotoxy(13,35);
	printf("ɾ���ɹ�!");
	getch();
	color(14);
}

void not_del()
{
	window();
	gotoxy(9,37);
	printf("����");
	gotoxy(13,28);
	printf("�û����д��޷�ɾ�� ");
	gotoxy(17,31);
	printf("�����������......");
	getch();
}

void try_chg()
{
	window();
	gotoxy(9,33);
	printf("�����û�����");
	gotoxy(13,30);
	printf("1��ȷ�� 2��ȡ��");
}

void chg_psw()
{
	window();
	gotoxy(17,51);
	printf("��ESC������");
	gotoxy(9,33);
	printf("�޸��û�����");
	gotoxy(13,26);
	printf("���������Ա����: ");
}

void chg_newpsw()
{
	window();
	gotoxy(17,51);
	printf("��ESC������");
	gotoxy(9,33);
	printf("�޸��û�����");
	gotoxy(13,23);
	printf("�������û�������: ");
}

void chg_ok()
{
	ok();
	gotoxy(13,35);
	printf("�޸ĳɹ�!");
	getch();
	color(14);
}

void find_err()
{
	printf("\n\n��ѯʧ��!�����������ѯ��Ϣ!\n\n");
	getch();
	system("cls");
}

void save_now(USER_T *user)
{
	gotoxy(4,29);
	printf("��Ŀǰ�������: ");
	show_money(user->save);
	printf("Ԫ");
	gotoxy(5,43);
	putchar(' ');
}

void mustbe_100()
{
	color(12);
	gotoxy(6,25);
	printf("���ܴ�������ٵĽ��!����������!");
	getch();
	Clear_msg(6,25,32,0);
	color(14);
}

void onesave_max()
{
	color(12);
	gotoxy(6,30);
	printf("���ʲ��ܳ�����ʮ��!");
	getch();
	Clear_msg(6,30,20,0);
	color(14);
}

void save_max()
{
	color(12);
	gotoxy(6,20);
	printf("�𾴵��û�,��֧�����֧��һ�������´��");
	getch();
	Clear_msg(6,20,40,0);
	color(14);
}

void save_ok(int save, USER_T *user)
{
	ok();
	gotoxy(12,35);
	printf("���ɹ�!");
	gotoxy(14,23);
	printf("����%dԪ�ɹ�!����ǰ�������%d",save,user->save);
	getch();
	color(14);
}

void sava_few()
{
	color(12);
	gotoxy(7,34);
	printf("��������!");
	getch();
	Clear_msg(7,34,15,0);
	color(14);
}

void onedraw_max()
{
	color(12);
	gotoxy(6,32);
	printf("���ʲ��ܳ�������!");
	getch();
	Clear_msg(6,32,18,0);
	color(14);
}

void draw_psw()
{
	color(12);
	gotoxy(6,36);
	printf("�������!");
	getch();
	color(14);
}

void draw_ok(int draw, USER_T *user)
{
	ok();
	gotoxy(12,35);
	printf("ȡ��ɹ�!");
	gotoxy(14,23);
	printf("ȡ��%dԪ�ɹ�!����ǰ�������%d",draw,user->save);
	getch();
	color(14);
}

void no_man()
{
	color(12);
	gotoxy(6,36);
	printf("���޴���!");
	getch();
	color(14);
}

void turn_fz()
{
	color(12);
	printf("���û��ѱ�����!!!");
	getch();
	color(14);
}

void turn_self()
{
	color(12);
	printf("�������Լ�ת��!!!");
	getch();
	color(14);
}

void turn_ok(int money, USER_T *user)
{
	ok();
	gotoxy(12,35);
	printf("ת�˳ɹ�!");
	gotoxy(14,23);
	printf("ת��%dԪ�ɹ�!����ǰ�������%dԪ",money,user->save);
	gotoxy(17,31);
	getch();
	color(14);
}

void tel_pk()
{
	color(12);
	gotoxy(5,20);
	printf("��������ֻ�������Ԥ���Ĳ�ƥ��,����������!");
	getch();
	color(14);
}

int check_md5()
{
	int i, n = 6;

	i = Get_rand();

	Clear_msg(5,20,40,0);
	gotoxy(5,30);
	printf("��֤���ȡ��");
	while(n--)
	{
		putchar('.');
		Sleep(1000);
	}
	
	Clear_msg(5,20,30,1);
	printf("��ATM����֤��Ϊ: %d, ����3����֮������",i);
	
	Clear_msg(10,40,4,1);

	return i;
}

void md5_err()
{
	color(12);
	Clear_msg(6,30,30,1);
	printf("��֤�����!����������!");
	getch();
	Clear_msg(6,30,30,0);
	Clear_msg(10,40,6,0);
	color(14);
}

void psw_differ()
{
	color(12);
	Clear_msg(4,30,26,1);
	printf("�����������벻ͬ!");
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
	printf("�޸ĳɹ�!");
	gotoxy(14,23);
	printf("��ϲ��!���������Ѿ��ɹ��޸�Ϊ %s!",newpsw);
	color(14);
	getch();
	system("cls");
}

void too_long()
{
	color(12);
	gotoxy(15,30);
	printf("��ѯ�ļ�¼̫��ңԶ!\n");
	getch();
	color(14);
}

void over_now()
{
	color(12);
	gotoxy(15,30);
	printf("���ܳ�����ǰʱ��!\n");
	getch();
	color(14);
}

void month_err()
{
	color(12);
	gotoxy(15,30);
	printf("�·��������!\n");
	getch();
	color(14);
}

void over_three()
{
	color(12);
	gotoxy(15,30);
	printf("ֻ�ܲ�ѯ��������µļ�¼!\n");
	getch();
	color(14);
}

void input_err()
{
	color(12);
	gotoxy(15,30);
	printf("�����������!\n");
	getch();
	color(14);
}

void endyear_err()
{
	color(12);
	gotoxy(15,30);
	printf("��ֹ����������!\n");
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
	printf("��ESC������");
	gotoxy(9,31);
	printf("��ȷ��Ҫ�˳�ϵͳ��");
	gotoxy(13,32);
	printf("1��ȷ�� 2��ȡ��");
}

void u_back()
{
	window();
	gotoxy(17,51);
	printf("��ESC������");
	gotoxy(9,29);
	printf("��ȷ��Ҫ�˳���ǰ�û���");
	gotoxy(13,30);
	printf("1��ȷ��     2��ȡ��");
}

void nozero()
{
	color(12);
	gotoxy(6,30);
	printf("����Ϊ0!����������!");
	getch();
	Clear_msg(6,25,32,0);
	color(14);
}

void psw_dif()
{
	color(12);
	gotoxy(4,32);
	printf("���ܺ;�������ͬ!");
	getch();
	Clear_msg(4,27,32,0);
	color(14);
}