#include "monty.h"

/**
 * rotl_opcode - Function rotates the top value of a
 * stack_t linked list to the bottom.
 * @stack: input param - A pointer to the top mode node of
 * a stack_t linked list.
 * @line_number: input param - The current working line number
 * of a Monty bytecodes file.
 */
void rotl_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *high, *low;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	high = (*stack)->next;
	low = (*stack)->next;
	while (low->next != NULL)
		low = low->next;

	high->next->prev = *stack;
	(*stack)->next = high->next;
	low->next = high;
	high->next = NULL;
	high->prev = low;

	(void)line_number;
}
