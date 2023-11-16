#include "monty.h"

/**
 * monty_push - Function that pushes a value to a stack_t linked list.
 * @stack: input param - A pointer to the top mode node
 * of a stack_t linked list
 * @line_number: input param - The current working line
 * number of a Monty bytecodes file
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *mp, *new1;
	int a;

	new1 = malloc(sizeof(stack_t));
	if (new1 == NULL)
		set_op_tok_error(malloc_error());
		return;

	if (op_toks[1] == NULL)
		set_op_tok_error(no_int_error(line_number));
		return;

	for (a = 0; op_toks[1][a]; a++)
		if (op_toks[1][a] == '-' && a == 0)
			continue;
		if (op_toks[1][a] < '0' || op_toks[1][a] > '9')
			set_op_tok_error(no_int_error(line_number));
			return;
	new1->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK) /* STACK mode insert at front... */
		mp = (*stack)->next;
		new1->prev = *stack;
		new1->next = mp;
		if (mp)
			mp->prev = new1;
		(*stack)->next = new1;
	else /* QUEUE mode insert at end... */
		mp = *stack;
		while (mp->next)
			mp = mp->next;
		new1->prev = mp;
		new1->next = NULL;
		mp->next = new1;
}

/**
 * monty_pall - Function that prints the values of a stack_t linked list.
 * @stack: input param - A pointer to the top mode node
 * of a stack_t linked list
 * @line_number: input param - The current working line
 * number of a Monty bytecodes file
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *mp = (*stack)->next;

	while (mp)
	{
		printf("%d\n", mp->n);
		mp = mp->next;
	}
	(void)line_number;
}

/**
 * monty_pint - Function that prints the top value of a
 * stack_t linked list
 * @stack: input param - A pointer to the top mode node
 * of a stack_t linked list
 * @line_number: input param - The current working line
 * number of a Monty bytecodes file
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}

/**
 * monty_pop - Function that removes the top value element
 * of a stack_t linked list
 * @stack: input param - A pointer to the top mode node
 * of a stack_t linked list
 * @line_number: input param - The current working line
 * number of a Monty bytecodes file
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->net);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * monty_swap - Function that waps the top two value
 * elements of a stack_t linked list.
 * @stack: input param - A pointer to the top mode node
 * of a stack_t linked list
 * @line_number: input param - The current working line
 * number of a Monty bytecodes file
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *mp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
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
