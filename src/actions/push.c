/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:47:56 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/02 17:00:22 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// t_stack	*push(t_stack *stack)
// {
// 	t_stack	*tmp;

// 	if (!stack->b)
// 		return ;
// 	write(1, "pa\n", 3);
// 	tmp = stack->b;
// 	if (stack->a && stack->b)
// 	{
// 		stack->b = stack->b->next;
// 		tmp->next = stack->a;
// 		stack->a = tmp;
// 	}
// 	else if (stack->b && !stack->a)
// 	{
// 		stack->b = stack->b->next;
// 		tmp->next = NULL;
// 		stack->a = tmp;
// 	}
// }

void	pa(t_board *stack)
{
	t_stack	*tmp;

	if (!stack->b)
		return ;
	write(1, "pa\n", 3);
	tmp = stack->b;
	if (stack->a && stack->b)
	{
		stack->b = stack->b->next;
		tmp->next = stack->a;
		stack->a = tmp;
	}
	else if (stack->b && !stack->a)
	{
		stack->b = stack->b->next;
		tmp->next = NULL;
		stack->a = tmp;
	}
}

void	pb(t_board *stack)
{
	t_stack	*tmp;

	if (!stack->a)
		return ;
	write(1, "pb\n", 3);
	tmp = stack->a;
	if (stack->a && stack->b)
	{
		stack->a = stack->a->next;
		tmp->next = stack->b;
		stack->b = tmp;
	}
	else if (stack->a && !stack->b)
	{
		stack->a = stack->a->next;
		tmp->next = NULL;
		stack->b = tmp;
	}
}
