/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltrevin- <ltrevin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:41:32 by ltrevin-          #+#    #+#             */
/*   Updated: 2024/05/18 19:35:50 by ltrevin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/push_swap.h"


int	main(int argc, char **argv)
{

	if (argc != 2 || not_valid_nums(argv[1]))
		return (write (1, "ERROR", 5));

}