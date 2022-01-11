/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:19 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/11 01:29:02 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "list.h"

void	rra(t_state *state, int is_output)
{
	if (is_output)
		write(1, "rra\n", 4);
	reverse_rotate(&state->a);
}

void	rrb(t_state *state, int is_output)
{
	if (is_output)
		write(1, "rrb\n", 4);
	reverse_rotate(&state->b);
}

void	rrr(t_state *state, int is_output)
{
	if (is_output)
		write(1, "rrr\n", 4);
	reverse_rotate(&state->a);
	reverse_rotate(&state->b);
}
