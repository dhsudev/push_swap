/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:57:17 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/08 21:36:19 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*node;

	printf("Empezando push..\n");
	if (*src == NULL)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (dest && *dest)
	{
		node->next = *dest;
		node->next->prev = node;
	}
	else
	{
		node->next = NULL;
	}
	*dest = node;
	printf("Acabao.\n");
}

void	pa(t_stack **a, t_stack **b, int checker)
{
	push(b, a);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int checker)
{
	push(a, b);
	if (!checker)
		write(1, "pb\n", 3);
}
