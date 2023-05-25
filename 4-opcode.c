#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "monty.h"

/**
 * rotl - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void rotl(__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{

}
/**
 * stack - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void stack(__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{

}
/**
 * queue - pushes an element to the stack.
 * @stack: stack of elements
 * @line_number: line number
 * Return: void
 */
void queue(__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{

}

/**
 * push_arg - pushes an element to the stack.
 * @str: string
 * @index: line number
 * Return: 0 or 1
 */
int push_arg(char *str, int index)
{
	char *temp, *num;
	size_t i = 0;

	if (!str)
	{
		temp = malloc(10);
		num = malloc(10);
		if (!temp || !num)
			error_message("Error: malloc failed", NULL);
		temp = strcpy(temp, "L");
		tostring(num, index);
		temp = strcat(temp, num);
		error_message(temp, ": usage: push integer");
		return (0);
	}
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] > 47 && str[i] < 58)
			continue;
		else if ((str[i] == 43 || str[i] == 45) && i == 0)
			continue;
		else
		{
			temp = malloc(10);
			num = malloc(10);
			if (!temp || !num)
				error_message("Error: malloc failed", NULL);
			temp = strcpy(temp, "L");
			tostring(num, index);
			temp = strcat(temp, num);
			error_message(temp, ": usage: push integer");
			return (0);
		}
	}
	return (1);
}
