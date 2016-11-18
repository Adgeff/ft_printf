/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 16:40:30 by gargence          #+#    #+#             */
/*   Updated: 2016/10/06 23:55:04 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					converse_text(t_printflist *list)
{
	char			*data_str;
	char			*str;
	size_t			i;

	data_str = (char *)list->data;
	i = 0;
	while (data_str[i] != '\0' && data_str[i] != '%' && data_str[i] != '{')
		i++;
	if ((str = (char *)malloc(i + 1)) == NULL)
		return (-1);
	i = 0;
	while (data_str[i] != '\0' && data_str[i] != '%' && data_str[i] != '{')
	{
		str[i] = data_str[i];
		i++;
	}
	str[i] = '\0';
	list->type = 's';
	list->data = str;
	return (ft_strlen(str));
}

t_printflist		*converse(t_printflist *begin_list, va_list ap,
					char ***modifs)
{
	t_printflist	*list;

	list = begin_list;
	while (list != NULL)
	{
		if (list->type == '%')
		{
			if (converse_conv(list, ap) == -1)
				return (NULL);
		}
		else if (list->type == '{')
		{
			if (converse_modif(list, modifs) == -1)
				return (NULL);
		}
		else
		{
			if (converse_text(list) == -1)
				return (NULL);
		}
		list = list->next;
	}
	return (begin_list);
}
