/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:53:06 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/03 19:23:29 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	finish(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if(a == 0 || b == 0)
		return ;
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

void	exit_checking(t_stack **stack)
{
	write(1,"Error\n",6);
	finish(stack, NULL);
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
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
			|| s[i] == '\r' || s[i] == '\v' || s[i] == '\f'))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		i++;
		if (s[i] == '\0')
			return(1);
	}
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

	i = 1;
	while (i < size)
	{
		if (not_valid_chars(args[i]))
			exit_checking(stack);
		n = ft_atol(args[i]);
		if (n > INT_MAX || n < INT_MIN)
			exit_checking(stack);
		if (search_dup(*stack, (int)n))
			exit_checking(stack);
		add_to_stack(stack, (int)n);
		i++;
	}
	return (0);
}
