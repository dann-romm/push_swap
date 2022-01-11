/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:12 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/11 02:12:51 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"
#include "utils.h"

static void	ra_rrb(t_state *state, t_stack *tmp)
{
	while (tmp->ra-- > 0)
		ra(state, 1);
	while (tmp->rrb-- > 0)
		rrb(state, 1);
}

static void	rra_rb(t_state *state, t_stack *tmp)
{
	while (tmp->rra-- > 0)
		rra(state, 1);
	while (tmp->rb-- > 0)
		rb(state, 1);
}

static void	rr_ra_rb(t_state *state, t_stack *tmp)
{
	while (tmp->ra > 0 && tmp->rb > 0)
	{
		rb(state, 1);
		tmp->ra--;
		tmp->rb--;
	}
	while (tmp->rb-- > 0)
		rb(state, 1);
	while (tmp->ra-- > 0)
		ra(state, 1);
}

static void	rrr_rra_rrb(t_state *state, t_stack *tmp)
{
	while (tmp->rra > 0 && tmp->rrb > 0)
	{
		rrr(state, 1);
		tmp->rra--;
		tmp->rrb--;
	}
	while (tmp->rrb-- > 0)
		rrb(state, 1);
	while (tmp->rra-- > 0)
		rra(state, 1);
}

void	execute_operation(t_state *state, t_stack *tmp)
{
	int	min_instr;

	min_instr = min4(tmp->ra + tmp->rrb, tmp->rra + tmp->rb,
			max(tmp->ra, tmp->rb), max(tmp->rra, tmp->rrb));
	if (min_instr == tmp->ra + tmp->rrb)
		ra_rrb(state, tmp);
	else if (min_instr == tmp->rra + tmp->rb)
		rra_rb(state, tmp);
	else if (min_instr == max(tmp->ra, tmp->rb))
		rr_ra_rb(state, tmp);
	else
		rrr_rra_rrb(state, tmp);
	pa(state, 1);
}
