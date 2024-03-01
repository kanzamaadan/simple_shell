#include "shell.h"


/**
 * _un_se_te_nv - remove environ var
 * @info: structure containing potential args.
 * @vrbl: str env var property
 *  Return: 1 delete, 0 otherwise
 */
int _un_se_te_nv(info_t *info, char *vrbl)
{
list_t *nodey = info->env;
size_t y = 0;
char *d;

if (!nodey || !vrbl)
return (0);

while (nodey)
{
d = strt_wth(nodey->stry, vrbl);
if (d && *d == '=')
{
info->env_changed = indx_del_nod(&(info->env), y);
y = 0;
nodey = info->env;
continue;
}
nodey = nodey->next;
y++;
}
return (info->env_changed);
}


/**
 * my_sete_nv - initialize new env var,
 * or modify an existing one
 * @info: structure containing potential args.
 * @vrbl: str env var property
 * @valy: str env var value
 *  Return: Always 0
 */
int my_sete_nv(info_t *info, char *vrbl, char *valy)
{
char *bff = NULL;
list_t *nodey;
char *d;

if (!vrbl || !valy)
return (0);

bff = malloc(_stry_len(vrbl) + _stry_len(valy) + 2);
if (!bff)
return (1);
_strycpy(bff, vrbl);
_strycat(bff, "=");
_strycat(bff, valy);
nodey = info->env;
while (nodey)
{
d = strt_wth(nodey->stry, vrbl);
if (d && *d == '=')
{
free(nodey->stry);
nodey->stry = bff;
info->env_changed = 1;
return (0);
}
nodey = nodey->next;
}
nodey_ad_end(&(info->env), bff, 0);
free(bff);
info->env_changed = 1;
return (0);
}


/**
 * _env_iron_get - this returns str array copy of our environ
 * @info: structure containing potential args.
 * Return: this info->environ
 */
char **_env_iron_get(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_t_str_s(info->env);
info->env_changed = 0;
}

return (info->environ);
}
