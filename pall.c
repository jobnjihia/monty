#include "monty.h"
/**
 * f_push - addition of a node to the top of stack
 * @head: top of the stack
 * @counter: counter line being executed
*/
void stash_push(stack_t **head, unsigned int counter)
{
	int k, l = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			l++;
		for (; bus.arg[l] != '\0'; l++)
		{
			if (bus.arg[l] > 57 || bus.arg[l] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	k = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, k);
	else
		addqueue(head, k);
}
