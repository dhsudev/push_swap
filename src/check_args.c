/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:53:06 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/02 17:05:13 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exit_checking(char *error)
{
	//printf("ERROR: %s", error);
	(void) error;
	write(1,"error\n",6);
	exit(1);
}

int	search_dup(t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next;
		i++;
	}
	return (0);
}

int	not_valid_chars(char *s)
{
	int	i;

	i = 0;
	// Check sign
	if (s[i] == '+' || s[i] == '-')
	{
		i++;
		if (s[i] == '\0')
			exit_checking("Found a number outside int limits");
	}
	// Check if all chars are digits
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	if (i == 0)
		return (1);
	return (0);
}

int	init_stack(char **args, int size, t_stack **stack)
{
	int		i;
	long	n;

	// We start at one to ommit the executor file
	i = 1;
	// Check if all args are valid
	while (i < size)
	{
		if (not_valid_chars(args[i]))
			exit_checking("Found something that is not a number");
		n = ft_atol(args[i]);
		if (n > INT_MAX || n < INT_MIN)
			exit_checking("Found a number outside limits");
		if (search_dup(*stack, (int)n))
			exit_checking("Duplicate numbers");
		add_to_stack(stack, (int)n);
		i++;
	}
	return (0);
}

void	finish(t_stack **a, t_stack **b)
{
	t_stack	*node;

	while (*a)
	{
		node = *a;
		*a = (*a)->next;
		free(node);
	}
	while (*b)
	{
		node = *b;
		*b = (*b)->next;
		free(node);
	}
	exit(0);
}
