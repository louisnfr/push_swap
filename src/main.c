/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 03:46:17 by lraffin           #+#    #+#             */
/*   Updated: 2021/08/29 17:33:29 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_board(t_board **stack)
{
	*stack = malloc(sizeof(t_board));
	if (!(*stack))
		ft_terminate(MALLOC);
	(*stack)->a = NULL;
	(*stack)->b = NULL;
}

int	main(int ac, char **av)
{
	t_board	*stack;

	check_input(ac, av);
	init_board(&stack);
	print_board(stack);
	return (0);
}
