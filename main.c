#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "monty.h"


int main(int argc, char *argv[])
{
	/*stack_t *head;
	instruction_t *headI;*/

	if (argc != 2)
		error_message("USAGE: monty file");

	if (check_file(argv[1])) /* strstr(argv[1], ".m") */
	{

	}

	return (0);
}
