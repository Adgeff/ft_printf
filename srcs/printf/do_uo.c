/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_uo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:16:39 by gargence          #+#    #+#             */
/*   Updated: 2016/10/03 19:45:28 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*sharp_o(char *result)
{
	if (*result != '0')
		result = ft_strjoinfree("0", result, 2);
	return (result);
}

char			*do_conv_uo(uintmax_t arg, int precision)
{
	uintmax_t	power;
	int			size;
	char		*result;

	size = (arg == 0) ? 0 : 1;
	power = (arg == 0) ? 0 : 1;
	while (power != 0 && arg / power >= 8)
	{
		power = power * 8;
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
		power = power / 8;
	}
	result[size] = '\0';
	while ((signed)ft_strlen(result) < precision)
		result = ft_strjoinfree("0", result, 2);
	return (result);
}
