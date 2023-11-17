#include "monty.h"

/**
 * pop_error - Function prints pop error messages for empty stacks.
 * @line_number: input param - Line number in script where
 * error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - Function prints pint error messages for empty stacks.
 * @line_number: input param - Line number in Monty bytecodes
 * file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - Function prints monty math function
 * error messages for stacks/queues smaller than two nodes.
 * @line_number: input param - Line number in Monty bytecodes
 * file where error occurred.
 * @op: input param (Operation where the error occurred)
 *
 * Return: (EXIT_FAILURE) always.
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - Function prints division error messages for division by 0.
 * @line_number: input param - Line number in Monty bytecodes
 * file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - Function prints pchar error messages for empty
 * stacks empty stacks and non-character values.
 * @line_number: input param - Line number in Monty bytecodes
 * file where error occurred.
 * @message: input param (The corresponding error message to print)
 *
 * Return: (EXIT_FAILURE) always.
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
