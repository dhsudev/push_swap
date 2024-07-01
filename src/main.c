/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:41:32 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/07/01 16:09:37 by ltrevin-         ###   ########.fr       */
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
		return (write(1, "ERROR", 5));
	init_stack(argv, argc, &a);
	add_to_stack(&b, 9);
	add_to_stack(&b, 1);
	print_stack(a, b);
	rrr(&a, &b, 0);
	print_stack(a, b);
	finish(&a, &b);
}
