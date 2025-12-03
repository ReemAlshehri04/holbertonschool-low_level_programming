#include "lists.h"
/**
	* insert_dnodeint_at_index - inserts a new node at a given index
	* @h: pointer to pointer to head of list
	* @idx: index where new node should be inserted, starting from 0
	* @n: value for new node
	*
	* Return: address of new node, or NULL if failed
	*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new_node, *temp;
unsigned int i = 0;
if (h == NULL)
return (NULL);
/* Insert at index 0 (beginning) */
if (idx == 0)
return (add_dnodeint(h, n));
temp = *h;
while (temp != NULL)
{
if (i == idx - 1)
{
/* If inserting at end */
if (temp->next == NULL)
return (add_dnodeint_end(h, n));
/* Insert in the middle */
new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);
new_node->n = n;
new_node->prev = temp;
new_node->next = temp->next;
temp->next->prev = new_node;
temp->next = new_node;
return (new_node);
}
temp = temp->next;
i++;
}
/* Index out of range */
return (NULL);
}
