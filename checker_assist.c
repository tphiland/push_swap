/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_assist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphiland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:05:00 by tphiland          #+#    #+#             */
/*   Updated: 2019/11/05 10:00:37 by tphiland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	apply_command_2(int stacka[], int stackb[], int top[], char **line)
{
	else if (!ft_strcmp("rr", *line))
	{
		rotate(stacka, top[0]);
		rotate(stackb, top[1]);
	}
	else if (!ft_strcmp("rrr", *line))
	{
		reverse_rotate(stacka, top[0]);
		reverse_rotate(stackb, top[1]);
	}
	else
	{
		write(1, "Error", 5);
		exit(0);
	}
}
void	main_2(char **line, int top[])
{
	line = (char **)malloc(sizeof(char *) * 100000);
	*line = (char *)malloc(4);
	top[2] = 0;
	if (top[3] == 1)
		exit(0);
	top[0] = -1;
	top[1] = -1;
}

void	main_3(char *argv, int stacka[], int stackb[], char **array)
{
	if (space_count(argv) == 2)
	{
		stacka = (int *)malloc(sizeof(int) * 3);
		stackb = (int *)malloc(sizeof(int) * 3);
	}
	else if (space_count(argv) == 4)
	{
		stacka = (int *)malloc(sizeof(int) * 5);
		stackb = (int *)malloc(sizeof(int) * 5);
	}
	else if (space_count(argv) == 99)
	{
		stacka = (int *)malloc(sizeof(int) * 100);
		stackb = (int *)malloc(sizeof(int) * 100);
	}
	else if (space_count(argv) == 499)
	{
		stacka = (int *)malloc(sizeof(int) * 500);
		stackb = (int *)malloc(sizeof(int) * 500);
	}
	array = ft_strsplit(argv, ' ');
}

void	main_4(int top[], int stacka[], int stackb[], char **argv)
{
	top[2] = 0;
	if (top[3] != 2)
	{
		stacka = (int *)malloc(sizeof(int) * (top[3] - 1));
		stackb = (int *)malloc(sizeof(int) * (top[3] - 1));
		while (top[2] < top[3] - 1)
		{
			if ((!ft_atoi(argv[top[2] + 1]) && argv[top[2] + 1][0] != '0') || \
					ft_atoi(argv[top[2] + 1]) < 0 || \
					ft_strlen(argv[top[2] + 1]) > 10)
			{
				write(1, "Error", 5);
				return (0);
			}
			stacka[top[2]] = ft_atoi(argv[top[2] + 1]);
			top[0]++;
			top[2]++;
		}
	}
}
