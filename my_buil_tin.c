#include "shell.h"


/**
 * _My_Cd - this changes current dir of process
 * @info: structure containing potential args.
 *  Return: Always 0
 */
int _My_Cd(info_t *info)
{
char *z, *diry, buffer[1024];
int ch_Dir_Ret;

z = getcwd(buffer, 1024);
if (!z)
my_pu_ts("TODO: >>getcwd failure emsg here<<\n");
if (!info->argv[1])
{
diry = _Get_Env(info, "HOME=");
if (!diry)
ch_Dir_Ret = /* TODO: what this should be? */
chdir((diry = _Get_Env(info, "PWD=")) ? diry : "/");
else
ch_Dir_Ret = chdir(diry);
}
else if (_stry_cmp(info->argv[1], "-") == 0)
{
if (!_Get_Env(info, "OLDPWD="))
{
my_pu_ts(z);
_putchar('\n');
return (1);
}
my_pu_ts(_Get_Env(info, "OLDPWD=")), _putchar('\n');
ch_Dir_Ret = /* TODO: what this should be? */
chdir((diry = _Get_Env(info, "OLDPWD=")) ? diry : "/");
}
else
ch_Dir_Ret = chdir(info->argv[1]);
if (ch_Dir_Ret == -1)
{
err_or_pri_nt(info, "can't cd to ");
my_ep_uts(info->argv[1]), _E_Put_Charc('\n');
}
else
{
my_sete_nv(info, "OLDPWD", _Get_Env(info, "PWD="));
my_sete_nv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}


/**
 * _My_exit - function to exit the shell
 * @info: structure containing potential args
 *  Return: exits with a given exit status
 *(0) if info.argv[0] != "exit"
 */
int _My_exit(info_t *info)
{
int extcheck;

if (info->argv[1])
{
extcheck = my_er_ra_toi(info->argv[1]);
if (extcheck == -1)
{
info->status = 2;
err_or_pri_nt(info, "Illegal number: ");
my_ep_uts(info->argv[1]);
_E_Put_Charc('\n');
return (1);
}
info->err_num = my_er_ra_toi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}


/**
 * _myhelp - this changes current dir of the process
 * @info: structure containing potential args.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
char **arr_arg;

arr_arg = info->argv;
my_pu_ts("help call works. Function not yet implemented \n");
if (0)
my_pu_ts(*arr_arg);
return (0);
}
