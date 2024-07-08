/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:44:55 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/06 20:33:17 by ltrevin-         ###   ########.fr       */
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

int	smallest(t_stack *stack)
{
	int	n;

	n = stack->value;
	while (stack)
	{
		if (n > stack->value)
			n = stack->value;
		stack = stack->next;
	}
	return (n);
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

int sorted(t_stack *stack)
{
	while(stack->next)
	{
		if(stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// TO DELETE, DEBUG FUNC
void	print_stack(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	printf("--------Printing stacks------------\n--Stack A --\n");
	while (a != NULL)
	{
		printf("%d - |%d|\n", a->index, a->value);
		a = a->next;
		i++;
	}
	i = 0;
	printf("--Stack B --\n");
	while (b != NULL)
	{
		if(b->target != NULL)
			printf("%d - |%d| target: %d push_price: %d\n", b->index, b->value, b->target->value, b->price);
		else {
			printf("%d - |%d| no target\n", b->index, b->value);
		}
		b = b->next;
		i++;
	}
}
