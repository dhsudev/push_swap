/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:41:32 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/06/21 16:04:24 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
//	t_stack *b;

	a = NULL;
 //	b = NULL;
	// Args checking
	if (argc < 2)
		return (write(1, "ERROR", 5));
	print_stack(a);
	init_stack(argv, argc, a);
}
