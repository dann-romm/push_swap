/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:09 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/11 02:21:33 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "algorithm.h"
#include "instructions.h"
#include "utils.h"

#include <stdio.h> // remove
void	print_state(t_state *state)
{
	int a = state->len_a;
	int b = state->len_b;

	t_stack	*tmp_a = state->a;
	t_stack	*tmp_b = state->b;

	printf("\nSTATE:\n\n");
	while (a > b)
	{
		printf("%6d\n", tmp_a->value);
		tmp_a = tmp_a->next;
		a--;
	}
	while (a < b)
	{
		printf("%14d\n", tmp_b->value);
		tmp_b = tmp_b->next;
		b--;
	}
	while (a)
	{
		printf("%6d %6d\n", tmp_a->value, tmp_b->value);
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
		a--;
		b--;
	}
	printf("<--A-->_<--B-->\n");
} // remove

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

static void	sort_3(int *args)
{
	if (args[0] < args[2] && args[1] > args[2])
		write(1, "sa\nra\n", 6);
	else if (args[0] > args[1] && args[0] < args[2])
		write(1, "sa\n", 3);
	else if (args[0] < args[1] && args[0] > args[2])
		write(1, "rra\n", 4);
	else if (args[0] > args[2] && args[1] < args[2])
		write(1, "ra\n", 3);
	else if (args[0] > args[1] && args[1] < args[2])
		write(1, "sa\nrra\n", 7);
}

void	algorithm(t_state *state, int *args)
{
	if (state->len_a == 3)
	{
		sort_3(args);
		return ;
	}
	fill_stack_b(state, args, find_max_increasing(args, state, 0));
	print_state(state);
	while (state->b)
		move_to_stack_a(state);
	rotate_stack_a(state);
	print_state(state);
}
