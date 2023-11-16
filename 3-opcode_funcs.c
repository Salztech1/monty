#include "monty.h"

/**
 * monty_nop - Function does absolutely nothing for the Monty opcode 'nop'.
 * @stack: input param - A pointer to the top mode node
 * of a stack_t linked list.
 * @line_number: input param - The current working line number
 * of a Monty bytecodes file.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pchar - Function prints the character in the top value
 * node of a stack_t linked list.
 * @stack: input param - A pointer to the top mode node of
 * a stack_t linked list.
 * @line_number: input param - The current working line number
 * of a Monty bytecodes file.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_number,
					     "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - Function prints the string contained in a stack_t linked list.
 * @stack: input param - A pointer to the top mode node of a
 * stack_t linked list.
 * @line_number: input param - The current working line number
 * of a Monty bytecodes file.
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
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
