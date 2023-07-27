#include "shell.h"
/**
 * is_alphabetic - checks if the character is alphabet
 * @a: The character to check for
 * Return: 1, 0
 */
int is_alphabetic(int a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * is_interactive_mode - check an interactive mode
 * @info: struct containing shell information
 * Return: 1
 */
int is_interactive_mode(ShellInfo *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * string_to_integer - conversion of string to integer
 * @a: converted strings
 * Return: 0
 */
int string_to_integer(char *a)
{
	int j, signal = 1, flag = 0, output;
	unsigned int result = 0;

	for (j = 0; a[j] != '\0' && flag != 2; j++)
	{
		if (a[j] == '-')
			signal *= -1;
		if (a[j] >= '0' && a[j] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (a[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (signal == -1)
		output = -result;
	else
		output = result;
	return (output);
}
/**
 * is_delimiter - checks if string/value is a delimiter
 * @a: character to check for
 * @delimiter: the string text
 * Return: 1
 */
int is_delimiter(char a, char *delimiter)
{
	while (*delimiter)
		if (*delimiter++ == a)
			return (1);
	return (0);
}
