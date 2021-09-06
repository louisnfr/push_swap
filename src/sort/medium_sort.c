/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:29:59 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/06 19:00:04 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	get_quartiles(t_stack *stack, t_quart *quart)
{
	int		*array;

	array = malloc(sizeof(int) * len(stack));
	if (!array)
	{
		free(array);
		return ;
	}
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

void	sort_5_100(t_board *stack)
{
	t_quart	*quart;
	int		max_b;

	quart = malloc(sizeof(t_quart));
	if (!quart)
		return ;

	get_quartiles(stack->a, quart);

	// divise le bloc en deux
	while (smallest(stack->a) <= quart->q2)
	{
		if (stack->a->value <= quart->q2)
			pb(stack);
		else
			ra(stack);
	}

	// calcul quartiles de B
	get_quartiles(stack->b, quart);
	max_b = largest(stack->b);

	// plus grande moitie sur pa
	while (largest(stack->b) >= quart->q2)
	{
		if (stack->b->value == smallest(stack->b))
		{
			pa(stack);
			ra(stack);
		}
		else if (stack->b->value >= quart->q2)
			pa(stack);
		else
			rb(stack);
	}
	// on tri le reste en remettant sur a
	while (stack->b && !is_empty(stack->b))
	{
		if (stack->b->value == smallest(stack->b))
		{
			pa(stack);
			ra(stack);
		}
		else if (stack->b->value == largest(stack->b))
			pa(stack);
		else
			rb(stack);
	}

	// on envoie la partie triee en bas
	while (stack->a->value <= quart->q2)
		ra(stack);
	// on recupere sur b la plus grande moitie
	while (stack->a->value >= quart->q2 && stack->a->value <= max_b)
		pb(stack);

	// on tri le reste en remettant sur a
	while (stack->b && !is_empty(stack->b))
	{
		if (stack->b->value == smallest(stack->b))
		{
			pa(stack);
			ra(stack);
		}
		else if (stack->b->value == largest(stack->b))
			pa(stack);
		else
			rb(stack);
	}
	// envoie la partie triee en bas
	while (stack->a->value >= quart->q2 && stack->a->value <= max_b)
		ra(stack);

	//on envoie le deuxieme bloc
	while (stack->a->value >= max_b)
		pb(stack);

	get_quartiles(stack->b, quart);
	max_b = largest(stack->b);

	// plus grande moitie sur pa
	while (largest(stack->b) >= quart->q2)
	{
		if (stack->b->value == smallest(stack->b))
		{
			pa(stack);
			ra(stack);
		}
		else if (stack->b->value >= quart->q2)
			pa(stack);
		else
			rb(stack);
	}
	// on tri le reste en remettant sur a
	while (stack->b && !is_empty(stack->b))
	{
		if (stack->b->value == smallest(stack->b))
		{
			pa(stack);
			ra(stack);
		}
		else if (stack->b->value == largest(stack->b))
			pa(stack);
		else
			rb(stack);
	}
	// on envoie la partie triee en bas
	while (stack->a->value <= quart->q2)
		ra(stack);
	// on recupere sur b la plus grande moitie
	while (stack->a->value >= quart->q2 && stack->a->value <= max_b)
		pb(stack);

	// on tri le reste en remettant sur a
	while (stack->b && !is_empty(stack->b))
	{
		if (stack->b->value == smallest(stack->b))
		{
			pa(stack);
			ra(stack);
		}
		else if (stack->b->value == largest(stack->b))
			pa(stack);
		else
			rb(stack);
	}
	// envoie la partie triee en bas
	while (stack->a->value >= quart->q2 && stack->a->value <= max_b)
		ra(stack);

	free(quart);
}

void	medium_sort(t_board *stack)
{
	sort_5_100(stack);
}
