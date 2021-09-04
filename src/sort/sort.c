/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:29:59 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/04 17:07:19 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort(t_board *stack)
{
	while (!is_empty(stack->a))
		pb(stack);
	while (!is_empty(stack->b))
	{
		bring_on_top_b(stack, largest(stack->b));
		pa(stack);
	}
}
