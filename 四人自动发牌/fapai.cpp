#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initCard(int a[], int n);
void randCard(int a[], int b[][13]);
void sortCard(int a[][13]);
void printCard(int a[13], int low, int top, char type[10]);
void printFinal(int a[][13]);

int main()
{
	int initcards[52] = {0}, cards[4][13] = {0};
	
	initCard(initcards, 52);
	randCard(initcards, cards);
	sortCard(cards);
	printFinal(cards);
	
	system("pause");
	return 0;
}

/*
	��ʼ���ƶ�
	1  ~ 13 ��ʾ������  14 ~ 26 ��ʾ÷����
	27 ~ 39 ��ʾ�컨��  40 ~ 52 ��ʾ�ڿ���
*/
void initCard(int a[], int n)
{
	int i;
	for(i=0; i<n; ++i)
		a[i] = i+1;
}


//	�����ƶѣ�a[]�ǳ�ʼ���õ��ƶѣ�b[4][]�Ǵ�������ƶ�
void randCard(int a[], int b[][13])
{
	int i, j, index;
	srand((unsigned)time(NULL));    //  �������
	
	for(i=0; i<4; i++)              //  Ϊ 4���˷���
	{
		for(j=0; j<13; )            //  ÿ�� 13��
		{
			index = rand() % 52;        //  ��ʼ�ƶ�����±�
			if(a[index] != 0)           //  ��������û�б�����
			{
				b[i][j++] = a[index];   //  ��ӵ������ƶ���ȥ
				a[index] = 0;           //  ��ʼ�ƶ�������ֵ�� 0��������ʹ�ã�
			}
		}
	}
}

//  Ϊ 4���˵��ƴӴ�С���򣬺���������ʱ���Ӵ�С���
void sortCard(int a[][13])
{
	int i, j, k, tmp;
	for(i=0; i<4; i++)  //  �� i ����
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

//  ��ӡһ�ֻ�ɫ�����ͣ�low �� top �Ǹ��ֻ�ɫ���½�ֵ���Ͻ�ֵ��type[]�ǻ�ɫ����
void printCard(int a[13], int low, int top, char type[10])
{
	int i, tmp;
	printf("%s��", type);

	for(i=0; i<13; i++)
	{
		if(a[i]<low || a[i]>top)    //  ���ڴ˷�Χ��˵�����Ǵ˻�ɫ��
			continue;
		tmp = a[i] % 13 + 1;        //  1Ϊ A����10��11��12��13�ֱ�ΪT��J��Q��K

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

//  ��ӡ�ĸ��˵�����
void printFinal(int a[][13])
{
	int i, j, tmp;
	for(i=0; i<4; i++)
	{
		printf("��%dλ��ҵ��������£�\n", i+1);

		printCard(a[i], 40, 52, "������");
		printCard(a[i], 27, 39, "������");
		printCard(a[i], 14, 26, "÷����");
		printCard(a[i],  1, 13, "������");
	}
}		
