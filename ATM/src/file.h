#ifndef		_FILE_H_
#define		_FILE_H_

#include "list.h"
void   Writetofile(LIST_T *head, char *s);
void   Writetorecord(LIST_T *rehead, char *s);
LIST_T *Readrecord(char *s);
FILE*  File_open(char *s);
LIST_T *Readfromfile(char *s);
void   ReadAdmin(USER_T *admin);


#endif