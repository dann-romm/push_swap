/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:13:00 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/06 19:12:07 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "push_swap.h"

void	algorithm(t_state *state, int *args);
int		calc_a_index(t_state *state, int value);
int		find_max_increasing(int *args, t_state *state, int count_max);
void	execute_operation(t_state *state, t_stack *tmp);

#endif
