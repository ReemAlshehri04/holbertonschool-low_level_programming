#include "hash_tables.h"
/**
	* hash_table_set - Adds or updates an element in the hash table
	* @ht: Hash table
	* @key: Key (cannot be an empty string)
	* @value: Value associated with the key
	*
	* Return: 1 on success, 0 on failure
	*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
hash_node_t *node, *current;
char *value_copy, *key_copy;
if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
return (0);
index = key_index((const unsigned char *)key, ht->size);
current = ht->array[index];
while (current != NULL)
{
if (strcmp(current->key, key) == 0)
{
value_copy = strdup(value);
if (value_copy == NULL)
return (0);
free(current->value);
current->value = value_copy;
return (1);
}
current = current->next;
}
node = malloc(sizeof(hash_node_t));
if (node == NULL)
return (0);
key_copy = strdup(key);
value_copy = strdup(value);
if (key_copy == NULL || value_copy == NULL)
{
free(node);
free(key_copy);
free(value_copy);
return (0);
}
node->key = key_copy;
node->value = value_copy;
node->next = ht->array[index];
ht->array[index] = node;
return (1);
}
