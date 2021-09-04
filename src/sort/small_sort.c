/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:38:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/04 13:13:33 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_2(t_board *stack)
{
	if (!stack)
		terminate(ERROR, stack);
	if (stack->a->value > stack->a->next->value)
		sa(stack);
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
		sa(stack);
	else if (one > two && two < three && one > two)
		ra(stack);
	else if (one < two && two > three && one > three)
		rra(stack);
	else if (one > two && two > three && one > three)
	{
		sa(stack);
		rra(stack);
	}
	else if (one < two && two > three && one < three)
	{
		sa(stack);
		ra(stack);
	}
}

void	prep_4_5(t_board *stack)
{
	int	large;
	int	small;

	large = largest(stack->a);
	small = smallest(stack->a);
	while (!is_on_top(stack->a, small))
		bring_on_top_a(stack, small);
	pb(stack);
	if (len(stack->a) > 3)
	{
		while (!is_on_top(stack->a, large))
			bring_on_top_a(stack, large);
		pb(stack);
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
		pa(stack);
		ra(stack);
	}
	pa(stack);
	if (is_empty(stack->a))
		terminate(ERROR, stack);
	// free_all(stack);
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
}
