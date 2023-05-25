#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a stack_t list
 * @head:  pointer to the head of list
 * @n: number
 * Return: the head of list
 */

stack_t *add_node(stack_t **head, const int n)
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
 * free_list - frees a stack_t list.
 * @head: given list
 * Return: void
 */

void free_list(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * print_list - frees a dlistint_t list.
 * @head: given list
 * Return: void
 */
size_t print_list(stack_t *h)
{
	int len = 0;

	while (h)
	{
		printf("%d\n", h->n);
		len++;
		h = h->next;
	}
	return (len);
}
