/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnchabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 09:42:57 by mnchabel          #+#    #+#             */
/*   Updated: 2019/06/29 12:18:45 by mnchabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*file[2147483647];
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	int			ret;
	int			endl;

	if (fd < 0 || !line)
		return (-1);
	while (ret = read(fd, buff, BUFF_SIZE))
	return (0);
}
