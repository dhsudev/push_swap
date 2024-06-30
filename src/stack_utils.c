/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:44:55 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/06/30 18:41:56 by ltrevin-         ###   ########.fr       */
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

void add_to_stack(t_stack **stack, int n)
{
	t_stack	*last;
	t_stack *new;
	
	last = last_node(*stack);
	new = malloc(sizeof(t_stack));
	new->value = n;
	new->next = NULL;
	if(last)
	{
		new->prev = last;
		last->next = new;
	}
	else 
		*stack = new;
}

void print_stack(t_stack *stack)
{
	int i = 0;
	printf("Current status of the stack:\n");
	while(stack != NULL)
	{
		printf("%d - |%d|\n", i, stack->value);
		stack = stack->next;
		i++;
	}
}

int	search_dup(t_stack *stack, int n)
{
	int i = 0;
	while(stack != NULL)
	{
		if(stack->value == n)
			return 1;
		stack = stack->next;
		i++;
	}
	return 0;
}
