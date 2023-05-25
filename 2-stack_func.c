#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * swap_node - adds a new node at the beginning of a stack_t list
 * @head:  pointer to the head of list
 * @index: number
 * Return: the head of list
 */
void swap_node(stack_t *head, unsigned int index)
{
	int temp;

	if (head && (head->next))
	{
		temp = head->n;
		head->n = head->next->n;
		head->next->n = temp;
	}
	else
		error_with_line(": can't swap, stack too short", index);
}
/**
 * add_val - adds a new node at the beginning of a stack_t list
 * @head:  pointer to the head of list
 * @index: number
 * Return: the head of list
 */
void add_val(stack_t **head, unsigned int index)
{
	int temp;

	if (*head && ((*head)->next))
	{
		temp = ((*head)->n) + ((*head)->next->n);
		head->next->n = temp;
		pop_top_node(head, index);
	}
	else
		error_with_line(": can't add, stack too short", index);
}
