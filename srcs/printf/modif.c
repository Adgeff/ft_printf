/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 18:15:52 by gargence          #+#    #+#             */
/*   Updated: 2016/10/07 14:48:18 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cmp_all_str(char *str, char **strs, size_t max)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < max)
	{
		i = 0;
		while (str[i] != '\0' && str[i] == strs[j][i])
			i++;
		if (strs[j][i] == '\0')
			return (j);
		j++;
	}
	return (-1);
}

static int	str_modif(t_printflist *list, char ***modifs)
{
	char	*data_str;
	char	*str;
	int		ret;
	size_t	i;

	data_str = (char *)list->data;
	if ((str = (char *)malloc(1)) == NULL)
		return (-1);
	i = 1;
	*str = '\0';
	while ((ret = cmp_all_str(data_str + i, modifs[0], MODIFS)) != -1)
	{
		str = ft_strjoinfree(str, modifs[1][ret], 1);
		while (data_str[i] != '\0' && data_str[i] != '}' &&
			data_str[i] != ' ' && data_str[i] != ',')
			i++;
		while (data_str[i] == ',' || data_str[i] == ' ')
			i++;
	}
	list->type = 'm';
	list->data = str;
	return (ft_strlen(str));
}

int			converse_to_text(t_printflist *list)
{
	size_t	i;
	char	*str;

	i = 1;
	while (list->data[i] != '\0' && list->data[i] != '}' &&
		list->data[i] != '%')
		i++;
	if (list->data[i] == '}')
		i++;
	if ((str = (char *)malloc(i + 1)) == NULL)
		return (-1);
	str = ft_strncpy(str, list->data, i);
	list->data = str;
	list->type = 's';
	return (ft_strlen(list->data));
}

int			converse_modif(t_printflist *list, char ***modifs)
{
	char	*str;
	size_t	i;

	str = (char *)list->data;
	i = 1;
	while (cmp_all_str(str + i, modifs[0], MODIFS) != -1)
	{
		while (str[i] != '\0' && str[i] != '}' && str[i] != ' ' &&
			str[i] != ',')
			i++;
		while (str[i] == ',' || str[i] == ' ')
			i++;
	}
	if (str[i] != '}')
		return (converse_to_text(list));
	return (str_modif(list, modifs));
}
