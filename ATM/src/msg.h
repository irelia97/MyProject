#ifndef _MSG_H_
#define _MSG_H_


void window();
void ok();
void roll_ok(USER_T *user);
int  acc_fz();
void acc_unexist();
void psw_fz();
void psw_err();
void login_msg();
void psw_chg();
void user_msg();
void admin_psw(USER_T *admin);
void user_dowhat(USER_T *user);
void try_fz();
void fz_msg();
void fz_ok();
void has_fz();
void psw_ero();
void free_msg();
void free_psw();
void free_ok();
void hasnot_fz();
void try_del();
void del_psw();
void del_ok();
void not_del();
void try_chg();
void chg_psw();
void chg_newpsw();
void chg_ok();
void find_err();
void save_now(USER_T *user);
void mustbe_100();
void onesave_max();
void save_max();
void save_ok(int save, USER_T *user);
void sava_few();
void onedraw_max();
void draw_psw();
void draw_ok(int draw, USER_T *user);
void no_man();
void turn_fz();
void turn_self();
void turn_ok(int money, USER_T *user);
void tel_pk();
int  check_md5();
void md5_err();
void psw_differ();
void psw_ok(char *newpsw);
void too_long();
void over_now();
void month_err();
void over_three();
void input_err();
void less4();
void endyear_err();
void tel_same();
void u_exit();
void u_back();
void nozero();
void psw_dif();


#endif