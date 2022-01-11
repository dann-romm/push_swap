/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:33 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/11 18:24:15 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "algorithm.h"
#include "list.h"
#include "parsing.h"
#include "initialize_utils.h"

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
