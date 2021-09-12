/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:20:55 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/13 00:04:48 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_4_5(t_board *stack)
{
	bring_a_push_b(stack, smallest(stack->a));
	if (len(stack->a) > 3)
		bring_a_push_b(stack, largest(stack->a));
}
