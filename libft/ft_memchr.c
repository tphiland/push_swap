/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphiland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:14:13 by tphiland          #+#    #+#             */
/*   Updated: 2019/06/03 16:14:38 by tphiland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	t;

	t = 0;
	while (t < n)
	{
		if (((unsigned char *)s)[t] == (unsigned char)c)
			return ((void *)(s + t));
		t++;
	}
	return (NULL);
}
