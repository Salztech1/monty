#include "monty.h"

/**
 * set_op_tok_error - It sets last element of op_toks
 * to be an error code.
 * @error_code: input param(Integer to store as a string in op_toks)
 */
void set_op_tok_error(int error_code)
{
	int toks_lengt = 0, a = 0;
	char *exit_strg = NULL;
	char **new_toks1 = NULL;

	toks_lengt = token_arr_len();
	new_toks1 = malloc(sizeof(char *) * (toks_lengt + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (a < toks_lengt)
	{
		new_toks1[a] = op_toks[a];
		a++;
	}
	exit_strg = get_int(error_code);
	if (!exit_strg)
	{
		free(new_toks1);
		malloc_error();
		return;
	}
	new_toks1[a++] = exit_strg;
	new_toks1[a] = NULL;
	free(op_toks);
	op_toks = new_toks1;
}
