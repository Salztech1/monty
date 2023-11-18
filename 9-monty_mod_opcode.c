#include "monty.h"

/**
 * mod_opcode - Function computes the modulus of the second
 * value from the top of a stack_t linked list  by the top
 * @stack: input param - A pointer to the top mode node of
 * a stack_t linked list.
 * @line_number: input param - The current working line number
 * of a Monty bytecodes file
 */
void mod_opcode(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(opcode_err_shswap(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(opcode_err_div(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	pop_opcode(stack, line_number);
}
