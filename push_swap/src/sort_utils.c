#include "../push_swap.h"

void move_to_top(t_node **stack, int index, int size, char stack_char)
{
	char op[4];
	op[0] = 'r';
	if (index <= size / 2)
	{
		op[1] = stack_char;
		op[2] = '\0';
		while (index-- > 0)
			rx(stack, op);
	}
	else
	{
		index = size - index;
		op[1] = 'r';
		op[2] = stack_char;
		op[3] = '\0';
		while (index-- > 0)
			rrx(stack, op);
	}
}

int get_index(t_node *current, int n)
{
	int index = 0;

	while (current)
	{
		if (current->value == n)
			return (index);
		current = current->next;
		index++;
	}
	return index;
}

int get_max(t_node *stack)
{
	int max = stack->value;
	t_node *current = stack;

	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int get_next_max(t_node *current, int max)
{
	int next_max;

	next_max = INT_MIN;
	while (current)
	{
		if (current->value < max && current->value > next_max)
			next_max = current->value;
		current = current->next;
	}
	return (next_max);
}

int get_min(t_node *stack)
{
	int min = stack->value;
	t_node *current = stack;

	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int get_next_min(t_node *current, int min)
{
	int next_min;

	next_min = INT_MAX;
	while (current)
	{
		if (current->value > min && current->value < next_min)
			next_min = current->value;
		current = current->next;
	}
	return (next_min);
}

