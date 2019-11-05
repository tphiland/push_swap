/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphiland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:07:19 by tphiland          #+#    #+#             */
/*   Updated: 2019/11/05 09:08:43 by tphiland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		index_smallest(int stacka[], int top, int exclude_val)
{
	int		i;
	int		smallest_index;
	int		smallest_val;

	i = 0;
	smallest_index = 0;
	smallest_val = 2000000;
	while (i <= top)
	{
		if (stacka[i] <= smallest_val && stacka[i] > exclude_val)
		{
			smallest_val = stacka[i];
			smallest_index = i;
		}
		i++;
	}
	return (smallest_index);
}

int		index_biggest(int stacka[], int top, int exclude_val)
{
	int		i;
	int		biggest_index;
	int		biggest_val;

	i = 0;
	biggest_index = 0;
	biggest_val = -1;
	while (i <= top)
	{
		if (stacka[i] >= biggest_val && stacka[i] < exclude_val)
		{
			biggest_val = stacka[i];
			biggest_index = i;
		}
		i++;
	}
	return (biggest_index);
}

void	sort3(int stacka[])
{
	if (stacka[2] > stacka[0] && stacka[1] > stacka[2])
		write(1, "rra\nsa\n", 7);
	if (stacka[0] > stacka[1] && stacka[2] > stacka[0])
		write(1, "sa\n", 3);
	if (stacka[0] > stacka[2] && stacka[1] > stacka[0])
		write(1, "rra\n", 4);
	if (stacka[2] > stacka[1] && stacka[0] > stacka[2])
		write(1, "ra\n", 3);
	if (stacka[1] > stacka[2] && stacka[0] > stacka[1])
		write(1, "ra\nsa\n", 6);
}

void	sort5_2(int stacka[], int stackb[], int top[2])
{
	int		i;

	i = index_smallest(stacka, top[0], -1);
	if (i == 0)
	{
		pushB(stacka, stackb, top);
		write(1, "pb\n", 3);
	}
	else if (i == 1)
	{
		rotate(stacka, top[0]);
		pushB(stacka, stackb, top);
		write(1, "ra\npb\n", 6);
	}
	else if (i == 2)
	{
		reverse_rotate(stacka, top[0]);
		reverse_rotate(stacka, top[0]);
		pushB(stacka, stackb, top);
		write(1, "rra\nrra\npb\n", 11);
	}
	else
	{
		reverse_rotate(stacka, top[0]);
		pushB(stacka, stackb, top);
		write(1, "rra\npb\n", 7);
	}
	sort3(stacka);
	write(1, "pa\npa\n", 6);
}

void	sort5(int stacka[], int stackb[], int top[2])
{
	int		i;

	i = index_smallest(stacka, top[0], -1);
	if (i == 0)
	{
		pushB(stacka, stackb, top);
		write(1, "pb\n", 3);
	}
	else if (i == 1)
	{
		rotate(stacka, top[0]);
		pushB(stacka, stackb, top);
		write(1, "ra\npb\n", 6);
	}
	else if (i == 2)
	{
		rotate(stacka, top[0]);
		rotate(stacka, top[0]);
		pushB(stacka, stackb, top);
		write(1, "ra\nra\npb\n", 9);
	}
	else if (i == 3)
	{
		reverse_rotate(stacka, top[0]);
		reverse_rotate(stacka, top[0]);
		pushB(stacka, stackb, top);
		write(1, "rra\nrra\npb\n", 11);
	}
	else
	{
		reverse_rotate(stacka, top[0]);
		pushB(stacka, stackb, top);
		write(1, "rra\npb\n", 7);
	}
	sort5_2(stacka, stackb, top);
}

void	make_chunks100(int stacka[], int top[2], int chunks100[5][20])
{
	int			i;
	int			j;

	i = 0;
	j = 1;
	chunks100[0][0] = stacka[index_smallest(stacka, top[0], -1)];
	while (i < 5)
	{
		while (j < 20)
		{
			chunks100[i][j] = stacka[index_smallest(stacka, top[0], chunks100[i][j - 1])];
			j++;
		}
		i++;
		j = 1;
		if (i != 5)
			chunks100[i][j - 1] = stacka[index_smallest(stacka, top[0], chunks100[i - 1][19])];
	}
}

void	make_chunks500(int stacka[], int top[2], int chunks500[10][50])
{
	int			i;
	int			j;

	i = 0;
	j = 1;
	chunks500[0][0] = stacka[index_smallest(stacka, top[0], -1)];
	while (i < 10)
	{
		while (j < 50)
		{
			chunks500[i][j] = stacka[index_smallest(stacka, top[0], chunks500[i][j - 1])];
			j++;
		}
		i++;
		j = 1;
		if (i != 10)
			chunks500[i][j - 1] = stacka[index_smallest(stacka, top[0], chunks500[i - 1][49])];
	}
}

int		space_count(char *str)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == ' ')
			i++;
		str++;
	}
	return (i);
}

int		in_chunk100(int stacka, int chunks100[5][20], int i)
{
	int		j;

	j = 0;
	while (j <= 19)
	{
		if (stacka == chunks100[i][j])
			return (1);
		j++;
	}
	return (0);
}

int		in_chunk500(int stacka, int chunks500[10][50], int i)
{
	int		j;

	j = 0;
	while (j <= 49)
	{
		if (stacka == chunks500[i][j])
			return (1);
		j++;
	}
	return (0);
}

void	complete(int stacka[], int stackb[], int top[2])
{
	int		ra;
	int		rra;

	ra = index_biggest(stackb, top[1], 2000);
	rra = top[1] + 1 - ra;
	if (ra <= rra)
		while (ra > 0)
		{
			rotate(stackb, top[1]);
			write(1, "rb\n", 3);
			ra--;
		}
	else
		while (rra > 0)
		{
			reverse_rotate(stackb, top[1]);
			write(1, "rrb\n", 4);
			rra--;
		}
	write(1, "pa\n", 3);
	pushA(stacka, stackb, top);
}

void	sort100(int stacka[], int stackb[], int top[2], int chunks100[5][20], int chunk)
{
	int		i;
	int		caught;
	int		ra;

	ra = 1000;
	caught = 0;
	i = 0;
	while (stacka[i] && caught == 0)
	{
		if (in_chunk100(stacka[i], chunks100, chunk))
		{
			ra = i;
			caught = 1;
		}
		i++;
	}
	while (ra > 0)
	{
		rotate(stacka, top[0]);
		write(1, "ra\n", 3);
		ra--;
	}
	pushB(stacka, stackb, top);
	write(1, "pb\n", 3);
}

void	sort500(int stacka[], int stackb[], int top[2], int chunks500[10][50], int chunk)
{
	int		i;
	int		caught;
	int		ra;

	ra = 1000;
	caught = 0;
	i = 0;
	while (stacka[i] && caught == 0)
	{
		if (in_chunk500(stacka[i], chunks500, chunk))
		{
			ra = i;
			caught = 1;
		}
		i++;
	}
	while (ra > 0)
	{
		rotate(stacka, top[0]);
		write(1, "ra\n", 3);
		ra--;
	}
	pushB(stacka, stackb, top);
	write(1, "pb\n", 3);
}

void	sort100_2(int stacka[], int stackb[], int top[2], int chunks100[5][20])
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (j <= 4)
	{
		while (i <= 19)
		{
			sort100(stacka, stackb, top, chunks100, j);
			i++;
		}
		j++;
		i = 0;
	}
	i = 0;
	while (i <= 99)
	{
		complete(stacka, stackb, top);
		i++;
	}
}

void	sort500_2(int stacka[], int stackb[], int top[2], int chunks500[10][50])
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (j <= 9)
	{
		while (i <= 49)
		{
			sort500(stacka, stackb, top, chunks500, j);
			i++;
		}
		j++;
		i = 0;
	}
	i = 0;
	while (i <= 499)
	{
		complete(stacka, stackb, top);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		*stacka;
	int		*stackb;
	char	**array;
	int		top[2];
	int		i;
	int		chunks100[5][20];
	int		chunks500[10][50];

	i = 0;
	top[0] = -1;
	top[1] = -1;
	if ((argc == 2 && ft_strlen(argv[1]) < 5) || argc == 5 || argc == 11)
		return (0);
	if (argc == 2)
	{
		if (space_count(argv[1]) == 2)
		{
			stacka = (int *)malloc(sizeof(int) * 3);
			stackb = (int *)malloc(sizeof(int) * 3);
		}
		else if (space_count(argv[1]) == 4)
		{
			stacka = (int *)malloc(sizeof(int) * 5);
			stackb = (int *)malloc(sizeof(int) * 5);
		}
		else if (space_count(argv[1]) == 99)
		{
			stacka = (int *)malloc(sizeof(int) * 100);
			stackb = (int *)malloc(sizeof(int) * 100);
		}
		else if (space_count(argv[1]) == 499)
		{
			stacka = (int *)malloc(sizeof(int) * 500);
			stackb = (int *)malloc(sizeof(int) * 500);
		}
		array = ft_strsplit(argv[1], ' ');
		while (array[i])
		{
			stacka[i] = ft_atoi(array[i]);
			top[0]++;
			i++;
		}
	}
	i = 0;
	if (argc != 2)
	{
		stacka = (int *)malloc(sizeof(int) * (argc - 1));
		stackb = (int *)malloc(sizeof(int) * (argc - 1));
		top[0] = -1;
		while (i < argc - 1)
		{
			stacka[i] = ft_atoi(argv[i + 1]);
			top[0]++;
			i++;
		}
	}
	if (top[0] == 2)
		sort3(stacka);
	if (top[0] == 4)
		sort5(stacka, stackb, top);
	if (top[0] == 99)
	{
		make_chunks100(stacka, top, chunks100);
		sort100_2(stacka, stackb, top, chunks100);
	}
	if (top[0] == 499)
	{
		make_chunks500(stacka, top, chunks500);
		sort500_2(stacka, stackb, top, chunks500);
	}
	free(stacka);
	free(stackb);
	return (0);
}
