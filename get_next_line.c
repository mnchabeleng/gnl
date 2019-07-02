/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnchabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 09:42:57 by mnchabel          #+#    #+#             */
/*   Updated: 2019/07/02 10:38:55 by mnchabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*c[2147483647];
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	ssize_t		ret;
	int			endl;

	if (fd < 0 || (!c[fd] && !(c[fd] = ft_strnew(1))) || !line)
		return (-1);
	while (!ft_strchr(c[fd], '\n') && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp = c[fd];
		c[fd] = ft_strjoin(c[fd], buff);
		ft_strdel(&temp);
	}
	if (ret == -1 || !*(temp = c[fd]))
		return (ret == -1 ? -1 : 0);
	if ((endl = (ft_strchr(c[fd], '\n') > 0)))
		*line = ft_strsub(c[fd], 0, ft_strchr(c[fd], '\n') - c[fd]);
	else
		*line = ft_strdup(c[fd]);
	c[fd] = ft_strsub(c[fd], (unsigned int)(ft_strlen(*line) + endl),
			(size_t)(ft_strlen(c[fd]) - (ft_strlen(*line) + endl)));
	ft_strdel(&temp);
	return (!(!c[fd] && !ft_strlen(*line)));
}
