#include "monty.h"
#include <stdlib.h>

/**
 * strtow - Function takes a string and seperates its words
 * @str: input param (string to seperate into words)
 * @delims: input param (delimitors to use to delimit words)
 *
 * Return: 2D array of pointers to each word
 */

char **strtow(char *str, char *delims)
{
	char **sentence = NULL;
	int sent_numb, sentencelengt, j, a = 0;

	if (str == NULL || !*str)
		return (NULL);
	sent_numb = get_word_count(str, delims);


	if (sent_numb == 0)
		return (NULL);
	sentence = malloc((sent_numb + 1) * sizeof(char *));
	if (sentence == NULL)
		return (NULL);
	while (a < sent_numb)
	{
		sentencelengt = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		sentence[a] = malloc((sentencelengt + 1) * sizeof(char));
		if (sentence[a] == NULL)
			while (a >= 0)
			{
				a--;
				free(sentence[a]);
			}
		free(sentence);
		return (NULL);
		j = 0;
		while (j < sentencelengt)
			sentence[a][j] = *(str + j);
		j++;
		sentence[a][j] = '\0'; /* set end of str... */
		str = get_next_word(str, delims);
		a++;
	}
	sentence[a] = NULL; /* last element is null for iteration... */
	return (sentence);
}

/**
 * is_delim - Function checks if stream has delimitor char
 * @ch: input param (character in stream)
 * @delims: input param (Pointer to null terminated array of delimitors)
 *
 * Return: 1 (success) 0 (failure)
 */

int is_delim(char ch, char *delims)
{
	int a = 0;

	while (delims[a])
	{
		if (delims[a] == ch)
			return (1);
		a++;
	}
	return (0);
}

/**
 * get_word_length - Function gets the word length of cur word in str
 * @str: input param (string to get word length from current word)
 * @delims: input param (delimitors to use to delimit words)
 *
 * Return: word length of current word
 */

int get_word_length(char *str, char *delims)
{
	int sentlengt = 0, remander = 1, a = 0;

	while (*(str + a))
	{
		if (is_delim(str[a], delims))
			remander = 1;
		else if (remander)
		{
			sentlengt++;
		}
		if (sentlengt > 0 && is_delim(str[a], delims))
			break;
		a++;
	}
	return (sentlengt);
}

/**
 * get_word_count - Function gets the word count of a string
 * @str: input param (string to get word count from)
 * @delims: input param (delimitors to use to delimit words)
 *
 * Return: the word count of the string
 */

int get_word_count(char *str, char *delims)
{
	int sentencelengt = 0, remander = 1, a = 0;

	while (*(str + a))
	{
		if (is_delim(str[a], delims))
			remander = 1;
		else if (remander)
		{
			remander = 0;
			sentencelengt++;
		}
		a++;
	}
	return (sentencelengt);
}

/**
 * get_next_word - Function gets the next word in a string
 * @str: input param (string to get next word from)
 * @delims: input param (delimitors to use to delimit words)
 *
 * Return: pointer to first char of next word
 */

char *get_next_word(char *str, char *delims)
{
	int remander = 0;
	int a = 0;

	while (*(str + a))
	{
		if (is_delim(str[a], delims))
			remander = 1;
		else if (remander)
			break;
		a++;
	}
	return (str + a);
}
