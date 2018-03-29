#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitCard(int a[], const int n);
void RandCard(int a[], int b[][13]);
void SortCard(int a[][13]);
void PrintCard(const int a[13], int low, int top, const char type[10]);
void PrintFinal(const int a[][13]);

int main()
{
	int initcards[52] = {0}; 
	int cards[4][13]  = {0};
	
	InitCard(initcards, 52);
	RandCard(initcards, cards);
	SortCard(cards);
	PrintFinal(cards);
	
	system("pause");
	return 0;
}

/*
	初始化牌堆
	1  ~ 13 表示方桃牌  14 ~ 26 表示梅桃牌
	27 ~ 39 表示红花牌  40 ~ 52 表示黑块牌
*/
void InitCard(int a[], const int n)
{
	int i;
	for(i=0; i<n; ++i)
		a[i] = i+1;
}


//	分配牌堆，a[]是初始化好的牌堆，b[4][]是待分配的牌堆
void RandCard(int a[], int b[][13])
{
	int i, j, index;
	srand((unsigned)time(NULL));    //  随机种子
	
	for(i=0; i<4; i++)              //  为 4个人分牌
	{
		for(j=0; j<13; )            //  每人 13张
		{
			index = rand() % 52;        //  初始牌堆随机下标
			if(a[index] != 0)           //  若这张牌没有被分配
			{
				b[i][j++] = a[index];   //  添加到分配牌堆中去
				a[index] = 0;           //  初始牌堆这张牌值归 0（不能再使用）
			}
		}
	}
}

//  为 4个人的牌从大到小排序，后面遍历输出时即从大到小输出
void SortCard(int a[][13])
{
	int i, j, k, tmp;
	for(i=0; i<4; i++)  //  第 i 个人
	{
		for(j=0; j<12; j++)
		{
			for(k=0; k<12-j; k++)
			{
				if(a[i][k] < a[i][k+1])
				{
					tmp = a[i][k];
					a[i][k] = a[i][k+1];
					a[i][k+1] = tmp;
				}
			}
		}
	}
}

//  打印一种花色的牌型，low 和 top 是该种花色的下界值和上界值，type[]是花色名字
void PrintCard(const int a[13], int low, int top, const char type[10])
{
	int i, tmp;
	printf("%s：", type);

	for(i=0; i<13; i++)
	{
		if(a[i]<low || a[i]>top)    //  不在此范围，说明不是此花色牌
			continue;
		tmp = a[i] % 13 + 1;        //  1为 A，而10、11、12、13分别为T、J、Q、K

		if(tmp > 1 && tmp <= 9)
			printf("%d", tmp);
		else if(tmp == 10)
			putchar('T');
		else if(tmp == 11)
			putchar('J');
		else if(tmp == 12)
			putchar('Q');
		else if(tmp == 13)
			putchar('K');
		else
			putchar('A');
	}
	printf("\n\n");
}

//  打印四个人的牌型
void PrintFinal(const int a[][13])
{
	int i, j, tmp;
	for(i=0; i<4; i++)
	{
		printf("第%d位玩家的牌型如下：\n", i+1);

		PrintCard(a[i], 40, 52, "黑桃牌");
		PrintCard(a[i], 27, 39, "红桃牌");
		PrintCard(a[i], 14, 26, "梅花牌");
		PrintCard(a[i],  1, 13, "方块牌");
	}
}		
