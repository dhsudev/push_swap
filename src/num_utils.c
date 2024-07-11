/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:07:31 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/11 14:29:36 by ltrevin-         ###   ########.fr       */
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
	while (stack)
	{
		if (stack->cheapest)
			return (stack->value);
		stack = stack->next;
	}
	return (0);
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

int	count_elements(t_stack *head, int value, int count_smallest)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = head;
	while (current != NULL)
	{
		if (count_smallest)
		{
			if (current->value < value)
				count++;
		}
		else
		{
			if (current->value > value)
				count++;
		}
		current = current->next;
	}
	return (count);
}

int	find_median(t_stack *head, int size)
{
	t_stack	*current;
	int		median_position;

	current = head;
	median_position = (size - 1) / 2;
	int count_smaller, count_greater;
	while (current != NULL)
	{
		count_smaller = count_elements(head, current->value, 1);
		count_greater = count_elements(head, current->value, 0);
		if (count_smaller == median_position && count_greater == size / 2)
			return (current->value);
		current = current->next;
	}
	return (-1); // Should never reach here if input is valid
}
