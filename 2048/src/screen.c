#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "screen.h"
#include "doscreen.h"
#include "common.h"
#include "move.h"
#include "game.h"	


char a0[]="│──│                                                              │──│";

char a1[]="┌──┬───────────────────────────────┬──┐";

char a2[]="│──│───────────────────────────────│──│";		

char a3[]="└──┴───────────────────────────────┴──┘";

char a4[]="│──│              	    	   2048游戏 	   	 	      │──│";

char a5[]="│──│     Esc：退出         			      Enter:确定      │──│";


void Login_sc(Add *point,int n)		//登录界面 
{
	
	char a6[]="│──│                输入账号：		      		      │──│";
	
	char a7[]="│──│                输入密码：		      		      │──│";
	
	char a8[]="		   管理员账户:irelia	      密码:123456                         ";
	
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",a1,a4,a2,a0,a0,a0,a0,a6,a0,a0,a0,a7,a0,a0,a0,a0,a0,a0,a5,a2,a3,a8);
	
	gotoxy(8,37);
	
	do_Loginsc(point,n);	
	
}


int Init_sc(int n)			//初始化界面 
{
	
	char b0[]="│──│                       ┌──────┐                       │──│";
	
	char b1[]="│──│                       │            │                       │──│";	
	
	char b2[]="│──│                       │ 1、注册    │                       │──│";
	
	char b3[]="│──│                       │ 2、登录    │                       │──│";
	 
	char b4[]="│──│                       │ 3、退出    │                       │──│";		
	
	char b5[]="│──│                       └──────┘                       │──│";		
	
	char b6[]="│──│     【↑↓选择】            	            【Enter】确定     │──│";	
	
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a1,a4,a2,a0,a0,a0,b0,b2,b5,b3,b5,b4,b5,a0,a0,a0,a0,a0,a0,a2,b6,a3);

	n = do_Initsc(n);
			
	return n;
}

int Enroll_sc(Add *point)
{
	int i;
	
	char c0[]="│──│             ┌────────────────┐             │──│";
	
	char c1[]="│──│             │            │                  │             │──│";	
	
	char c2[]="│──│             │    账号    │                  │             │──│";
	
	char c4[]="│──│             │    密码    │                  │             │──│";
	 
	char c5[]="│──│             │  确认密码  │                  │             │──│";

	char c6[]="│──│             │    昵称    │                  │             │──│";				
	
	char c7[]="│──│             └────────────────┘             │──│";		
	
	char c8[]="│──│     【ESC】返回            	            【Enter】确定     │──│";
	
	char a9[]="│──│              	    	   用户注册 	   	 	      │──│";	
	
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a1,a9,a2,a0,a0,a0,c0,c2,c7,c4,c7,c5,c7,c6,c7,a0,a0,a0,a0,a2,c8,a3);
	
	gotoxy(17,24);
	printf("Tips: 账号为数字和字母的组合"); 
	gotoxy(18,29);
	printf(" 密码只能为数字");
	gotoxy(19,29);		
	printf(" 昵称可以取字母数字下划线组合");

	i = do_Enroll(point);
	return i;
}

void Game_ready(char *nick)
{
	int a[4][4] = {0};
	int i, j, z, x = 6, y = 27, arrow = 26, flag = 0, old = 0;
	FILE *p;
	char e1[]="│──│  【↑↓】移动           Made by Irelia	        Enter:确定    │──│";
	
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);						   ;

	while(1)
	{
		Cls(hStdout);		
		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a1,a4,a2,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a2,e1,a3);		
		gotoxy(x,y+5);				
		printf("1、 新的开始");
		gotoxy(x+2,y+5);		
		printf("2、 旧的回忆");
		gotoxy(x+4,y+5);		
		printf("3、 游戏玩法");	
		gotoxy(x+6,y+5);		
		printf("4、 排行榜查询");
		gotoxy(x+8,y+5);		
		printf("5、 排行榜清空");
		gotoxy(x+10,y+5);		
		printf("6、 退出");		
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
			p = fopen("record.txt", "w");//以只写方式打开文件时 其实就是创建了一个新文件(空的)。 如果本来存在文件，也同样会被覆盖
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
	char d1[]="│──│ 【ESC】返回            Made by Irelia       【←↑↓→】移动 │──│";	
	Cls(hStdout);																		    
	
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",a1,a4,a2,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a0,a2,d1,a3);
	for(i = 0; i <= 4; i++)					//横线 
	{
		gotoxy(x-1, y-2);
		for(j = 0; j <= 4; j++)	
			printf("───");
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
	printf("********************************游戏玩法********************************\n\n"); 
	printf("	1、开始时棋盘内随机出现两个数字，出现的数字仅可能为2或4\n");
	printf("	2、玩家选择上下左右四个方向，若棋盘内的数字出现位移或合并，\n  	   视为有效移动\n");
    printf("	3、合并所得的所有新生成数字想加即为该步的有效得分\n");
    printf("	4、玩家选择的方向行或列前方有空格则出现位移\n");
    printf("	5、每有效移动一步，棋盘的空位(无数字处)随机出现一个\n   	   数字(依然可能为2或4)\n");
    printf("	6、棋盘被数字填满且无法进行有效移动，判负，游戏结束\n");
    printf("	7、棋盘上出现2048，判胜，但游戏仍可继续\n\n");
	printf("    *****************************Made by Irelia*****************************\n");
	x = wherex(); y = wherey();
	gotoxy(x+2,y+30);
	system("pause");
	Cls(hStdout);					    
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
