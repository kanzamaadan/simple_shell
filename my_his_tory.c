#include "shell.h"


/**
 * hist_wrt - this creates file, or appends to existing file
 * @info: parameter struct
 * Return: 1 on success, else -1
 */
int hist_wrt(info_t *info)
{
ssize_t fld;
char *filenom = fil_get_his(info);
list_t *nodey = NULL;

if (!filenom)
return (-1);

fld = open(filenom, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filenom);
if (fld == -1)
return (-1);
for (nodey = info->history; nodey; nodey = nodey->next)
{
_Fd_Pu_Ts(nodey->stry, fld);
_Fdmy_ep_uts('\n', fld);
}
_Fdmy_ep_uts(BUF_FLUSH, fld);
close(fld);
return (1);
}



/**
 * his_rmb - this renumbers his linked list after changes
 * @info: structure containing potential args.
 * Return: new histcount
 */
int his_rmb(info_t *info)
{
list_t *nodey = info->history;
int y = 0;

while (nodey)
{
nodey->num = y++;
nodey = nodey->next;
}
return (info->histcount = y);
}


/**
 * hist_rd - this reads history from file
 * @info: a parameter struct
 * Return: histcount on success, 0 otherwise
 */
int hist_rd(info_t *info)
{
int y, la_stly = 0, cnt_line = 0;
ssize_t fld, lin_rd, sz_f = 0;
struct stat st;
char *bff = NULL, *filenom = fil_get_his(info);

if (!filenom)
return (0);

fld = open(filenom, O_RDONLY);
free(filenom);
if (fld == -1)
return (0);
if (!fstat(fld, &st))
sz_f = st.st_size;
if (sz_f < 2)
return (0);
bff = malloc(sizeof(char) * (sz_f + 1));
if (!bff)
return (0);
lin_rd = read(fld, bff, sz_f);
bff[sz_f] = 0;
if (lin_rd <= 0)
return (free(bff), 0);
close(fld);
for (y = 0; y < sz_f; y++)
if (bff[y] == '\n')
{
bff[y] = 0;
bld_lis_his(info, bff + la_stly, cnt_line++);
la_stly = y + 1;
}
if (la_stly != y)
bld_lis_his(info, bff + la_stly, cnt_line++);
free(bff);
info->histcount = cnt_line;
while (info->histcount-- >= HIST_MAX)
indx_del_nod(&(info->history), 0);
his_rmb(info);
return (info->histcount);
}

/**
 * fil_get_his -this gets history of file
 * @info: parameter struct
 * Return: allocated str containg history file
 */

char *fil_get_his(info_t *info)
{
char *bff, *diry;

diry = _Get_Env(info, "HOME=");
if (!diry)
return (NULL);
bff = malloc(sizeof(char) * (_stry_len(diry) + _stry_len(HIST_FILE) + 2));
if (!bff)
return (NULL);
bff[0] = 0;
_strycpy(bff, diry);
_strycat(bff, "/");
_strycat(bff, HIST_FILE);
return (bff);
}



/**
 * bld_lis_his - this adds entry to hist linked list
 * @info: structure containing potential args.
 * @bff: a buffer
 * @cnt_line: history cnt_line, histcount
 * Return: Always 0
 */
int bld_lis_his(info_t *info, char *bff, int cnt_line)
{
list_t *nodey = NULL;

if (info->history)
nodey = info->history;
nodey_ad_end(&nodey, bff, cnt_line);

if (!info->history)
info->history = nodey;
return (0);
}
