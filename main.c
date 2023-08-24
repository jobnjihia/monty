#include "monty.h"
#include <sys/types.h>
#include <fcntl.h>

char **optoks = NULL;
/**
 * main - entry point of the monty interpreter
 * @argc: count of args passed to interpreter
 * @argv: array of pointers to the command-line arguments
 * Return: on implementation error (EXIT_FAILURE) and (EXIT_SUCCESS) on success
 */
int main(int argc, char **argv)
{
	int exit_denote = EXIT_SUCCESS;
	FILE *inter_fd = NULL;

	if (argc != 2)
		return (usage_error());
	inter_fd = fopen(argv[1], "r");
	if (inter_fd == NULL)
		return (f_open_error(argv[1]));
	exit_denote = run_monty(inter_fd);
	fclose(inter_fd);
	return (exit_denote);
}
