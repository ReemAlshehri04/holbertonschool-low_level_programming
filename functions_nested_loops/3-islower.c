#include "main.h"
/**
* _islower - Checks for a lowercase character.
* @c: The character to check (represented as an int).
*
* Return: 1 if c is a lowercase character (a-z), 0 otherwise.
*/
int _islower(int c)
{
/* Check if the character's ASCII value is within the range of 'a' to 'z' */
if (c >= 'a' && c <= 'z')
{
return (1);
}
else
{
return (0);
}
}
