#include "common.h"
#include "screen.h"

int main()
{
	int n = 1;											/*	system("cls")效率过低		*/		
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);	/*	定义高效清屏函数Cls()变量	*/

	while(1)
	{
		Cls(hStdout);		
		n = Init_sc(n);	
		if(n == 0)
			break;		
	}	

}
