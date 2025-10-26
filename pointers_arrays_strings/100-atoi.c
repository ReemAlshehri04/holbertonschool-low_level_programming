#include "main.h"
/**
	* _atoi - converts a string to an integer
	* @s: the string to convert
	*
	* Return: the integer value of the string
	*/
int _atoi(char *s)
{
int i = 0;
int sign = 1;
int result = 0;
int found_num = 0;
while (s[i] != '\0')
{
if (s[i] == '-')
sign *= -1;
if (s[i] >= '0' && s[i] <= '9')
{
found_num = 1;
result = result * 10 + (s[i] - '0') * sign;
/* once number starts, handle next chars carefully */
if (s[i + 1] < '0' || s[i + 1] > '9')
break;
}
else if (found_num)
break;
i++;
}
return (result);
}

