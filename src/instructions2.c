/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:17 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/11 01:28:45 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "list.h"

void	ra(t_state *state, int is_output)
{
	if (is_output)
		write(1, "ra\n", 3);
	rotate(&state->a);
}

void	rb(t_state *state, int is_output)
{
	if (is_output)
		write(1, "rb\n", 3);
	rotate(&state->b);
}

void	rr(t_state *state, int is_output)
{
	if (is_output)
		write(1, "rr\n", 3);
	rotate(&state->a);
	rotate(&state->b);
}
