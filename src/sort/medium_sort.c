/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:29:59 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/06 19:44:38 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	get_quartiles(t_stack *stack, t_quart *quart)
{
	int		*array;

	array = malloc(sizeof(int) * len(stack));
	if (!array)
		return (free(array));
	get_array(stack, array);
	sort_array(array, len(stack));
	if (len(stack) % 2 == 0)
	{
		quart->q1 = (array[(len(stack) * 1 / 4)]
				+ array[(len(stack) - 1) * 1 / 4]) / 2;
		quart->q2 = (array[(len(stack) * 2 / 4)]
				+ array[(len(stack) - 1) * 2 / 4]) / 2;
		quart->q3 = (array[(len(stack) * 3 / 4)]
				+ array[(len(stack) - 1) * 3 / 4]) / 2;
	}
	else
	{
		quart->q1 = array[len(stack) * 1 / 4];
		quart->q2 = array[len(stack) * 2 / 4];
		quart->q3 = array[len(stack) * 3 / 4];
	}
	free(array);
}

void	sort_5_100(t_board *stack, t_quart *quart)
{
	int	max;

	get_quartiles(stack->a, quart);
	pb_q2(stack, quart);
	get_quartiles(stack->b, quart);
	max = largest(stack->b);
	half_on_a(stack, quart);
	sort_rest_a(stack);
	ra_sorted_half_on_b(stack, quart, max);
	sort_rest_a(stack);
	while (stack->a->value >= quart->q2 && stack->a->value <= max)
		ra(stack);
	while (stack->a->value >= max)
		pb(stack);
	get_quartiles(stack->b, quart);
	max = largest(stack->b);
	half_on_a(stack, quart);
	sort_rest_a(stack);
	ra_sorted_half_on_b(stack, quart, max);
	sort_rest_a(stack);
	while (stack->a->value >= quart->q2 && stack->a->value <= max)
		ra(stack);
}

void	medium_sort(t_board *stack)
{
	t_quart	*quart;

	quart = malloc(sizeof(t_quart));
	if (!quart)
		return ;
	sort_5_100(stack, quart);
	free(quart);
}
/*
divise le bloc en deux pb_q2()
calcul quartiles de B
plus grande moitie sur pa
on tri le reste en remettant sur a
on envoie la partie triee en bas
on recupere sur b la plus grande moitie
on tri le reste en remettant sur a
envoie la partie triee en bas
on envoie le deuxieme bloc
plus grande moitie sur pa
on tri le reste en remettant sur a
on envoie la partie triee en bas
on recupere sur b la plus grande moitie
on tri le reste en remettant sur a
envoie la partie triee en bas
 */
