/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:18:36 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/02 16:54:55 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	bigger(t_stack *stack)
{
	int	n;

	n = stack->value;
	while (stack)
	{
		if (n < stack->value)
			n = stack->value;
		stack = stack->next;
	}
	return (n);
}

void	sort_three(t_stack **stack)
{
	int big;

	big = bigger(*stack);
	if((*stack)->value == big)
		ra(stack, 0);
	else if((*stack)->next->value == big)
		rra(stack, 0);
	if((*stack)->value > (*stack)->next->value)
		sa(stack, 0);
}
