#include "monty.h"
#include <stdio.h>
#include <string.h>

/**
 * get_op_func - Function matches an opcode with its corresponding function.
 * @opcode: input param (The opcode to match)
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
		{"pint", pint_opcode},
		{"pop", pop_opcode},
		{"swap", swap_opcode},
		{"add", add_opcode},
		{"nop", nop_opcode},
		{"sub", sub_opcode},
		{"div", div_opcode},
		{"mul", mul_opcode},
		{"mod", mod_opcode},
		{"pchar", pchar_opcode},
		{"pstr", pstr_opcode},
		{"rotl", rotl_opcode},
		{"rotr", rotr_opcode},
		{"stack", stack_opcode},
		{"queue", queue_opcode},
		{NULL, NULL}
	};
	int a;

	for (a = 0; op_funcs[a].opcode; a++)
	{
		if (strcmp(opcode, op_funcs[a].opcode) == 0)
			return (op_funcs[a].f);
	}

	return (NULL);
}
