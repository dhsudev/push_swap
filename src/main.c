/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:41:32 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/11 14:37:17 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <unistd.h>

/*
 * Rotate both stack to optimize the moves.
 * Reverse is a flag to know if it's need a reverse or a normal rotate
 */
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest, int reverse)
{
	while (*a != cheapest->target && *b != cheapest)
	{
		// printf("Hola\n");
		if (reverse)
			rrr(a, b, 0);
		else
			rr(a, b, 0);
	}
	set_index(*a);
	set_index(*b);
}

void	top_targets(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	// printf("HOLAAAA\n");
	cheapest = search_node(*b, (long)cheapest_value(*b));
	if (cheapest->above_center && cheapest->target->above_center)
		rotate_both(a, b, cheapest, 0);
	else if (!cheapest->above_center && !cheapest->target->above_center)
		rotate_both(a, b, cheapest, 1);
	while (*a != cheapest->target)
	{
		// printf("T^T %d |||||||||||||||| %d\n", cheapest->target->value,(*a)->value);
		if (cheapest->target->above_center)
			ra(a, 0);
		else
			rra(a, 0);
	}
	while (*b != cheapest)
	{
		if (cheapest->above_center)
			rb(b, 0);
		else
			rrb(b, 0);
	}
	pa(a, b, 0);
}

void	move(t_stack **a, t_stack **b)
{
	top_targets(a, b);
	set_index(*a);
	set_index(*b);
}

/*
 * Handle a stack bigger than 3, there is more efficient sort with len 5
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
		if((*b)->above_median)
			rb(b, 0);
	}
	// print_stack(*a,*b);
	sort_three(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move(a, b);
		// print_stack(*a, *b);
	}
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

void set_above_median_flag(t_stack *head, int median) {
    t_stack *current = head;
    while (current != NULL) {
        current->above_median = current->value > median ? 1 : 0;
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
//	print_stack(a, b);
	if (!sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 0);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			big_sort(&a, &b);
	}
	// printf("======== END OF THE PROGRAM ==========\n");
	// print_stack(a, b);
	finish(&a, &b);
	return (0);
}
