/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:44:12 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/12 01:55:11 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "parsing.h"
#include "utils.h"
#include "get_next_line.h"
#include "instructions.h"
#include "initialize_utils.h"
#include "algorithm.h"

static int	execute_instruction(char *str, t_state *state)
{
	if (ft_strcmp(str, "pa") == 0 || ft_strcmp(str, "pa") == 10)
		pa(state, 0);
	else if (ft_strcmp(str, "pb") == 0 || ft_strcmp(str, "pb") == 10)
		pb(state, 0);
	else if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sa") == 10)
		sa(state, 0);
	else if (ft_strcmp(str, "sb") == 0 || ft_strcmp(str, "sb") == 10)
		sb(state, 0);
	else if (ft_strcmp(str, "ss") == 0 || ft_strcmp(str, "ss") == 10)
		ss(state, 0);
	else if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "ra") == 10)
		ra(state, 0);
	else if (ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rb") == 10)
		rb(state, 0);
	else if (ft_strcmp(str, "rr") == 0 || ft_strcmp(str, "rr") == 10)
		rr(state, 0);
	else if (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rra") == 10)
		rra(state, 0);
	else if (ft_strcmp(str, "rrb") == 0 || ft_strcmp(str, "rrb") == 10)
		rrb(state, 0);
	else if (ft_strcmp(str, "rrr") == 0 || ft_strcmp(str, "rrr") == 10)
		rrr(state, 0);
	else
		return (1);
	return (0);
}

static void	check(t_state *state)
{
	char	*str;

	str = get_next_line(0);
	while (str && str[0] != '\n')
	{
		if (execute_instruction(str, state))
		{
			write(2, "Error\n", 6);
			free(str);
			return ;
		}
		free(str);
		str = get_next_line(0);
	}
	if (is_state_sorted(state))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	int		*args;
	t_state	*state;

	if (ac < 2)
		return (0);
	args = parsing(&ac, av);
	if (!args)
		return (display_error(1));
	state = initialize_state(args, ac - 1);
	if (!state)
		return (display_error(1));
	check(state);
	free_state(&state);
	free(args);
	return (0);
}
