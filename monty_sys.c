#include "monty.h"

/**
 * sys_err_usgae - Function prints usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int sys_err_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * sys_err_malloc - Function prints malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int sys_err_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * sys_err_fopen - Function prints file opening error messages w/ file name.
 * @filename: input param (Name of file failed to open)
 *
 * Return: (EXIT_FAILURE) always.
 */
int sys_err_fopen(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * sys_err_unknownop - Function prints unknown instruction error messages.
 * @opcode: input param (Opcode where error occurred)
 * @line_number: input param - Line number in Monty bytecodes
 * file where error occured)
 *
 * Return: (EXIT_FAILURE) always.
 */
int sys_err_unknownop(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * sys_err_noint - Function prints invalid push_opcode argument error messages.
 * @line_number: input param - Line number in Monty bytecodes
 * file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int sys_err_noint(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
