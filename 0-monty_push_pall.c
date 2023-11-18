#include "monty.h"

/**
 * push_opcode - Function pushes a value to a stack_t linked list.
 * @stack: input param - A pointer to the top mode node of a
 * stack_t linked list.
 * @line_number: input param - The current working line number
 * of a Monty bytecodes file.
 */
void push_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *mp, *new;
	int a;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(sys_err_malloc());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(sys_err_noint(line_number));
		return;
	}

	for (a = 0; op_toks[1][a]; a++)
	{
		if (op_toks[1][a] == '-' && a == 0)
			continue;
		if (op_toks[1][a] < '0' || op_toks[1][a] > '9')
		{
			set_op_tok_error(sys_err_noint(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK) /* STACK mode insert at front... */
	{
		mp = (*stack)->next;
		new->prev = *stack;
		new->next = mp;
		if (mp)
			mp->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end... */
	{
		mp = *stack;
		while (mp->next)
			mp = mp->next;
		new->prev = mp;
		new->next = NULL;
		mp->next = new;
	}
}

/**
 * pall_opcode - Function prints the values of a stack_t linked list.
 * @stack: input param - A pointer to the top mode node of a
 * stack_t linked list
 * @line_number: input param - The current working line number
 * of a Monty bytecodes file.
 */
void pall_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *mp = (*stack)->next;

	while (mp)
	{
		printf("%d\n", mp->n);
		mp = mp->next;
	}
	(void)line_number;
}
