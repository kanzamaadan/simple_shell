#include "shell.h"

/**
 * _inptget_ - this gets line minus newline
 * @info: the parameter struct
 * Return: bytes read
 */
ssize_t _inptget_(info_t *info)
{
static char *bff;
static size_t y, v, leny;
ssize_t w = 0;
char **buf_p = &(info->arg), *d;

_putchar(BUF_FLUSH);
w = rea_d_bff(info, &bff, &leny);
if (w == -1)
return (-1);
if (leny)
{
v = y;
d = bff + y;

check_chain(info, bff, &v, y, leny);
while (v < leny)
{
if (my_is_cha_in(info, bff, &v))
break;
v++;
}
y = v + 1;
if (y >= leny)
{
y = leny = 0;
info->c_md_buf_type = CMD_NORM;
}
*buf_p = d;
return (_stry_len(d));
}

*buf_p = bff;
return (w);
}

/**
 * _Handler_sig_int - blocks ctrl-C
 * @_numb_sig_: the signal number
 * Return: void
 */
void _Handler_sig_int(__attribute__((unused))int _numb_sig_)
{
my_pu_ts("\n");
my_pu_ts("$ ");
_putchar(BUF_FLUSH);
}


/**
 * _bff_read - this reads buff
 * @info: a parameter struct
 * @bff:the buffer
 * @y:the size
 * Return: w
 */
ssize_t _bff_read(info_t *info, char *bff, size_t *y)
{
ssize_t w = 0;

if (*y)
return (0);
w = read(info->readfd, bff, READ_BUF_SIZE);
if (w >= 0)
*y = w;
return (w);
}

/**
 * rea_d_bff - these buffers chained commands
 * @info: this is parameter struct
 * @bff: this is address of buffer
 * @leny: this is address of len var
 * Return: bytes read
 */
ssize_t rea_d_bff(info_t *info, char **bff, size_t *leny)
{
ssize_t w = 0;
size_t len_p = 0;

if (!*leny)
{
free(*bff);
*bff = NULL;
signal(SIGINT, _Handler_sig_int);
#if USE_GETLINE
w = getline(bff, &len_p, stdin);
#else
w = _li_ne_get(info, bff, &len_p);
#endif
if (w > 0)
{
if ((*bff)[w - 1] == '\n')
{
(*bff)[w - 1] = '\0';
w--;
}
info->cnt_line_flagy = 1;
_comnts_rm(*bff);
bld_lis_his(info, *bff, info->histcount++);
{
*leny = w;
info->c_md_buf = bff;
}
}
}
return (w);
}

/**
 * _li_ne_get - it gets next line of input from STDIN
 * @info: parameter struct
 * @pntr: address of pointer to buff, preallocated or NULL
 * @lenthy: size of preallocated pntr buffer if not NULL
 * Return: z
 */
int _li_ne_get(info_t *info, char **pntr, size_t *lenthy)
{
static char bff[READ_BUF_SIZE];
static size_t y, leny;
size_t t;
ssize_t w = 0, z = 0;
char *d = NULL, *new_d = NULL, *k;

d = *pntr;
if (d && lenthy)
z = *lenthy;
if (y == leny)
y = leny = 0;

w = _bff_read(info, bff, &leny);
if (w == -1 || (w == 0 && leny == 0))
return (-1);

k = _char_stry(bff + y, '\n');
t = k ? 1 + (unsigned int)(k - bff) : leny;
new_d = _re_al_loc(d, z, z ? z + t : t + 1);
if (!new_d)
return (d ? free(d), -1 : -1);

if (z)
con_cat_stry(new_d, bff + y, t - y);
else
cpy_st_r(new_d, bff + y, t - y + 1);

z += t - y;
y = t;
d = new_d;

if (lenthy)
*lenthy = z;
*pntr = d;
return (z);
}
