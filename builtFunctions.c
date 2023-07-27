#include "shell.h"
/**
 * change_directory - changing the directory of a file
 * @argument: argument to change
 * Return: 0
 */

int change_directory(Shell_Info *argument)
{
	char *current_dir, *new_dir, buffer[1024];
	int chdir_reset;

	current_dir = getcwd(buffer, 1024);
	if (!current_dir)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!argument->args[1])
	{
		new_dir = _getenv(argument, "HOME=");
		if (!new_dir)
			chdir_reset = chdir((new_dir = _getenv(argument, "PWD=")) ? new_dir : "/");
		else
			chdir_reset = chdir(new_dir);
	}
	else if (_strcmp(argument->args[1], "-") == 0)
	{
		if (!_getenv(argument, "OLDPWD="))
		{
			_puts(current_dir);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(argument, "OLDPWD=")), _putchar('\n');
		chdir_reset = chdir((new_dir = _getenv(arument, "OLDPWD=")) ? new_dir : "/");
	}
	else
		chdir_reset = chdir(argument->args[1]);
	if (chdir_reset == -1)
	{
		print_error(argument, "can't cd to ");
		_eputs(argument->args[1]), _eputchar('\n');
	}
	else
	{
		_setenv(argument, "OLDPWD", _getenv(argument, "PWD="));
		_setenv(argument, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * change_current_directory - information for shell commands
 * @info: Structure arguments
 * constant function prototype.
 * Return: 0
 */
int change_current_directory(ShellInfo *info)
{
	char **argument_array;

	argument_array = info->args;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*argument_array);
	return (0);
}
/**
 * exit_shell - exits the shell termnal
 * @info: Structure contai argument
 * Return: given value
 */

int exit_shell(Shell_Info *info)
{
	int exit_status;

	if (info->arguments[1])
	{
		exit_status = parse_integer(info->arguments[1]);
		if (exit_status == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->arguments[1]);
			_eputchar('\n');
			return (1);
		}
		info->error_num = parse_integer(info->arguments[1]);
		return (-2);
	}
	info->error_num = -1;
	return (-2);
`}
