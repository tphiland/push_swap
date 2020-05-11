/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphiland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:59:54 by tphiland          #+#    #+#             */
/*   Updated: 2019/06/28 16:26:54 by tphiland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while ((haystack[i] != '\0') && len > i)
	{
		j = 0;
		if ((needle[j] == haystack[i]))
		{
			str = (char *)&haystack[i];
			while ((needle[j] == haystack[i]) && i < len)
			{
				if (needle[j + 1] == '\0')
					return (str);
				i++;
				j++;
			}
		}
		else
			i++;
	}
	return (NULL);
}
