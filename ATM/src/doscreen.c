#include <stdio.h>
#include <conio.h>
#include "doscreen.h"
#include "common.h"
#include "gotoxy.h"
#include "screen.h"
#include <direct.h>		//for mkdir()
#include "file.h"
#include "msg.h"

SYSTEMTIME sys; 

int do_Initsc()
{
	int  x = 9, y = 29, arrow = 26, key = 0, i = 1;	
	char ch;
	FILE    *fp;
	USER_T  *admin = (USER_T*)malloc(sizeof(USER_T));
	USER_T  *user = (USER_T *)malloc(sizeof(USER_T));
	LIST_T  *head = NULL, *rehead = NULL;
	memset(user,0,sizeof(USER_T));	
	memset(admin,0,sizeof(USER_T));							//以上为初始化
	
	i  = mkdir("./data/");									//创建文件夹data存放用户、管理员和交易记录的信息
	fp = File_open("./data/user.txt");						
	fp = File_open("./data/record.txt");					//无则创建
	
	ReadAdmin(admin);										//读入管理员数据
	head = Readfromfile("./data/user.txt");					//读入用户数据
	rehead = Readrecord("./data/record.txt");				//读入最近三个月交易记录数据
	Writetorecord(rehead,"./data/record.txt");				//刷新交易记录文本，只保留最近三个月的记录
	
	i = Move_arrow(x,y,3);		//箭头移动
	system("cls");
	
	if(i == 1)					//进入注册界面
	{
		Login_sc(head,rehead,user,admin);
		return 0;
	}
	
	else if(i == 2)				//进入登录界面
	{		
		Enroll_sc(head,user);
		return 0;
	}
	
	else if(i == 3)				//退出
	{
		u_exit();
		while(ch = getch())
		{
			if(ch == 49)
			{
				system("cls");
				return -1;
			}
			else if(ch == 50 || ch ==ESC)
			{
				system("cls");
				color(14);
				return 0;
			}

		}
	}	
	else
		return 0;
	
	return 0;
}


void do_Enroll(LIST_T *head, USER_T *user)		//用户注册界面
{
	int    id, n, count, z;	
	char   check[10] = {'\0'};

	USER_T *temp;
	
	while(1)		//账号输入
	{
		memset(user->acc,'\0',sizeof(user->acc));	//	覆盖上一次的输入的账号 
		
		Clear_msg(6,43,8,1);
		
		if(Glb_putstring(user->acc,8,3,0) == 1)		//  为 1 则接收了 ESC键						
			return ;
		
		if(Test_empty(user->acc[0]) == 1)			//	账号为空，重新输入 
			continue;			 		
		
		if(Test_admin(user->acc) == 1)				//	账号名为 irelia，重新输入 
			continue;

		if(strlen(user->acc) <= 4)					//	账号不得小于4位
		{
			less4();
			continue;
		}
	

		n = list_count(head);
		z = 0;
		for(count = 1; count <= n; count++)
		{
			temp = (USER_T *)list_getdata(head,count);
			if(Test_same(user->acc,temp->acc) == 1 || Test_same(user->acc,temp->id) == 1 || Test_same(user->acc,"1000") == 1)		//	账号已经存在 
			{
				z++;
				break;	//	跳出for()，继续while()
			}
		}
		if(z == 0)		//	账号可用，准备输入密码
			break;			
	}


	
	while(1)		//密码输入
	{
		memset(user->psw ,'\0',sizeof(user->psw));		//覆盖上一次输入的密码
		memset(check,'\0',sizeof(check));
		
		gotoxy(8,43);											
		if(Glb_putstring(user->psw,6,1,1) == 1)				//	输入密码 
			return ; 
		
		if(Test_empty(user->psw[0]) == 1)					//	密码为空,重新输入 
			continue;

		if(Test_len(user->psw,6) == 1)
		{
			Clear_msg(8,43,6,0);
			continue;
		}
				
		gotoxy(10,43);
		if(Glb_putstring(check,6,1,1) == 1)					//	确认密码				 
			return ;			
		
		if(Test_passwd(user->psw,check) == 1)				//	两次密码输入不一致，重新输入				
			continue;
		else												//	两次密码输入一致 ,  下一步 
			break;
	}

	while(1)												//	中文姓名
	{
		memset(user->name,'\0',sizeof(user->name));

		gotoxy(12,43);
		if(Glb_putstring(user->name,13,5,0) == 1)
			return ;
		if(user->name[0] == '\0')
			continue;
		else
			break;
	}

	while(1)												//	手机号码
	{
		memset(user->tel,'\0',sizeof(user->tel));
		Clear_msg(14,43,11,1);
		if(Glb_putstring(user->tel,11,1,0) == 1)
			return ;
		if(user->tel[0] == '\0')
			continue;
		if(Test_len(user->tel,11) == 1)
		{
			Clear_msg(14,43,11,0);
			continue;
		}


		n = list_count(head);
		z = 0;	
		for(count = 1; count <= n; count++)					//	检测是否已经被使用
		{
			temp = (USER_T *)list_getdata(head,count);
			if(strcmp(user->tel,temp->tel) == 0 || strcmp(user->tel,temp->tel) == 0)		//	账号已经存在 
			{
				z++;
				tel_same();
				break;	//	跳出for()，继续while()
			}
		}
		if(z == 0)		//	账号可用，准备输入密码
			break;
	}

	user->flag = 1;										//	激		1表示账号可用
	user->role = 1;										//	活		1表示普通用户
	user->save = 0;										//	户		初始存款为0

	if(n == 0)
	{
		id = 1001 + n;
		sprintf(user->id,"%d",id);						//	用		ID
	}
	else
	{
		temp = list_getdata(head,n);
		id = atoi(temp->id) + 1;
		sprintf(user->id,"%d",id);
	}

	n = list_add(head,user);							//	添加用户信息至链表
	Writetofile(head,"./data/user.txt");				//	写入/data/user.txt中

	roll_ok(user);		//	注册成功信息	

	return ;	
}


void do_Loginsc(LIST_T *head, LIST_T *rehead, USER_T *user, USER_T *admin)
{
	int  	 flag = 0, flag1 = 0, count = 1, i;	
	USER_T  *temp;

	char     num[10] ;				//	账号初始化								
	char      pw[10] ;				//	密码初始化 	

	while(1)
	{
		if(flag == 0)
		{
			memset(num,'\0',sizeof(num));		//	重置账号	
			Clear_msg(8,37,8,1);				//	覆盖提示信息

			if(Glb_putstring(num,8,3,0) == 1)	//	输入账号 
				return ; 
			if(Test_empty(num[0]) == 1)	
				continue; 						
		}
									//	flag为0，即为第一次输入或账号输入错误

		if(flag == 0)
		{
			if(strcmp(num,admin->acc) == 0 || strcmp(num,admin->id) == 0)
			{
				flag = 1;
			}
			else
			{
				for(i = 1; i <= list_count(head); i++)
				{
					temp = (USER_T *)list_getdata(head,i);
					if((strcmp(num,temp->acc) == 0 || strcmp(num,temp->id) == 0))	//	遍历链表
					{
						if(temp->flag == 0)	//	存在账号，但是被冻结
						{
							flag = -1;
							break;
						}
						else				//	账号正确，若密码错误，下次不用输入账号
						{
							flag = 1;		 
							break;
						}
					}
				}
			}
	
		}

		if(flag == -1)					//	账号被冻结
		{
			flag = acc_fz();
			continue;
		}
											
		else if(flag == 0)				//	不存在此用户
		{
			acc_unexist();
			continue;

		}
		else										//  flag = 1
		{

			memset(pw ,'\0',sizeof(pw));			//	重置密码		
			Clear_msg(12,37,6,1);

			if(Glb_putstring(pw,6,1,1) == 1)		//	输入密码  
				return ;
		}

		
		if(strcmp(num,admin->acc)== 0 || strcmp(num,admin->id) == 0)
		{
			if(strcmp(pw,admin->psw)== 0)			//	如果是管理员账号且密码正确
			{
				flag = 2;							//	准备进入管理员界面
				break;
			}
		}		
		else if(strcmp(pw,temp->psw) == 0)			//	如果是用户账号且密码正确
		{

			flag = 3;								//	准备进入用户界面
			break;								
		}

		if(flag == 1)	//密码错误							
		{
			if(strcmp(num,admin->acc) != 0 && strcmp(num,admin->id) != 0)
			{
				if((count++) == 3)		//	密码输入错误3次
				{
					temp->flag = 0;
					Writetofile(head,"./data/user.txt");			//	写入/data/temp.txt中
					psw_fz();
					return ;
				}
				else
					psw_err();			//	输入错误提示信息
			}
			else
				psw_err();
		}
	}

	system("cls");

	if(flag == 2)
	{
		login_msg();
		Admin_sc(head,user,admin);		//	进入管理员界面
	}
	if(flag == 3)
	{
		login_msg();
		User_sc(head,rehead,temp);		//	进入用户界面
	}

	system("cls");
}


int do_Admin(LIST_T *head, USER_T *user, USER_T *admin)
{
	int  x = 9, y = 29, arrow = 26, key = 0, i = 1;	
	char ch;

	while(1)
	{	
		i = Move_arrow(x,y,4);		//	箭头选择相应功能

		if(i == 0)					//	ESC	
		{
			u_back();
			while(ch = getch())
			{
				if(ch == 49)
				{
					system("cls");
					return 0;
				}
				else if(ch == 50 || ch == ESC)
				{
					system("cls");
					color(14);
					return 1;
				}
			}

		}
	
		if(i == 1)					//	进入管理用户界面
		{
			system("cls");
			Ban_user(head,user,admin);
			system("cls");
			return 1;
		}
		
		else if(i == 2)				//	进入修改密码界面
		{	
			system("cls");
			key = Modify_sc(admin);
			if(key == 0)
			{
				psw_chg();
				return 0;			
			}
			else
			{
				system("cls");
				return 1 ;
			}
		}

		else if(i == 3)				//	模糊查询用户
		{
			system("cls");
			find_user(head,admin);
			return 1;
		}
		
		else if(i == 4)				//	退出系统
		{
			u_exit();
			while(ch = getch())
			{
				if(ch == 49)
				{
					system("cls");
					byebye();
				}
				else if(ch == 50 || ch ==ESC)
				{
					system("cls");
					color(14);
					return 1;
				}
			}
		}
		
		else
			;	
	}

}


void Ban_user(LIST_T *head, USER_T *user, USER_T *admin)
{
	int  z = 0, i = 0, n = 0, page = 1, flag = 0, count = 0, num = 0;
	LIST_T *ptemp = head; 
	USER_T *lyy;

	n = list_count(head);
	num = (n - 1) / 8 + 1;
	Ban_sc();

	while(1)
	{
		user_msg();
		count = 0;

		if(ptemp == NULL)
			ptemp = head;
		ptemp = list_printusers(ptemp, 8, &count);
		gotoxy(23,39);
		printf("%d/%d",page,num);
		gotoxy(7,3);
		printf("%c",26);
		while(1)
		{	
			z = Move_arrow(7,3,count);
			
			if(z == 0)
			{
				return ;
			}

			else if(z == 30)		//左翻
			{
				if(page == 1)
					continue;
				else
				{
					system("cls");
					Ban_sc();
					i = 1 + 8 * (page - 2);
					ptemp = list_getnode(head,i);		//获取当前上一页第一个用户结点信息
					page--;		
					break;
				}
			}
			
			else if(z == 40)		//右翻
			{
				if(ptemp->next == NULL)
					continue;
				else
				{
					system("cls");
					Ban_sc();
					page++;
					break;
				}

			}

			else
			{
				z += 8 * (page - 1);
				if(z > n)
				{
					i = 1 + 8 * (page - 1);
					ptemp = list_getnode(head,i);
					printf("操作错误!");
					getch();
					break;
				}
				else
				{
					i = 1 + 8 * (page - 1);
					ptemp = list_getnode(head,i);
					lyy   = list_getdata(head,z);
					window();
					deal_user(head,lyy,admin,z);					//	ENTER进入管理用户界面
					Writetofile(head,"./data/user.txt");			//	写入/data/temp.txt中
					color(14);
					break;
				}
				system("pause");
			}

		}
	
	}
		

}

int do_Modify(USER_T *admin)					//修改管理员密码
{
	FILE *fp;
	char newpsw[10], check[10];
	while(1)
	{
		memset(check ,'\0',sizeof(check));		//覆盖上一次输入的密码
		memset(newpsw,'\0',sizeof(newpsw));
		
		Clear_msg(10,43,6,1);											
		if(Glb_putstring(newpsw,6,1,1) == 1)			//	输入密码 
			return 1; 
		
		if(Test_empty(newpsw[0]) == 1)					//	密码为空,重新输入 
			continue;

		if(Test_len(newpsw,6) == 1)						//	必须为6位
		{
			Clear_msg(10,43,6,0);
			continue;
		}

		if(strcmp(admin->psw,newpsw) == 0)
		{
			psw_dif();
			continue;
		}
		
		gotoxy(12,43);
		if(Glb_putstring(check,6,1,1) == 1)				//	确认密码				 
			return 1;			
		
		if(Test_passwd(check,newpsw) == 1)				//	两次密码输入不一致，重新输入
		{
			Clear_msg(12,43,6,0);
			continue;
		}
		else												//	两次密码输入一致 ,  下一步 
			break;
	}

	strcpy(admin->psw,newpsw);
	fp = fopen("./data/admin.txt","w+");
	fwrite(admin,sizeof(USER_T),1,fp);						//	管理员信息写入/data/admin.txt
	fclose(fp);
	admin_psw(admin);			//	显示修改后的管理员信息
	return 0;
}

void deal_user(LIST_T *head, USER_T *user, USER_T *admin, int index)
{
	int  key1 = 0, key2 = 0;
	char psw[10];

	user_dowhat(user);
	while(1)
	{
		key1 = Get_key(key1);
		if(key1 == 7)				//ESC
			return ;

		else if(key1 == 11)			//选择冻结用户
		{
			if(user->flag == 1)		//若未被冻结
			{
				try_fz();			//询问是否冻结

				while(1)
				{
					key2 = Get_key(key2);
					if(key2 == 11)		//选择冻结
					{
						fz_msg();
						while(1)
						{
							memset(psw,'\0',sizeof(psw));
							if(Glb_putstring(psw,6,1,1) == 1)	//输入管理员密码
								return;
							if(strcmp(psw,admin->psw) == 0)
							{
								user->flag = 0;
								fz_ok();
								return ;
							}
							else
							{
								psw_ero();
								continue ;
							}
						}
					}
					
					else if(key2 == 12 || key2 == 7)	//选择不冻结或ESC
						return ;
					
					else
						continue;
				}
			}
	
			else	//已被冻结
			{
				has_fz();
				return ;
			}
		}
		else if(key1 == 12)				//解冻用户
		{
			if(user->flag == 0)			//若已被冻结
			{
				free_msg();				//询问是否解冻

				while(1)
				{
					key2 = Get_key(key2);
					if(key2 == 11)				//选择解冻
					{
						free_psw();
						while(1)
						{
							memset(psw,'\0',sizeof(psw));
							if(Glb_putstring(psw,6,1,1) == 1)		//输入管理员密码
								return;
							if(strcmp(psw,admin->psw) == 0)
							{
								user->flag = 1;
								free_ok();
								return ;
							}
							else
							{
								psw_ero();
								continue ;
							}
						}
					}
					
					else if(key2 == 12 || key2 == 7)				//选择不冻结或按ESC
						return ;
					
					else
						continue;
				}
			}
			
			else				//若未被冻结
			{
				hasnot_fz();
				return ;
			}

		}

		else if(key1 == 13)		//删除用户
		{
			try_del();			//询问是否删除

			while(1)
			{
				key2 = Get_key(key2);
				if(key2 == 11)
				{
					if(user->save == 0)		//若存款为0
					{
						del_psw();			//提示输入管理员密码
						while(1)
						{
							memset(psw,'\0',sizeof(psw));
							if(Glb_putstring(psw,6,1,1) == 1)		//输入管理员密码
								return;
							if(strcmp(psw,admin->psw) == 0)
							{
								list_deletenode(head,index);		//删除此用户
								del_ok();
								return ;
							}
							else
							{
								psw_ero();
								continue ;
							}
						}
					}
					else			//用户仍有存款，不能删除
					{
						not_del();
						return ;
					}
				}
				else if(key2 == 12 || key2 == 7)		//选择不删除或ESC
					return ;

				else
					continue;
			}
		}

		else if(key1 == 14)		//修改密码
		{

			try_chg();			//询问是否修改
			while(1)
			{
				key2 = Get_key(key2);
				if(key2 == 11)			//修改
				{	
					chg_psw();			//提示输入管理员密码
					while(1)
					{
						memset(psw,'\0',sizeof(psw));
						if(Glb_putstring(psw,6,1,1) == 1)			//输入管理员密码
							return;
						if(strcmp(psw,admin->psw) == 0)
						{
							while(1)
							{
								memset(psw,'\0',sizeof(psw));		//输入用户新密码
								chg_newpsw();

								if(Glb_putstring(psw,6,1,1) == 1)
									return ;
								if(Test_len(psw,6) == 1)			//必须为6位
								{
									Clear_msg(13,26,20,0);
									continue;
								}
								else
								{
									strcpy(user->psw,psw);
									break;
								}
							}
							chg_ok();
							return ;
						}
						else
						{
							psw_ero();
							continue ;
						}
					}
				}
				else if(key2 == 12 || key2 == 7)
					return ;
			
				else
					continue;
			}

		}

	}
}

void find_user(LIST_T *head, USER_T *admin)
{
	int  i = 0, n = 0, flag = 0, count = 0, z = 0, page = 1, p = 0, num = 0;
	char name[20];
	char *p1, *p2, *p3;
	LIST_T *ptemp = (LIST_T *)malloc(sizeof(LIST_T)) , *head1 = (LIST_T *)malloc(sizeof(LIST_T));
	USER_T *temp, *user = (USER_T*)malloc(sizeof(USER_T)), *lyy;

	head1->data = NULL;	head1->next = NULL;

	while(1)
	{
		memset(user,0,sizeof(USER_T));
		memset(name,'\0',sizeof(name));	
		gotoxy(3,1);
		printf("请输入用户姓名或账号或ID的部分信息(模糊查询): ");
		if(Glb_putstring(name,20,0,0) == 1)
		{
			system("cls");
			return ;
		}

		for(i = 1; i <= list_count(head); i++)
		{
			temp = (USER_T *)list_getdata(head,i);

			p1 = strstr(temp->acc,name);			//匹配账号

			p2 = strstr(temp->id,name);				//匹配ID

			p3 = strstr(temp->name,name);			//匹配姓名

			if(p1 || p2 || p3)						//匹配到其中任意一个
			{	
				user = (USER_T *)malloc(sizeof(USER_T));
				flag = 1;
				user = temp;
				n    = list_add(head1,user);		//添加用户信息至链表
				p++;
			}
		}
		if(flag == 0)			//未找到符合查询条件的用户
		{
			find_err();
			p = 0;
		}
		else					//查询到符合条件的用户
		{
			printf("\n\n共查询到%d个符合条件的用户!\n",p);
			break;
		}
	}
	system("pause");

	ptemp = head1;				//得到储存这些用户链表的头结点
	n = list_count(head1);		//得到总人数
	num = (n - 1) / 8 + 1;

	while(1)
	{
		system("cls");
		Ban_sc();
		gotoxy(5,5);
		printf("ID\t\t 账号\t\t密码\t      手机\t    余额\t状态");
		
		count = 0;
		if(ptemp == NULL)
			ptemp = head;
		ptemp = list_printusers(ptemp, 8, &count);	
		gotoxy(23,39);
		printf("%d/%d",page,num);
		gotoxy(7,3);
		printf("%c",26);

		while(1)
		{
			z = Move_arrow(7,3,count);
			
			if(z == 0)
			{
				system("cls");
				return ;
			}
			
			else if(z == 30)		//左翻
			{
				if(page == 1)
					continue ;
				else
				{
					system("cls");
					Ban_sc();
					i = 1 + 8 * (page - 2);
					ptemp = list_getnode(head1,i);
					page--;
					break;
				}
			}
			
			else if(z == 40)		//右翻
			{
				if(ptemp->next == NULL)
					continue;
				else
				{
					system("cls");
					Ban_sc();
					page++;
					break;
				}
				
			}	
		
			else
			{
				z += 8 * (page - 1);
				if(z > n)
				{
					i = 1 + 8 * (page - 1);
					ptemp = list_getnode(head1,i);
					printf("操作错误!");
					getch();
					break;
				}
				else
				{
					i = 1 + 8 * (page - 1);
					ptemp = list_getnode(head1,i);
					lyy = list_getdata(head1,z);
					window();
					deal_user(head1,lyy,admin,z);					//	ENTER进入管理用户界面
					Writetofile(head,"./data/user.txt");			//	写入/data/temp.txt中
					color(14);
					break;
				}
				system("pause");
			}
		}
	}
	system("cls");
}


int do_User(LIST_T *head, LIST_T *rehead, USER_T *user)
{
	int  x = 9, y = 28, arrow = 26, key = 0, i = 1, count = 0;	
	char ch;
	
	while(1)
	{		
		i = Move_arrow(x,y,6);

		if(i == 0)
		{
			u_back();
			while(ch = getch())
			{
				if(ch == 49)
				{
					system("cls");
					return 0;
				}
				else if(ch == 50 || ch == ESC)
				{
					system("cls");
					color(14);
					return 1;
				}
			}
		}
				
		if(i == 1)					//进入存款界面
		{
			User_save(head,rehead,user);
			return 1;
		}
		
		else if(i == 2)				//进入取款界面
		{	
			User_draw(head,rehead,user);
			return 1;
		}
		
		else if(i == 3)				//进入转账界面
		{
			User_turn(head,rehead,user);
			return 1;
		}
		
		else if(i == 4)				//修改密码
		{
			key = User_psw(head,user);
			if(key == 1)
			{
				printf("检测到您的用户密码修改,请重新登录!");
				getch();
				return 0;
			}
			else
				return 1;
		}

		else if(i == 5)				//交易记录
		{
			User_record(rehead,user);
			return 1;
		}
		
		else if(i == 6)
		{
			u_exit();
			while(ch = getch())
			{
				if(ch == 49)
				{
					system("cls");
					byebye();
				}
				else if(ch == 50 || ch ==ESC)
				{
					system("cls");
					color(14);
					return 1;
				}
			}
		}

		else
			;
	}

}

void User_save(LIST_T *head, LIST_T *rehead, USER_T *user)
{
	int  temp = user->save;
	char save[10];
	Record_t *record = (Record_t *)malloc(sizeof(Record_t));

	while(1)
	{
		system("cls");
		Save_sc();
		save_now(user);
		memset(save,'\0',sizeof(save));
		Clear_msg(11,40,8,1);
		if(Glb_putstring(save,6,1,0) == 1)
		{
			system("cls");
			return ;
		}


		if(atoi(save) == 0)
		{
			nozero();
			continue;
		}

		else if(atoi(save) % 100 != 0)
		{
			mustbe_100();
			continue;
		}
		else if(atoi(save) > 200000)
		{
			onesave_max();
			continue;
		}
		else if(temp + atoi(save) > 1000000)
		{
			save_max();
			continue;
		}
		else
			break;
	}


	GetLocalTime(&sys);
	memset(record,0,sizeof(Record_t));
	user->save += atoi(save);

	save_ok(atoi(save),user);
	gettime(record->number);
	strcat(record->number,user->id);
	strcpy(record->what,"存款");
	record->money = atoi(save);
	record->save = user->save;
	record->year  = sys.wYear;
	record->month = sys.wMonth;
	record->day   = sys.wDay;
	strcpy(record->user,user->acc);
	strcpy(record->other,"农业银行");

	list_add(rehead,record);

	Writetorecord(rehead,"./data/record.txt");
	Writetofile(head,"./data/user.txt");			//	写入/data/temp.tx


	system("cls");	
}


void User_draw(LIST_T *head, LIST_T *rehead, USER_T *user)
{
	int  temp = user->save;
	char draw[10], psw[10];
	Record_t *record = (Record_t *)malloc(sizeof(Record_t));
	
	while(1)
	{
		system("cls");
		Draw_sc();
		save_now(user);
		memset(draw,'\0',sizeof(draw));
		memset(psw,'\0',sizeof(psw));

		Clear_msg(8,40,5,1);
		Clear_msg(10,40,6,1);
		if(Glb_putstring(draw,5,1,0) == 1)
		{
			system("cls");
			return ;
		}


		if(atoi(draw) > temp)
		{
			sava_few();
			continue;
		}

		else if(atoi(draw) == 0)
		{
			nozero();
			continue;
		}

		else if(atoi(draw) % 100 != 0)
		{
			mustbe_100();
			continue;
		}

		else if(atoi(draw) > 50000)
		{
			onedraw_max();
			continue;
		}

		else
		{
			gotoxy(12,40);
			if(Glb_putstring(psw,6,1,1) == 1)
			{
				system("cls");
				return ;
			}
			
			if(strcmp(psw,user->psw) == 0)
				break;
			else
			{
				draw_psw();
			}
		}
	}


	GetLocalTime(&sys);
	memset(record,0,sizeof(Record_t));	
	user->save -= atoi(draw);

	draw_ok(atoi(draw),user);
	gettime(record->number);
	strcat(record->number,user->id);
	strcpy(record->what,"取款");
	record->money = -atoi(draw);
	record->save = user->save;
	record->year  = sys.wYear;
	record->month = sys.wMonth;
	record->day   = sys.wDay;
	strcpy(record->user,user->acc);
	strcpy(record->other,"农业银行");

	list_add(rehead,record);
	
	Writetorecord(rehead,"./data/record.txt");	
	Writetofile(head,"./data/user.txt");			//	写入/data/temp.tx

	system("cls");
}

void User_turn(LIST_T *head, LIST_T *rehead, USER_T *user)
{
	LIST_T *p = head;
	USER_T *temp;
	Record_t *record1 = (Record_t *)malloc(sizeof(Record_t));
	Record_t *record2 = (Record_t *)malloc(sizeof(Record_t));
	int  i = 0, flag;
	char name[10], money[10], psw[10];

	while(1)
	{
		flag = 0;
		system("cls");
		memset(name,'\0',sizeof(name));		

		turn_sc();
		save_now(user);
		Clear_msg(8,40,8,1);
		if(Glb_putstring(name,8,3,0) == 1)
		{
			system("cls");
			return ;
		}

		for(i = 1; i <= list_count(head); i++)
		{
			temp = (USER_T *)list_getdata(head,i);
			if((strcmp(name,temp->acc) == 0 || strcmp(name,temp->id) == 0))
			{
				if(temp->flag == 0)		//冻结状态
				{
					flag = 1;
					break;
				}
				else					//可用状态
				{
					flag = 2;
					break;
				}
			}
		}

		gotoxy(6,32);
		if(flag == 0)
		{
			no_man();
			continue;
		}

		else if(flag == 1)
		{
			turn_fz();
			continue;
		}

		else if(strcmp(user->id,temp->id) == 0)
		{
			turn_self();
			continue;
		}

		else
		{
			while(1)
			{
				memset(money,'\0',sizeof(money));
				Clear_msg(6,26,40,0);
				Clear_msg(10,40,5,1);

				if(Glb_putstring(money,5,1,0) == 1)
				{
					system("cls");
					return ;
				}


				if(atoi(money) > user->save)
				{
					sava_few();
					continue;
				}

				else if(atoi(money) == 0)
				{
					nozero();
					continue;
				}

				else if(atoi(money) > 50000)
				{
					onedraw_max();
					continue;
				}

				else if(temp->save + atoi(money) > 1000000)
				{
					save_max();
					continue;
				}
				
				else
				{
					while(1)
					{
						memset(psw,'\0',sizeof(psw));
						Clear_msg(6,35,20,0);
						Clear_msg(12,40,6,1);
						if(Glb_putstring(psw,6,1,1) == 1)
							return ;
						if(strcmp(psw,user->psw) == 0)
							break;
						else
						{
							draw_psw();
							continue;
						}
					}
				}
				break;
			}


			GetLocalTime(&sys);
			memset(record1,0,sizeof(Record_t));
			memset(record2,0,sizeof(Record_t));

			temp->save += atoi(money);
			user->save -= atoi(money);
			turn_ok(atoi(money),user);			
			gettime(record1->number);
			strcat(record1->number,user->id);
			strcpy(record1->what,"转账转出");				//用户
			record1->money = -atoi(money);
			record1->save = user->save;
			record1->year  = sys.wYear;
			record1->month = sys.wMonth;
			record1->day   = sys.wDay;
			strcpy(record1->user,user->acc);
			strcpy(record1->other,temp->acc);


			gettime(record2->number);
			strcat(record2->number,temp->id);
			strcpy(record2->what,"转账转入");				//对象
			record2->money = atoi(money);
			record2->save = temp->save;
			record2->year  = sys.wYear;
			record2->month = sys.wMonth;
			record2->day   = sys.wDay;
			strcpy(record2->user,temp->acc);
			strcpy(record2->other,user->acc);

			list_add(rehead,record1);
			list_add(rehead,record2);			
			Writetorecord(rehead,"./data/record.txt");
			Writetofile(head,"./data/user.txt");			//	写入/data/temp.tx

			system("cls");
		}
		break;
	}

}


int User_psw(LIST_T *head, USER_T *user)
{
	int  i = 0, z;
	char tel[12];
	char md5[5], newpsw[10], check[10];

	while(1)
	{
		system("cls");
		psw_sc();

		Clear_msg(8,40,11,1);
		memset(tel,'\0',sizeof(tel));
		if(Glb_putstring(tel,11,1,0) == 1)
		{
			system("cls");
			return 0;
		}

		if(strcmp(tel,user->tel) != 0)
		{
			tel_pk();
			continue;
		}
		else
		{
			while(1)
			{
				i = check_md5();
				memset(md5,'\0',sizeof(md5));

				if(Glb_putstring(md5,4,1,0) == 1)
				{
					system("cls");
					return 0;
				}

				z = atoi(md5);
				if(z != i)
				{
					md5_err();
					continue;
				}
				else
				{
					while(1)
					{
						Clear_msg(12,40,6,1);
						memset(newpsw,'\0',sizeof(newpsw));
						memset(check,'\0',sizeof(check));

						if(Glb_putstring(newpsw,6,1,1) == 1)
						{
							system("cls");
							return 0;
						}

						if(Test_len(newpsw,6) == 1)
						{
							continue;
						}

						if(strcmp(user->psw,newpsw) == 0)
						{
							psw_dif();
							continue;
						}

						else
						{
							Clear_msg(14,40,6,1);
							if(Glb_putstring(check,6,1,1) == 1)
							{
								system("cls");
								return 0;
							}

							if(strcmp(newpsw,check) != 0)
							{
								psw_differ();
								continue;
							}

							else
								break;
						}
					}
				
				}
				break;
			}
		}
		break;
	}

	strcpy(user->psw,newpsw);
	Writetofile(head,"./data/user.txt");			//	写入/data/temp.tx

	psw_ok(newpsw);

	return 1;
}


void User_record(LIST_T *rehead, USER_T *user)
{
	int i = 0, z = 0, count = 0, page = 1, n;
	char ch;
	char op_year[5], op_month[5], op_day[5];
	char ed_year[5], ed_month[5], ed_day[5];

	LIST_T *rehead1 = (LIST_T *)malloc(sizeof(LIST_T));
	LIST_T *rehead2 = (LIST_T *)malloc(sizeof(LIST_T)); 
	LIST_T *p = (LIST_T *)malloc(sizeof(LIST_T));
	Record_t *ptemp = (Record_t *)malloc(sizeof(Record_t));
	rehead1->data = NULL;	rehead1->next = NULL;
	rehead2->data = NULL;	rehead2->next = NULL;
	GetLocalTime(&sys);

	while(1)
	{
		system("cls");
		printf("1、全部查询\n2、按时间查询\n\n请选择查询方式: ");
		ch = getch();
		if(ch == 49)		//1
		{
			for(i = 1; i <= list_count(rehead); i++)
			{
				ptemp = (Record_t *)list_getdata(rehead,i);
				if(strcmp(ptemp->user,user->acc) == 0)
					list_add(rehead1,ptemp);
			}
			n = (list_count(rehead1) - 1) / 8 + 1;
			
			p = rehead1;		
			while(1)
			{
				system("cls");
				Record_sc();
				count = 0;
				if(p == NULL)
					p = rehead;	
				p = list_printrecord(p,8,&count);
				gotoxy(23,39);
				printf("%d/%d",page,n);
				while(1)
				{
					z = Move_arrow(7,3,count);
					
					if(z == 0)
					{
						system("cls");
						return ;
					}
					
					else if(z == 30)		//左翻
					{
						if(page == 1)
							continue ;
						else
						{
							i = 1 + 8 * (page - 2);
							p = list_getnode(rehead1,i);
							page--;
							break;
						}
					}
					
					else if(z == 40)		//右翻
					{
						if(p->next == NULL)
							continue;
						else
						{
							page++;
							break;
						}
					}
				}
			}
		}

		else if(ch == 50)	//2
		{
			while(1)
			{
				memset(op_year,'\0',sizeof(op_year));memset(op_month,'\0',sizeof(op_month));memset(op_day,'\0',sizeof(op_day));
				Clear_msg(9,1,50,0);	
				Clear_msg(7,1,40,0);
				Clear_msg(15,30,25,0);
				Clear_msg(5,1,30,1);
				printf("当前年月日：%d 年 %02d 月 %02d 日\n",sys.wYear,sys.wMonth,sys.wDay);
				gotoxy(7,1);printf("起始年月日：");gotoxy(7,18);printf("年");gotoxy(7,24);printf("月");gotoxy(7,30);printf("日");
				gotoxy(7,13);
				if(Glb_putstring(op_year,4,1,0) == 1)
				{
					system("cls");
					return ;
				}
				if(sys.wYear - 2 >= atoi(op_year))
				{
					too_long();
					continue;
				}
				else if(sys.wYear < atoi(op_year))
				{
					over_now();
					continue;
				}
				putchar(' ');				
/*********************************起始年*******************************/

				gotoxy(7,21);
				if(Glb_putstring(op_month,2,1,0) == 1)
				{
					system("cls");
					return ;
				}
				if(atoi(op_month) < 1 || atoi(op_month) > 12)
				{
					month_err();
					continue;
				}

				if(sys.wYear == atoi(op_year))
				{
					if(atoi(op_month)> sys.wMonth)
					{
						over_now();
						continue;
					}
					else if(atoi(op_month) + 3 < sys.wMonth)
					{
						over_three();
						continue;
					}
				}
				else
				{
					if(sys.wMonth + 12 - atoi(op_month) > 3)
					{
						over_three();
						continue;
					}
				}
/*********************************起始月*******************************/
				gotoxy(7,27);
				if(Glb_putstring(op_day,2,1,0) == 1)
				{
					system("cls");
					return ;
				}
				if(atoi(op_month) == 1 || atoi(op_month) == 3 ||atoi(op_month) == 5 ||atoi(op_month) == 7 ||atoi(op_month) == 8 ||atoi(op_month) == 10 ||atoi(op_month) == 12 )
				{
					if(atoi(op_day) < 1 || atoi(op_day) > 31)
					{
						input_err();
						continue;
					}
				}
				else if(atoi(op_month) == 4 || atoi(op_month) == 6 ||atoi(op_month) == 9 ||atoi(op_month) == 11)
				{
					if(atoi(op_day) < 1 || atoi(op_day) > 30)
					{
						input_err();
						continue;
					}
				}

				else if(atoi(op_month) == 2)
				{
					if(atoi(op_day) < 1 || atoi(op_day) > 28)
					{
						input_err();
						continue;
					}
				}

				if(atoi(op_month) == sys.wMonth)
				{
					if(atoi(op_day) > sys.wDay)
					{
						over_now();
						continue;
					}
				}

				if(sys.wYear - atoi(op_year) == 1)
				{
					if(31*(12-atoi(op_month)+sys.wMonth-1)+(31+sys.wDay-atoi(op_day)) > 93)
					{
						printf("最多查询最近三个月的记录!\n");
						getch();
						continue;
					}
					else
						;
				}
				else if(sys.wYear == atoi(op_year))
				{
					if(31*(sys.wMonth-atoi(op_month)-1)+(31+sys.wDay-atoi(op_day)) > 93)
					{
						over_three();
						continue;
					}
					else
						;
					
				}

				while(1)
				{
					Clear_msg(9,1,30,0);
					Clear_msg(15,30,25,0);
					memset(ed_year,'\0',sizeof(ed_year));memset(ed_month,'\0',sizeof(ed_month));memset(ed_day,'\0',sizeof(ed_day));
					gotoxy(9,1);printf("终止年月日：");gotoxy(9,18);printf("年");gotoxy(9,24);printf("月");gotoxy(9,30);printf("日");

					gotoxy(9,13);
					if(Glb_putstring(ed_year,4,1,0) == 1)
					{
						system("cls");
						return ;
					}
					if(atoi(ed_year) < atoi(op_year) || atoi(ed_year) - atoi(op_year) > 2)
					{
						endyear_err();
						continue;
					}

					if(atoi(ed_year) > sys.wYear)
					{
						over_now();
						continue;
					}
					
					gotoxy(9,21);
					if(Glb_putstring(ed_month,2,1,0) == 1)
					{
						system("cls");
						return ;
					}
					if(atoi(ed_month) < 1 && atoi(ed_month) > 12)
					{
						month_err();
						continue;
					}
					if(atoi(op_year) == atoi(ed_year))
					{
						if(atoi(ed_month) < atoi(op_month))
						{
							month_err();
							continue;
						}
						if(atoi(ed_month) > sys.wMonth)
						{
							over_now();
							continue;
						}
					}
					if(atoi(op_year) + 1 == atoi(ed_year))
					{
						if(atoi(ed_month) + 12 - atoi(op_month) - 1 > 3)
						{
							month_err();
							continue;
						}
					}
					
					gotoxy(9,27);
					if(Glb_putstring(ed_day,2,1,0) == 1)
					{
						system("cls");
						return ;
					}
					if(atoi(ed_month) == 1 || atoi(ed_month) == 3 ||atoi(ed_month) == 5 ||atoi(ed_month) == 7 ||atoi(ed_month) == 8 ||atoi(ed_month) == 10 ||atoi(ed_month) == 12 )
					{
						if(atoi(ed_day) < 1 || atoi(ed_day) > 31)
						{
							input_err();
							continue;
						}
					}
					else if(atoi(ed_month) == 4 || atoi(ed_month) == 6 ||atoi(ed_month) == 9 ||atoi(ed_month) == 11)
					{
						if(atoi(ed_day) < 1 || atoi(ed_day) > 30)
						{
							input_err();
							continue;
						}
					}
					if(atoi(ed_year) - atoi(op_year) >= 2)
					{
						printf("所查询记录时间跨度太大!\n");
						getch();
						continue;
					}
					else
					{
						if(atoi(ed_year) - atoi(op_year) == 1)
						{
							if(31*(12-atoi(op_month)+atoi(ed_month)-1)+(31+atoi(ed_day)-atoi(op_day)) > 93)
							{
								printf("最多查询最近三个月的记录!\n");
								getch();
								continue;
							}
							else
								break;
						}

						else if(atoi(ed_year) == atoi(op_year))
						{
							if(sys.wMonth == atoi(ed_month))
							{
								if(atoi(ed_day) > sys.wDay)
								{
									over_now();
									continue;
								}
								else
									break;
							}
							else if(31*(atoi(ed_month)-atoi(op_month)-1)+(31+atoi(ed_day)-atoi(op_day)) > 93)
							{
								printf("最多查询最近三个月的记录!\n");
								getch();
								continue;
							}
							else
								break;
							
						}
					}
				}
				break;		
			}

			for(i = 1; i <= list_count(rehead); i++)
			{
				ptemp = (Record_t *)list_getdata(rehead,i);

				if(strcmp(ptemp->user,user->acc) == 0)
				{
					if(ptemp->year >= atoi(op_year) && ptemp->year <= atoi(ed_year) )
					{
						if(31*atoi(op_month)+atoi(op_day) <= 31*ptemp->month+ptemp->day && 31*atoi(ed_month)+atoi(ed_day) >= 31*ptemp->month+ptemp->day)
						{					
							list_add(rehead2,ptemp);
						}
							
					}
				}
				
			}
			n = (list_count(rehead2) - 1) / 8 + 1;
			
			p = rehead2;		
			while(1)
			{
				system("cls");
				Record_sc();

				count = 0;
				if(p == NULL)
					p = rehead;	
				p = list_printrecord(p,8,&count);
				gotoxy(23,39);
				printf("%d/%d",page,n);
				gotoxy(2,5);
				printf("%d/%02d/%02d --- %d/%02d/%02d",atoi(op_year),atoi(op_month),atoi(op_day),atoi(ed_year),atoi(ed_month),atoi(ed_day));
				while(1)
				{
					z = Move_arrow(7,3,count);
					
					if(z == 0)
					{
						system("cls");
						return ;
					}
					
					else if(z == 30)		//左翻
					{
						if(page == 1)
							continue ;
						else
						{
							i = 1 + 8 * (page - 2);
							p = list_getnode(rehead2,i);
							page--;
							break;
						}
					}
					
					else if(z == 40)		//右翻
					{
						if(p->next == NULL)
							continue;
						else
						{
							page++;
							break;
						}
					}
				}
			}
		}

		else if(ch == 27)	//ESC
		{
			system("cls");
			return ;
		}
		else
			continue;
	}


}


LIST_T *list_printusers(LIST_T *head, int n, int *count)			//	用户信息打印
{
	int x = 7;
	LIST_T *p = head;
	
	while(p->next)
	{
		USER_T *data = (USER_T *)malloc(sizeof(USER_T));
		p = p->next;
		data = p->data;
		
		
		gotoxy(x,5);
		if(data->role == 1 && data->flag != 2)
		{
			printf("%4s\t%8s\t%6s\t    %11s\t   ",data->id,data->acc,data->psw,data->tel);
			show_money(data->save);
			putchar('\t');
			gotoxy(x,73);
			if(data->flag == 1)
				printf("激活");
			else
			{
				color(12);
				printf("冻结");
				color(14);
			}
			x+=2;
			(*count)++;
		}
		
		if((*count) == n)
			break;
	}	
	return p;
}

LIST_T *list_printrecord(LIST_T *rehead, int n, int *count)			//	用户信息打印
{
	int x = 7;
	LIST_T *p = rehead;
	system("cls");
	Record_sc();
	gotoxy(5,5);
	printf("\t交易流水号\t    业务  \t交易对象\t 收支\t     余额");
	while(p->next)
	{
		Record_t *data = (Record_t *)malloc(sizeof(Record_t));
		p = p->next;
		data = p->data;
		
		
		gotoxy(x,5);
		if(1)
		{
			printf("%12s\t%10s\t%8s",data->number,data->what,data->other);
			gotoxy(x,56);
			show_money(data->money);
			gotoxy(x,67);
			show_money(data->save);

			x+=2;
			(*count)++;
		}
		
		if((*count) == n)
			break;
	}

	return p;
}



		
	
