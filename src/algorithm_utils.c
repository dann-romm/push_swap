/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:06 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/12 03:05:16 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"
#include "utils.h"

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

void	sort_3(t_state *state)
{
	t_stack	*tmp;

	tmp = state->a;
	if (tmp->value < tmp->prev->value && tmp->next->value > tmp->prev->value)
	{
		sa(state, 1);
		ra(state, 1);
	}
	else if (tmp->value > tmp->next->value && tmp->value < tmp->prev->value)
		sa(state, 1);
	else if (tmp->value < tmp->next->value && tmp->value > tmp->prev->value)
		rra(state, 1);
	else if (tmp->value > tmp->prev->value
		&& tmp->next->value < tmp->prev->value)
		ra(state, 1);
	else if (tmp->value > tmp->next->value
		&& tmp->next->value > tmp->prev->value)
	{
		sa(state, 1);
		rra(state, 1);
	}
}

void	sort_5(t_state *state, int *args)
{
	int	min_value;
	int	max_value;
	int	i;

	min_value = args[0];
	max_value = args[0];
	i = -1;
	while (++i < 5)
	{
		max_value = max(max_value, args[i]);
		min_value = min_value + args[i] - max(min_value, args[i]);
	}
	while (state->len_b < 2)
	{
		if (state->a->value == min_value || state->a->value == max_value)
			pb(state, 1);
		else
			ra(state, 1);
	}
	sort_3(state);
	if (state->b->value > state->b->prev->value)
		sb(state, 1);
	pa(state, 1);
	pa(state, 1);
	ra(state, 1);
}
