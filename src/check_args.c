/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:53:06 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/01 13:20:04 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void exit_checking(char *error)
{
	printf("ERROR: %s", error);
	//write(1,"error\n",6);
	exit(1);
}

int	not_valid_chars(char *s)
{
	int i;

	i = 0;
	// Check sign
	if (s[i] == '+' || s[i] == '-')
	{
		i ++;
		if (s[i] == '\0')
		exit_checking("Found a number outside int limits");
	}
	// Check if all chars are digits
	while(s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i ++;
	}
	if (i == 0)
		return (1);
	return (0);
}


int	init_stack(char **args, int size, t_stack *stack)
{
	int		i;
	long	n;
	//int nums[nums-1];
	
	// We start at one to ommit the executor file
	i = 1;
	// Check if all args are valid
	while (i < size)
	{
		if (not_valid_chars(args[i]))
			exit_checking("Found something that is not a number");
		n = ft_atol(args[i]);
		if(n > INT_MAX || n < INT_MIN)
			exit_checking("Found a number outside limits");
		(void)stack;
		add_to_stack(&stack, (int)n);
		//nums[i-1] = ft_atoi(args[i]); 
		i ++;
	}
	return (0);
}
