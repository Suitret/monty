#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "monty.h"

/**
 * mod - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	mod_val(stack, line_number);
}
/**
 * pchar - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	print_char(*stack, line_number);
}
/**
 * pound - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void pound(__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{

}
/**
 * pstr - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void pstr(stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
	print_string(*stack);
}
/**
 * rotr - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void rotr(__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{

}
