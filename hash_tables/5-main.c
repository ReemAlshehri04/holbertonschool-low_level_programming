#include "hash_tables.h"

int main(void)
{
	hash_table_t *ht;

	ht = hash_table_create(1024);
	hash_table_set(ht, "betty", "cool");
	hash_table_set(ht, "python", "awesome");
	hash_table_set(ht, "C", "fun");

	hash_table_print(ht);

	return (0);
}

