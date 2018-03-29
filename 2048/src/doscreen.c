#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "common.h"
#include "doscreen.h"
#include "screen.h"
#include "move.h"
#include "game.h"


int do_Initsc(int n)
{
	int  x = 8, y = 29, arrow = 26, key = 0, i = 1;	
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	Add admin = 
	{
		"irelia",
		"123456",
		"Irelia_97",
		1
	};
	if(user[0].acc[0] == '\0')	//��һ�ν������Ż��ʼ������Աuser[0]�������޸��������Ч
		memcpy(&user[0],&admin,sizeof(admin));

	gotoxy(x,y); 
	
	i = Move_arrow(x,y,3);
	Cls(hStdout);

	if(i == 1)					//����ע�����
	{
		n = Enroll_sc(user);
		if(n == 0)				//û��ע�᷵�� 0����1ʹ��Ϊ��ʼֵ1������� 
			n++;
		return n;
	}
		
	else if(i == 2)				//�����¼����
	{		
		Login_sc(user,n);
		return n;
	}
		 
	else if(i == 3)				//�˳�
		return 0;

	else
		return 0;
			
}


void do_Loginsc(Add *point,int n)
{
	FILE	 *fp;
	int  	 flag = 0, flag1 = 0, i;	
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	char     num[10] ;				//	�˺ų�ʼ��								
	char      pw[10] ;				//	�����ʼ�� 
	char    nick[10] ;				//	�ǳƳ�ʼ��
	
	while(1)
	{
		if(flag == 0)
		{
			memset(num,'\0',sizeof(num));		//	�����˺�	
			Clear_msg(8,37,8,1);				//	������ʾ��Ϣ

			if(Glb_putstring(num,8,3,0) == 1)	//	�����˺� 
				return ; 
			if(num[0] == '\0')
			{
				gotoxy(15,30);
				printf("Account can't be empty!");
				getch();			
				Clear_msg(15,30,25,0);			
				continue; 
			}							
		}

		
		if(flag == 0)
		{
			for(i = 0; i < n + 1; i++)
			{
				if((strcmp(num,point[0].acc) == 0||strcmp(num,point[i].acc) == 0)&&point[i].flag == 1)
				{
					flag = 1;		//�˺���ȷ������������´β��������˺� 
					break;
				}
				else
					;
			}
		}

		gotoxy(15,30);				//	׼�������ʾ��Ϣ 		
		if(flag == 0)				//	�����ڴ��û�
		{
			printf("No this account!");
			getch();
			Clear_msg(15,30,25,0);
			Clear_msg(12,37,6,0);			
			continue;
		}

		else										//  flag = 1
		{
			memset(pw ,'\0',sizeof(pw));			//	��������		
			Clear_msg(12,37,6,1);

			if(Glb_putstring(pw,6,1,1) == 1)		//	��������  
				return ;
		}
		
		if(strcmp(pw,point[0].psw)==0||strcmp(pw,point[i].psw) == 0)	//������ȷ
		{
			if(strcmp(num,point[0].acc) == 0)		//����ǹ���Ա�˺�
			{
				strcpy(nick,point[0].nick);
				flag = 2;							//׼���������Ա����
			}
			
			else									//������û��˺�
			{
				strcpy(nick,point[i].nick);
				flag = 3;							//׼�������û�����
			}

			break;		//�˺�������ȷ���뿪 
		}

		if(flag == 1)	//�������							
		{
			gotoxy(15,30);
			printf("Password is Error!");
			getch();
		}

		Clear_msg(15,30,25,0);

	}
	fp=fopen("Record.txt","a");			//��鵱ǰĿ¼������Record.txt�����򴴽�
	fp=NULL;
	
	Cls(hStdout);
	printf("Welcome to 2048, %s!\n\n",nick);
	system("pause");
	Cls(hStdout);
	if(flag == 2)
		do_Admin(point,n);		//�������Ա���棨δϸ����
	if(flag == 3)
		Game_ready(nick);		//������Ϸ׼������
	Cls(hStdout);
}

	
int do_Enroll(Add *point)		//�û�ע�����
{
	static int i = 1;	
	int    count, z;	
	char   check[10] = {'\0'};
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	 
	while(1)
	{
		memset(point[i].acc,'\0',sizeof(point[i].acc));	//	�����˺����� 
				
		Clear_msg(8,43,8,1);
					
		if(Glb_putstring(point[i].acc,8,3,0) == 1)		//  Ϊ 1 ������� ESC��						
			return i;
			
		if(Test_empty(point[i].acc[0]) == 1)				//	�˺�Ϊ�գ��������� 
			continue;			 		
			
		if(Test_admin(point[i].acc) == 1)				//	�˺���Ϊ irelia���������� 
			continue;
			
		z = 0;
		for(count = 0; count < i; count++)
		{
			if(Test_same(point[i].acc,point[count].acc) == 1)		//	�˺��Ѿ����� 
			{
				z++;
				break;
			}
		}
		if(z == 0)		//	�˺ſ��� 
			break;			
	}
	
	while(1)
	{
		memset(point[i].psw ,'\0',sizeof(point[i].psw));
		memset(check,'\0',sizeof(check));
						
		gotoxy(10,43);											
		if(Glb_putstring(point[i].psw,6,1,1) == 1)			//	�������� 
			return i; 	
		if(Test_empty(point[i].psw[0]) == 1)					//	����Ϊ��,�������� 
			continue;
					
		gotoxy(12,43);
		if(Glb_putstring(check,6,1,1) == 1)					//	ȷ������				 
			return i;			
			
		if(Test_passwd(point[i].psw,check) == 1)				//	�����������벻һ�£���������				
			continue;
		else												//	������������һ�� ,  ��һ�� 
			break;
	}

	while(1)
	{
		memset(point[i].nick ,'\0',sizeof(point[i].nick));	
		gotoxy(14,43);
		if(Glb_putstring(point[i].nick,10,4,0) == 1)			//	�����ǳ�
			return i;
		if(Test_empty(point[i].nick[0]) == 1)				//	�ǳ�Ϊ�գ��������� 
			continue;
		else 
			break;
	}

	point[i].flag = 1;									//	�����û�		 
	Cls(hStdout);										//	���� 

	//printf("i is %d\n",i);
	printf("Remember your account and password:\n\nAccount = %s\n\nPassword = %s\n\nNickname = %s\n",point[i].acc,point[i].psw,point[i].nick);	
	getch();
	i++;
	return i;	
}

void do_Record()			//���а����
{
	struct node				//��ʱ��50����¼ 
	{
	    int  score;
	    int  steps;
	    char nick[10];
	}cord[50];	
	
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);	
	int  i, j, n, count = 0, ret, flag, z;
	FILE *p;
	struct node temp;
		
	for(i = 0; i < 50; i++)
	{
		cord[i].score = 0;
		cord[i].steps = 0;
	}
		
	p = fopen("record.txt","r");
	z = fgetc(p);
	rewind(p);

	if(z == EOF)
	{
		gotoxy(11,29);	
		printf("You haven't play this game!\n");	//�����Ϣ
		gotoxy(13,33);
		system("pause");
		return ;
	}

	for(i = 0; i < 50; i++)
	{
		ret = fscanf(p,"%d%d%s\n",&cord[i].score,&cord[i].steps,cord[i].nick);
		if(ret == EOF)
			break;
		count++;
	}
	fclose(p);
		
		
	for(i = 0; i < count; i++)
	{
		for(j = 0; j < count - 1; j++)
		{
			if(cord[j].score < cord[j+1].score)
			{
				temp = cord[j];
				cord[j] = cord[j+1];
				cord[j+1] = temp;
			}
		}
	}
	
	
	i = 0;
	n = 0;
	j = 5;
	count = 1;
	flag = 0;
	


	while(1)
	{
		printf("***************��������ҳ��**********���а�**********��ESC���ء�***************");
		gotoxy(3,26);
		printf("Score        Steps          User");	
		while((cord[i].score != 0 && i%10 != 0) || flag == 0)
		{
			gotoxy(j,17);
			printf("%dst",count);
			gotoxy(j,26);
			printf("%4d ",cord[i].score);
			Print_space(4);
			printf("     %3d            %s",cord[i].steps,cord[i].nick);
			count++;
			i++;
			j+=2;
			n++;
			flag = 1;
		}
		while(1)
		{		
			z = Get_key(z);
				
			if(z == 2)			//�·�ҳ
			{
				if(n < 10)
					continue;
				else
				{
					if(cord[i].score != 0)
					{
						Cls(hStdout);
						
						j = 5;
						n = 0;
						flag = 0;
						
						break;
					}
					else
						continue;
				}
			}
			
			else if(z == 1)		//�Ϸ�ҳ
			{
				if(i <= 10)
					continue;
				else
				{
					Cls(hStdout);
					
					i = ((i-1)/10-1) * 10;
					count = ((count-2)/10-1) * 10 + 1;
					j = 5;
					n = 0;
					flag = 0;
					
					break;
				}
			}
			
			else if(z == 7)		//ESC����
			{
				flag = 2;
				break;
			}
	
			else
			{
				continue;
			}
		}
		if(flag == 2)
			break;
	}
	return ;		
}
				
	
int Test_empty(char ch)
{
	if(ch == '\0')
	{
		gotoxy(6,33);
		printf("can't be empty!");
		getch();
		Clear_msg(6,25,32,0);
		return 1;
	}		
	else
		return 0;
}

int Test_admin(char *s)
{	
	if(strcmp(s,"irelia") == 0)
	{
		gotoxy(6,25);
		printf("Admin account can't be resgiter!");
		getch();
		Clear_msg(6,25,32,0);
		return 1;
	}
	else
		return 0;
}
	

int Test_same(char *s1, char *s2)
{	
	if(strcmp(s1,s2) == 0)
	{
		gotoxy(6,25);
		printf("This account has been resgiter!");
		getch();
		Clear_msg(6,25,32,0);
		return 1;		
	}
	else
		return 0;

}

int Test_passwd(char *s1, char *s2)
{
	if(strcmp(s1,s2) != 0)						//	ȷ������
	{
		gotoxy(6,27);
		printf("Entered passwords differ!");
		getch();
		Clear_msg(6,27,32,0);
		
		Clear_msg(10,43,6,0);

		Clear_msg(12,43,6,0);
		
		return 1;
	}	
	else
		return 0;
}

void do_Admin(Add *point,int n)
{
	int  i;
	char psw[10];

	printf("Now there are following users:\n");
	for(i = 0; i <= n; i++)
	{
		if(point[i].flag == 1)
		{
			//user[i+1].flag = 0;
			printf("user[%d],account = %s, password = %s, nickname = %s\n",i,point[i].acc,point[i].psw,point[i].nick);
		}
	}

	printf("\n\n*******************************\n\n");
	while(1)
	{
		printf("%s,Your psw is %s now\nThen change your password to: ",point[0].acc,point[0].psw);
		gets(psw);
		if(psw[0] == '\0')
		{
			printf("Error!Password can't be empty!ReEnter!\n\n");
				continue;
		}
		else if(strlen(psw) > 6)
			printf("Error!The lenth of password can't more than 6bit!\n\n");
		else
			break;
	}

	memcpy(&point[0].psw,&psw,sizeof(psw));
	printf("\nNow your password is: %s, Please remember it!\n",point[0].psw);

	while(1)
	{
		printf("%s, Then you want to ban user[i]? i = ",point[0].acc);
		scanf("%d",&i);
		if(i == 0)
		{
			printf("\nError!Admin account can't be delete!!!\n\n");
			system("pause");
			return ;
		}

		if(i < n)
		{
			if(point[i].flag == 1)
			{
				point[i].flag = 0;
				break;
			}
			else
			{
				printf("\nuser[%d] has been banned!!\n\n",i);
				continue;
			}
		}
		else
		{
			printf("\nNo this account!!!\n\n");
			fflush(stdin);
			continue;
		}
	}
	printf("\nOK!user[%d] has been banned,but his data will be kept!\n\nbye bye!",i);
	system("pause");
}





	
