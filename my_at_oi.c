#include "shell.h"


/**
 *My_Atoi - this convert str to int
 *@z:str to be converted
 *Return: 0 while no numbers in string, converted number otherwise
 */

int My_Atoi(char *z)
{
int y, signy = 1, flagy = 0, outpt;
unsigned int rslt = 0;

for (y = 0;  z[y] != '\0' && flagy != 2; y++)
{
if (z[y] == '-')
signy *= -1;

if (z[y] >= '0' && z[y] <= '9')
{
flagy = 1;
rslt *= 10;
rslt += (z[y] - '0');
}
else if (flagy == 1)
flagy = 2;
}

if (signy == -1)
outpt = -rslt;
else
outpt = rslt;

return (outpt);
}

/**
 * My_Interactive - Indicates whether the shell is in My_Interactive mode
 * @info: pointer to a structure containing information
 * Return: 1 if My_Interactive mode 0 otherwise
 */
int My_Interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


/**
 *My_Isalpha - this checks for alphabetic char
 *@k: character to the input
 *Return: 1 if k is alphabetic, 0 otherwise
 */

int My_Isalpha(int k)
{
if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z'))
return (1);
else
return (0);
}

/**
 * my_Is_delimy - this checks if chars delimeter
 * @k: the char to check
 * @delimy: the delimyeter string
 * Return: 1 true, 0 false
 */
int my_Is_delimy(char k, char *delimy)
{
while (*delimy)
if (*delimy++ == k)
return (1);
return (0);
}
