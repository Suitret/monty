#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list
 * @head:  pointer to the head of list
 * @n: number
 * Return: the head of list
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));

	if (!node)
		return (node);

	node->n = n;
	node->next = *head;
	node->prev = NULL;
	*head = node;
	if (node->next)
		(node->next)->prev = node;

	return (node);
}

/**
 * free_dlistint - frees a dlistint_t list.
 * @head: given list
 * Return: void
 */

void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

