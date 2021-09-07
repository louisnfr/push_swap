/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:34:53 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/07 17:29:42 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_to_b(t_board *stack, t_quart *quart)
{
	get_quartiles(stack->a, quart);
	pb_q2(stack, quart);
}

void	sort_100_500(t_board *stack, t_quart *quart)
{
	int	max;

	(void)max;
	split_to_b(stack, quart);
}

void	large_sort(t_board *stack)
{
	t_quart	*quart;

	quart = malloc(sizeof(t_quart));
	if (!quart)
		return ;
	sort_100_500(stack, quart);
	free(quart);
}
