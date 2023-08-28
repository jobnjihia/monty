#include "monty.h"
/**
 * stash_pstr - prints string at the top of the string & a newline
 * @head: top of the stack, head
 * @counter: lineof code being executed
*/
void stash_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
