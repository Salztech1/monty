#include "monty.h"

/**
 * nop_opcode - Function does absolutely nothing for the Monty opcode 'nop'.
 * @stack: input param - A pointer to the top mode node of a
 * stack_t linked list.
 * @line_number: input param - The current working line number
 * of a Monty bytecodes file.
 */
void nop_opcode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
