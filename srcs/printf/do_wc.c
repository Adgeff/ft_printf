/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_wc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:53:08 by gargence          #+#    #+#             */
/*   Updated: 2016/10/07 18:28:20 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*do_conv_wc4(wint_t c)
{
	char	*result;

	if ((result = (char *)malloc(5 * sizeof(char))) == NULL)
		return (NULL);
	result[0] = (char)((c >> 18) | 0xF0);
	c = c & 0x3FFFF;
	result[1] = (char)((c >> 12) | 0x80);
	c = c & 0xFFF;
	result[2] = (char)((c >> 6) | 0x80);
	c = c & 0x3F;
	result[3] = (char)(c | 0x80);
	result[4] = '\0';
	return (result);
}

static char	*do_conv_wc3(wint_t c)
{
	char	*result;

	if ((result = (char *)malloc(4 * sizeof(char))) == NULL)
		return (NULL);
	result[0] = (char)((c >> 12) | 0xE0);
	c = c & 0xFFF;
	result[1] = (char)((c >> 6) | 0x80);
	c = c & 0x3F;
	result[2] = (char)(c | 0x80);
	result[3] = '\0';
	return (result);
}

static char	*do_conv_wc2(wint_t c)
{
	char	*result;

	if ((result = (char *)malloc(3 * sizeof(char))) == NULL)
		return (NULL);
	result[0] = (char)((c >> 6) | 0xC0);
	c = c & 0x3F;
	result[1] = (char)(c | 0x80);
	result[2] = '\0';
	return (result);
}

char		*do_conv_wc(wint_t c)
{
	char	*result;

	if (c >= 0x10000)
		result = do_conv_wc4(c);
	else if (c >= 0x800)
		result = do_conv_wc3(c);
	else if (c >= 0x80)
		result = do_conv_wc2(c);
	else
		return (do_conv_c((char)c));
	return (result);
}
