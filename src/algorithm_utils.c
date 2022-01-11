/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:06 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/11 18:02:59 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_increasing(int *args, t_state *state, int count_max)
{
	int	i;
	int	j;
	int	count_cur;
	int	value_cur;
	int	index_max;

	i = -1;
	while (++i < state->len_a)
	{
		j = (i + 1) % state->len_a;
		count_cur = 1;
		value_cur = args[i];
		while (j != i)
		{
			if (args[j] > value_cur)
				value_cur = args[j] + (count_cur++ < 0);
			j = (j + 1) % state->len_a;
		}
		if (count_cur > count_max)
		{
			count_max = count_cur;
			index_max = i;
		}
	}
	return (index_max);
}

int	calc_a_index(t_state *state, int value)
{
	t_stack	*tmp;
	int		i;
	int		first_index;

	i = 0;
	first_index = 0;
	tmp = state->a;
	while (tmp)
	{
		if (tmp->prev->value < value && tmp->value > value)
			return (i);
		if (tmp->prev->value > tmp->value)
			first_index = i;
		tmp = tmp->next;
		i++;
	}
	return (first_index);
}

int	is_state_almost_sorted(t_state *state)
{
	t_stack	*tmp;
	int		is_start_found;

	if (!state->a || state->b)
		return (0);
	is_start_found = 0;
	tmp = state->a;
	while (tmp)
	{
		if (tmp->value < tmp->prev->value)
		{
			if (is_start_found)
				return (0);
			else
				is_start_found = 1;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	is_state_sorted(t_state *state)
{
	t_stack	*tmp;

	if (!state->a || state->b)
		return (0);
	tmp = state->a->next;
	while (tmp)
	{
		if (tmp->value < tmp->prev->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
