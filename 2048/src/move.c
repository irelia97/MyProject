#include <stdio.h>
#include "move.h"
#include "common.h"	
		
			
int Move(int a[][4])
{
	int scores = 0, old = 0, key = 0;

	while(1)
	{
		key = Get_key(key);
		if(key == 1)
			return(Move_up(scores,a));
		else if(key == 2)
			return(Move_down(scores,a));
		else if(key == 3)
			return(Move_left(scores,a));
		else if(key == 4)
			return(Move_right(scores,a));
		else if(key == 7)
			return -1;
		else if(key == 9)
			return -2;
		else
			continue;
	}		
}

int Move_up(int scores, int a[][4])
{
	int i, j, k = 2;
	while(k--)
	{
		for(j = 0; j < 4; j++)
		{
			for(i = 0; i < 3; i++)
			{
				if(a[i][j] == 0)
				{
					a[i][j] = a[i+1][j];
					a[i+1][j] = 0;
				}
			}
		}
	}
	
	for(j = 0; j < 4; j++)
	{
		for(i = 0; i < 3; i++)
		{
			if(a[i][j] == a[i+1][j])
			{
				scores += (2*a[i][j]);
				a[i][j] *= 2;
				a[i+1][j] = 0;
			}
		}
	}
	
	for(j = 0; j < 4; j++)
	{
		for(i = 0; i < 3; i++)
		{
			if(a[i][j] == 0)
			{
				a[i][j] = a[i+1][j];
				a[i+1][j] = 0;
			}
		}
	}	
	
	return scores;
}
	
	
int Move_down(int scores, int a[][4])
{
	int i, j, k =2;

	while(k--)
	{
		for(j = 0; j < 4; j++)
		{
			for(i = 3; i > 0; i--)
			{
				if(a[i][j] == 0)
				{
					a[i][j] = a[i-1][j];
					a[i-1][j] = 0;
				}
			}
		}
	}	
	
	for(j = 0; j < 4; j++)
	{
		for(i = 3; i > 0; i--)
		{
			if(a[i][j] == a[i-1][j])
			{
				scores += (2*a[i][j]);								
				a[i][j] *= 2;
				a[i-1][j] = 0;
			}
		}
	}

	for(j = 0; j < 4; j++)
	{
		for(i = 3; i > 0; i--)
		{
			if(a[i][j] == 0)
			{
				a[i][j] = a[i-1][j];
				a[i-1][j] = 0;
			}
		}
	}				

	return scores;
}	
	

int Move_left(int scores, int a[][4])
{
	int i, j, k = 2;

	while(k--)
	{
		for(i = 0; i < 4; i++)
		{
			for(j = 0; j < 3; j++)
			{
				if(a[i][j] == 0)
				{
					a[i][j] = a[i][j+1];
					a[i][j+1] = 0;
				}
			}
		}
	}	
	
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(a[i][j] == a[i][j+1])
			{
				scores += (2*a[i][j]);		
				a[i][j] *= 2;
				a[i][j+1] = 0;
			}
		}
	}

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(a[i][j] == 0)
			{
				a[i][j] = a[i][j+1];
				a[i][j+1] = 0;
			}
		}
	}
	
	return scores;
}


int Move_right(int scores, int a[][4])
{
	int i, j, k = 2;

	while(k--)
	{
		for(i = 0; i < 4; i++)
		{
			for(j = 3; j > 0; j--)
			{
				if(a[i][j] == 0)
				{
					a[i][j] = a[i][j-1];
					a[i][j-1] = 0;
				}
			}
		}
	}
				
	for(i = 0; i < 4; i++)
	{
		for(j = 3; j > 0; j--)
		{
			if(a[i][j] == a[i][j-1])
			{
				scores += (2*a[i][j]);								
				a[i][j] *= 2;
				a[i][j-1] = 0;
			}
		}
	}

	for(i = 0; i < 4; i++)
	{
		for(j = 3; j > 0; j--)
		{
			if(a[i][j] == 0)
			{
				a[i][j] = a[i][j-1];
				a[i][j-1] = 0;
			}
		}
	}
	
	return scores;
}

int Move_arrow(int x, int y, int z)
{
	int i = 1, key = 0, arrow = 26;	
	
	while(1)
	{
		key = Get_key(key);
		
		if(key == 1)
		{
			if(i > 1)
			{
				Clear_msg(x,y,1,0);
				
				i -- ;
				x = x - 2 ;
				
				gotoxy(x,y);
				printf("%c",arrow);				
				continue;
			}
		}
		
		else if(key == 2)
		{			
			if(i < z)
			{
				Clear_msg(x,y,1,0);
				
				i ++ ;
				x = x + 2 ;

				gotoxy(x,y);
				printf("%c",arrow);				
				continue;
			}
		}
		
		else if(key == 6)
		{
			return i;
		}

		else
		{
			continue;
		}
	}
}	
		
	

