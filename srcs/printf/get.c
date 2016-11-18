/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:28:55 by gargence          #+#    #+#             */
/*   Updated: 2016/10/07 18:29:34 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_flags(char *str, t_format *conv)
{
	if (*str == '#')
		conv->flags = conv->flags | sharp;
	else if (*str == '0')
		conv->flags = conv->flags | zero;
	else if (*str == '-')
		conv->flags = conv->flags | minus;
	else if (*str == '+')
		conv->flags = conv->flags | plus;
	else if (*str == ' ')
		conv->flags = conv->flags | space;
	else
		return (str);
	return (get_flags(str + 1, conv));
}

int			get_width(char *str, va_list ap)
{
	int		i;

	if ((*str < '0' || *str > '9') && *str != '*')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '*')
		return (va_arg(ap, int));
	return (ft_atoi(str));
}

int			get_precision(char *str, va_list ap)
{
	int		i;

	if (*str != '.')
		return (-1);
	str++;
	if ((*str < '0' || *str > '9') && *str != '*')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '*')
		return (va_arg(ap, int));
	return (ft_atoi(str));
}

char		get_modifier(char *str)
{
	char	modifier;

	modifier = '\0';
	if (*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z')
	{
		modifier = *str;
		str++;
		if (modifier == *str)
			modifier++;
	}
	return (modifier);
}

void		get_adapt(t_format *conv)
{
	if (ft_strnstr("DOUCS", conv->conversion, 1) != NULL)
		conv->modifier = 'l';
	if (((conv->flags & minus) != 0 || conv->precision != -1) &&
		(conv->flags & zero) != 0)
		conv->flags = conv->flags - zero;
	if ((conv->flags & plus) != 0 && (conv->flags & space) != 0)
		conv->flags = conv->flags - space;
	if (*(conv->conversion) == 'p')
	{
		conv->flags = conv->flags | sharp;
		conv->modifier = 'l';
	}
	if ((conv->flags & zero) != 0 && conv->width != -1 && conv->precision == -1)
	{
		conv->precision = conv->width;
		if ((*(conv->conversion) == 'd' || *(conv->conversion) == 'i') &&
			((conv->flags & plus) != 0 || (conv->flags & space) != 0))
			conv->precision--;
		if ((*(conv->conversion) == 'x' || *(conv->conversion) == 'X' ||
			*(conv->conversion) == 'p') && (conv->flags & sharp) != 0)
			conv->precision = conv->precision - 2;
	}
	if (ft_strnstr("dDioOuUxXp", conv->conversion, 1) != NULL &&
		conv->precision == -1)
		conv->precision = 1;
}
