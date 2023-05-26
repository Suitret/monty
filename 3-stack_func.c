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
/**
 * print_char - adds a new node at the end of a listint_t list
 * @head:  pointer to the head of list
 * @index: number
 * Return: void
 */

void print_char(stack_t *head, unsigned int index)
{
	if (head)
	{
		if (head->n > -1 && head->n < 128)
			printf("%c\n", head->n);
		else
			error_with_line(": can't pchar, value out of range", index);
	}
	else
		error_with_line(": can't pchar, stack empty", index);
}
/**
 * print_string - frees a dlistint_t list.
 * @h: given list
 * Return: void
 */
void print_string(stack_t *h)
{
	if (!h)
		printf("\n");
	else
	{
		while (h && (h->n > 0) && (h->n < 128))
		{
			printf("%c", h->n);
			h = h->next;
		}
		printf("\n");
	}
}
