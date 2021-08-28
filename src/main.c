/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 03:46:17 by lraffin           #+#    #+#             */
/*   Updated: 2021/08/28 22:42:37 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	(void)av;

	if (ac < 2)
		ft_terminate(ERROR);
	// ft_fill_stack(av);

	t_stack *a;
	
	a = malloc(sizeof(t_stack));
	if (!a)
		ft_terminate(MALLOC);
	a->value = 12;
	a->next = NULL;

	// t_stack *b;

	addback(&a, new_cell(42));
	addback(&a, new_cell(24));
	print_stack(a);

	return (0);
}
