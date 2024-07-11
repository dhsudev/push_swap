/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:44:55 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/11 14:34:49 by ltrevin-         ###   ########.fr       */
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
	{
		*stack = new;
		(*stack)->prev = NULL;
	}
}


t_stack	*find_last_node(t_stack *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
int	stack_len(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
	//	printf("Estoy en count:::::::::%i", count);
		count++;
		stack = stack->next;
	}
	return (count);
}

int	sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
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
		printf("%d - |%d| flag: %d\n", i, a->value, a->above_median);
		a = a->next;
		i++;
	}
	i = 0;
	printf("--Stack B --\n");
	while (b != NULL && i < 10)
	{
		if (b->target != NULL)
			printf("%d - |%d| target: %d push_price: %d\n", i, b->value,
				b->target->value, b->price);
		else
		{
			printf("%d - |%d| no target\n", i, b->value);
		}
		b = b->next;
		i++;
	}
}
