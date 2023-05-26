#ifndef _MONTY_H
#define _MONTY_H

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

typedef void (*func)(stack_t **, unsigned int);

int value; /* contains argument of push */

/* Functions to check the file */

void error_message(char *mes, char *arg);
void error_inside(int index, char *str);
int check_file(char *filename);
void tostring(char str[], int num);
func valid_opcode(char *opcode);
int push_arg(char *str, int index);
void error_with_line(char *str, int index);
void add_val(stack_t **head, unsigned int index);
void sub_val(stack_t **head, unsigned int index);
void div_val(stack_t **head, unsigned int index);
void mul_val(stack_t **head, unsigned int index);
void mod_val(stack_t **head, unsigned int index);
void print_char(stack_t *head, unsigned int index);
void print_string(stack_t *h);


/* Functions to manage the stack */

void free_list(stack_t *head);
stack_t *add_node(stack_t **head, const int n);
void print_list(stack_t *h);
void print_top_node(stack_t *h, unsigned int lnumber);
void pop_top_node(stack_t **head, unsigned int lnumber);
void swap_node(stack_t *head, unsigned int lnumber);

/* Opcodes Functions */

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pound(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

#endif /* _MONTY_H */
