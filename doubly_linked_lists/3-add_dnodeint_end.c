#include "lists.h"
/**
	* add_dnodeint_end - adds a new node at the end of a dlistint_t list
	* @head: pointer to a pointer to the head of the list
	* @n: value to store in the new node
	*
	* Return: address of the new node, or NULL if it failed
	*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *new_node, *temp;
if (head == NULL)
return (NULL);
/* Allocate memory for new node */
new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);
new_node->n = n;
new_node->next = NULL;
/* If list is empty, new node becomes the head */
if (*head == NULL)
{
new_node->prev = NULL;
*head = new_node;
return (new_node);
}
/* Traverse to last node */
temp = *head;
while (temp->next != NULL)
temp = temp->next;
/* Link new node at the end */
temp->next = new_node;
new_node->prev = temp;
return (new_node);
}
