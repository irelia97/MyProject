#include <stdio.h>
#include <windows.h>
#include "list.h"

void Writetofile(LIST_T *head, char *s)				
{
	FILE *fp;
	LIST_T * ptemp;
	fp = fopen(s,"w+");	//文件打开
	
	ptemp = head->next;
	while(ptemp)
	{
		fwrite(ptemp->data,sizeof(USER_T),1,fp);
		ptemp = ptemp->next;
	}
	fclose(fp);
	//list_free(head);		//暂时不清
}

void Writetorecord(LIST_T *rehead, char *s)				
{
	FILE *fp;
	LIST_T * ptemp;
	fp = fopen(s,"w+");	//文件打开
	
	ptemp = rehead->next;
	while(ptemp)
	{
		fwrite(ptemp->data,sizeof(Record_t),1,fp);
		ptemp = ptemp->next;
	}
	fclose(fp);
	//list_free(head);		//暂时不清
}

LIST_T *Readfromfile(char *s)
{
	FILE   *fp;
	LIST_T *head = list_create();
	USER_T *user;
	
	fp = fopen(s,"r");
	while(1)
	{
		user = (USER_T *)malloc(sizeof(USER_T));
		
		memset(user,0,sizeof(USER_T)); 
		
		fread(user,sizeof(USER_T),1,fp);
		
		if(feof(fp))	    //先读再判断，防止读入空行
			break;
		
		list_add(head,user);
		
	}
	fclose(fp);
	return head;
}

LIST_T *Readrecord(char *s)
{
	FILE   *fp;
	LIST_T *rehead = list_create();
	Record_t *user;

	SYSTEMTIME sys; 
	GetLocalTime(&sys);
	
	fp = fopen(s,"r");
	while(1)
	{
		user = (Record_t *)malloc(sizeof(Record_t));
		
		memset(user,0,sizeof(Record_t)); 
		
		fread(user,sizeof(Record_t),1,fp);
		
		if(feof(fp))	    //先读再判断，防止读入空行
			break;
		
		if(user->year == sys.wYear)
		{
			if((sys.wMonth - user->month - 1) * 31 + (31 + sys.wDay - user->day) < 93)
					list_add(rehead,user);
		}

		if(user->year == sys.wYear - 1)
		{
			if((sys.wMonth + 12 - user->month - 1) * 31 + (31 + sys.wDay - user->day) < 93)
				list_add(rehead,user);
		}

		
	}
	fclose(fp);
	return rehead;
}

FILE* File_open(char *s)
{	
	FILE *fp;
	fp = fopen(s,"a");		//"w+"，打开后写入从末尾开始，防止覆盖
	fclose(fp);
	return fp;	
}


void ReadAdmin(USER_T *admin)
{
	FILE *fp;
	fp = File_open("./data/admin.txt");
	
	fp = fopen("./data/admin.txt","r");
	fread(admin,sizeof(USER_T),1,fp);
	if(strcmp(admin->psw,"\0") == 0)
	{
		strcpy(admin->acc,"irelia");
		strcpy(admin->psw,"123456");
		admin->save = 100000000;
		admin->role = 0;
		admin->flag = 1;
		strcpy(admin->id,"1000");
		fwrite(admin,sizeof(USER_T),1,fp);
		fclose(fp);
	}
	else
		fclose(fp);

}