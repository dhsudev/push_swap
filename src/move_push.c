/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:57:17 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/09 06:45:38 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*void	push(t_stack **src, t_stack **dest)
{
	t_stack	*node;
	int len;

	len = stack_len(*src);
	if (*src == NULL || src == NULL || len < 1)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (dest && *dest)
	{
		printf(":3\n");
		node->next = *dest;
		node->next->prev = node;
	}
	else
	{
		node->next = NULL;
	}
	*dest = node;
}*/
void	push(t_stack **src, t_stack **dest)
{
	t_stack	*node_to_push;

	if (NULL == *src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
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
