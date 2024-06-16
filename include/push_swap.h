/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:38:48 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/06/16 20:03:26 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 

# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

int		not_valid_nums(char **s, int size);
long	ft_atol(char *str);
int	init_stack(char **args, int size, t_stack *stack);
void add_to_stack(t_stack *stack, int n);

#endif
