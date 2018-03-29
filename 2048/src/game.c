#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "move.h"
#include "common.h"
#include "doscreen.h"
#include "game.h"

//int score = 0, steps = 0;

void Print_num(int a[][4])
{
	int  i, j, x = 7, y = 27;

	for(i = 0; i < 4; i++)					 
	{
		gotoxy(x,y-2);
		printf("│");						
		for(j = 0; j < 4; j++)
		{
			if(a[i][j]==0)
			{
				printf("     │");			
			}
			else
			{
				printf("%4d │",a[i][j]);	//竖线和数
			}
		}
		x = x + 2;							//每一排隔两行
	}

}

void Rand24(int a[][4])
{
	int i, j, k;
	srand(time(0));
	while(1)
	{
		i = rand() % 4;
		j = rand() % 4;
		if(a[i][j] == 0)
		{
			k = rand() % 100;
			if(k > 10) 				// 90%几率出 2 
				a[i][j] = 2;
			else
				a[i][j] = 4;		// 10%几率出 4 
			break;
		}
	}
}


int Game_check(int a[][4])
{
	int score = 0, flag = 0;

	score += Move_up(score,a);

	score += Move_left(score,a);
		
	if(score == 0)
		return 0;
	else
		return 1;
}


int Game(int *old, int a[][4], char *nick)
{
	FILE *p;
	static int score = 0, steps = 0;
	int i, j, z, flag, temp = 0;
	int b[4][4] = {0}; 
		
	if((*old) == 0)			//new game
	{
		score = 0;
		steps = 0;
		Rand24(a);
		Rand24(a);
		Print_num(a);
	}
	

	while(1)
	{
		z = 0;
		flag = 0;
		gotoxy(15,17);
		
		Print_space(4);
		printf("Score = %d",score);
		Print_space(16);
		printf("Steps = %d",steps);
		
		if((*old) == 1)
		{
			(*old)++;
			continue;
		}
		
		if((*old) == 2)
		{
			Print_num(a);
		}	

		temp = Move(a);	

		if(temp == -1)					//ESC返回-1 
		{
			return 1;
		}
		
		else if(temp == 0)					//该步得分为0，判断是否结束 
		{
			for(i = 0; i < 4; i++)			//先判断格子是否满了 
			{
				for(j = 0; j < 4; j++)
				{
					if(a[i][j] == 0)	
					{
						z = 1;
					}	
									
					if(a[i][j] == 2048)		//检测到2048 
					{
						gotoxy(20,34);
						printf("Your have got 2048!");
						
						p = fopen("record.txt","a");
						fprintf(p,"%d %d %s\n",score,steps,nick);
						fclose(p);
					}					
				}
			}
				
			if(z == 1)					//z = 1，格子没有满，退出 处理得分，步数 
			{
				steps ++;
				score += temp; 
			}
			 					
			
			else						//z = 0，如果格子满了且得分为0 
			{
				memcpy(b,a,sizeof(b));
				flag = Game_check(b);	//四个方向都判断一遍 
				if(flag == 0)			//四个方向得分总和为0，游戏结束 
				{
					Clear_msg(15,17,4,0);
					printf("Score = %d",score);
					Print_space(16);
					printf("Steps = %d",steps);
					
					gotoxy(18,35);
					printf("Game Over!\n");
					gotoxy(23,31);
					system("pause");
					
					for(i = 0; i < 4; i++)
						for(j = 0; j < 4; j++)
							a[i][j] = 0;
							
					p = fopen("record.txt","a");
					fprintf(p,"%d %d %s\n",score,steps,nick);
					fclose(p);					
					return 0;
				}
				
				else					//得分不为0，说明还有方向可以移动 
				{
					continue;			//重新进行移动 
				}
			}	 
		}
					
		else		//temp > 0，此步有得分 
		{
			steps ++;
			score += temp;
		}
		Rand24(a);			
		*old = 2;
	}
}
		

	
	

