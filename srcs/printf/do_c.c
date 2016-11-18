/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:30:45 by gargence          #+#    #+#             */
/*   Updated: 2016/09/30 17:40:52 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*do_conv_c(char c)
{
	char	*result;

	if ((result = (char *)malloc(2 * sizeof(char))) == NULL)
		return (NULL);
	result[0] = c;
	result[1] = '\0';
	return (result);
}
