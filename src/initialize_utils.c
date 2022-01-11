/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:44:23 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/11 18:04:19 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "list.h"

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
