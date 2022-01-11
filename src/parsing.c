/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:30 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/10 20:40:57 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_split.h"
#include "utils.h"

static int	*free_args(void **ptr, int is_splitted, int len)
{
	int	i;

	if (is_splitted)
	{
		i = -1;
		while (++i < len)
			free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int	validate_numbers(char **av, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = 0;
		if (av[i][0] == '-' || av[i][0] == '+')
			j++;
		if (av[i][j] == 0)
			return (1);
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
	}
	return (0);
}

static int	is_repetition(int *args, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (args[j] == args[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	*parse_numbers(char **av, int len)
{
	int	*args;
	int	neg;
	int	pos;
	int	i;

	args = (int *) malloc(sizeof(int) * len);
	if (!args)
		return (0);
	i = -1;
	while (++i < len)
	{
		neg = av[i][0] == '-';
		pos = av[i][0] == '+';
		if (ft_strlen(av[i]) > (10 + neg + pos))
			return (free_args((void **) args, 0, 0));
		if (neg && ft_strlen(av[i]) == 11
			&& ft_strcmp(av[i], "-2147483648") > 0)
			return (free_args((void **) args, 0, 0));
		if (!neg && ft_strlen(av[i]) == (10 + pos)
			&& ft_strcmp(&av[i][pos], "2147483647") > 0)
			return (free_args((void **) args, 0, 0));
		args[i] = ft_atoi(av[i]);
	}
	return (args);
}

int	*parsing(int *ac, char **av)
{
	int	*args;
	int	is_splitted;

	is_splitted = 0;
	if (*ac == 2)
	{
		av = ft_split(av[1], ' ', ac);
		is_splitted = 1;
	}
	else
		av++;
	if (validate_numbers(av, *ac - 1))
		return (free_args((void **) av, is_splitted, *ac));
	args = parse_numbers(av, *ac - 1);
	if (is_splitted)
		free_args((void **) av, is_splitted, *ac);
	if (!args)
		return (free_args((void **) av, is_splitted, *ac));
	if (is_repetition(args, *ac - 1))
		return (free_args((void **) args, 0, 0));
	return (args);
}
