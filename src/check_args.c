/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:10:56 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/05/20 19:16:25 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return ((int) c);
	return (0);
}
int	protected_atoi(const char *str)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
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
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
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
			return (1);
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