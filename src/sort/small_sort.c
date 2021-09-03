/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .c                                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:38:31 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/03 16:52:27 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_3(t_board *stack)
{
	int				one;
	int				two;
	int				three;

	if (!stack)
		terminate(ERROR, stack);
	one = stack->a->value;
	two = stack->a->next->value;
	three = stack->a->next->next->value;
	if (one > two && two < three && one < three)
		sa(stack);
	else if (one > two && two > three && one > three)
	{
		sa(stack);
		rra(stack);
	}
	else if (one > two && two < three && one > two)
		ra(stack);
	else if (one < two && two > three && one < three)
	{
		sa(stack);
		ra(stack);
	}
	else if (one < two && two > three && one > three)
		rra(stack);
}
