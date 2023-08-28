#include "monty.h"
/**
 * stash_pall - prints the all elements of the stack
 * @head: head
 * @counter: no used
 */
void stash_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
