/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:13:00 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/12 03:01:57 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "push_swap.h"

void	algorithm(t_state *state, int *args);
int		calc_a_index(t_state *state, int value);
void	execute_operation(t_state *state, t_stack *tmp);
int		is_state_almost_sorted(t_state *state);
int		is_state_sorted(t_state *state);
void	sort_3(t_state *state);
void	sort_5(t_state *state, int *args);

#endif
