/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:52 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/05 22:12:53 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				value;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_state
{
	t_stack	*a;
	t_stack	*b;
	int		len_a;
	int		len_b;
}			t_state;

#endif
