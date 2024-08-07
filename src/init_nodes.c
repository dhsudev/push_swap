/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:14:33 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/15 15:21:16 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 * Calculates the price to perfom the pa (to be in order)
 * of every node in b.
 * The price is a sum of how many moves
 * we need to put in the top the node in b and its target node in a
 */

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->price = b->index;
		if (!(b->above_center))
			b->price = len_b - b->index;
		if (b->target->above_center)
			b->price += b->target->index;
		else
			b->price += len_a - b->target->index;
		b = b->next;
	}
}

/*
 * Set the current position of the nodes in the stack
 *	it also calculates the center line and defines
 *	if the node is above it
 */
void	set_index(t_stack *stack)
{
	int	i;
	int	center;

	i = 0;
	center = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= center)
			stack->above_center = 1;
		else
			stack->above_center = 0;
		i++;
		stack = stack->next;
	}
}

/*
 * Search the target node from a to b.
 * The target node is the closest bigger value
 * if there is no value, is the smallest
 * */
void	set_target(t_stack *a, t_stack *b)
{
	long	best_target;
	t_stack	*curr_a;

	while (b)
	{
		curr_a = a;
		best_target = LONG_MAX;
		while (curr_a)
		{
			if (curr_a->value > b->value && curr_a->value < best_target)
				best_target = (long)curr_a->value;
			curr_a = curr_a->next;
		}
		b->target = search_node(a, best_target);
		b = b->next;
	}
}

/*
 * Search for the cheapest node in the stack b and flags it
 */
void	set_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;

	cheapest_node = stack;
	while (stack)
	{
		if (stack->price < cheapest_node->price)
		{
			cheapest_node = stack;
		}
		stack->cheapest = 0;
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

/*
 * Inits the nodes of the stacks to make the decision of what to move:
 *		- sets the index of the node in the stack
 *		- if its above the half of the stack
 *		- the target nodes of b from a
 *		- the cost of move of each node to the correct position in a
 */
void	init_nodes(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target(a, b);
	set_price(a, b);
	set_cheapest(b);
}
