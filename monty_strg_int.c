#include <stdlib.h>

/**
 * get_int - Function gets a character pointer to new string containing int
 * @num: input param (number to convert to string)
 *
 * Return: character pointer to newly created string.
 * NULL if malloc fails.
 */
char *get_int(int num)
{
	unsigned int mp;
	int lengt = 0;
	long num_len = 0;
	char *lent;

	mp = _abs(num);
	lengt = get_numbase_len(mp, 10);

	if (num < 0 || num_len < 0)
		lengt++; /* negative sign... */
	lent = malloc(lengt + 1); /* create new string... */
	if (!lent)
		return (NULL);

	fill_numbase_buff(mp, 10, lent, lengt);
	if (num < 0 || num_len < 0)
		lent[0] = '-';

	return (lent);
}

/**
 * _abs - Function gets the absolute value of an integer
 * @i: input param (integer to get absolute value)
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - Function gets length of buffer needed for an unsigned int
 * @num: input param (number to get length needed)
 * @base: input param (base of number representation used by buffer)
 *
 * Return: integer containing length of buffer needed (doesn't contain null bt)
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int lengt = 1; /* all numbers contain atleast one digit... */

	while (num > base - 1)
	{
		lengt++;
		num /= base;
	}
	return (lengt);
}

/**
 * fill_numbase_buff - Function fills buffer with correct numbers up to base 36
 * @num: input param (number to convert to string given base)
 * @base: input param - base of number used in conversion,
 * only works up to base 36
 * @buff: input param - buffer to fill with result of
 * conversion
 * @buff_size: input param (size of buffer in bytes)
 *
 * Return: always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int lef, a = buff_size - 1;

	buff[buff_size] = '\0';
	while (a >= 0)
	{
		lef = num % base;
		if (lef > 9) /* return lowercase ascii val representation... */
			buff[a] = lef + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[a] = lef + '0';
		num /= base;
		a--;
	}
}
