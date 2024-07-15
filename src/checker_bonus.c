/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:57:07 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/15 17:27:56 by ltrevin-         ###   ########.fr       */
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

void	end(t_stack **a, t_stack **b, char *move)
{
	write(2, "Error\n", 6);
	finish(a, b);
	free(move);
	exit(1);
}

void	exec_move(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strcmp(move, "sa\n"))
		sa(a, 1);
	else if (!ft_strcmp(move, "sb\n"))
		sb(b, 1);
	else if (!ft_strcmp(move, "ss\n"))
		ss(a, b, 1);
	else if (!ft_strcmp(move, "pa\n"))
		pa(a, b, 1);
	else if (!ft_strcmp(move, "pb\n"))
		pb(a, b, 1);
	else if (!ft_strcmp(move, "ra\n"))
		ra(a, 1);
	else if (!ft_strcmp(move, "rb\n"))
		rb(b, 1);
	else if (!ft_strcmp(move, "rr\n"))
		rr(a, b, 1);
	else if (!ft_strcmp(move, "rra\n"))
		rra(a, 1);
	else if (!ft_strcmp(move, "rrb\n"))
		rrb(b, 1);
	else if (!ft_strcmp(move, "rrr\n"))
		rrr(a, b, 1);
	else
		end(a, b, move);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*move;

	a = NULL;
	b = NULL;
	init_stack(argv, argc, &a);
	move = get_next_line(STDIN_FILENO);
	while (move)
	{
		exec_move(&a, &b, move);
		free(move);
		move = get_next_line(STDIN_FILENO);
	}
	if (sorted(a) && stack_len(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	finish(&a, &b);
	return (0);
}
