/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnchabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:32:00 by mnchabel          #+#    #+#             */
/*   Updated: 2019/06/18 12:24:49 by mnchabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = ft_itoa_len(n);
	res = ft_strnew(len);
	if (!res)
		return (0);
	res[len] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		i = 1;
	}
	else
		i = 0;
	while (len-- > i)
	{
		if (n < 0)
			res[len] = -1 * (n % 10) + '0';
		else
			res[len] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
