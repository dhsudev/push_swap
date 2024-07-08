/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:41:32 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/08 13:55:46 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <unistd.h>

void move(t_stack **a, t_stack **b)
{
	pa(a,b, 0);
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
	while(*b)
	{
		//print_stack(*a,*b);
		init_nodes(*a, *b);
		print_stack(*a, *b);
		move(a, b);
	}

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
	printf("======== END OF THE PROGRAM ==========\n");
	print_stack(a, b);
	finish(&a, &b);
	return (0);
}
