/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:41:32 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/03 19:26:07 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (write(2, "push_swap: error\n", ft_strlen("push_swap: error\n")));
	init_stack(argv, argc, &a);
	// add_to_stack(&b, 9);
	// add_to_stack(&b, 1);
	// print_stack(a, b);
	// Two nums
	if (stack_len(a) == 2)
	{
		if (a->value > a->next->value)
			sa(&a, 0);
	}
	else if (stack_len(a) == 3)
		sort_three(&a);
	// print_stack(a, b);
	// printf("Smallest in a: %d\n", stack_len(a));
	// printf("Smallest in b: %d\n", stack_len(b));
	finish(&a, &b);
	return (0);
}
