/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphiland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:45:26 by tphiland          #+#    #+#             */
/*   Updated: 2019/06/06 15:14:29 by tphiland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(size);
	if (ptr == NULL)
		return (NULL);
	while (size > 0)
	{
		ptr[i] = 0;
		i++;
		size--;
	}
	return (ptr);
}
