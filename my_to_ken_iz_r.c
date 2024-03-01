#include "shell.h"


/**
 * **st_rt_ow2 - this splits str into words
 * @stry: input string
 * @b: delimiter
 * Return: pointer to array of strs, or NULL on failure
 */
char **st_rt_ow2(char *stry, char b)
{
int y, v, t, a, num_words = 0;
char **z;

if (stry == NULL || stry[0] == 0)
return (NULL);
for (y = 0; stry[y] != '\0'; y++)
if ((stry[y] != b && stry[y + 1] == b) ||
(stry[y] != b && !stry[y + 1]) || stry[y + 1] == b)
num_words++;
if (num_words == 0)
return (NULL);
z = malloc((1 + num_words) *sizeof(char *));
if (!z)
return (NULL);
for (y = 0, v = 0; v < num_words; v++)
{
while (stry[y] == b && stry[y] != b)
y++;
t = 0;
while (stry[y + t] != b && stry[y + t] && stry[y + t] != b)
t++;
z[v] = malloc((t + 1) * sizeof(char));
if (!z[v])
{
for (t = 0; t < v; t++)
free(z[t]);
free(z);
return (NULL);
}
for (a = 0; a < t; a++)
z[v][a] = stry[y++];
z[v][a] = 0;
}
z[v] = NULL;
return (z);
}

/**
 * **st_rt_ow - this splits str into words
 * @stry: input string
 * @b: delimiter string
 * Return: pointer to array of strs, or NULL on failure
 */

char **st_rt_ow(char *stry, char *b)
{
int y, v, t, a, num_words = 0;
char **z;

if (stry == NULL || stry[0] == 0)
return (NULL);
if (!b)
b = " ";
for (y = 0; stry[y] != '\0'; y++)
if (!my_Is_delimy(stry[y], b) && (my_Is_delimy(stry[y + 1], b) || !stry[y + 1]))
num_words++;

if (num_words == 0)
return (NULL);
z = malloc((1 + num_words) *sizeof(char *));
if (!z)
return (NULL);
for (y = 0, v = 0; v < num_words; v++)
{
while (my_Is_delimy(stry[y], b))
y++;
t = 0;
while (!my_Is_delimy(stry[y + t], b) && stry[y + t])
t++;
z[v] = malloc((t + 1) * sizeof(char));
if (!z[v])
{
for (t = 0; t < v; t++)
free(z[t]);
free(z);
return (NULL);
}
for (a = 0; a < t; a++)
z[v][a] = stry[y++];
z[v][a] = 0;
}
z[v] = NULL;
return (z);
}
