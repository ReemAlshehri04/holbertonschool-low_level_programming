#include "lists.h"
/**
	* free_dlistint - frees a dlistint_t list
	* @head: pointer to the head of the list
	*
	* Description: Goes through the list and frees each node.
	*/
void free_dlistint(dlistint_t *head)
{
dlistint_t *temp;
while (head != NULL)
{
temp = head->next; /* save next node */
free(head);        /* free current node */
head = temp;       /* move to next */
}
}
