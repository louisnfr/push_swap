/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:26:38 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/06 22:29:45 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_board	*init_board(void)
{
	t_board	*stack;

	stack = malloc(sizeof(t_board));
	if (!stack)
		terminate(MALLOC, stack);
	stack->a = NULL;
	stack->b = NULL;
	stack->moves = 0;
	stack->length = 0;
	return (stack);
}
