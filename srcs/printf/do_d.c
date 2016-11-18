/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:47:34 by gargence          #+#    #+#             */
/*   Updated: 2016/10/07 18:14:43 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*do_conv_d(intmax_t arg, int precision, t_format conv)
{
	uintmax_t	uarg;
	int			sign;
	char		*result;

	sign = 0;
	if (arg < 0)
	{
		uarg = (uintmax_t)-arg;
		sign = 1;
	}
	else
		uarg = (uintmax_t)arg;
	if ((conv.flags & zero) != 0 && (conv.flags & plus) == 0 &&
		(conv.flags & space) == 0 && sign == 1)
		precision--;
	result = do_conv_ud(uarg, precision);
	if (sign == 1)
		result = ft_strjoinfree("-", result, 2);
	return (result);
}
