/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:57:07 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/15 16:57:21 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void exec_move(char *move, t_stack **a, t_stack **b)
{
	if(!ft_strcmp(move, "sa\n"))
		sa(a, 1);
	else 
	{
		write(2, "Error\n", 6);
		finish(a, b);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*move;

	a = NULL;
	b = NULL;
	init_stack(argv, argc, &a);
	move = "";
	while(move)
	{
		move = get_next_line(1);
		exec_move(move, &a, &b);
	}
	if(sorted(a))
		write(1,"OK\n", 3);
	else 
		write(1, "KO\n", 3);
	finish(&a, &b);
	return (0);
}
