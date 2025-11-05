#include <stdlib.h>
#include "dog.h"
/**
	* _strlen - returns the length of a string
	* @s: string
	* Return: length of string
	*/
int _strlen(char *s)
{
int i;
for (i = 0; s[i] != '\0'; i++)
;
return (i);
}
/**
	* _strcpy - copies a string
	* @dest: destination
	* @src: source
	* Return: pointer to dest
	*/
char *_strcpy(char *dest, char *src)
{
int i;
for (i = 0; src[i] != '\0'; i++)
dest[i] = src[i];
dest[i] = '\0';
return (dest);
}
/**
	* new_dog - creates a new dog
	* @name: dog's name
	* @age: dog's age
	* @owner: dog's owner
	* Return: pointer to new dog, or NULL if fails
	*/
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *dog;
int len_name, len_owner;
if (name == NULL || owner == NULL)
return (NULL);
dog = malloc(sizeof(dog_t));
if (dog == NULL)
return (NULL);
len_name = _strlen(name);
len_owner = _strlen(owner);
dog->name = malloc(sizeof(char) * (len_name + 1));
if (dog->name == NULL)
{
free(dog);
return (NULL);
}
dog->owner = malloc(sizeof(char) * (len_owner + 1));
if (dog->owner == NULL)
{
free(dog->name);
free(dog);
return (NULL);
}
_strcpy(dog->name, name);
_strcpy(dog->owner, owner);
dog->age = age;
return (dog);
}
