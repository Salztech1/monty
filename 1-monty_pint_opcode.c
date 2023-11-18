#include "monty.h"

/**
 * pint_opcode - Function prints the top value of a stack_t linked list.
 * @stack: input param - A pointer to the top mode node
 * of a stack_t linked list.
 * @line_number: input param - The current working line number
 * of a Monty bytecodes file.
 */
void pint_opcode(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(opcode_err_pint(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}
