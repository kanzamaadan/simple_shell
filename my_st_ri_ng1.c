#include "shell.h"

/**
 * _strydup - this duplicates string
 * @stry: string to duplicate
 * Return: pointer to duplicated str
 */
char *_strydup(const char *stry)
{
int lngth = 0;
char *rety;

if (stry == NULL)
return (NULL);
while (*stry++)
lngth++;
rety = malloc(sizeof(char) * (lngth + 1));
if (!rety)
return (NULL);
for (lngth++; lngth--;)
rety[lngth] = *--stry;
return (rety);
}

/**
 * _putchar - func writes the char k to stdout
 * @k: char to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char k)
{
static int y;
static char buf[WRITE_BUF_SIZE];

if (k == BUF_FLUSH || y >= WRITE_BUF_SIZE)
{
write(1, buf, y);
y = 0;
}
if (k != BUF_FLUSH)
buf[y++] = k;
return (1);
}



/**
 *my_pu_ts - this prints input string
 *@stry: string to be printed
 * Return: Nothing
 */
void my_pu_ts(char *stry)
{
int y = 0;

if (!stry)
return;
while (stry[y] != '\0')
{
_putchar(stry[y]);
y++;
}
}


/**
 * _strycpy - this copies string
 * @destny: the destination
 * @sorc: the source
 * Return: pointer to destination
 */
char *_strycpy(char *destny, char *sorc)
{
int y = 0;

if (destny == sorc || sorc == 0)
return (destny);
while (sorc[y])
{
destny[y] = sorc[y];
y++;
}
destny[y] = 0;
return (destny);
}
