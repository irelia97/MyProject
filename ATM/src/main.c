#include "screen.h"		//for Init_sc()
#include "common.h"		//for real_time()

DWORD WINAPI ThreadProc1(LPVOID lpParam)	//子线程
{
    real_time();							//在第1行打印时间
    return 0;
}

int main()
{
	int i = 0;

	Welcome();
    CreateThread(NULL, 0, ThreadProc1, NULL, 0, NULL);		//时间显示子线程
	while(1)
	{
		system("cls");
		i = Init_sc();							//in screen.c
		if(i == -1)
			break;
	}
	byebye();
	
	return 0;
}
