/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 12:56:35 by gargence          #+#    #+#             */
/*   Updated: 2016/10/07 17:12:26 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printflist	*new_printflist(const char *data)
{
	t_printflist	*new_list;

	if (*data == '\0')
		return (NULL);
	if ((new_list = (t_printflist *)malloc(sizeof(t_printflist))) == NULL)
		exit(EXIT_FAILURE);
	new_list->data = (char *)data;
	if (*data == '%')
		new_list->type = '%';
	else if (*data == '{')
		new_list->type = '{';
	else
		new_list->type = 'f';
	new_list->next = NULL;
	return (new_list);
}

static const char	*go_end_conv(const char *format)
{
	format++;
	while (ft_strnstr("#0-+ ", format, 1) != NULL && *format != '\0')
		format++;
	while ((*format >= '0' && *format <= '9') || *format == '*')
		format++;
	if (*format == '.')
	{
		format++;
		while ((*format >= '0' && *format <= '9') || *format == '*')
			format++;
	}
	if (ft_strnstr("hljz", format, 1) != NULL && *format != '\0')
	{
		if (*format == *(format + 1) && ft_strnstr("hl", format, 1) != NULL)
			format = format + 2;
		else
			format++;
	}
	if (*format != '\0')
		format++;
	return (format);
}

static const char	*go_end(const char *format)
{
	if (*format == '%')
		format = go_end_conv(format);
	else if (*format == '{')
	{
		while (*format != '\0' && *format != '%' && *format != '}')
			format++;
		if (*format == '}')
			format++;
	}
	else
		while (*format != '\0' && *format != '%' && *format != '{')
			format++;
	return (format);
}

t_printflist		*cut_format(const char *format)
{
	t_printflist	*begin_list;
	t_printflist	*list;

	begin_list = NULL;
	while (*format != '\0')
	{
		if (begin_list == NULL)
		{
			begin_list = new_printflist(format);
			list = begin_list;
		}
		else
		{
			list->next = new_printflist(format);
			list = list->next;
		}
		format = go_end(format);
	}
	return (begin_list);
}
