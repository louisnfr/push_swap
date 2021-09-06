/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:05:05 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/06 22:29:38 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	terminate(char *error_message, t_board *stack)
{
	ft_putstr_fd(error_message, 2);
	free_all(stack);
	exit(EXIT_FAILURE);
}
