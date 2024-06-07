/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:18:30 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/05/25 12:55:00 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h>

void exit_checking(char *error)
{
	printf("ERROR: %s", error);
	//write(1,"error\n",6);
	exit(1);
}

int	protected_atoi(const char *str)
{
	long	n;
	int	sign;
	int	i;

	n = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i ++;
	}
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (INT_MIN > n || n > INT_MAX)
		exit_checking("Found a number outside int limits");
	return ((int)n * sign);
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


int	not_valid_nums(char **args, int size)
{
	int i;
	//int nums[nums-1];
	
	// We start at one to ommit the executor file
	i = 1;
	// Check if all args are valid
	while (i < size)
	{
		if (not_valid_chars(args[i]))
			return (1);
		//printf("%d\n", protected_atoi(args[i]));
		//nums[i-1] = ft_atoi(args[i]); 
		i ++;
	}
	return (0);
}