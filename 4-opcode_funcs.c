#include "monty.h"

/**
 * monty_rotl - Function rotates the top value of a
 * stack_t linked list to the bottom.
 * @stack: input param - A pointer to the top mode node of a
 * stack_t linked list.
 * @line_number: input param - The current working line number
 * of a Monty bytecodes file.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
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

/**
 * monty_rotr - Function rotates the bottom value of a
 * stack_t linked list to the top.
 * @stack: input param - A pointer to the top mode node of
 * a stack_t linked list.
 * @line_number: input param - The current working line number
 * of a Monty bytecodes file.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
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

/**
 * monty_stack - Function converts a queue to a stack.
 * @stack: input param - A pointer to the top mode node of
 * a stack_t linked list.
 * @line_number: input param - The current working line number
 * of a Monty bytecodes file.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - Function converts a stack to a queue.
 * @stack: input param - A pointer to the top mode node of
 * a stack_t linked list.
 * @line_number: input param - The current working line number
 * of a Monty bytecodes file.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
