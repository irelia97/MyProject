#include <stdio.h>
#include <stdlib.h>
#include "list.h"

LIST_T *list_create()						//��������
{
	LIST_T *head = (LIST_T *)malloc(sizeof(LIST_T));

	head->data = NULL;
	head->next = NULL;

	return head;	
}

int list_add(LIST_T *head, void *data)		//��ӽ��
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

int list_empty(LIST_T *head)				//��������Ƿ�Ϊ��
{
	return (head->next == NULL);
}

int list_count(LIST_T *head)				//������������
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

void *list_getnode(LIST_T *head, int index)	//��õ�index������ַ
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

void *list_getdata(LIST_T *head, int index)	//��õ�index��������ݵ�ַ
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

int list_deletenode(LIST_T *head, int index)	//ɾ����index�����
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

void *list_free(LIST_T *head)		//�ͷŽ��
{
	LIST_T *p = head;
	while(p)
	{
		head = head->next;
		free(p->data);		//���ͷ�data��ֹ�ڴ�й©
		free(p);
		p = head;
	}
	return NULL;
}
