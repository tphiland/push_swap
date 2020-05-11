/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphiland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 10:53:41 by tphiland          #+#    #+#             */
/*   Updated: 2019/06/18 11:05:52 by tphiland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int		i;

	i = 0;
	while (*src && len > 0)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
		len--;
	}
	while (len > 0)
	{
		*dst = '\0';
		dst++;
		i++;
		len--;
	}
	dst = dst - i;
	return (dst);
}
