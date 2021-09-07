/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:38:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/07 21:25:48 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_board *stack)
{
	if (!stack)
		terminate(ERROR, stack);
	if (stack->a->value > stack->a->next->value)
		sa(stack, 1);
}

void	sort_3(t_board *stack)
{
	int	one;
	int	two;
	int	three;

	if (!stack)
		terminate(ERROR, stack);
	one = stack->a->value;
	two = stack->a->next->value;
	three = stack->a->next->next->value;
	if (one > two && two < three && one < three)
		sa(stack, 1);
	else if (one > two && two < three && one > two)
		ra(stack, 1);
	else if (one < two && two > three && one > three)
		rra(stack, 1);
	else if (one > two && two > three && one > three)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (one < two && two > three && one < three)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
}

void	sort_4_5(t_board *stack)
{
	int	s_len;

	s_len = len(stack->a);
	prep_4_5(stack);
	sort_3(stack);
	if (s_len == 5)
	{
		pa(stack, 1);
		ra(stack, 1);
	}
	pa(stack, 1);
	if (is_empty(stack->a))
		terminate(ERROR, stack);
}

void	sort_20(t_board *stack)
{
	t_quart	*quart;
	int		max;

	quart = malloc(sizeof(t_quart));
	if (!quart)
		return ;
	get_quartiles(stack->a, quart);
	pb_q2(stack, quart);
	get_quartiles(stack->b, quart);
	max = largest(stack->b);
	while (stack->b && !is_empty(stack->b))
	{
		bring_b_push_a(stack, smallest(stack->b));
		ra(stack, 1);
	}
	while (stack->a->value <= max)
		ra(stack, 1);
	while (stack->a->value >= max)
		pb(stack, 1);
	while (stack->b && !is_empty(stack->b))
	{
		bring_b_push_a(stack, smallest(stack->b));
		ra(stack, 1);
	}
	free(quart);
}

void	small_sort(t_board *stack)
{
	if (stack->length <= 1)
		free_all(stack);
	else if (stack->length == 2)
		sort_2(stack);
	else if (stack->length == 3)
		sort_3(stack);
	else if (stack->length <= 5)
		sort_4_5(stack);
	else
		sort_20(stack);
}

