#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "screen.h"
#include "doscreen.h"
#include "common.h"
#include "move.h"
#include "game.h"	


char a0[]="��������                                                              ��������";

char a1[]="�������Щ��������������������������������������������������������������Щ�����";

char a2[]="������������������������������������������������������������������������������";		

char a3[]="�������ة��������������������������������������������������������������ة�����";

char a4[]="��������              	    	   2048��Ϸ 	   	 	      ��������";

char a5[]="��������     Esc���˳�         			      Enter:ȷ��      ��������";


void Login_sc(Add *point,int n)		//��¼���� 
{
	
	char a6[]="��������                �����˺ţ�		      		      ��������";
	
	char a7[]="��������                �������룺		      		      ��������";
	
	char a8[]="		   ����Ա�˻�:irelia	      ����:123456                         ";
	
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",a1,a4,a2,a0,a0,a0,a0,a6,a0,a0,a0,a7,a0,a0,a0,a0,a0,a0,a5,a2,a3,a8);
	
	gotoxy(8,37);
	
	do_Loginsc(point,n);	
	
}


int Init_sc(int n)			//��ʼ������ 
{
	
	char b0[]="��������                       ����������������                       ��������";
	
	char b1[]="��������                       ��            ��                       ��������";	
	
	char b2[]="��������                       �� 1��ע��    ��                       ��������";
	
	char b3[]="��������                       �� 2����¼    ��                       ��������";
	 
	char b4[]="��������                       �� 3���˳�    ��                       ��������";		
	
	char b5[]="��������                       ����������������                       ��������";		
	
	char b6[]="��������     ������ѡ��            	            ��Enter��ȷ��     ��������";	
	
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a1,a4,a2,a0,a0,a0,b0,b2,b5,b3,b5,b4,b5,a0,a0,a0,a0,a0,a0,a2,b6,a3);

	n = do_Initsc(n);
			
	return n;
}

int Enroll_sc(Add *point)
{
	int i;
	
	char c0[]="��������             ������������������������������������             ��������";
	
	char c1[]="��������             ��            ��                  ��             ��������";	
	
	char c2[]="��������             ��    �˺�    ��                  ��             ��������";
	
	char c4[]="��������             ��    ����    ��                  ��             ��������";
	 
	char c5[]="��������             ��  ȷ������  ��                  ��             ��������";

	char c6[]="��������             ��    �ǳ�    ��                  ��             ��������";				
	
	char c7[]="��������             ������������������������������������             ��������";		
	
	char c8[]="��������     ��ESC������            	            ��Enter��ȷ��     ��������";
	
	char a9[]="��������              	    	   �û�ע�� 	   	 	      ��������";	
	
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a1,a9,a2,a0,a0,a0,c0,c2,c7,c4,c7,c5,c7,c6,c7,a0,a0,a0,a0,a2,c8,a3);
	
	gotoxy(17,24);
	printf("Tips: �˺�Ϊ���ֺ���ĸ�����"); 
	gotoxy(18,29);
	printf(" ����ֻ��Ϊ����");
	gotoxy(19,29);		
	printf(" �ǳƿ���ȡ��ĸ�����»������");

	i = do_Enroll(point);
	return i;
}

void Game_ready(char *nick)
{
	int a[4][4] = {0};
	int i, j, z, x = 6, y = 27, arrow = 26, flag = 0, old = 0;
	FILE *p;
	char e1[]="��������  ���������ƶ�           Made by Irelia	        Enter:ȷ��    ��������";
	
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);						   ;

	while(1)
	{
		Cls(hStdout);		
		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a1,a4,a2,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a2,e1,a3);		
		gotoxy(x,y+5);				
		printf("1�� �µĿ�ʼ");
		gotoxy(x+2,y+5);		
		printf("2�� �ɵĻ���");
		gotoxy(x+4,y+5);		
		printf("3�� ��Ϸ�淨");	
		gotoxy(x+6,y+5);		
		printf("4�� ���а��ѯ");
		gotoxy(x+8,y+5);		
		printf("5�� ���а����");
		gotoxy(x+10,y+5);		
		printf("6�� �˳�");		
		gotoxy(x,y);
		printf("%c",arrow);
		
		z = Move_arrow(x,y,6);
		flag = 0;
		
		if(z == 1)
		{
			for(i = 0; i < 4; i++)
				for(j = 0; j < 4; j++)
					a[i][j] = 0;
	
			old = 0;
			Cls(hStdout);		
			Game_sc(&old,a,nick);
			continue;		
		}
			
		else if(z == 2)
		{
			for(i = 0; i < 4; i++)
			{
				for(j = 0; j < 4; j++)
				{
					if(a[i][j] != 0 && old == 1)
					{
						flag = 1;
						break;
					}
				}
				if(flag == 1)
					break;
			}
			
			if(flag == 1)
			{
				old = 1;
				Cls(hStdout);						
				Game_sc(&old,a,nick);
				continue;
			}									
		}
			 
		else if(z == 3)
		{			
			Game_help();
		}
			
		else if(z == 4)
		{
			Cls(hStdout);
			do_Record();	
		}
		else if(z == 5)
		{
			p = fopen("record.txt", "w");//��ֻд��ʽ���ļ�ʱ ��ʵ���Ǵ�����һ�����ļ�(�յ�)�� ������������ļ���Ҳͬ���ᱻ����
			if(p == NULL)
				printf("do empty file %s failed\n", p);
			else fclose(p);
			Cls(hStdout);
			printf("Records have been clear!\n");
			system("pause");
		}			
		else
			break;
	}	
}
	
	

void Game_sc(int *old, int a[][4], char *nick)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
				   	
	int i, j, x = 7, y = 27;																		   	    
	char d1[]="�������� ��ESC������            Made by Irelia       �������������ƶ� ��������";	
	Cls(hStdout);																		    
	
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",a1,a4,a2,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a2,d1,a3);
	for(i = 0; i <= 4; i++)					//���� 
	{
		gotoxy(x-1, y-2);
		for(j = 0; j <= 4; j++)	
			printf("������");
		x = x + 2;
	}
	*old = Game(old,a,nick);		
}

void Game_help()
{
	int x, y;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);	
	Cls(hStdout);
	gotoxy(5,5);
	printf("********************************��Ϸ�淨********************************\n\n"); 
	printf("	1����ʼʱ��������������������֣����ֵ����ֽ�����Ϊ2��4\n");
	printf("	2�����ѡ�����������ĸ������������ڵ����ֳ���λ�ƻ�ϲ���\n  	   ��Ϊ��Ч�ƶ�\n");
    printf("	3���ϲ����õ�����������������Ӽ�Ϊ�ò�����Ч�÷�\n");
    printf("	4�����ѡ��ķ����л���ǰ���пո������λ��\n");
    printf("	5��ÿ��Ч�ƶ�һ�������̵Ŀ�λ(�����ִ�)�������һ��\n   	   ����(��Ȼ����Ϊ2��4)\n");
    printf("	6�����̱������������޷�������Ч�ƶ����и�����Ϸ����\n");
    printf("	7�������ϳ���2048����ʤ������Ϸ�Կɼ���\n\n");
	printf("    *****************************Made by Irelia*****************************\n");
	x = wherex(); y = wherey();
	gotoxy(x+2,y+30);
	system("pause");
	Cls(hStdout);					    
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
