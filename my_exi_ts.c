#include "shell.h"


/**
 **con_cat_stry - this concatenates 2 str
 *@destny: the 1st string
 *@sorc: the 2nd string
 *@u: amount of bytes to be maximally used
 *Return: concatenated str
 */
char *con_cat_stry(char *destny, char *sorc, int u)
{
int y, v;
char *z = destny;

y = 0;
v = 0;
while (destny[y] != '\0')
y++;
while (sorc[v] != '\0' && v < u)
{
destny[y] = sorc[v];
y++;
v++;
}
if (v < u)
destny[y] = '\0';
return (z);
}


/**
 **_char_stry - locates char in a str
 *@z: str to be parsed
 *@k: char to look for
 *Return: (z) a pointer to the memory area z
 */
char *_char_stry(char *z, char k)
{
do {
if (*z == k)
return (z);
} while (*z++ != '\0');

return (NULL);
}


/**
 **cpy_st_r - this copies string
 *@destny: destination string to be copied to
 *@sorc: source string
 *@u: the amount of chars to be copied
 *Return: the concatenated string
 */
char *cpy_st_r(char *destny, char *sorc, int u)
{
int y, v;
char *z = destny;

y = 0;
while (sorc[y] != '\0' && y < u - 1)
{
destny[y] = sorc[y];
y++;
}
if (y < u)
{
v = y;
while (v < u)
{
destny[v] = '\0';
v++;
}
}
return (z);
}
