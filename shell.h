#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define CMD_NORM    0
#define CMD_OR      1
#define CMD_AND     2
#define CMD_CHAIN   3

#define READ_BUF_SIZE  1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH       -1

#define HIST_FILE   ".simple_shell_history"
#define HIST_MAX    4096

#define CONVERT_LOWERCASE   1
#define CONVERT_UNSIGNED    2

#define USE_GETLINE 0
#define USE_OK 0

extern char **environ;

/**
 * struct liststry - singly linked list
 * @num: the number field
 * @stry: a string
 * @next: points to the next node
 */
typedef struct liststry
{
int num;
char *stry;
struct liststry *next;
} list_t;

/**
 * struct passinfo - contains pseudo-arguments to pass into a function,
 *      allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguments
 * @argv: an array of strings generated from arg
 * @pathe: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @cnt_line_flagy: if on count this line of input
 * @fnom: the program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the lastly exec'd command
 * @c_md_buf: address of pointer to cmd_buf, on if chaining
 * @c_md_buf_type: cmd_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
 */
typedef struct passinfo
{
char *arg;
char **argv;
char *pathe;
int argc;
unsigned int line_count;
int err_num;
int cnt_line_flagy;
char *fnom;
list_t *env;
list_t *history;
list_t *alias;
char **environ;
int env_changed;
int status;
char **c_md_buf;
int c_md_buf_type;
int readfd;
int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
char *type;
int (*func)(info_t *);
} builtin_table;

/* Function Declarations */

/* loopmy_h_sh.c */
int loopmy_h_sh(char **);

/* toem_My_Err_ors.c */
void my_ep_uts(char *);
int _E_Put_Charc(char);
int _Fdmy_ep_uts(char c, int fd);
int _Fd_Pu_Ts(char *stry, int fd);

/* toem_strying.c */
int _stry_len(char *);
int _stry_cmp(char *, char *);
char *strt_wth(const char *, const char *);
char *_strycat(char *, char *);

/* toem_strying1.c */
char *_strycpy(char *, char *);
char *_strydup(const char *);
void my_pu_ts(char *);
int _putchar(char);

/* toem_my_exi_ts.c */
char *cpy_st_r(char *, char *, int);
char *con_cat_stry(char *, char *, int);
char *_char_stry(char *, char);

/* toem_my_to_ken_iz_r.c */
char **st_rt_ow(char *, char *);
char **st_rt_ow2(char *, char);

/* toem_my_re_al_loc.c */
char *_me_m_set(char *, char, unsigned int);
void fre_ef(char **);
void *_re_al_loc(void *, unsigned int, unsigned int);

/* toem_my_me_mo_ry.c */
int fre_eb(void **);

/* toem_shloop.c */
int my_h_sh(info_t *, char **);
int fnd_bltin(info_t *);
void c_m_d_fnd(info_t *);
void c_md_frk(info_t *);

/* toem_my_par_ser.c */
int it_is_c_md(info_t *, char *);
char *chars_dupp(char *, int, int);
char *fnd_pathe(info_t *, char *, char *);

/* toemmy_at_oi.c */
int My_Interactive(info_t *);
int my_Is_delimy(char, char *);
int My_Isalpha(int);
int My_Atoi(char *);

/* toem__err_or_s_one.c */
int my_er_ra_toi(char *);
void err_or_pri_nt(info_t *, char *);
int _d_pri_nt(int, int);
char *_num_conv(long int, int, int);
void _comnts_rm(char *);

/* toem_my_buil_tin.c */
int _My_exit(info_t *);
int _My_Cd(info_t *);
int _myhelp(info_t *);

/* this toem_builtin1.c */
int _My_History(info_t *);
int _My_Alias(info_t *);
int Un_Set_Al_ias(info_t *, char *);
int Pri_nt_Alias(list_t *);

/* toem_my_his_tory.c */
char *fil_get_his(info_t *info);
int hist_wrt(info_t *info);
int hist_rd(info_t *info);
int bld_lis_his(info_t *info, char *bff, int cnt_line);
int his_rmb(info_t *info);

/* toem_my_li_sts.c */
list_t *nodey_ad(list_t **, const char *, int);
list_t *nodey_ad_end(list_t **, const char *, int);
size_t pr_1st_stry(const list_t *);
int indx_del_nod(list_t **, unsigned int);
void lst_free(list_t **);


/* toem_my_li_st_s_1.c */
size_t ls_len(const list_t *);
char **list_t_str_s(list_t *);
size_t list_prnt(const list_t *);
list_t *nodey_strts_wth(list_t *, char *, char);
ssize_t get_nodey_indx(list_t *, list_t *);

/* toem_my_va_rs.c */
int my_is_cha_in(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int rplc_alis(info_t *);
int rplc_va_rs(info_t *);
int replace_strying(char **, char *);

/* toem_my_get_line.c */
ssize_t _inptget_(info_t *);
ssize_t rea_d_bff(info_t *info, char **bff, size_t *leny);
int _li_ne_get(info_t *, char **, size_t *);
ssize_t _bff_read(info_t *info, char *bff, size_t *y);
void _Handler_sig_int(int);

/* toem_my_geting_info.c */
void _info_clr(info_t *);
void _info_seting(info_t *, char **);
void info_freeing(info_t *, int);

/* toem_En_Viron.c */
char *_Get_Env(info_t *, const char *);
int _My_Env(info_t *);
int _My_Set_Env(info_t *);
int _My_Un_Se_Tenv(info_t *);
int Pop_Env_Li_St(info_t *);

/* toem_Get_Env.c */
char **_env_iron_get(info_t *);
int _un_se_te_nv(info_t *, char *);
int my_sete_nv(info_t *, char *, char *);

void c_md_frk(info_t *info);
void c_m_d_fnd(info_t *info);
int my_h_sh(info_t *info, char **a_v);
int _putchar(char k);
void my_pu_ts(char *stry);
char **st_rt_ow2(char *stry, char b);
char **st_rt_ow(char *stry, char *b);
int rplc_str(char **oldy, char *nw);
int rplc_alis(info_t *info);
int _Set_AliaS(info_t *info, char *stry);


#endif /* _SHELL_H_ */
