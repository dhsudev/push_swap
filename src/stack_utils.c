/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:44:55 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/15 17:21:43 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_last_node(t_stack *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	add_to_stack(t_stack **stack, int n)
{
	t_stack	*last;
	t_stack	*new;

	last = find_last_node(*stack);
	new = malloc(sizeof(t_stack));
	new->value = n;
	new->next = NULL;
	if (last)
	{
		new->prev = last;
		last->next = new;
	}
	else
	{
		*stack = new;
		(*stack)->prev = NULL;
	}
}

int	stack_len(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* Returns a node in a stack which have n as value*/
t_stack	*search_node(t_stack *stack, long n)
{
	if (n == LONG_MAX)
		n = smallest(stack);
	while (stack)
	{
		if ((long)stack->value == n)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
