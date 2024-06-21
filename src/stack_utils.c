/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:44:55 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/06/21 16:09:47 by ltrevin-         ###   ########.fr       */
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
