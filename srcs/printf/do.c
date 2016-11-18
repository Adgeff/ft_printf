/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 17:54:56 by gargence          #+#    #+#             */
/*   Updated: 2016/10/07 18:37:28 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*do_conv_int(t_format conv, va_list ap)
{
	char		*result;
	intmax_t	arg;

	result = NULL;
	if (conv.modifier == 'l')
		arg = (intmax_t)va_arg(ap, long);
	else if (conv.modifier == 'm')
		arg = (intmax_t)va_arg(ap, long long);
	else if (conv.modifier == 'h')
		arg = (intmax_t)((short)va_arg(ap, int));
	else if (conv.modifier == 'i')
		arg = (intmax_t)((char)va_arg(ap, int));
	else if (conv.modifier == 'j')
		arg = (intmax_t)va_arg(ap, intmax_t);
	else if (conv.modifier == 'z')
		arg = (intmax_t)va_arg(ap, ssize_t);
	else
		arg = (intmax_t)va_arg(ap, int);
	result = do_conv_d(arg, conv.precision, conv);
	return (result);
}

char			*do_conv_uint(t_format conv, va_list ap)
{
	uintmax_t	arg;

	if (conv.modifier == 'l')
		arg = (uintmax_t)va_arg(ap, unsigned long);
	else if (conv.modifier == 'm')
		arg = (uintmax_t)va_arg(ap, unsigned long long);
	else if (conv.modifier == 'h')
		arg = (uintmax_t)((unsigned short)va_arg(ap, unsigned int));
	else if (conv.modifier == 'i')
		arg = (uintmax_t)((unsigned char)va_arg(ap, unsigned int));
	else if (conv.modifier == 'j')
		arg = (uintmax_t)va_arg(ap, uintmax_t);
	else if (conv.modifier == 'z')
		arg = (uintmax_t)va_arg(ap, size_t);
	else
		arg = (intmax_t)va_arg(ap, unsigned int);
	if (*(conv.conversion) == 'u' || *(conv.conversion) == 'U')
		return (do_conv_ud(arg, conv.precision));
	else if (*(conv.conversion) == 'o' || *(conv.conversion) == 'O')
		return (do_conv_uo(arg, conv.precision));
	else if (*(conv.conversion) == 'x' || *(conv.conversion) == 'p')
		return (do_conv_uh(arg, conv.precision));
	else
		return (do_conv_uuph(arg, conv.precision));
}

char			*do_conv_wchar(t_format conv, va_list ap)
{
	char		*result;
	wint_t		c;
	wchar_t		*s;

	result = NULL;
	if (*(conv.conversion) == 'c' || *(conv.conversion) == 'C')
	{
		c = (wint_t)va_arg(ap, wint_t);
		result = do_conv_wc(c);
	}
	else if (*(conv.conversion) == 's' || *(conv.conversion) == 'S')
	{
		s = (wchar_t *)va_arg(ap, wchar_t *);
		result = do_conv_ws(s, conv.precision);
	}
	else
		result = do_conv_end(conv.conversion);
	return (result);
}

char			*do_conv_char(t_format conv, va_list ap)
{
	char		*result;
	char		c;
	char		*s;

	result = NULL;
	if (*(conv.conversion) == 'c')
	{
		c = (char)va_arg(ap, int);
		result = do_conv_c(c);
	}
	else if (*(conv.conversion) == 's')
	{
		s = (char *)va_arg(ap, char *);
		result = do_conv_s(s, conv.precision);
	}
	else
		result = do_conv_end(conv.conversion);
	return (result);
}
