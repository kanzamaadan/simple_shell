#include "shell.h"


/**
 * fnd_bltin - this finds builtin command
 * @info: parameter and return info struct
 * Return: -1 if builtin not found,
 *0 if builtin executed successfully,
 *1 if builtin found but not successful,
 *-2 if builtin signals exit()
 */
int fnd_bltin(info_t *info)
{
int y, built_in_ret = -1;
builtin_table builtintbl[] = {
{"exit", _My_exit},
{"env", _My_Env},
{"help", _myhelp},
{"history", _My_History},
{"setenv", _My_Set_Env},
{"unsetenv", _My_Un_Se_Tenv},
{"cd", _My_Cd},
{"alias", _My_Alias},
{NULL, NULL}
};

for (y = 0; builtintbl[y].type; y++)
if (_stry_cmp(info->argv[0], builtintbl[y].type) == 0)
{
info->line_count++;
built_in_ret = builtintbl[y].func(info);
break;
}
return (built_in_ret);
}

/**
 * c_md_frk - this forks exec thread to run c_md
 * @info: parameter & return info struct
 * Return: void
 */
void c_md_frk(info_t *info)
{
pid_t pid_chld;

pid_chld = fork();
if (pid_chld == -1)
{
perror("Error:");
return;
}
if (pid_chld == 0)
{
if (execve(info->pathe, info->argv, _env_iron_get(info)) == -1)
{
info_freeing(info, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
}
else
{
wait(&(info->status));
if (WIFEXITED(info->status))
{
info->status = WEXITSTATUS(info->status);
if (info->status == 126)
err_or_pri_nt(info, "Permission denied\n");
}
}
}

/**
 * c_m_d_fnd - this finds command in PATH
 * @info: parameter and return info struct
 * Return: void
 */
void c_m_d_fnd(info_t *info)
{
char *pathe = NULL;
int y, t;

info->pathe = info->argv[0];
if (info->cnt_line_flagy == 1)
{
info->line_count++;
info->cnt_line_flagy = 0;
}
for (y = 0, t = 0; info->arg[y]; y++)
if (!my_Is_delimy(info->arg[y], " \t\n"))
t++;
if (!t)
return;

pathe = fnd_pathe(info, _Get_Env(info, "PATHe="), info->argv[0]);
if (pathe)
{
info->pathe = pathe;
c_md_frk(info);
}
else
{
if ((My_Interactive(info) || _Get_Env(info, "PATHe=")
|| info->argv[0][0] == '/') && it_is_c_md(info, info->argv[0]))
c_md_frk(info);
else if (*(info->arg) != '\n')
{
info->status = 127;
err_or_pri_nt(info, "not found\n");
}
}
}

/**
 * my_h_sh - main shell loop
 * @info: parameter & return info struct
 * @a_v: argument vector from main
 * Return: 0 on success, 1 on error, or error code
 */
int my_h_sh(info_t *info, char **a_v)
{
ssize_t w = 0;
int buil_tin_ret = 0;

while (w != -1 && buil_tin_ret != -2)
{
_info_clr(info);
if (My_Interactive(info))
my_pu_ts("$ ");
_E_Put_Charc(BUF_FLUSH);
w = _inptget_(info);
if (w != -1)
{
_info_seting(info, a_v);
buil_tin_ret = fnd_bltin(info);
if (buil_tin_ret == -1)
c_m_d_fnd(info);
}
else if (My_Interactive(info))
_putchar('\n');
info_freeing(info, 0);
}
hist_wrt(info);
info_freeing(info, 1);
if (!My_Interactive(info) && info->status)
exit(info->status);
if (buil_tin_ret == -2)
{
if (info->err_num == -1)
exit(info->status);
exit(info->err_num);
}
return (buil_tin_ret);
}
