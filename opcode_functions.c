#include "monty.h"

/**
 * fn_push - call the function to add node at beginning (top stack)
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: number of nodes in the linked list, 0 if empty
 */
void fn_push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (line_global.argument != NULL && _isdigit() != 0)
	{
		add_dnodeint(stack, atoi(line_global.argument));
		return;
	}
	dprintf(STDERR_FILENO, "L%d: usage: push integer\n",
			line_global.number_line);
	exit(EXIT_FAILURE);
}
/**
 * fn_pall - call the function to print elements of linked listng
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: number of nodes in the linked list, 0 if empty
 */
void fn_pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	print_dlistint(*stack);
}
/**
 * fn_pint - call the function to prints the value at the top of the stack
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: number of nodes in the linked list, 0 if empty
 */
void fn_pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack && *stack)
		print_head(*stack);
	else
	{
		fclose(line_global.file_i);
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n",
				line_global.number_line);
		exit(EXIT_FAILURE);
	}
}
/**
 * fn_pop - call the function to delete node at beginning (top stack)
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: number of nodes in the linked list, 0 if empty
 */
void fn_pop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack && *stack)
	{
		delete_dnodeint_at_index(stack, 0);
		return;
	}
	dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n",
			line_global.number_line);
	exit(EXIT_FAILURE);
}
/**
 * fn_swap - swaps the top two elements of the stack
 * @stack: pointer to head of stack
 * @line_number: number of the line in the bytecode file
 * Return: EXIT_FAILURE or return to function
 */
void fn_swap(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (dlistint_len(*stack) >= 2)
	{
		swap_node(*stack);
		return;
	}
	dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n",
			line_global.number_line);
	exit(EXIT_FAILURE);
}
