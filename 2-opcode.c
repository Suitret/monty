#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "monty.h"

/**
 * add - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	add_val(stack, line_number);
}
/**
 * nop - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void nop(__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{

}
/**
 * sub - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	sub_val(stack, line_number);
}
/**
 * divi - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void divi(stack_t **stack, unsigned int line_number)
{
	div_val(stack, line_number);
}
/**
 * mul - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	mul_val(stack, line_number);
}
