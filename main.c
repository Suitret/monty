#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int index = 1;
	stack_t *head;
	FILE *file;
	char line[256], *opcode;
	void (*func)(stack_t **, unsigned int);

	if (argc != 2)
		error_message("USAGE: monty file");

	if (strstr(argv[1], ".m") && check_file(argv[1]))
	{
		file = fopen(argv[1], "r");
		while (fgets(line, 256, file) != NULL)
		{
			opcode = strtok(line, " ");
			func = valid_opcode(temp);
			if (!func)
			{
				error_inside(index, argv[1]);
				return (0);
			}
			else
			{
				
			}
			index++;
		}
		close(file);
	}

	return (0);
}
