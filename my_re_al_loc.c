#include "shell.h"



/**
 * fre_ef - this frees a string of strings
 * @dd: string of strings
 */
void fre_ef(char **dd)
{
char **e = dd;

if (!dd)
return;
while (*dd)
free(*dd++);
free(e);
}


/**
 * _re_al_loc - this reallocates block of memory
 * @pntr: pointer to previous malloc'ated block
 * @old_siz: this byte size of previous block
 * @nw_size: this byte size of new block
 * Return: pointer to da ol'block nomen.
 */
void *_re_al_loc(void *pntr, unsigned int old_siz, unsigned int nw_size)
{
char *d;

if (!pntr)
return (malloc(nw_size));
if (!nw_size)
return (free(pntr), NULL);
if (nw_size == old_siz)
return (pntr);

d = malloc(nw_size);
if (!d)
return (NULL);

old_siz = old_siz < nw_size ? old_siz : nw_size;
while (old_siz--)
d[old_siz] = ((char *)pntr)[old_siz];
free(pntr);
return (d);
}

/**
 **_me_m_set - this fills memory with a constant byte
 *@z: pointer to memory area
 *@o: byte to fill *z with
 *@u: amount of bytes to be filled
 *Return: (z) a pointer to the memory area z
 */
char *_me_m_set(char *z, char o, unsigned int u)
{
unsigned int y;

for (y = 0; y < u; y++)
z[y] = o;
return (z);
}
