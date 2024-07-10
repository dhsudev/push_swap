/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:57:59 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/09 06:53:34 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*void	reverse_rotate(t_stack **stack)
{
	int len;
	t_stack	*bot;
	t_stack	*tmp;

	len = stack_len(*stack);
	if (stack == NULL || *stack == NULL || len < 2)
		return ;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	bot = tmp;
	bot->prev->next = NULL;
	bot->next = *stack;
	(*stack)->prev = bot;
	*stack = bot;
	*tmp = *stack;
	while (tmp->next)
	{
		printf("|||%i|||\n", tmp->value);
		tmp = tmp->next;
	}
}*/
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	int				len;

	len = stack_len(*stack);
	if (NULL == *stack || NULL == stack || 1 == len)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}
void	rra(t_stack **a, int checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
