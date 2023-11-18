#include "monty.h"

/**
 * add_opcode - Function adds the top two values of a stack_t linked list.
 * @stack: input param - A pointer to the top mode node of a
 * stack_t linked list.
 * @line_number: input param - The current working line number
 * of a Monty bytecodes file.
 */
void add_opcode(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(opcode_err_shswap(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	pop_opcode(stack, line_number);
}
