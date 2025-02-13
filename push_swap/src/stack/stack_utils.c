/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:07:28 by ddragos           #+#    #+#             */
/*   Updated: 2025/02/13 18:07:29 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// Function to free the stack
void	*free_stack(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	return (NULL);
}

// Function to add a node at the end
t_node	*add_node(t_node *last_node, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	last_node->next = new_node;
	return (new_node);
}

// Function to process numbers and add them to the stack
int	process_numbers(char *arg, t_node **last_node)
{
	char	**tokens;
	int		i;
	long	value;

	i = 0;
	tokens = ft_split(arg, ' ');
	if (!tokens)
		return (0);
	while (tokens[i])
	{
		value = ft_atoi_check(tokens[i]);
		if (value < INT_MIN || value > INT_MAX)
			return (free_tokens(tokens));
		*last_node = add_node(*last_node, value);
		if (!*last_node)
			return (free_tokens(tokens));
		i++;
	}
	free_tokens(tokens);
	return (1);
}

// Function to initialize stack A
t_node	*init_stack(int argc, char **argv)
{
	t_node	*dummy;
	int		i;
	t_node	*head;
	t_node	*last_node;

	if (argc < 2)
		return (NULL);
	dummy = malloc(sizeof(t_node));
	if (!dummy)
		return (NULL);
	dummy->next = NULL;
	last_node = dummy;
	i = 1;
	while (i < argc)
	{
		if (!process_numbers(argv[i], &last_node))
			return (free_stack(dummy));
		i++;
	}
	head = dummy->next;
	free(dummy);
	if (stack_has_duplicates(head))
		return (free_stack(head));
	return (head);
}

void	duplicate_stack(t_node **dest, t_node *src)
{
	t_node	*current;
	t_node	*new_node;
	t_node	*last;

	current = src;
	*dest = NULL;
	while (current)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return ;
		new_node->value = current->value;
		new_node->next = NULL;
		if (*dest == NULL)
		{
			*dest = new_node;
		}
		else
		{
			last->next = new_node;
		}
		last = new_node;
		current = current->next;
	}
}
