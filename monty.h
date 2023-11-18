#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* opcode tokens */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Opcode main functions - opcode_funcs.c */
void push_opcode(stack_t **stack, unsigned int line_number);
void pall_opcode(stack_t **stack, unsigned int line_number);
void pint_opcode(stack_t **stack, unsigned int line_number);
void pop_opcode(stack_t **stack, unsigned int line_number);
void swap_opcode(stack_t **stack, unsigned int line_number);

/* Opcode main functions for operations - opcode_funcs.c */
void add_opcode(stack_t **stack, unsigned int line_number);
void sub_opcode(stack_t **stack, unsigned int line_number);
void div_opcode(stack_t **stack, unsigned int line_number);
void mul_opcode(stack_t **stack, unsigned int line_number);
void mod_opcode(stack_t **stack, unsigned int line_number);

/* Opcode main functions for printing nothing, character
 * and string - opcode_funcs.c */
void nop_opcode(stack_t **stack, unsigned int line_number);
void pchar_opcode(stack_t **stack, unsigned int line_number);
void pstr_opcode(stack_t **stack, unsigned int line_number);

/* Opcode, queue and stack functions */
void rotl_opcode(stack_t **stack, unsigned int line_number);
void rotr_opcode(stack_t **stack, unsigned int line_number);
void stack_opcode(stack_t **stack, unsigned int line_number);
void queue_opcode(stack_t **stack, unsigned int line_number);

/* Token custom std library functions - token.c */
char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/* Custom std library functions - int.c */
char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base, char *buff, int buff_size);

/* Warning message and error function for
 * (pop, pint, math, division, empty stacks using pchar) */
int opcode_err_pop(unsigned int line_number);
int opcode_err_pint(unsigned int line_number);
int opcode_err_shswap(unsigned int line_number, char *op);
int opcode_err_div(unsigned int line_number);
int opcode_err_pchar(unsigned int line_number, char *message);

/* Warning messages and error functions for system call
 * (usage, malloc, file opening, unknown,invalid) - error.c */
int sys_err_usage(void);
int sys_err_malloc(void);
int sys_err_fopen(char *filename);
int sys_err_unknownop(char *opcode, unsigned int line_number);
int sys_err_noint(unsigned int line_number);

/* Interpreter main functions  - monty_stack-run-optoks_set.c*/
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);
void free_tokens(void);
unsigned int token_arr_len(void);
void set_op_tok_error(int error_code);

#endif /* __MONTY_H__ */
