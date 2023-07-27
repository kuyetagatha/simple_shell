#ifndef SHELL_H
#define SHELL_H
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#define CMD_AND 2
#define CMD_CHAIN 3
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2
#define CMD_NORM 0
#define CMD_OR 1
#define BUF_FLUSH -1
extern char **environ;
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE ".simple_shell_project"
#define HIST_MAX 4096
/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - contains pseudo-arguement
 * @arg: getline  arguements
 * @argv:  strings generated
 * @path: path for current command
 * @argc: argument count
 * @line_count: error count
 * @err_num: exit() error code
 * @linecount_flag: count this line input
 * @fname: program filename
 * @env: linked list
 * @environ: modified environment
 * @history: history node
 * @alias: alias node
 * @env_changed: environ changed
 * @status: return status for exec command
 * @cmd_buf: address of pointer
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the filedata from which to read
 * @histcount: line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
}Shell_Info;
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}
/**
 * struct builtin - contains a builtin string
 * @type: command flag
 * @func: function
 */
typedef struct builtin
{
	char *type;
	int (*func)(Shell_Info *);
} builtin_table;
int main(int argc, char **argv);
int freememory(void **pointer);
int change_directory(Shell_Info *argument);
int exit_shell(ShellInfo *info)
int change_current_directory(Shell_Info *info);
int is_interactive_mode(ShellInfo *info);
int is_delimiter(char a, char *delimiter);
int is_alphabetic(int a);
int string_to_integer(char *a);
