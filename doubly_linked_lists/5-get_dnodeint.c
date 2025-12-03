#include "lists.h"
/**
	* get_dnodeint_at_index - returns the node at a given idex
	* @head: pointer to the head of the list
	* @index: the index of the desired node (starting from 0)
	* Return: pointer to the node at the given index
	*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
unsigned int i = 0;
while (head != NULL)
{
if (i == index)
return (head);
head = head->next;
i++;
}
return (NULL); /* index out of range */
}
