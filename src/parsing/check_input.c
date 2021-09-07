/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 20:08:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/08 00:33:54 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args(char **av)
{
	int	i;

	i = 0;
	while (av && av[i])
		i++;
	return (i);
}

int	check_arg(char *av)
{
	int	i;

	if (ft_strcmp(av, "-") == 0 || ft_strcmp(av, "+") == 0)
		return (0);
	if (av[0] == '-' || av[0] == '+')
		i = 0;
	else
		i = -1;
	while (av[++i])
		if (!ft_isdigit(av[i]))
			return (0);
	return (1);
}

void	parse_args(t_board *stack, char **av)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (av[++i])
	{
		if (empty_string(av[i]))
			terminate(ERROR, stack);
		count = 0;
		j = 0;
		if (!check_arg(av[i]))
			terminate(ERROR, stack);
		while (av[++j])
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				count++;
		if (count != 1 || ft_atol(av[i]) > 2147483647
			|| ft_atol(av[i]) < -2147483648)
			terminate(ERROR, stack);
		addback(&stack->a, new_cell(ft_atoi(av[i])));
		stack->length++;
	}
}

void	parse_string(t_board *stack, char **av)
{
	char	**args;
	int		count;
	int		i;
	int		j;

	args = ft_split(av[1], ' ');
	i = -1;
	while (args[++i])
	{
		count = 0;
		j = -1;
		while (args[++j])
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				count++;
		if (!check_arg(args[i]) || count != 1
			|| ft_atol(args[i]) > 2147483647
			|| ft_atol(args[i]) < -2147483648)
		{
			free_split(args, count_args(args));
			terminate(ERROR, stack);
		}
		addback(&stack->a, new_cell(ft_atoi(args[i])));
		stack->length++;
	}
	free_split(args, count_args(args));
}

void	fill_indexes(t_stack *stack)
{
	t_stack *head;
	int	*array;
	int	size;
	int	i;

	head = stack;
	size = len(stack);
	array = malloc(sizeof(int) * size);
	if (!array)
		return ;
	get_array(stack, array);
	sort_array(array, size);
	i = -1;
	while (++i < size)
	{
		while (stack)
		{
			if (stack->value == array[i])
				stack->index = i + 1;
			stack = stack->next;
		}
		stack = head;
	}
	free(array);
}

void	check_input(int ac, char **av, t_board *stack)
{
	if (ac < 2)
		terminate("", stack);
	if (ac == 2 && !empty_string(av[1]))
		parse_string(stack, av);
	else
		parse_args(stack, av);
	fill_indexes(stack->a);
}
