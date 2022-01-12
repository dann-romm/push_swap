/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:09 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/12 03:01:47 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "algorithm.h"
#include "instructions.h"
#include "utils.h"

static void	fill_stack_b(t_state *state, int *args, int index)
{
	int	i;
	int	cur_value;

	i = index;
	cur_value = args[index];
	while (++i < state->len_a)
		cur_value = max(cur_value, args[i]);
	while (i > 0)
	{
		if (i == state->len_a + state->len_b - index)
			cur_value = -2147483647 - 1;
		if (state->a->next && state->a->value == state->a->next->value + 1)
			sa(state, 1);
		if (state->a->value >= cur_value)
		{
			cur_value = state->a->value;
			ra(state, 1);
		}
		else
			pb(state, 1);
		i--;
	}
}

static void	move_to_stack_a(t_state *state)
{
	int		min_count;
	int		i;
	t_stack	*tmp;
	t_stack	*node;

	i = 0;
	tmp = state->b;
	min_count = 2147483647;
	while (tmp)
	{
		tmp->rb = i;
		tmp->ra = calc_a_index(state, tmp->value);
		tmp->rra = state->len_a - tmp->ra;
		tmp->rrb = state->len_b - tmp->rb;
		if (min4(tmp->ra + tmp->rrb, tmp->rra + tmp->rb,
				max(tmp->ra, tmp->rb), max(tmp->rra, tmp->rrb)) < min_count)
		{
			min_count = min4(tmp->ra + tmp->rrb, tmp->rra + tmp->rb,
					max(tmp->ra, tmp->rb), max(tmp->rra, tmp->rrb));
			node = tmp;
		}
		tmp = tmp->next;
		i++;
	}
	execute_operation(state, node);
}

static void	rotate_stack_a(t_state *state)
{
	int	i;

	i = calc_a_index(state, 2147483647);
	if (i < state->len_a - i)
	{
		while (i-- > 0)
			ra(state, 1);
	}
	else
	{
		while (i++ < state->len_a)
			rra(state, 1);
	}
}

static int	find_max_increasing(int *args, t_state *state, int count_max)
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

void	algorithm(t_state *state, int *args)
{
	if (is_state_sorted(state))
		return ;
	if (state->len_a == 3)
	{
		sort_3(state);
		return ;
	}
	else if (state->len_a == 5)
	{
		sort_5(state, args);
		return ;
	}
	if (!is_state_almost_sorted(state))
	{
		fill_stack_b(state, args, find_max_increasing(args, state, 0));
		while (state->b)
			move_to_stack_a(state);
	}
	rotate_stack_a(state);
}
