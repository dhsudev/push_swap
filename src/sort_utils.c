/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:18:36 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/15 15:26:11 by ltrevin-         ###   ########.fr       */
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
	int	big;

	big = bigger(*stack);
	if ((*stack)->value == big)
		ra(stack, 0);
	else if ((*stack)->next->value == big)
		rra(stack, 0);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, 0);
}

/*
 * Rotate both stack to optimize the moves.
 * Reverse is a flag to know if it's need a reverse or a normal rotate
 */
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest, int reverse)
{
	while (*a != cheapest->target && *b != cheapest)
	{
		if (reverse)
			rrr(a, b, 0);
		else
			rr(a, b, 0);
	}
	set_index(*a);
	set_index(*b);
}

/*
 * Move the stacks with the more efficient moves to put the targets in
 * the top of the stack. We use rrr and rr
 * if we need to make the same rotate in both stacks
 */
void	top_targets(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = search_node(*b, (long)cheapest_value(*b));
	if (cheapest->above_center && cheapest->target->above_center)
		rotate_both(a, b, cheapest, 0);
	else if (!cheapest->above_center && !cheapest->target->above_center)
		rotate_both(a, b, cheapest, 1);
	while (*a != cheapest->target)
	{
		if (cheapest->target->above_center)
			ra(a, 0);
		else
			rra(a, 0);
	}
	while (*b != cheapest)
	{
		if (cheapest->above_center)
			rb(b, 0);
		else
			rrb(b, 0);
	}
	pa(a, b, 0);
}

/*
 * Calcs all the info needed to decide what to move,
 * moves, and reindexed
 */
void	move(t_stack **a, t_stack **b)
{
	init_nodes(*a, *b);
	top_targets(a, b);
	set_index(*a);
	set_index(*b);
}


