#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "list.h"
#include "parsing.h"
#include "utils.h"
#include "get_next_line.h"
#include "instructions.h"

#include <stdio.h> // remove

int	display_error(int code)
{
	write(1, "Error\n", 6);
	return (code);
}

t_state	*free_state(t_state **state)
{
	clear(&((*state)->a));
	clear(&((*state)->b));
	free(*state);
	*state = 0;
	return (0);
}

t_state	*initialize_state(int *args, int len)
{
	t_state	*state;
	int		i;

	state = (t_state *) malloc(sizeof(t_state));
	if (!state)
		return (0);
	state->a = 0;
	i = -1;
	while (++i < len)
	{
		if (!push_back(&state->a, args[i]))
			return (free_state(&state));
	}
	state->b = 0;
	state->len_a = len;
	state->len_b = 0;
	return (state);
}




void	print_state(t_state *state)
{
	int a = state->len_a;
	int b = state->len_b;

	t_stack	*tmp_a = state->a;
	t_stack	*tmp_b = state->b;

	printf("\nSTATE:\n\n");
	while (a > b)
	{
		printf("%6d\n", tmp_a->value);
		tmp_a = tmp_a->next;
		a--;
	}
	while (a < b)
	{
		printf("%14d\n", tmp_b->value);
		tmp_b = tmp_b->next;
		b--;
	}
	while (a)
	{
		printf("%6d %6d\n", tmp_a->value, tmp_b->value);
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
		a--;
		b--;
	}
	printf("<--A-->_<--B-->\n");
}



int	execute_instruction(char *str, t_state *state)
{
	if (ft_strcmp(str, "pa") == 0 || ft_strcmp(str, "pa") == 10)
		pa(state, 0);
	else if (ft_strcmp(str, "pb") == 0 || ft_strcmp(str, "pb") == 10)
		pb(state, 0);
	else if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sa") == 10)
		sa(state, 0);
	else if (ft_strcmp(str, "sb") == 0 || ft_strcmp(str, "sb") == 10)
		sb(state, 0);
	else if (ft_strcmp(str, "ss") == 0 || ft_strcmp(str, "ss") == 10)
		ss(state, 0);
	else if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "ra") == 10)
		ra(state, 0);
	else if (ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rb") == 10)
		rb(state, 0);
	else if (ft_strcmp(str, "rr") == 0 || ft_strcmp(str, "rr") == 10)
		rr(state, 0);
	else if (ft_strcmp(str, "rra") == 0 || ft_strcmp(str, "rra") == 10)
		rra(state, 0);
	else if (ft_strcmp(str, "rrb") == 0 || ft_strcmp(str, "rrb") == 10)
		rrb(state, 0);
	else if (ft_strcmp(str, "rrr") == 0 || ft_strcmp(str, "rrr") == 10)
		rrr(state, 0);
	else
		return (1);
	return (0);
}

int	is_state_sorted(t_state *state)
{
	t_stack	*tmp;

	if (!state->a || state->b)
		return (0);
	tmp = state->a->next;
	while (tmp)
	{
		if (tmp->value < tmp->prev->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	check(t_state *state)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str || str[0] == '\n')
			break ;
		if (execute_instruction(str, state))
		{
			write(2, "Error\n", 6);
			free(str);
			return ;
		}
		free(str);
	}
	if (is_state_sorted(state))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	int		*args;
	t_state	*state;

	if (ac < 2)
		return (0);
	args = parsing(&ac, av);
	if (!args)
		return (display_error(1));
	state = initialize_state(args, ac - 1);
	if (!state)
		return (display_error(1));
	check(state);
	free_state(&state);
	free(args);
	return (0);
}
