/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:59:18 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/01 16:13:07 by ltrevin-         ###   ########.fr       */
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
