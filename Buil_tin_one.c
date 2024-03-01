#include "shell.h"

/* Add declarations before their first usage*/
int Un_Set_Al_ias(info_t *, char *);
int Pri_nt_Alias(list_t *);

/**
 * _Set_AliaS - sets alias to string
 * @info: parameter struct
 * @stry: the string alias
 * Return: Always 0 on success, 1 on error
 */
int _Set_AliaS(info_t *info, char *stry)
{
char *d;

d = _char_stry(stry, '=');
if (!d)
return (1);
if (!*++d)
return (Un_Set_Al_ias(info, stry));

Un_Set_Al_ias(info, stry);
return (nodey_ad_end(&(info->alias), stry, 0) == NULL);
}


/**
 * _My_History - this displays history list 1 command by the line, preceded
 *  with line nums, start with 0.
 * @info: ure containing potential args.
 *  Return: Always 0
 */
int _My_History(info_t *info)
{
list_prnt(info->history);
return (0);
}

/**
 * Un_Set_Al_ias - the sets alias to stry
 * @info: the parame struct
 * @stry:stry alias
 * Return: Always 0 on success, 1 on error
 */
int Un_Set_Al_ias(info_t *info, char *stry)
{
char *d, k;
int rety;

d = _char_stry(stry, '=');
if (!d)
return (1);
k = *d;
*d = 0;
rety = indx_del_nod(&(info->alias),
get_nodey_indx(info->alias, nodey_strts_wth(info->alias, stry, -1)));
*d = k;
return (rety);
}




/**
 * _My_Alias - this mimics alias builtin
 * @info: ure containing potential args.
 *  Return: Always 0
 */
int _My_Alias(info_t *info)
{
int y = 0;
char *d = NULL;
list_t *nodey = NULL;

if (info->argc == 1)
{
nodey = info->alias;
while (nodey)
{
Pri_nt_Alias(nodey);
nodey = nodey->next;
}
return (0);
}
for (y = 1; info->argv[y]; y++)
{
d = _char_stry(info->argv[y], '=');
if (d)
_Set_AliaS(info, info->argv[y]);
else
Pri_nt_Alias(nodey_strts_wth(info->alias, info->argv[y], '='));
}

return (0);
}



/**
 * Pri_nt_Alias - this prints alias str
 * @nodey: alias node
 * Return: Always 0 on success, 1 on error
 */
int Pri_nt_Alias(list_t *nodey)
{
char *d = NULL, *e = NULL;

if (nodey)
{
d = _char_stry(nodey->stry, '=');
for (e = nodey->stry; e <= d; e++)
_putchar(*e);
_putchar('\'');
my_pu_ts(d + 1);
my_pu_ts("'\n");
return (0);
}
return (1);
}
