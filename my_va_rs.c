#include "shell.h"


/**
 * check_chain - this checks we should continue
 * chaining based on last status
 * @info:  this parameter struct
 * @bff: this char buffer
 * @d: address of current position in bff
 * @y: starting position in the bff
 * @leny: this length of bff
 * Return: Void
 */
void check_chain(info_t *info, char *bff, size_t *d, size_t y, size_t leny)
{
size_t v = *d;

if (info->c_md_buf_type == CMD_AND)
{
if (info->status)
{
bff[y] = 0;
v = leny;
}
}
if (info->c_md_buf_type == CMD_OR)
{
if (!info->status)
{
bff[y] = 0;
v = leny;
}
}

*d = v;
}


/**
 * rplc_str - this replaces str
 * @oldy: an address of the old str
 * @nw: new string
 * Return: 1 if replaced, 0 otherwise
 */
int rplc_str(char **oldy, char *nw)
{
free(*oldy);
*oldy = nw;
return (1);
}



/**
 * rplc_alis - this replaces aliases in tokenized str
 * @info: this is parameter struct
 * Return: 1 if replaced, 0 otherwise
 */
int rplc_alis(info_t *info)
{
int y;
list_t *nodey;
char *d;

for (y = 0; y < 10; y++)
{
nodey = nodey_strts_wth(info->alias, info->argv[0], '=');
if (!nodey)
return (0);
free(info->argv[0]);
d = _char_stry(nodey->stry, '=');
if (!d)
return (0);
d = _strydup(d + 1);
if (!d)
return (0);
info->argv[0] = d;
}
return (1);
}

/**
 * my_is_cha_in - this test if current char in bff is  chain delim
 * @info: parameter struct
 * @bff: char buffer
 * @d: address of current position in bff
 * Return: 1 if chain delimeter, 0 otherwise
 */
int my_is_cha_in(info_t *info, char *bff, size_t *d)
{
size_t v = *d;

if (bff[v] == '|' && bff[v + 1] == '|')
{
bff[v] = 0;
v++;
info->c_md_buf_type = CMD_OR;
}
else if (bff[v] == '&' && bff[v + 1] == '&')
{
bff[v] = 0;
v++;
info->c_md_buf_type = CMD_AND;
}
else if (bff[v] == ';')
{
bff[v] = 0;
info->c_md_buf_type = CMD_CHAIN;
}
else
return (0);
*d = v;
return (1);
}



/**
 * rplc_va_rs - this replaces vars in  tokenized str
 * @info: this parameter struct
 * Return: 1 if replaced, 0 otherwise
 */
int rplc_va_rs(info_t *info)
{
int y = 0;
list_t *nodey;

for (y = 0; info->argv[y]; y++)
{
if (info->argv[y][0] != '$' || !info->argv[y][1])
continue;

if (!_stry_cmp(info->argv[y], "$?"))
{
rplc_str(&(info->argv[y]),
_strydup(_num_conv(info->status, 10, 0)));
continue;
}
if (!_stry_cmp(info->argv[y], "$$"))
{
rplc_str(&(info->argv[y]),
_strydup(_num_conv(getpid(), 10, 0)));
continue;
}
nodey = nodey_strts_wth(info->env, &info->argv[y][1], '=');
if (nodey)
{
rplc_str(&(info->argv[y]),
_strydup(_char_stry(nodey->stry, '=') + 1));
continue;
}
rplc_str(&info->argv[y], _strydup(""));

}
return (0);
}
