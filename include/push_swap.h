/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:38:48 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/15 17:23:09 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				price;
	int				above_center;
	int				cheapest;
	int				above_median;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// Checking utils
int					not_valid_nums(char **s, int size);
long				ft_atol(char *str);
int					init_stack(char **args, int size, t_stack **stack);
// Stack utils
void				add_to_stack(t_stack **stack, int n);
int					search_dup(t_stack *stack, int n);
void				finish(t_stack **a, t_stack **b);
int					smallest(t_stack *stack);
int					stack_len(t_stack *stack);
int					sorted(t_stack *stack);
t_stack				*search_node(t_stack *stack, long n);
// Sorting fucn
void				sort_three(t_stack **stack);
void				sort_five(t_stack **a, t_stack **b);
void				init_nodes(t_stack *a, t_stack *b);
void				set_index(t_stack *stack);
int					smallest(t_stack *stack);
int					cheapest_value(t_stack *stack);
int					find_median(t_stack *head, int size);
t_stack				*find_last_node(t_stack *head);
void				rotate_both(t_stack **a, t_stack **b, t_stack *cheapest,
						int reverse);
void				top_targets(t_stack **a, t_stack **b);
void				move(t_stack **a, t_stack **b);

// MOVES
void				sa(t_stack **a, int checker);
void				sb(t_stack **b, int checker);
void				ss(t_stack **a, t_stack **b, int checker);
void				pa(t_stack **a, t_stack **b, int checker);
void				pb(t_stack **a, t_stack **b, int checker);
void				ra(t_stack **a, int checker);
void				rb(t_stack **b, int checker);
void				rr(t_stack **a, t_stack **b, int checker);
void				rra(t_stack **a, int checker);
void				rrb(t_stack **b, int checker);
void				rrr(t_stack **a, t_stack **b, int checker);

#endif
