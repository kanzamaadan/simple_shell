#include "shell.h"


/**
 *_Fd_Pu_Ts - this prints input str
 * @stry: str to be printed
 * @fld: filedescriptor
 * Return: num of chars put
 */
int _Fd_Pu_Ts(char *stry, int fld)
{
int y = 0;

if (!stry)
return (0);
while (*stry)
{
y += _Fdmy_ep_uts(*stry++, fld);
}
return (y);
}

/**
 * _E_Put_Charc - writes the char k to stderr
 * @k: charak to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _E_Put_Charc(char k)
{
static int y;
static char bff[WRITE_BUF_SIZE];

if (k == BUF_FLUSH || y >= WRITE_BUF_SIZE)
{
write(2, bff, y);
y = 0;
}
if (k != BUF_FLUSH)
bff[y++] = k;
return (1);
}


/**
 * my_ep_uts - this prints input str
 * @stry: str to be printed
 * Return: void
 */
void my_ep_uts(char *stry)
{
int y = 0;

if (!stry)
return;
while (stry[y] != '\0')
{
_E_Put_Charc(stry[y]);
y++;
}
}


/**
 * _Fdmy_ep_uts - this writes the char k to given fld
 * @k: character to print
 * @fld: The filedescriptor
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _Fdmy_ep_uts(char k, int fld)
{
static int y;
static char bff[WRITE_BUF_SIZE];

if (k == BUF_FLUSH || y >= WRITE_BUF_SIZE)
{
write(fld, bff, y);
y = 0;
}
if (k != BUF_FLUSH)
bff[y++] = k;
return (1);
}
