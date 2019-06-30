/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnchabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:52:17 by mnchabel          #+#    #+#             */
/*   Updated: 2019/06/23 14:26:26 by mnchabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list *list)
{
	if (!list)
		return ;
	while (list)
	{
		ft_putstr("content : ");
		ft_putstr(list->content);
		ft_putchar('\n');
		ft_putstr("content size : ");
		ft_putnbr(list->content_size);
		ft_putchar('\n');
		list = list->next;
	}
}