/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:59:47 by gargence          #+#    #+#             */
/*   Updated: 2016/10/06 21:55:11 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*do_conv_end(char *p)
{
	int		size;
	int		i;
	char	*result;

	if (*p == '\0')
		return (ft_strdup(""));
	if ((*p & 0xF0) == 0xF0)
		size = 4;
	else if ((*p & 0xE0) == 0xE0)
		size = 3;
	else if ((*p & 0xC0) == 0xC0)
		size = 2;
	else
		size = 1;
	if ((result = (char *)malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = p[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
