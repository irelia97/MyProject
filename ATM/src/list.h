#ifndef  _LIST_H_
#define  _LIST_H_

typedef struct list_t
{
	void *data;
	struct list_t *next;
}LIST_T;


typedef struct users_t
{
	char acc[10];
	char psw[10];
	char name[13];
	char tel[12];
	char id[5];
	int  save;
	int  role;
	int  flag;
}USER_T;

typedef struct record_t
{
	char number[20];
	char what[10];	
	int  money;
	int  save;
	char user[10];
	char other[10];
	int  year;
	int  month;
	int  day;
}Record_t;


LIST_T *list_create();	//创建链表

int list_add(LIST_T *head, void *data);		//添加结点

int list_empty(LIST_T *head);		//测试链表是否为空

int list_count(LIST_T *head);		//结点个数

void *list_getnode(LIST_T *head, int index);	//获取某结点地址

void *list_getdata(LIST_T *head, int index);	//获取某结点数据地址

int list_deletenode(LIST_T *head, int index);	//删除某结点

void *list_free(LIST_T *head);		//释放链表

#endif