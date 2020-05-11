/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphiland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:21:27 by tphiland          #+#    #+#             */
/*   Updated: 2019/07/01 12:05:35 by tphiland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		t;

	if (dst == NULL && src == NULL)
		return (dst);
	t = 0;
	d = dst;
	s = src;
	while (t < n)
	{
		*d = *s;
		d++;
		s++;
		t++;
	}
	return (dst);
}
