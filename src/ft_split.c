#include <stdlib.h>

static int	count_words(const char *str, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (str[i])
	{
		count = 0;
		while (str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			count++;
			i++;
		}
		if (count > 0)
			j++;
	}
	return (j);
}

static int	free_arr(char **arr)
{
	while (*arr)
		free(*arr++);
	free(arr);
	return (1);
}

static int	allocate_strs(char **arr, const char *str, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (str[i])
	{
		count = 0;
		while (str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			count++;
			i++;
		}
		if (count > 0)
		{
			arr[j] = (char *) malloc(sizeof(char) * (count + 1));
			if (!arr[j++])
				return (free_arr(arr));
		}
	}
	return (0);
}

static void	fill_strs(char **arr, const char *str, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (str[i])
	{
		count = 0;
		while (str[i] == c)
			i++;
		while (str[i] && str[i] != c)
			arr[j][count++] = str[i++];
		if (count > 0)
			arr[j][count] = 0;
		j++;
	}
}

char	**ft_split(char const *str, char c, int *ac)
{
	char	**arr;
	int		count;

	if (str == 0)
		return (0);
	count = count_words(str, c);
	*ac = count + 1;
	arr = (char **) malloc(sizeof(char *) * (count + 1));
	if (arr == 0)
		return (0);
	arr[count] = 0;
	if (allocate_strs(arr, str, c))
		return (0);
	fill_strs(arr, str, c);
	return (arr);
}