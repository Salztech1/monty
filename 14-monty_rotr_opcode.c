#include "monty.h"

/**
 * rotr_opcode - Function rotates the bottom value of a
 * stack_t linked list to the top.
 * @stack: input param - A pointer to the top mode node of
 * a stack_t linked list.
 * @line_number: input param - The current working line
 * number of a Monty bytecodes file.
 */
void rotr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *high, *low;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	high = (*stack)->next;
	low = (*stack)->next;
	while (low->next != NULL)
		low = low->next;

	low->prev->next = NULL;
	(*stack)->next = low;
	low->prev = *stack;
	low->next = high;
	high->prev = low;

	(void)line_number;
}
