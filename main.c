#include "shell.h"
/**
 * main - the main page of the project
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 || 1
 */
int main(int argc, char **argv)
{
	info_t info[] = {INFO_INIT};
	int fade = 2;

	asm("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fade)
			: "r" (fade));
	if (argc == 2)
	{
		fade = open(argv[1], O_RDONLY);
		if (fade == -1)
		{
			if (errno == EACCES)
			{
				exit(126);
			}
			else if (errno == ENOENT)
			{
				_eputs(argv[0]);
				_eputs(": 0: Can't open ");
				_eputs(argv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fade;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, argv);
	return (EXIT_SUCCESS);
}

/**
 * freememory - free memory of a pointer
 * @pointer: pointer address
 * Return: 1 || 0
 */
int freememory(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}
