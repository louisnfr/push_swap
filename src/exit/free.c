/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:40:04 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/02 18:44:42 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		stack = stack->next;
		free(tmp);
		tmp = NULL;
		tmp = stack;
	}
	free(stack);
	stack = NULL;
}

void	free_all(t_board *stack)
{
	free_stack(stack->a);
	free_stack(stack->b);
	free(stack);
	stack = NULL;
	exit (EXIT_SUCCESS);
}