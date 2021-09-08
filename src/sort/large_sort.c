/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:34:53 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/08 03:02:16 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_to_b(t_board *stack, t_quart *quart)
{
	get_quartiles(stack->a, quart);
	pb_q2(stack, quart);
}

void	smart_rotate(t_board *stack)
{
	int i;

	i = 0;
	while (stack->a)
	{
		if (stack->a->value == largest(stack->a))
			break ;
		stack->a = stack->a->next;
		i++;
	}
	if (i <= len(stack->a) / 2)
		rrb(stack, 1);
	else
		rb(stack, 1);
}


void	get_max_to_a(t_board *stack)
{
	if (stack->b->value == largest(stack->b))
		pa(stack, 1);
	else
	{
		if (getlast(stack->a)->index + 1 == stack->b->index || stack->b->index == 1)
		{
			pa(stack, 1);
			ra(stack, 1);
		}
		else
		{
			if (where_is(smallest(stack->b), stack->b) == 1)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
			// smart_rotate(stack);
	}
}

void	split_to_a(t_board *stack, t_quart *quart, int size)
{
	get_quartiles(stack->b, quart);
	while (size-- > 0)
	{
		if (len(stack->b) < 13)
			get_max_to_a(stack);
		else
		{
			if (stack->b->value >= quart->q2)
				pa(stack, 1);
			else
			{
				if (stack->a->index + 1 == stack->b->index || stack->b->index == 1)
				{
					pa(stack, 1);
					ra(stack, 1);
				}
				else
					rb(stack, 1);
			}
		}
		// else
		// {
		// 	if (stack->b->value == smallest(stack->b))
		// 	{
		// 		pa(stack, 1);
		// 		ra(stack, 1);
		// 	}
		// 	else if (stack->b->value >= quart->q2)
		// 		pa(stack, 1);
		// 	else
		// 		rb(stack, 1);
		// }
	}
}

int	indx(t_stack *stack, int value, int size)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (-1);
	get_array(stack, array);
	sort_array(array, size);
	i = -1;
	while (++i < size)
		if (array[i] == value)
			return (i);
	return (-1);
	free(array);
}

int	get_size(t_stack *stack, int max)
{
	int	i;

	if (len(stack) == 0)
		return (0);
	i = 0;
	while (stack->value <= max)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

// void	backtrack_split(t_board *stack, int max)
// {
// 	int avg;
// 	int c;
// 	int i;

// 	c = 0;


// 	avg = pw_get_avg_limit(a, limit);
// 	while (ARRAY_DATA(a, a->size - 1) <= limit &&
// 			ARRAY_DATA(a, a->size - 1) != 1)
// 	{
// 		if (ARRAY_DATA(a, a->size - 1) >= avg)
// 		{
// 			pw_rotate(a, b, "ra");
// 			c++;
// 		}
// 		else
// 			pw_push(b, a, "pb");
// 	}
// 	i = -1;
// 	while (++i < c)
// 		if (ARRAY_DATA(b, b->size - 1) != pw_get_max(b))
// 			pw_rev_rotate_r(a, b, "rrr");
// 		else
// 			pw_rev_rotate(a, b, "rra");
// 	if (pw_get_min(b) == ARRAY_DATA(a, 0) + 1 && c > 0)
// 		ft_push_swap(a, b);
// }

void	backtrack(t_board *stack, t_quart *quart, int max)
{
	(void)quart;
	while (stack->a->value <= max && getlast(stack->a)->index != 1)
	{
		if (indx(stack->a, stack->a->value, len(stack->a)) + 1 == getlast(stack->a)->index)
			ra(stack, 1);
		else
			pb(stack, 1);
	}
	printf("min: %d\ndata: %d\n", indx(stack->b, smallest(stack->b), len(stack->b)), stack->a->index + 1);
	// if (indx(stack->b, smallest(stack->b), len(stack->b))
	// 	== stack->a->index + 1)
	// 	push_swap(stack, quart);
}

int	largest_index(t_stack *stack)
{
	int	largest;

	largest = stack->value;
	while (stack)
	{
		if (stack->value > largest)
			largest = stack->value;
		stack = stack->next;
	}
	return (largest);
}

void	push_swap(t_board *stack, t_quart *quart)
{
	int max;

	(void)max;
	printf("size: %d\n", len(stack->b));
	if (len(stack->b) == 0)
		return ;
	max = indx(stack->b, largest(stack->b), len(stack->b));
	// printf("MAX: %d\n", max);
	split_to_a(stack, quart, len(stack->b));
	push_swap(stack, quart);
	while ((stack->a->index
			== getlast(stack->a)->index + 1
			|| getlast(stack->a)->index == 1)
			&& !is_sorted(stack->a))
		ra(stack, 1);
	// if (get_size(stack->a, max) >= 20)
	// 	backtrack_split(stack, max);
	backtrack(stack, quart, max);
}

void	sort_100_500(t_board *stack, t_quart *quart)
{
	if (is_sorted(stack->a))
		return ;
	split_to_b(stack, quart);
	push_swap(stack, quart);
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
