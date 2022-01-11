/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:21 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/06 19:34:29 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static t_stack	*create_node(int value)
{
	t_stack	*tmp;

	tmp = (t_stack *) malloc(sizeof(t_stack));
	if (!tmp)
		return (0);
	tmp->value = value;
	tmp->next = 0;
	tmp->prev = tmp;
	return (tmp);
}

// t_stack	*push_front(t_stack **head, int value)
// {
// 	t_stack	*tmp;

// 	tmp = create_node(value);
// 	if (!tmp)
// 		return (0);
// 	if (*head)
// 	{
// 		tmp->prev = (*head)->prev;
// 		tmp->next = *head;
// 		(*head)->prev = tmp;
// 		(*head) = tmp;
// 	}
// 	else if (head)
// 		*head = tmp;
// 	return (tmp);
// }

t_stack	*push_back(t_stack **head, int value)
{
	t_stack	*tmp;

	tmp = create_node(value);
	if (!tmp)
		return (0);
	if (*head)
	{
		tmp->prev = (*head)->prev;
		(*head)->prev->next = tmp;
		(*head)->prev = tmp;
	}
	else if (head)
		*head = tmp;
	return (tmp);
}

// t_stack	*pop_front(t_stack **head)
// {
// 	t_stack	*tmp;

// 	tmp = *head;
// 	*head = (*head)->next;
// 	if (*head)
// 		(*head)->prev = tmp->prev;
// 	tmp->prev = tmp;
// 	tmp->next = 0;
// 	return (tmp);
// }

// t_stack	*pop_back(t_stack **head)
// {
// 	t_stack	*tmp;

// 	tmp = (*head)->prev;
// 	if ((*head)->prev == *head)
// 		*head = 0;
// 	else
// 	{
// 		(*head)->prev = tmp->prev;
// 		(*head)->prev->next = 0;
// 	}
// 	tmp->prev = tmp;
// 	return (tmp);
// }

void	clear(t_stack **head)
{
	t_stack	*tmp;

	if (!head)
		return ;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
	*head = 0;
}

// t_stack	*copy(t_stack *head)
// {
// 	t_stack	*tmp;

// 	tmp = 0;
// 	while (head)
// 	{
// 		if (!push_back(&tmp, head->value))
// 			return (clear(&tmp));
// 		head = head->next;
// 	}
// 	return (tmp);
// }

// t_stack	*find(t_stack *head, int value)
// {
// 	while (head)
// 	{
// 		if (head->value == value)
// 			return (head);
// 		head = head->next;
// 	}
// 	return (0);
// }

// int	index(t_stack *head, int value)
// {
// 	int	i;

// 	if (!head)
// 		return (-1);
// 	while (head)
// 	{
// 		if (head->value == value)
// 			return (i);
// 		head = head->next;
// 		i++;
// 	}
// 	return (-1);
// }

// t_stack	*at(t_stack *head, int index)
// {
// 	while (index-- > 0)
// 	{
// 		if (!head)
// 			return (0);
// 		head = head->next;
// 	}
// 	return (head);
// }
