#include "../push_swap.h"
#include "stdio.h"

void	add_operation(const char *op)
{
	static char	best_operations[999991];
	static char	current_operations[999991];
	size_t		current_len;
	size_t		best_len;

	current_len = ft_strlen(current_operations);
	best_len = ft_strlen(best_operations);
	if (ft_strncmp(op, "end", 3) == 0)
	{
		if (best_len == 0 || (current_len < best_len && current_len > 0))
		{
			ft_memcpy(best_operations, current_operations, current_len + 1);
			best_operations[current_len] = '\0';
		}
		return ;
	}
	if (ft_strncmp(op, "print", 5) == 0)
		return (void)printf("%s", best_operations);
	ft_strlcat(current_operations, op, current_len + 5);
	ft_strlcat(current_operations, "\n", current_len + 10);
}

static int	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	return (1);
}

void	sx(t_node **stack, char *op)
{
	if (swap(stack))
		add_operation(op);
}

int	push(t_node **dest, t_node **src)
{
	t_node	*head_src;

	if (!src || !(*src))
		return (0);
	head_src = *src;
	*src = head_src->next;
	head_src->next = *dest;
	*dest = head_src;
	return (1);
}

void	px(t_node **dest, t_node **src, char *op)
{
	if (push(dest, src))
		add_operation(op);
}

// Rotate stack A (shift up)
int	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	return (1);
}

void	rx(t_node **stack, char *op)
{
	if (rotate(stack))
		add_operation(op);
}

// Reverse rotate stack A (shift down)
int	reverse_rotate(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (0);
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rrx(t_node **stack, char *op)
{
	if (reverse_rotate(stack))
		add_operation(op);
}
