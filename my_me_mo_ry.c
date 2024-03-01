#include "shell.h"

/**
 * fre_eb - this frees  pointer and NULLs  address
 * @pntr: address of the pointer to free
 * Return: 1 if freed, otherwise 0.
 */
int fre_eb(void **pntr)
{
if (pntr && *pntr)
{
free(*pntr);
*pntr = NULL;
return (1);
}
return (0);
}
