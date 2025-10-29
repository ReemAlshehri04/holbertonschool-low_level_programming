#include "main.h"
/**
	* _strpbrk - searches a string for any of a set of bytes
	* @s: the string to search in
	* @accept: the set of bytes to search for
	*
	* Return: pointer to the first matching byte in s,
	* or NULL if no match is found
	*/
char *_strpbrk(char *s, char *accept)
{
int i, j;
for (i = 0; s[i] != '\0'; i++)
{
for (j = 0; accept[j] != '\0'; j++)
{
if (s[i] == accept[j])
return (s + i);
}
}
return (0);
}
