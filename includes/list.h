/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:56 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/06 19:12:19 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include "push_swap.h"

t_stack	*push_back(t_stack **head, int value);
void	swap(t_stack **head);
void	rotate(t_stack **head);
void	reverse_rotate(t_stack **head);
void	clear(t_stack **head);
// t_stack	*create_node(int value);
// t_stack	*push_front(t_stack **head, int value);
// t_stack	*pop_front(t_stack **head);
// t_stack	*pop_back(t_stack **head);
// t_stack	*copy(t_stack *head);
// t_stack	*find(t_stack *head, int value);
// int		index(t_stack *head, int value);
// t_stack	*at(t_stack *head, int index);

#endif
