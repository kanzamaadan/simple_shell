#include "shell.h"

/**
 * lst_free - this frees all nodes of a list
 * @the_head_pntr: address of pointer to the_head node
 * Return: void
 */
void lst_free(list_t **the_head_pntr)
{
list_t *nodey, *next_nodey, *the_head;

if (!the_head_pntr || !*the_head_pntr)
return;
the_head = *the_head_pntr;
nodey = the_head;
while (nodey)
{
next_nodey = nodey->next;
free(nodey->stry);
free(nodey);
nodey = next_nodey;
}
*the_head_pntr = NULL;
}

/**
 * nodey_ad_end - this adds a node to the end of the list
 * @the_head: address of pointer to the_head node
 * @stry: str field of node
 * @num: node indx used by history
 * Return: list's size
 */
list_t *nodey_ad_end(list_t **the_head, const char *stry, int num)
{
list_t *nod_nw, *nodey;

if (!the_head)
return (NULL);

nodey = *the_head;
nod_nw = malloc(sizeof(list_t));
if (!nod_nw)
return (NULL);
_me_m_set((void *)nod_nw, 0, sizeof(list_t));
nod_nw->num = num;
if (stry)
{
nod_nw->stry = _strydup(stry);
if (!nod_nw->stry)
{
free(nod_nw);
return (NULL);
}
}
if (nodey)
{
while (nodey->next)
nodey = nodey->next;
nodey->next = nod_nw;
}
else
*the_head = nod_nw;
return (nod_nw);
}

/**
 * pr_1st_stry - this prints only str element of list_t linked list
 * @f: pointer to 1st node
 * Return:list's size
 */
size_t pr_1st_stry(const list_t *f)
{
size_t y = 0;

while (f)
{
my_ep_uts(f->stry ? f->stry : "(nil)");
my_ep_uts("\n");
f = f->next;
y++;
}
return (y);
}

/**
 * nodey_ad - this adds node to start of list
 * @the_head: this is address of pointer to the_head node
 * @stry:the str field of node
 * @num: and node indx used by history
 * Return: size of list
 */
list_t *nodey_ad(list_t **the_head, const char *stry, int num)
{
list_t *nw_hd;

if (!the_head)
return (NULL);
nw_hd = malloc(sizeof(list_t));
if (!nw_hd)
return (NULL);
_me_m_set((void *)nw_hd, 0, sizeof(list_t));
nw_hd->num = num;
if (stry)
{
nw_hd->stry = _strydup(stry);
if (!nw_hd->stry)
{
free(nw_hd);
return (NULL);
}
}
nw_hd->next = *the_head;
*the_head = nw_hd;
return (nw_hd);
}


/**
 * indx_del_nod - this deletes node at given indx
 * @the_head: this address of pointer to 1st node
 * @indx: indx of node to delete
 * Return: 1 on success, 0 on failure
 */
int indx_del_nod(list_t **the_head, unsigned int indx)
{
list_t *nodey, *nod_prv;
unsigned int y = 0;

if (!the_head || !*the_head)
return (0);

if (!indx)
{
nodey = *the_head;
*the_head = (*the_head)->next;
free(nodey->stry);
free(nodey);
return (1);
}
nodey = *the_head;
while (nodey)
{
if (y == indx)
{
nod_prv->next = nodey->next;
free(nodey->stry);
free(nodey);
return (1);
}
y++;
nod_prv = nodey;
nodey = nodey->next;
}
return (0);
}
