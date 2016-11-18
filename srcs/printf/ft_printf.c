/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 18:02:25 by gargence          #+#    #+#             */
/*   Updated: 2016/10/07 18:28:39 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			modifs_list(t_printflist *list)
{
	while (list != NULL)
	{
		if (list->type == '{')
			return (1);
		list = list->next;
	}
	return (0);
}

int					print_printflist(t_printflist *list)
{
	int				ret;
	t_printflist	*tmp;

	ret = 0;
	while (list != NULL)
	{
		if (list->type == 's' || list->type == '\0')
			ret = ret + ft_strlen(list->data);
		ft_putstr(list->data);
		if (list->type == '\0')
		{
			ft_putchar('\0');
			ret++;
		}
		tmp = list;
		list = list->next;
		free(tmp->data);
		free(tmp);
	}
	return (ret);
}

int					ft_printf(const char *format, ...)
{
	t_printflist	*list;
	char			***modifs;
	va_list			ap;

	modifs = NULL;
	if ((list = cut_format(format)) == NULL)
		return (0);
	if (modifs_list(list) == 1 && (modifs = set_modifs()) == NULL)
		exit(EXIT_FAILURE);
	va_start(ap, format);
	if (converse(list, ap, modifs) == NULL)
		exit(EXIT_FAILURE);
	va_end(ap);
	if (modifs != NULL)
		free_modifs(modifs);
	return (print_printflist(list));
}
