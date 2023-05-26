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
	int index = 0;
	stack_t *head = NULL;
	FILE *file;
	char line[256], *opcode, *str;
	func myfunc;

	if (argc != 2)
		error_message("USAGE: monty file", NULL);
	if (check_file(argv[1]) && strstr(argv[1], ".m"))
	{
		file = fopen(argv[1], "r");
		while (fgets(line, 256, file) != NULL)
		{
			index++;
			line[strcspn(line, "\n")] = '\0';
			opcode = strtok(line, " ");
			if (opcode == NULL || opcode[0] == '#')
				continue;
			myfunc = valid_opcode(opcode);
			if (!myfunc)
				error_inside(index, opcode);
			else
			{
				if (strcmp(opcode, "push") == 0)
				{
					str = strtok(NULL, " ");
					if (push_arg(str, index))
						value = atoi(str);
				}
				myfunc(&head, index);
			}
		}
		fclose(file);
	}
	else
		error_message("Error: Can't open file ", argv[1]);
	free_list(head);
	return (0);
}
