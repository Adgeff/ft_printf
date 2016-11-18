/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converse_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 13:40:55 by gargence          #+#    #+#             */
/*   Updated: 2016/10/07 17:22:06 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_format	get_conv(t_printflist *list, va_list ap)
{
	char		*str;
	t_format	conv;

	str = ((char *)list->data) + 1;
	conv.flags = none;
	str = get_flags(str, &conv);
	conv.width = get_width(str, ap);
	while ((*str >= '0' && *str <= '9') || *str == '*')
		str++;
	conv.precision = get_precision(str, ap);
	while ((*str >= '0' && *str <= '9') || *str == '*' || *str == '.')
		str++;
	conv.modifier = get_modifier(str);
	if (ft_strnstr("hljz", str, 1) != NULL && *str != '\0')
	{
		if (*str == *(str + 1) && (*str == 'l' || *str == 'h'))
			str = str + 2;
		else
			str++;
	}
	conv.conversion = str;
	get_adapt(&conv);
	return (conv);
}

static void		*do_conv(t_format conv, va_list ap)
{
	char		*result;

	if (ft_strnstr("dDi", conv.conversion, 1) != NULL)
		result = do_conv_int(conv, ap);
	else if (ft_strnstr("oOuUpxX", conv.conversion, 1) != NULL)
		result = do_conv_uint(conv, ap);
	else if (conv.modifier == 'l')
		result = do_conv_wchar(conv, ap);
	else
		result = do_conv_char(conv, ap);
	return (result);
}

int				converse_conv(t_printflist *list, va_list ap)
{
	t_format	conv;
	char		*result;

	conv.flags = none;
	conv = get_conv(list, ap);
	if (*conv.conversion != '\0')
		result = do_conv(conv, ap);
	else
		result = ft_strdup("");
	if ((*(conv.conversion) == 'c' || *(conv.conversion) == 'C') &&
		*result == '\0')
	{
		list->type = '\0';
		conv.width--;
	}
	if ((conv.flags & sharp) != 0)
		result = sharp_flag(result, *(conv.conversion));
	result = other_flags(result, conv);
	if (result == NULL)
		return (-1);
	list->data = result;
	if (list->type != '\0')
		list->type = 's';
	return (ft_strlen(result));
}
