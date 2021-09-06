/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:35:36 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/06 22:30:42 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	get_array(t_stack *stack, int *array)
{
	int	i;

	i = 0;
	while (stack)
	{
		array[i] = stack->value;
		stack = stack->next;
		i++;
	}
}
