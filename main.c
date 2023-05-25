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
	int index = 1, value;
	head = NULL;
	FILE *file;
	char line[256], *opcode;
	void (*func)(stack_t **, unsigned int);

	if (argc != 2)
		error_message("USAGE: monty file", NULL);

	if (check_file(argv[1]) && strstr(argv[1], ".m"))
	{
		file = fopen(argv[1], "r");
		while (fgets(line, 256, file) != NULL)
		{
			opcode = strtok(line, " ");
			func = valid_opcode(opcode);
			if (!func)
			{
				error_inside(index, opcode);
				return (0);
			}
			else
			{
				exec_opcode(func, value);
				printf("%s\n", line);
			}
			index++;
		}
		fclose(file);
	}
	else
		error_message("Error: Can't open file ", argv[1]);

	return (0);
}
