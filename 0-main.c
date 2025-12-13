#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    if (ht == NULL)
    {
        printf("Failed to create hash table\n");
        return (1);
    }
    printf("Hash table created!\n");

    return (EXIT_SUCCESS);
}

