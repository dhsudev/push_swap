/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:53:06 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/06 17:10:31 by ltrevin-         ###   ########.fr       */
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
			exit_checking("Found an arg that is only a sign??");
	}
	// Check if all chars are digits
	while(s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			exit_checking("Found an arg that is NaN")
		i ++;
	}
	if (i == 0)
		return (1);
	return (0);
}


int	not_valid_nums(char **args, int size)
{
	int i;
	int len;
	
	// We start at one to ommit the executor file
	i = 1;
	// Check if all args are valid
	while (i < size)
	{
		if (not_valid_chars(args[i]))
			return ();
		len = ft_strlen(args[i]);

		// Int limits check
		if (len > 11)
			exit_checking("Found an arg that the len is larger than the int limits")
		else if (len == 10) // Max without sign
		{
			if (ft_strncmp(args[i], "2147483647", len) > 0)
				exit("Found an arg greater than max int");
		}
		else if (len == 11) // Max/Min with sign
		{
			if (ft_strncmp(args[i], "+2147483647", len) > 0)
			
		}
		// Try to pass the num to atot

		i ++;
	}
	return (0);
}
