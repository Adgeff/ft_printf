/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 18:52:09 by gargence          #+#    #+#             */
/*   Updated: 2016/10/06 00:08:05 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*other_flags(char *result, t_format conv)
{
	if ((*(conv.conversion) == 'd' || *(conv.conversion) == 'i')
		&& *result != '-')
	{
		if ((conv.flags & plus) != 0)
			result = ft_strjoinfree("+", result, 2);
		else if ((conv.flags & space) != 0)
			result = ft_strjoinfree(" ", result, 2);
	}
	while ((signed)ft_strlen(result) < conv.width)
	{
		if ((conv.flags & minus) != 0)
			result = ft_strjoinfree(result, " ", 1);
		else if ((conv.flags & zero) != 0)
			result = ft_strjoinfree("0", result, 2);
		else
			result = ft_strjoinfree(" ", result, 2);
	}
	return (result);
}
