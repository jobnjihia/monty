#include "monty.h"
/**
 * stash_pint - prints the top elements of stack
 * @head: stack head
 * @counter: line_number executing
 */
void stash_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
