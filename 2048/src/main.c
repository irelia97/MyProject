#include "common.h"
#include "screen.h"

int main()
{
	int n = 1;											/*	system("cls")Ч�ʹ���		*/		
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);	/*	�����Ч��������Cls()����	*/

	while(1)
	{
		Cls(hStdout);		
		n = Init_sc(n);	
		if(n == 0)
			break;		
	}	

}
