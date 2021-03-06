/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_va_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:12:40 by jacens            #+#    #+#             */
/*   Updated: 2020/02/14 11:39:26 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printffd.h"

char	*ft_va_null_char_fd(va_list *args, t_printfd *struc)
{
	char *ptr;

	ptr = va_arg(*args, char *);
	if (!ptr)
	{
		if (!(ptr = ft_strdup("(null)")))
			return (NULL);
		return (ptr);
	}
	if (struc->dot == 1 && struc->space == 0 && struc->zero == -1)
	{
		if (!(ptr = ft_strdup("(null)")))
			return (NULL);
		return (ptr);
	}
	if (!(ptr = ft_strdup(ptr)))
		return (NULL);
	return (ptr);
}

int		ft_va_null_int_fd(va_list *args, t_printfd *struc)
{
	int i;

	i = va_arg(*args, int);
	if (i == 0)
		struc->intnull = 1;
	return (i);
}
