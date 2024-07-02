/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:58:19 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/02 14:58:29 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*top;
	t_stack	*tmp;

	if (!stack)
		return ;
	top = *stack;
	*stack = (*stack)->next;
	top->next = NULL;
	(*stack)->prev = NULL;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = top;
}

void	ra(t_stack **a, int checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		write(1, "rr\n", 3);
}
