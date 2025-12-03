#include "lists.h"
/**
	* delete_dnodeint_at_index - deletes the node at a given index
	* @head: pointer to pointer to the head of the list
	* @index: index of the node to delete (starting at 0)
	*
	* Return: 1 if successful, -1 if failure
	*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *temp;
unsigned int i = 0;
if (head == NULL || *head == NULL)
return (-1);
temp = *head;
/* Case 1: delete the head node */
if (index == 0)
{
*head = temp->next;
if (temp->next != NULL)
temp->next->prev = NULL;
free(temp);
return (1);
}
/* Move to the node at position index */
while (temp != NULL && i < index)
{
temp = temp->next;
i++;
}
/* Index out of range */
if (temp == NULL)
return (-1);
/* Re-link previous and next nodes */
if (temp->prev != NULL)
temp->prev->next = temp->next;
if (temp->next != NULL)
temp->next->prev = temp->prev;
free(temp);
return (1);
}
