/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphiland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:25:59 by tphiland          #+#    #+#             */
/*   Updated: 2019/06/28 12:04:36 by tphiland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int				i;
	char			*result;
	const char		*begin;
	const char		*stop;

	result = NULL;
	if (s)
	{
		stop = (ft_strlen(s) + s);
		i = 0;
		while (*s && ft_strtrimassist(*s))
			s++;
		begin = s;
		while (stop != begin && ft_strtrimassist(*(stop - 1)))
			stop--;
		while (s != stop)
		{
			s++;
			i++;
		}
		if (!(result = ft_strsub(begin, 0, i)))
			return (NULL);
	}
	return (result);
}
