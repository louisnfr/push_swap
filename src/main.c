/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 03:46:17 by lraffin           #+#    #+#             */
/*   Updated: 2021/08/29 17:31:44 by lraffin          ###   ########.fr       */
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
	(void)av;

	if (ac < 2)
		ft_terminate(ERROR);

	t_board *stack;
	init_board(&stack);



	print_board(stack);
	return (0);
}
