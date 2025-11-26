#ifndef LISTS_H
#define LISTS_H
#include <stdio.h>
#include <stdlib.h>
/**
 * struct list_s - singly linked list
 * @str: string (malloc'ed string)
 * @len: length of the string
 * @next: pointer to the next node
 *
 * Description: Node structure for a singly linked list project
 * used in Holberton/ALX tasks.
 */
typedef struct list_s
{
char *str;
unsigned int len;
struct list_s *next;
} list_t;
/**
 * list_len - returns the number of elements in a linked list_t list
 * @h: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t list_len(const list_t *h);
size_t print_list(const list_t *h);
#endif
