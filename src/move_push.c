/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:57:17 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/04 15:15:13 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*node;

	if (!src)
		return ;
	node = *src;
	*src = node->next;
	(*src)->prev = NULL;
	if (dest && *dest)
	{
		node->next = *dest;
		(*dest)->prev = node;
	}
	else
		node->next = NULL;
	*dest = node;
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
