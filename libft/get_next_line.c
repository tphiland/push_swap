/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphiland <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:52:39 by tphiland          #+#    #+#             */
/*   Updated: 2019/08/22 14:04:58 by tphiland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int        get_next_line(const int fd, char **line)
{
    int            endofln;
    char        *hold;
    char        buf[BUFF_SIZE + 1];
    static char    *sc[2147483647];
    ssize_t        t;
    
    if (fd <= -1 || (!sc[fd] && !(sc[fd] = ft_strnew(1))) || !line)
        return (-1);
    while (!ft_strchr(sc[fd], 10) && (t = read(fd, buf, BUFF_SIZE)) >= 1)
    {
        buf[t] = 0;
        hold = sc[fd];
        sc[fd] = ft_strjoin(sc[fd], buf);
        ft_strdel(&hold);
    }
    if (!*(hold = sc[fd]) || t == -1)
        return (t == -1 ? -1 : 0);
    if ((endofln = (ft_strchr(sc[fd], 10) != 0)))
        *line = ft_strsub(sc[fd], 0, ft_strchr(sc[fd], 10) - sc[fd]);
    else
        *line = ft_strdup(sc[fd]);
    sc[fd] = ft_strsub(sc[fd], (unsigned int)(ft_strlen(*line) + endofln),
                       (size_t)(ft_strlen(sc[fd]) - (endofln + ft_strlen(*line))));
    ft_strdel(&hold);
    return (!(!ft_strlen(*line) && !sc[fd]));
}
