/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:59 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/11 01:29:23 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include <unistd.h>
# include "push_swap.h"

void	sa(t_state *state, int is_output);
void	sb(t_state *state, int is_output);
void	ss(t_state *state, int is_output);
void	pa(t_state *state, int is_output);
void	pb(t_state *state, int is_output);
void	ra(t_state *state, int is_output);
void	rb(t_state *state, int is_output);
void	rr(t_state *state, int is_output);
void	rra(t_state *state, int is_output);
void	rrb(t_state *state, int is_output);
void	rrr(t_state *state, int is_output);

#endif
