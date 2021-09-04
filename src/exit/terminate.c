/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:05:05 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/04 13:15:20 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	terminate(char *error_message, t_board *stack)
{
	ft_putstr_fd(error_message, 2);
	free_all(stack);
	exit(EXIT_FAILURE);
}
