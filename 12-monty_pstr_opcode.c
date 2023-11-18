#include "monty.h"

/**
 * pstr_opcode - Function prints the string contained in a stack_t linked list.
 * @stack: input param - A pointer to the top mode node of a
 * stack_t linked list.
 * @line_number: input param - The current working line number
 * of a Monty bytecodes file.
 */
void pstr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *mp = (*stack)->next;

	while (mp && mp->n != 0 && (mp->n > 0 && mp->n <= 127))
	{
		printf("%c", mp->n);
		mp = mp->next;
	}

	printf("\n");

	(void)line_number;
}
