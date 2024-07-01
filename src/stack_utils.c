/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:44:55 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/01 16:00:44 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*last_node(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	add_to_stack(t_stack **stack, int n)
{
	t_stack	*last;
	t_stack	*new;

	last = last_node(*stack);
	new = malloc(sizeof(t_stack));
	new->value = n;
	new->next = NULL;
	if (last)
	{
		new->prev = last;
		last->next = new;
	}
	else
		*stack = new;
}

void	print_stack(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	printf("--Stack A --\n");
	while (a != NULL)
	{
		printf("%d - |%d|\n", i, a->value);
		a = a->next;
		i++;
	}
	i = 0;
	printf("--Stack B --\n");
	while (b != NULL)
	{
		printf("%d - |%d|\n", i, b->value);
		b = b->next;
		i++;
	}
}

int	search_dup(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next;
		i++;
	}
	return (0);
}

void	finish(t_stack **a, t_stack **b)
{
	t_stack	*node;

	while (*a)
	{
		node = *a;
		*a = (*a)->next;
		free(node);
	}
	while (*b)
	{
		node = *b;
		*b = (*b)->next;
		free(node);
	}
	exit(0);
}
