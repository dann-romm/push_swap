/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:06 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/10 16:13:52 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_increasing(int *args, t_state *state, int count_max)
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


// // remove
// #include <stdlib.h>
// #include <stdio.h>
// #include "list.h"
// int main()
// {
// 	t_state *state = malloc(sizeof(t_state));
// 	state->a = 0;
// 	state->b = 0;
// 	push_back(&state->a, 1);
// 	push_back(&state->a, 3);
// 	push_back(&state->a, 4);
// 	push_back(&state->a, 5);
// 	push_back(&state->b, 2);
// 	printf("calc_a_index = %d\n", calc_a_index(state, 2));
// }