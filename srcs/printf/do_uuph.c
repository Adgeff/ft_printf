/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_uuph.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:33:41 by gargence          #+#    #+#             */
/*   Updated: 2016/10/07 18:16:07 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*sharp_upx(char *result)
{
	if (ft_strlen(result) > 1 || (*result != '0' && *result != '\0'))
		result = ft_strjoinfree("0X", result, 2);
	return (result);
}

static char		uph_char(uintmax_t arg, uintmax_t power)
{
	if (arg / power <= 9)
		return (arg / power + '0');
	else
		return (arg / power - 10 + 'A');
}

char			*do_conv_uuph(uintmax_t arg, int precision)
{
	uintmax_t	power;
	int			size;
	char		*result;

	size = (arg == 0) ? 0 : 1;
	power = (arg == 0) ? 0 : 1;
	while (power != 0 && arg / power >= 16)
	{
		power = power * 16;
		size++;
	}
	if ((result = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	size = 0;
	while (power > 0)
	{
		result[size] = uph_char(arg, power);
		size++;
		arg = arg - (arg / power * power);
		power = power / 16;
	}
	result[size] = '\0';
	while ((signed)ft_strlen(result) < precision)
		result = ft_strjoinfree("0", result, 2);
	return (result);
}
