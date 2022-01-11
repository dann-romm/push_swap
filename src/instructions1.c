/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:15 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/11 01:28:13 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "list.h"

void	pa(t_state *state, int is_output)
{
	t_stack	*tmp;

	if (is_output)
		write(1, "pa\n", 3);
	if (!state->b)
		return ;
	tmp = state->b;
	state->b = state->b->next;
	if (state->b)
		state->b->prev = tmp->prev;
	if (state->a)
	{
		tmp->prev = state->a->prev;
		state->a->prev = tmp;
		tmp->next = state->a;
	}
	else
	{
		tmp->prev = tmp;
		tmp->next = 0;
	}
	state->a = tmp;
	state->len_a++;
	state->len_b--;
}

void	pb(t_state *state, int is_output)
{
	t_stack	*tmp;

	if (is_output)
		write(1, "pb\n", 3);
	if (!state->a)
		return ;
	tmp = state->a;
	state->a = state->a->next;
	if (state->a)
		state->a->prev = tmp->prev;
	if (state->b)
	{
		tmp->prev = state->b->prev;
		state->b->prev = tmp;
		tmp->next = state->b;
	}
	else
	{
		tmp->prev = tmp;
		tmp->next = 0;
	}
	state->b = tmp;
	state->len_a--;
	state->len_b++;
}

void	sa(t_state *state, int is_output)
{
	if (is_output)
		write(1, "sa\n", 3);
	swap(&state->a);
}

void	sb(t_state *state, int is_output)
{
	if (is_output)
		write(1, "sb\n", 3);
	swap(&state->b);
}

void	ss(t_state *state, int is_output)
{
	if (is_output)
		write(1, "ss\n", 3);
	swap(&state->a);
	swap(&state->b);
}
