#include "shell.h"


/**
 * _info_seting - this initializes info_t struct
 * @info:the struct address
 * @a_v: the arg vector
 */
void _info_seting(info_t *info, char **a_v)
{
int y = 0;

info->fnom = a_v[0];
if (info->arg)
{
info->argv = st_rt_ow(info->arg, " \t");
if (!info->argv)
{

info->argv = malloc(sizeof(char *) * 2);
if (info->argv)
{
info->argv[0] = _strydup(info->arg);
info->argv[1] = NULL;
}
}
for (y = 0; info->argv && info->argv[y]; y++)
;
info->argc = y;

rplc_alis(info);
rplc_va_rs(info);
}
}


/**
 * info_freeing - this frees info_t struct fields
 * @info: struct address
 * @a_ll: true if freeing all fields
 */
void info_freeing(info_t *info, int a_ll)
{
fre_ef(info->argv);
info->argv = NULL;
info->pathe = NULL;
if (a_ll)
{
if (!info->c_md_buf)
free(info->arg);
if (info->env)
lst_free(&(info->env));
if (info->history)
lst_free(&(info->history));
if (info->alias)
lst_free(&(info->alias));
fre_ef(info->environ);
info->environ = NULL;
fre_eb((void **)info->c_md_buf);
if (info->readfd > 2)
close(info->readfd);
_putchar(BUF_FLUSH);
}
}

/**
 * _info_clr - this initializes info_t struct
 * @info: the struct address
 */
void _info_clr(info_t *info)
{
info->arg = NULL;
info->argv = NULL;
info->pathe = NULL;
info->argc = 0;
}
