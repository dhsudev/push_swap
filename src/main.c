/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:41:32 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/15 15:25:05 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <unistd.h>

/*
 * Handle a stack bigger than 3,
 * Push all the nodes to b until there is only 3 left and then
 * inits the nodes with the info needed to decide what to move.
 */
void	big_sort(t_stack **a, t_stack **b)
{
	int		len;
	t_stack	*small;

	(void)b;
	len = stack_len(*a);
	while (len-- > 3)
	{
		pb(a, b, 0);
		if ((*b)->above_median)
			rb(b, 0);
	}
	sort_three(a);
	while (*b)
		move(a, b);
	small = search_node(*a, (long)smallest(*a));
	if (small->above_center)
	{
		while (small != *a)
			ra(a, 0);
	}
	else
	{
		while (small != *a)
			rra(a, 0);
	}
}

void	set_above_median_flag(t_stack *head, int median)
{
	t_stack	*current;

	current = head;
	while (current != NULL)
	{
		if (current->value > median)
			current->above_median = 1;
		else
			current->above_median = 0;
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (write(2, "Error\n", 6));
	init_stack(argv, argc, &a);
	set_above_median_flag(a, find_median(a, stack_len(a)));
	if (!sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 0);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			big_sort(&a, &b);
	}
	finish(&a, &b);
	return (0);
}
