/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:07:31 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/09 06:52:00 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 *  atol, i need it to check eventual overflows
 *  converting every string into a long value
 */
long	ft_atol(char *str)
{
	long	n;
	int		sign;
	int		i;

	n = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * sign);
}


/* Returns the values of the node flagged as cheapest*/
int	cheapest_value(t_stack *stack)
{
	while(stack)
	{
		if(stack->cheapest)
			return (stack->value);
		stack = stack->next;
	}
	return 0;
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
