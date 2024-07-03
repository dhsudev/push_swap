/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:57:59 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/03 18:15:12 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*bot;
	t_stack	*tmp;

	if (!stack)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	bot = tmp;
	bot->prev->next = NULL;
	bot->next = *stack;
	(*stack)->prev = bot;
	*stack = bot;
}

void	rra(t_stack **a, int checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
