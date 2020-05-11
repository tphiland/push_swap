/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphiland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:11:10 by tphiland          #+#    #+#             */
/*   Updated: 2019/06/28 16:03:17 by tphiland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;
	size_t				t;

	t = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (t < n && *s != (unsigned char)c)
	{
		*d = *s;
		d++;
		s++;
		t++;
	}
	if (t < n)
	{
		*d++ = (unsigned char)c;
		return ((void *)d);
	}
	else
		return (NULL);
}
