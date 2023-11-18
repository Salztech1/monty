#include "monty.h"
#include <string.h>

/**
 * free_stack - Function frees a stack_t stack.
 * @stack: input param - A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *mp = *stack;

	while (*stack)
	{
		mp = (*stack)->next;
		free(*stack);
		*stack = mp;
	}
}

/**
 * init_stack - Function initializes a stack_t stack with
 * beginning stack and ending queue nodes.
 * @stack: input param(A pointer to an unitialized stack_t stack)
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
	stack_t *k;

	k = malloc(sizeof(stack_t));
	if (k == NULL)
		return (sys_err_malloc());

	k->n = STACK;
	k->prev = NULL;
	k->next = NULL;

	*stack = k;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Function check if a stack_t linked list is
 * in stack or queue mode.
 * @stack: input param - A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
