#include "monty.h"

/**
 * swap_opcode - Function that waps the top two value
 * elements of a stack_t linked list.
 * @stack: input param - A pointer to the top mode node
 * of a stack_t linked list
 * @line_number: input param - The current working line
 * number of a Monty bytecodes file
 */
void swap_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *mp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(opcode_err_shswap(line_number, "swap"));
		return;
	}

	mp = (*stack)->next->next;
	(*stack)->next->next = mp->next;
	(*stack)->next->prev = mp;
	if (mp->next)
		mp->next->prev = (*stack)->next;
	mp->next = (*stack)->next;
	mp->prev = *stack;
	(*stack)->next = mp;
}
