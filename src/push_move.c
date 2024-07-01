/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:34:47 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/01 14:23:38 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void push(t_stack **src, t_stack **dest)
{
	t_stack	*node;

	if(!src)
		return ;
	node = *src;
	// Put the second node to fisrt
	*src = node->next;
	(*src)->prev = NULL;
	write(1,"A\n",2);
	// Link node to the dest
	if(dest)
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
	if(!checker)
		write(1,"pa\n",3);
}

void	pb(t_stack **a, t_stack **b, int checker)
{
	push(a, b);
	if(!checker)
		write(1,"pb\n",3);
}
