/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:41:32 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/04 19:53:38 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <unistd.h>

/*
 * Set the current position of the nodes in the stack
 *	it also calculates the center line and defines
 *	if the node is above it
 */
void	set_index(t_stack *stack)
{
	int	i;
	int center;

	i = 0;
	center = stack_len(stack) / 2;
	while(stack)
	{
		stack->index = i;
		if(i <= center)
			stack->above_center = 1;
		else 
			stack->above_center = 0;
		i++;
		stack = stack -> next;
	}
}
/* Returns a node in a stack which have n as value*/
t_stack *search_node(t_stack *stack, int n)
{
	while(stack)
	{
		if(stack->value == n)
			return stack;
		stack=stack->next;
	}
	return NULL;
}

/*
 * Search the target node from a to b.
 * The target node is the one who is the most near to the node and is smallest, 
 * if there is no node with this conditions, its the smallest
 *
 *
 * TODO: fix it. lua is dumb, she doesnt know how to code
 * */
void	set_target(t_stack *a, t_stack *b)
{
	int goal;
	int best_target;
	t_stack *curr_a;

	while(b)
	{
		curr_a = a;
		goal = b->value;
		best_target = smallest(a);
		while(curr_a)
		{
			if(curr_a->value > goal && goal - curr_a->value < goal -best_target)
				best_target = curr_a->value;	
			curr_a = curr_a->next;
		}
		b->target = search_node(a, best_target);
		b = b->next;
	}
}

/*
 * Inits the nodes of the stacks to make the decision of what to move:
 *	 - sets the index of the node in the stack
 *	 - if its above the half of the stack
 *	 - the target nodes of b from a
 *	 - the cost of move of each node to the correct position in a
 */
void	init_nodes(t_stack 	*a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target(a, b);
	//set_price(a, b);
	//set_cheapest(b);
}

/*
 * Handle a stack bigger than 3, there is more efficient sort with len 5
 * Push all the nodes to b until there is only 3 left and then 
 * inits the nodes with the info needed to decide what to move.
 */
void	big_sort(t_stack **a, t_stack **b)
{
	int	len;
	

	(void)b;
	len = stack_len(*a);
	if(len == 5)
	{
		// handle five
		sort_five(a, b);
	}
	else 
	{
		// Push to b until there are three nodes
		while(len-- > 3)
			pb(a, b, 0);
	}
	sort_three(a);
	//while(*b)
	//{
	print_stack(*a,*b);
	init_nodes(*a, *b);
	//	move(a, b);
	//}

}


int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (write(2, "push_swap: error\n", ft_strlen("push_swap: error\n")));
	init_stack(argv, argc, &a);
	print_stack(a, b);	
	if(!sorted(a))
	{
		if (stack_len(a) == 2)
				sa(&a, 0);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else 
			big_sort(&a, &b);
	}
	print_stack(a, b);
	finish(&a, &b);
	return (0);
}
