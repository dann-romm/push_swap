/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:33 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/10 19:38:39 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "algorithm.h"
#include "list.h"
#include "parsing.h"

int	display_error(int code)
{
	write(1, "Error\n", 6);
	return (code);
}

t_state	*free_state(t_state **state)
{
	clear(&((*state)->a));
	clear(&((*state)->b));
	free(*state);
	*state = 0;
	return (0);
}

t_state	*initialize_state(int *args, int len)
{
	t_state	*state;
	int		i;

	state = (t_state *) malloc(sizeof(t_state));
	if (!state)
		return (0);
	state->a = 0;
	i = -1;
	while (++i < len)
	{
		if (!push_back(&state->a, args[i]))
			return (free_state(&state));
	}
	state->b = 0;
	state->len_a = len;
	state->len_b = 0;
	return (state);
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
	algorithm(state, args);
	free_state(&state);
	free(args);
	return (0);
}
