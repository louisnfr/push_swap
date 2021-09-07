/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:34:53 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/07 15:17:38 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_100_500(t_board *stack, t_quart *quart)
{
	int	max;
	int	max2;

	get_quartiles(stack->a, quart);
	pb_q2(stack, quart);
	get_quartiles(stack->b, quart);
	max2 = largest(stack->b);
	pa_q2(stack, quart);
	get_quartiles(stack->b, quart);
	max = largest(stack->b);
	pa_q2(stack, quart);
	sort_rest_a(stack);
	ra_sorted_half_on_b(stack, quart->q2, max);
	sort_rest_a(stack);
	while (stack->a->value >= quart->q2 && stack->a->value <= max)
		ra(stack, 1);
	while (stack->a->value >= quart->q3 && stack->a->value <= max2)
		pb(stack, 1);
	get_quartiles(stack->b, quart);
	max2 = largest(stack->b);
	pa_q2(stack, quart);
	get_quartiles(stack->b, quart);
	max = largest(stack->b);
	pa_q2(stack, quart);
	sort_rest_a(stack);
	ra_sorted_half_on_b(stack, quart->q2, max);
	sort_rest_a(stack);
	ra_sorted_half_on_b(stack, quart->q2, max);
	sort_rest_a(stack);
	while (stack->a->value >= quart->q2 && stack->a->value <= max)
		ra(stack, 1);
	while (stack->a->value >= quart->q3 && stack->a->value <= max2)
		pb(stack, 1);
	sort_rest_a(stack);
	while (stack->a->value >= quart->q3 && stack->a->value <= max2)
		ra(stack, 1);
	while (stack->a->value <= max2)
		pb(stack, 1);


	// get_quartiles(stack->b, quart);
	// max = largest(stack->b);
	// pa_q2(stack, quart);
	// sort_rest_a(stack);
	// sort_rest_a(stack);
	// while (stack->a->value >= quart->q2 && stack->a->value <= max)
	// 	ra(stack, 1);
	// while (stack->a->value >= max)
	// 	pb(stack, 1);
	// get_quartiles(stack->b, quart);
	// max = largest(stack->b);
	// half_on_a(stack, quart);
	// sort_rest_a(stack);
	// ra_sorted_half_on_b(stack, quart, max);
	// sort_rest_a(stack);
	// while (stack->a->value >= quart->q2 && stack->a->value <= max)
	// 	ra(stack, 1);


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
