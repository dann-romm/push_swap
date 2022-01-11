/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:28 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/05 22:12:29 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	if (!head || !(*head) || !(*head)->next)
		return ;
	if ((*head)->next->next)
	{
		(*head)->next->next->prev = *head;
		(*head)->next->prev = (*head)->prev;
		(*head)->prev = (*head)->next;
		(*head)->next = (*head)->next->next;
	}
	else
		(*head)->next = 0;
	(*head)->prev->next = *head;
	*head = (*head)->prev;
}

void	rotate(t_stack **head)
{
	if (!head || !(*head))
		return ;
	(*head)->prev->next = *head;
	*head = (*head)->next;
	(*head)->prev->next = 0;
}

void	reverse_rotate(t_stack **head)
{
	if (!head || !(*head))
		return ;
	(*head)->prev->next = *head;
	*head = (*head)->prev;
	(*head)->prev->next = 0;
}
