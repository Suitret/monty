#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * mod_val - adds a new node at the beginning of a stack_t list
 * @head:  pointer to the head of list
 * @index: number
 * Return: the head of list
 */
void mod_val(stack_t **head, unsigned int index)
{
	int temp;

	if (*head && ((*head)->next))
	{
		if ((*head)->n != 0)
		{
			temp = ((*head)->next->n) % ((*head)->n);
			(*head)->next->n = temp;
			pop_top_node(head, index);
		}
		else
			error_with_line(": division by zero", index);
	}
	else
		error_with_line(": can't mod, stack too short", index);
}
