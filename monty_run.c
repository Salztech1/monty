#include "monty.h"
#include <stdio.h>
#include <string.h>

/**
 * free_tokens - Function frees the global op_toks array of strings.
 */
void free_tokens(void)
{
	size_t a = 0;

	if (op_toks == NULL)
		return;

	for (a = 0; op_toks[a]; a++)
		free(op_toks[a]);

	free(op_toks);
}

/**
 * token_arr_len - Function gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int token_arr_len(void)
{
	unsigned int lengt_toks = 0;

	while (op_toks[lengt_toks])
		lengt_toks++;
	return (lengt_toks);
}

/**
 * is_empty_line - Function checks if a line read from getline
 * only contains delimiters.
 * @line: input param (A pointer to the line)
 * @delims: input param (A string of delimiter characters)
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
	int a, b;

	for (a = 0; line[a]; a++)
	{
		for (b = 0; delims[b]; b++)
		{
			if (line[a] == delims[b])
				break;
		}
		if (delims[b] == '\0')
			return (0);
	}

	return (1);
}
