#include "shell.h"


/**
 * chars_dupp - this duplicates characters
 * @pathestry: PATH string
 * @start: starting indx
 * @stop: stopping indx
 * Return: pointer to new buffer
 */
char *chars_dupp(char *pathestry, int start, int stop)
{
static char bff[1024];
int y = 0, t = 0;

for (t = 0, y = start; y < stop; y++)
if (pathestry[y] != ':')
bff[t++] = pathestry[y];
bff[t] = 0;
return (bff);
}


/**
 * fnd_pathe - this finds this c_md in the PATH string
 * @info: the info struct
 * @pathestry: PATH string
 * @c_md: the c_md to find
 * Return: full path of c_md if found or NULL
 */
char *fnd_pathe(info_t *info, char *pathestry, char *c_md)
{
int y = 0, curr_pos = 0;
char *pathe;

if (!pathestry)
return (NULL);
if ((_stry_len(c_md) > 2) && strt_wth(c_md, "./"))
{
if (it_is_c_md(info, c_md))
return (c_md);
}
while (1)
{
if (!pathestry[y] || pathestry[y] == ':')
{
pathe = chars_dupp(pathestry, curr_pos, y);
if (!*pathe)
_strycat(pathe, c_md);
else
{
_strycat(pathe, "/");
_strycat(pathe, c_md);
}
if (it_is_c_md(info, pathe))
return (pathe);
if (!pathestry[y])
break;
curr_pos = y;
}
y++;
}
return (NULL);
}


/**
 * it_is_c_md - this determines if file is executable command
 * @info: the info struct
 * @pathe: pathe to the file
 * Return: 1 if true, 0 otherwise
 */
int it_is_c_md(info_t *info, char *pathe)
{
struct stat st;

(void)info;
if (!pathe || stat(pathe, &st))
return (0);

if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}
