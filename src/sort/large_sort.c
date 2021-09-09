/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:34:53 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/09 03:36:39 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_avg(t_stack *stack)
{
	t_stack *head;
	float	total;
	int		size;
	int		i;

	if (len(stack) == 0)
		return (0);
	head = stack;
	total = 0;
	size = len(stack);
	i = 0;
	while (stack)
	{
		total += (stack->index);
		stack = stack->next;
		i++;
	}
	stack = head;
	return ((int)(total / (int)size + 0.5));
}

void	split_to_b(t_board *stack, t_quart *quart)
{
	(void)quart;

	int avg;
	int size;

	avg = get_avg(stack->a);
	size = len(stack->a);
	while (size-- > 0)
	{
		if (stack->a->index < avg)
			pb(stack, 1);
		else
			ra(stack, 1);
	}
}

void	smart_rotate(t_board *stack)
{
	t_stack *head;
	int i;
	int size;

	head = stack->b;
	size = len(stack->b);
	i = 0;
	// print_board_index(stack);
	stack->b = getlast(stack->b);
	// printf("size: %d\n", size);
	while (i < size)
	{
		// printf("%d < %d\n", i, size);
		// printf("-----%d == %d\n", stack->b->index, largest_index(stack->b));
		if (stack->b->index == largest_index(stack->b))
		{
			// printf("break (%d == %d)\n", stack->b->index, largest_index(stack->b));
			break ;
		}
		stack->b = stack->b->previous;
		i++;
	}
	// printf("%d <= %d\n", i, (int)(size / 2));
	stack->b = head;
	if (i <= (int)(size / 2))
		rrb(stack, 1);
	else
		rb(stack, 1);
}


void	get_max_to_a(t_board *stack)
{
	// printf("%d == %d\n", stack->b->index, largest_index(stack->b));
	if (stack->b->index == largest_index(stack->b))
		pa(stack, 1);
	else
	{
		if (getlast(stack->a)->index + 1 == stack->b->index || stack->b->index == 1)
		{
			pa(stack, 1);
			ra(stack, 1);
		}
		else
			smart_rotate(stack);
	}
}

void	split_to_a(t_board *stack, int avg, int size)
{
	while (size-- > 0)
	{
		// print_board_index(stack);
		if (len(stack->b) < 13)
		{
			// bring_b_push_a(stack, largest(stack->b));
			get_max_to_a(stack);
		}
		else
		{
			if (stack->b->index >= avg)
				pa(stack, 1);
			else
			{
				if (getlast(stack->a)->index + 1 == stack->b->index || stack->b->index == 1)
				{
					pa(stack, 1);
					ra(stack, 1);
				}
				else
					rb(stack, 1);
			}
		}
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
	t_stack *head;
	int	i;

	head = stack;
	if (len(stack) == 0)
		return (0);
	i = 0;
	while (stack->value <= max)
	{
		i++;
		stack = stack->next;
	}
	stack = head;
	return (i);
}

void	backtrack_split(t_board *stack, int max)
{
	int avg;
	int c;
	int i;

	c = 0;


	avg = pw_get_avg_limit(a, limit);
	while (ARRAY_DATA(a, a->size - 1) <= limit &&
			ARRAY_DATA(a, a->size - 1) != 1)
	{
		if (ARRAY_DATA(a, a->size - 1) >= avg)
		{
			pw_rotate(a, b, "ra");
			c++;
		}
		else
			pw_push(b, a, "pb");
	}
	i = -1;
	while (++i < c)
		if (ARRAY_DATA(b, b->size - 1) != pw_get_max(b))
			pw_rev_rotate_r(a, b, "rrr");
		else
			pw_rev_rotate(a, b, "rra");
	if (pw_get_min(b) == ARRAY_DATA(a, 0) + 1 && c > 0)
		ft_push_swap(a, b);
}

void	backtrack(t_board *stack, int max)
{
	while (stack->a->index <= max && stack->a->index != 1)
	{
		if (getlast(stack->a)->index + 1 == stack->a->index)
			ra(stack, 1);
		else
			pb(stack, 1);
	}
	if (smallest_index(stack->b) == getlast(stack->a)->index + 1)
		push_swap(stack);
}

int	largest_index(t_stack *stack)
{
	int	largest;

	if (len(stack) == 0)
		return (0);
	largest = stack->index;
	while (stack)
	{
		if (stack->index > largest)
			largest = stack->index;
		stack = stack->next;
	}
	return (largest);
}

int	smallest_index(t_stack *stack)
{
	int	smallest;

	if (len(stack) == 0)
		return (0);
	smallest = stack->index;
	while (stack)
	{
		if (stack->index < smallest)
			smallest = stack->index;
		stack = stack->next;
	}
	return (smallest);
}

void	push_swap(t_board *stack)
{
	int max;

	(void)max;
	if (len(stack->b) == 0)
		return ;
	max = largest_index(stack->b);
	// printf("max: %d\n", max);
	split_to_a(stack, get_avg(stack->b), len(stack->b));
	// print_board_index(stack);
	// printf("while %d == %d || %d == 1\n", stack->a->index, getlast(stack->a)->index + 1, stack->a->index);
	while ((stack->a->index
			== getlast(stack->a)->index + 1
			|| stack->a->index == 1)
			&& !is_sorted(stack->a))
		ra(stack, 1);
	push_swap(stack);
	if (get_size(stack->a, max) >= 20)
		backtrack_split(stack, max);
	backtrack(stack, max);
}

void	sort_100_500(t_board *stack, t_quart *quart)
{
	if (is_sorted(stack->a))
		return ;
	split_to_b(stack, quart);

	push_swap(stack);
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
