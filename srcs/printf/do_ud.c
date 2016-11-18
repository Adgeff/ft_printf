/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ud.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 17:49:28 by gargence          #+#    #+#             */
/*   Updated: 2016/10/03 19:44:47 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*do_conv_ud(uintmax_t arg, int precision)
{
	uintmax_t	power;
	int			size;
	char		*result;

	size = (arg == 0) ? 0 : 1;
	power = (arg == 0) ? 0 : 1;
	while (power != 0 && arg / power >= 10)
	{
		power = power * 10;
		size++;
	}
	if ((result = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	size = 0;
	while (power > 0)
	{
		result[size] = arg / power + '0';
		size++;
		arg = arg - (arg / power * power);
		power = power / 10;
	}
	result[size] = '\0';
	while ((signed)ft_strlen(result) < precision)
		result = ft_strjoinfree("0", result, 2);
	return (result);
}
