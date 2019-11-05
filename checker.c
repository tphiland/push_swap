/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphiland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 21:18:39 by tphiland          #+#    #+#             */
/*   Updated: 2019/11/05 10:09:20 by tphiland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

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

int		is_ordered(int stacka[], int top)
{
	int i;

	i = 0;
	while (i < top)
	{
		if (stacka[i] > stacka[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		has_duplicate(int stacka[], int top)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < top)
	{
		while (j <= top)
		{
			if (stacka[i] == stacka[j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

void	apply_command(int stacka[], int stackb[], int top[], char **line)
{
	if (!ft_strcmp("pa", *line))
		pushA(stacka, stackb, top);
	else if (!ft_strcmp("pb", *line))
		pushB(stacka, stackb, top);
	else if (!ft_strcmp("ra", *line))
		rotate(stacka, top[0]);
	else if (!ft_strcmp("rb", *line))
		rotate(stackb, top[1]);
	else if (!ft_strcmp("sa", *line))
		swap(stacka);
	else if (!ft_strcmp("sb", *line))
		swap(stackb);
	else if (!ft_strcmp("rra", *line))
		reverse_rotate(stacka, top[0]);
	else if (!ft_strcmp("rrb", *line))
		reverse_rotate(stackb, top[1]);
	else
		apply_command_2(stacka, stackb, top, line);
}

int		main(int argc, char **argv)
{
	int		*stacka;
	int		*stackb;
	int		top[4];
	char	**line;
	char	**array;

	top[3] = argc;
	main_2(line, top);
	if (top[3] == 2)
	{
		main_3(argv[1], stacka, stackb, array);
		while (array[top[2]])
		{
			stacka[top[2]] = ft_atoi(array[top[2]]);
			top[0]++;
			top[2]++;
		}
	}
	main_4(top, stacka, stackb, argv);
	if (has_duplicate(stacka, top[0]))
	{
		write(1, "Error", 5);
		return (0);
	}
	while (get_next_line(0, line) >= 1)
		apply_command(stacka, stackb, top, line);
	if (is_ordered(stacka, top[0]) && top[1] == -1)
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
	free(*line);
	free(line);
	return (0);
}
