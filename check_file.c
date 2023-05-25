#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "monty.h"

/*void (*func)(stack_t **, unsigned int);*/

/**
 * error_message - prints the suitable error message
 * @mes: message to print
 * @arg: second argument
 * Return: void
 */

void error_message(char *mes, char *arg)
{
	if (arg)
		fprintf(stderr, "%s%s\n", mes, arg);
	else
		fprintf(stderr, "%s\n", mes);
	exit(EXIT_FAILURE);
}

/**
 * error_inside - prints the suitable error message
 * @opc: incorrect opcode
 * @index: error line
 * Return: void
 */

void error_inside(int index, char *opc)
{
	char *str, *num;

	str = malloc(256);
	num = malloc(10);
	if (!str || !num)
		error_message("Error: malloc failed", NULL);

	tostring(num, index);
	str = strcpy(str, "L");
	str = strcat(str, num);
	str = strcat(str, ": unknown instruction ");
	str = strcat(str, opc);

	fprintf(stderr, "%s\n", str);
	if (str)
		free(str);
	if (num)
		free(num);
	exit(EXIT_FAILURE);
}

/**
 * check_file - checks if a file can be used
 * @filename: name of the file
 * Return: 0 or 1
 */

int check_file(char *filename)
{
	char *str;

	if (access(filename, R_OK) == 0)
		return (1);

	str = malloc(256);
	if (!str)
	{
		error_message("Error: malloc failed", NULL);
		return (0);
	}

	str = strcpy(str, "Error: Can't open file ");
	str = strcat(str, filename);
	error_message(str, NULL);
	if (str)
		free(str);
	return (0);
}

/**
 * tostring - converts an integer to string
 * @str: string
 * @num: number
 * Return: void
 */
void tostring(char str[], int num)
{
	int i, rem, len = 0, n;

	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
}

/**
 * valid_opcode - checks if opcode is valid
 * @opcode: given opcode
 * Return: func
 */
func valid_opcode(char *opcode)
{
	instruction_t tab[] = {
		{"push", &push}, {"pall", &pall}, {"pint", &pint}, {"pop", &pop},
		{"swap", &swap}, {"add", &add}, {"nop", &nop}, {"sub", &sub},
		{"div", &divi}, {"mul", &mul}, {"mod", &mod}, {"pchar", &pchar},
		{"#", &pound}, {"pstr", &pstr}, {"rotl", &rotl}, {"rotr", &rotr},
		{"stack", &stack}, {"queue", &queue}, {NULL, NULL}
	};
	int i = 0;

	while (tab[i].opcode)
	{
		if (strcmp(opcode, tab[i].opcode) == 0)
			return (tab[i].f);
		i++;
	}
	return (NULL);
}
