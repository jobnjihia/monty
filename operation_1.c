#include "monty.h"
void stash_push(stack_t **stack, unsigned int line_number);
void stash_pall(stack_t **stack, unsigned int line_number);
void stash_pint(stack_t **stack, unsigned int line_number);
void stash_pop(stack_t **stack, unsigned int line_number);
void stash_swap(stack_t **stack, unsigned int line_number);

/**
 * stash_push - push a node into stack_t to stack
 * @stack: pointer to topmost node in the singly linked list
 * @line_number: pointer to to the top most node of a stack
 */
void stash_push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *new_node;
	int j;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		set_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_tok_error(no_int_error(line_number));
		return;
	}

	for (j = 0; op_toks[1][j]; j++)
	{
		if (op_toks[1][j] == '-' && j == 0)
			continue;
		if (op_toks[1][j] < '0' || op_toks[1][j] > '9')
		{
			set_tok_error(no_int_error(linenumber));
			return;
		}
	}
	new_node->n = atoi(op_toks[1]);
	if (check_mode(stack) == STACK)
	{
		temp = (*stack)->next;
		new_node->prev = *stack;
		new_node->next = temp;
		if (temp)
			temp->prev = new_node;
		(*stack)->next = new;
	}
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		new_node->prev = temp;
		new_node->next = NULL;
	}
}
/**
 * stash_pall - prints stack_t values of linked list
 * @stack: pointer to the top most node
 * @line_number: the working line of Monty bytecodes file
 */
void stash_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	void(line_number)
}
/**
 * stash_pint - print the first value in list
 * @stack: pointer to top node of the stack
 * @line_number: line of monty bytecode being being executed
 */
void stash_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_tok_error(print_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n)
}
/**
 * stash_pop - deletes the top value of the stack elements in list
 * @stack: pointerto to top node of linked list
 * @line_number: monty bytecode line being executed
 */
void stash_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_tok_error(pop_error(line_number));
		return;
	}
	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
/**
 * stash_swap - swaps the two top elements of stack_t
 * @stack: pointer to the top nodes of a stack
 * @line_number: currentline being executed of monty bytecode
 */
void stash_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_tok_error(small_stack_error(line_number, "swap"));
		return;
	}
	temp = (*stack)->next->next;
	(*stack)->next->next = temp->next;
	(*stack)->next->next = temp;
	if (temp->next)
		temp->next->prev = (*stack)->next;
	temp->next = (*stack)->next;
	temp->next = *stack;
	(*stack)->next = *temp;
}
