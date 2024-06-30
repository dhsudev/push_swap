/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:41:32 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/06/30 19:07:23 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
//	t_stack *b;

	a = NULL;
	// Args checking
	if (argc < 2)
		return (write(1, "ERROR", 5));
	init_stack(argv, argc, &a);
	(void) argv;
	print_stack(a);
	sa(&a);
	print_stack(a);
}
