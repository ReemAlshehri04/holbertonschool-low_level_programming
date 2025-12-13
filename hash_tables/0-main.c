#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"

int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    if (ht == NULL)
    {
        printf("Failed to create hash table\n");
        return (1);
    }

    printf("Hash table created\n");
    return (0);
}

