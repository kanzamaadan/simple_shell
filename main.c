#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @a_v: arg vector
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **a_v)
{
info_t info[] = { INFO_INIT };
int fld = 2;

asm ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (fld)
: "r" (fld));

if (ac == 2)
{
fld = open(a_v[1], O_RDONLY);
if (fld == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
my_ep_uts(a_v[0]);
my_ep_uts(": 0: Can't open ");
my_ep_uts(a_v[1]);
_E_Put_Charc('\n');
_E_Put_Charc(BUF_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
info->readfd = fld;
}
Pop_Env_Li_St(info);
hist_rd(info);
my_h_sh(info, a_v);
return (EXIT_SUCCESS);
}
