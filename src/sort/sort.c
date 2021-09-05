/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:29:59 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/05 15:23:55 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
get stack into array
sort array
get index


*/

void	sort_array(int *array, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (array[i] > array[i + 1])
		{
			ft_swap(&array[i], &array[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

void	sort(t_board *stack)
{
	// store stack into array
	int array[stack->length];
	t_stack	*head;
	int i;
	int key;

	head = stack->a;
	i = 0;
	key = stack->length / 4;
	(void)key;
	while (stack->a)
	{
		array[i] = stack->a->value;
		stack->a = stack->a->next;
		i++;
	}
	stack->a = head;

	// sort array
	sort_array(array, stack->length);

	// print array
	for (i=0; i<stack->length;i++)
		printf("%d ", array[i]);
	// i = -1;
	// while (len(stack->b) < key)
	// 	if (stack->a->value <= key)
	// 		pb(stack);
	// 	else
	// 		ra(stack);
	int q1 = array[stack->length / 4];
	int q2 = array[stack->length * 2 / 4];
	int q3 = array[q1 * 2];
	printf("\n\nq1: %d\nq2: %d\nq3: %d\n", q1, q2, q3);
}
