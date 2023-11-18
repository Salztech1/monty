#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_toks = NULL;

/**
 * main - Function to the entry point for Monty Interpreter function
 * @argc: input param (the count of arguments passed to the program)
 * @argv: input param (pointer to an array of char pointers to arguments)
 *
 * Return: (EXIT_SUCCESS) on success and (EXIT_FAILURE) on error
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (sys_err_usage());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (sys_err_fopen(argv[1]));
	fclose(script_fd);
	return (exit_code);
}
