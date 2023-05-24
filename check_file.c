#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "monty.h"

/**
 * error_message - prints the suitable error message
 * @mes: message to print
 * Return: void
 */

void error_message(char *mes)
{
	fprintf(stderr, "%s\n", mes);
	exit(EXIT_FAILURE);
}

/**
 * check_file - checks if a file can be used
 * @filename: name of the file
 * Return: 0 or 1
 */

int check_file(char *fil)
{
	int index = 1;
	FILE *file;
	char line[1024], *temp, *str, *num;
	str = malloc(1024);

	if (!str)
		error_message("Error: malloc failed");

	if (access(fil, R_OK) == 0)
	{
		file = fopen(fil, "r");
		while (fgets(line, 1024, file) != NULL)
		{
			temp = strtok(line, " ");
			if (!valid_opcode(temp))
			{
				num = malloc(10);
				if (!num)
					error_message("Error: malloc failed");
				tostring(num, index);
				str = strcpy(str, "L");
				str = strcat(str, num);
				str = strcat(str, ": unknown instruction ");
				str = strcat(str, temp);
				error_message(str);
				free(num), free(str);
				return (0);
			}
			index++;
		}
		return (1);
	}

	str = strcpy(str, "Error: Can't open file ");
	str = strcat(str, fil);
	error_message(str);
	free(str);
	return (0);
}

/**
 * to_string - converts an integer to string
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
 * Return: 0 or 1
 */
int valid_opcode(char *opcode)
{
	char *tab[] = {"push", "pall", "pint", "pop", "swap", "add", "nop",
					"sub", "div", "mul", "mod", "pchar", "#", "pstr",
					"rotl", "rotr", "stack", "queue", NULL};
	int i = 0;

	while (tab[i])
	{
		if (strcmp(opcode, tab[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
