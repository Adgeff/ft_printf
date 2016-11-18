/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 18:14:59 by gargence          #+#    #+#             */
/*   Updated: 2016/10/07 16:47:16 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*sharp_flag(char *result, char conversion)
{
	if (conversion == 'o' || conversion == 'O')
		result = sharp_o(result);
	else if (conversion == 'x')
		result = sharp_x(result);
	else if (conversion == 'p')
		result = sharp_p(result);
	else if (conversion == 'X')
		result = sharp_upx(result);
	return (result);
}
