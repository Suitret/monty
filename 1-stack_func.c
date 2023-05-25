#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * add_node - adds a new node at the beginning of a stack_t list
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
 * @h: given list
 * Return: void
 */
void print_list(stack_t *h)
{
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 * print_top_node - adds a new node at the end of a listint_t list
 * @head:  pointer to the head of list
 * @index: number
 * Return: void
 */

void print_top_node(stack_t *head, unsigned int index)
{
	if (head)
		printf("%d\n", head->n);
	else
		error_with_line(": can't pint, stack empty", index);
}
/**
 * pop_top_node - adds a new node at the end of a listint_t list
 * @head:  pointer to the head of list
 * @index: number
 * Return: void
 */

void pop_top_node(stack_t **head, unsigned int index)
{
	stack_t *current;

	if (*head)
	{
		current = *head;
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
	}
	else
		error_with_line(": can't pop an empty stack", index);
}
