#include "shell.h"



/**
 * _My_Set_Env - this nitialize new envir var,
 *or modify existing one
 * @info: structure containing potential args.
 *  Return: Always 0
 */
int _My_Set_Env(info_t *info)
{
if (info->argc != 3)
{
my_ep_uts("Incorrect number of arguements\n");
return (1);
}
if (my_sete_nv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}


/**
 * _My_Env - this prints current envir
 * @info: structure containing potential argts.
 * Return: Always 0
 */
int _My_Env(info_t *info)
{
pr_1st_stry(info->env);
return (0);
}

/**
 * _My_Un_Se_Tenv - remove env var
 * @info: structure containing potential args.
 *  Return: Always 0
 */
int _My_Un_Se_Tenv(info_t *info)
{
int y;

if (info->argc == 1)
{
my_ep_uts("Too few arguements.\n");
return (1);
}
for (y = 1; y <= info->argc; y++)
_un_se_te_nv(info, info->argv[y]);

return (0);
}


/**
 * Pop_Env_Li_St - this populates env linked list
 * @info: structure containing potential args.
 * Return: Always 0
 */
int Pop_Env_Li_St(info_t *info)
{
list_t *nodey = NULL;
size_t y;

for (y = 0; environ[y]; y++)
nodey_ad_end(&nodey, environ[y], 0);
info->env = nodey;
return (0);
}

/**
 * _Get_Env - this gets value of environ var
 * @info: structure containing potential args.
 * @nom: env var nom
 * Return: the value
 */
char *_Get_Env(info_t *info, const char *nom)
{
list_t *nodey = info->env;
char *d;

while (nodey)
{
d = strt_wth(nodey->stry, nom);
if (d && *d)
return (d);
nodey = nodey->next;
}
return (NULL);
}
