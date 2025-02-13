/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddragos <ddragos@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:53:55 by ddragos           #+#    #+#             */
/*   Updated: 2025/02/13 20:53:56 by ddragos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

// Stack operations
void				sx(t_node **stack, char *op);
void				px(t_node **dest, t_node **src, char *op);
void				rx(t_node **stack, char *op);
void				rrx(t_node **stack, char *op);

// Sorting
void				sort_stack(t_node **a, t_node **b);

long				ft_atoi_check(const char *nptr);

// stack check
int					stack_size(t_node *stack);
int					stack_has_duplicates(t_node *head);
void				print_stack(t_node *stack);
int					stack_is_sorted(t_node *current);

t_node				*init_stack(int argc, char **argv);
void				*free_stack(t_node *stack);
void				duplicate_stack(t_node **dest, t_node *src);
void				operations_handler(const char *op);
void				sort_three(t_node **a);

// Sorting utils
int					get_min(t_node *stack);
void				move_to_top(t_node **stack, int index, int size,
						char stack_char);
int					get_index(t_node *current, int n);
int					get_max(t_node *stack);
int					get_next_max(t_node *current, int max);
int					get_next_min(t_node *current, int min);

// sort
void				sort_simple(t_node **a, t_node **b);
int					free_tokens(char **tokens);

// bucket sort
void				bucket_sort(t_node **a, t_node **b);
void				push_to_a(t_node **stack_a, t_node **stack_b);
void				push_to_b(t_node **stack_a, t_node **stack_b,
						int bucket_size);
int					get_closest_min_index(t_node *current, int min);
int					get_moves_required(t_node **stack_b, int number, int size);

#endif
