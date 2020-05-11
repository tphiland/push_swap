/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphiland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 14:13:33 by tphiland          #+#    #+#             */
/*   Updated: 2019/06/28 13:16:19 by tphiland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	if (!s)
		return ;
	else
		while (*s)
		{
			write(1, s, 1);
			s++;
		}
	write(1, "\n", 1);
}
