/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnchabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 09:42:57 by mnchabel          #+#    #+#             */
/*   Updated: 2019/07/02 10:44:47 by mnchabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*file[2147483647];
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	ssize_t		ret;
	int			endl;

	if (fd < 0 || (!file[fd] && !(file[fd] = ft_strnew(1))) || !line)
		return (-1);
	while (!ft_strchr(file[fd], '\n') && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp = file[fd];
		file[fd] = ft_strjoin(file[fd], buff);
		ft_strdel(&temp);
	}
	if (ret == -1 || !*(temp = file[fd]))
		return (ret == -1 ? -1 : 0);
	if ((endl = (int)(ft_strchr(file[fd], '\n') > 0)))
		*line = ft_strsub(file[fd], 0, ft_strchr(file[fd], '\n') - file[fd]);
	else
		*line = ft_strdup(file[fd]);
	file[fd] = ft_strsub(file[fd], (unsigned int)(ft_strlen(*line) + endl),
			(size_t)(ft_strlen(file[fd]) - (ft_strlen(*line) + endl)));
	ft_strdel(&temp);
	return (!(!file[fd] && !ft_strlen(*line)));
}
