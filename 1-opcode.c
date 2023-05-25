#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	add_node(stack, value);
}
/**
 * pall - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void pall(stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
	print_list(*stack);
}
/**
 * pint - prints the value at the top of the stack
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	print_top_node(*stack, line_number);
}
/**
 * pop - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	pop_top_node(stack, line_number);
}
/**
 * swap - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	swap_node(*stack, line_number);
}
