/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 22:12:35 by doalbaco          #+#    #+#             */
/*   Updated: 2022/01/05 22:12:37 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min4(int a, int b, int c, int d)
{
	if (b < a)
		a = b;
	if (c < a)
		a = c;
	if (d < a)
		a = d;
	return (a);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	ans;

	i = 0;
	ans = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') * (-1) + (str[i] == '+');
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
		ans = sign * (str[i++] - '0');
	while (str[i] >= '0' && str[i] <= '9')
		ans = ans * 10 + sign * (str[i++] - '0');
	return (ans);
}
