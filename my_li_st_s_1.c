#include "shell.h"



/**
 * list_t_str_s - this returns array of strings of list->stry
 * @the_head: pointer to 1st node
 * Return: array of strings
 */
char **list_t_str_s(list_t *the_head)
{
list_t *nodey = the_head;
size_t y = ls_len(the_head), v;
char **stryz;
char *stry;

if (!the_head || !y)
return (NULL);
stryz = malloc(sizeof(char *) * (y + 1));
if (!stryz)
return (NULL);
for (y = 0; nodey; nodey = nodey->next, y++)
{
stry = malloc(_stry_len(nodey->stry) + 1);
if (!stry)
{
for (v = 0; v < y; v++)
free(stryz[v]);
free(stryz);
return (NULL);
}

stry = _strycpy(stry, nodey->stry);
stryz[y] = stry;
}
stryz[y] = NULL;
return (stryz);
}


/**
 * get_nodey_indx - this gets indx of a node
 * @the_head: this pointer to list the_head
 * @nodey: pointer to the node
 * Return: indx of nodey or -1
 */
ssize_t get_nodey_indx(list_t *the_head, list_t *nodey)
{
size_t y = 0;

while (the_head)
{
if (the_head == nodey)
return (y);
the_head = the_head->next;
y++;
}
return (-1);
}



/**
 * list_prnt - this prints all elements of list_t linked list
 * @f: pointer to 1st node
 * Return: size of list
 */
size_t list_prnt(const list_t *f)
{
size_t y = 0;

while (f)
{
my_pu_ts(_num_conv(f->num, 10, 0));
_putchar(':');
_putchar(' ');
my_pu_ts(f->stry ? f->stry : "(nil)");
my_pu_ts("\n");
f = f->next;
y++;
}
return (y);
}

/**
 * ls_len - this determines length of linked_list
 * @f: pointer to 1st node
 * Return: size of list
 */
size_t ls_len(const list_t *f)
{
size_t y = 0;

while (f)
{
f = f->next;
y++;
}
return (y);
}


/**
 * nodey_strts_wth - this returns node string starts with pr_fx
 * @nodey: the pointer to list the_head
 * @pr_fx: string to match
 * @k: next char after pr_fx to match
 * Return: match nodey or null
 */
list_t *nodey_strts_wth(list_t *nodey, char *pr_fx, char k)
{
char *d = NULL;

while (nodey)
{
d = strt_wth(nodey->stry, pr_fx);
if (d && ((k == -1) || (*d == k)))
return (nodey);
nodey = nodey->next;
}
return (NULL);
}
