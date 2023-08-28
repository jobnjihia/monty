#include "monty.h"
/**
 * execute - executes the opcode
 * @stack: head of linked list - stack
 * @counter: counts the lines
 * @file: pointer to monty file
 * @content: content of the line
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", stash_push}, {"pall", f_pall}, {"pint", stash_pint},
				{"pop", f_pop},
				{"swap", stash_swap},
				{"add", stash_add},
				{"nop", stash_nop},
				{"sub", f_sub},
				{"div", stash_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", stash_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", stash_queue},
				{"stack", stash_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
