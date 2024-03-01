#include "shell.h"


/**
 * _stry_cmp - this performs lexicogarphic comparison of 2 strs.
 * @s_1: the 1st stryang
 * @s_2: the 2nd stryang
 * Return: negative if s_1 < s_2,
 * positive if s_1 > s_2, zero if s_1 == s_2
 */
int _stry_cmp(char *s_1, char *s_2)
{
while (*s_1 && *s_2)
{
if (*s_1 != *s_2)
return (*s_1 - *s_2);
s_1++;
s_2++;
}
if (*s_1 == *s_2)
return (0);
else
return (*s_1 < *s_2 ? -1 : 1);
}


/**
 * _strycat - this concatenates 2 strings
 * @destny: destination buffer
 * @sorc: source buffer
 * Return: pointer to destination buffer
 */
char *_strycat(char *destny, char *sorc)
{
char *rety = destny;

while (*destny)
destny++;
while (*sorc)
*destny++ = *sorc++;
*destny = *sorc;
return (rety);
}

/**
 * strt_wth - this checks if n_ee_dle starts with stck_hay
 * @stck_hay: string to search
 * @n_ee_dle: substring to find
 * Return: address of next char of stck_hay or NULL
 */
char *strt_wth(const char *stck_hay, const char *n_ee_dle)
{
while (*n_ee_dle)
if (*n_ee_dle++ != *stck_hay++)
return (NULL);
return ((char *)stck_hay);
}

/**
 * _stry_len - this returns length of string
 * @z: string whose length to check
 * Return: int length of string
 */
int _stry_len(char *z)
{
int y = 0;

if (!z)
return (0);

while (*z++)
y++;
return (y);
}
