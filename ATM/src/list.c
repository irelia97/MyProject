#include <stdio.h>
#include <stdlib.h>
#include "list.h"

LIST_T *list_create()						//创建链表
{
	LIST_T *head = (LIST_T *)malloc(sizeof(LIST_T));

	head->data = NULL;
	head->next = NULL;

	return head;	
}

int list_add(LIST_T *head, void *data)		//添加结点
{
	LIST_T *p = head;
	LIST_T *newcode = (LIST_T *)malloc(sizeof(LIST_T));
	if(newcode == NULL)
		return -1;

	newcode->data = data;
	newcode->next = NULL;

	while(p->next)
	{
		p = p->next;
	}
	p->next = newcode;
	return 0;
}

int list_empty(LIST_T *head)				//检查链表是否为空
{
	return (head->next == NULL);
}

int list_count(LIST_T *head)				//计算链表结点数
{
	int count = 0;
	LIST_T *p = head->next;
	while(p)
	{
		count++;
		p = p->next;
	}
	return count;
}

void *list_getnode(LIST_T *head, int index)	//获得第index个结点地址
{
	int count = 0;
	LIST_T *p = head;
	while(p)
	{
		count++;
		if(count == index)
			return p;

		p = p->next;
	}
	return NULL;
}

void *list_getdata(LIST_T *head, int index)	//获得第index个结点数据地址
{
	int count = 0;
	LIST_T *p = head->next;
	while(p)
	{
		count++;
		if(count == index)
			return p->data;
		
		p = p->next;
	}
	return NULL;
}

int list_deletenode(LIST_T *head, int index)	//删除第index个结点
{
	int count = 0;
	LIST_T *p = head->next, *pre = head;
	while(p)
	{
		count++;
		if(count == index)
		{
			pre->next = p->next;
			free(p->data);
			free(p);
			return 0;
		}
		pre = pre->next;
		p = p->next;
	}
	return -1;
}

void *list_free(LIST_T *head)		//释放结点
{
	LIST_T *p = head;
	while(p)
	{
		head = head->next;
		free(p->data);		//先释放data防止内存泄漏
		free(p);
		p = head;
	}
	return NULL;
}
