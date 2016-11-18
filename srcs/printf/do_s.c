/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:41:01 by gargence          #+#    #+#             */
/*   Updated: 2016/10/03 19:43:59 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*do_conv_s(char *s, int precision)
{
	int		slen;
	char	*result;

	if (s == NULL)
	{
		result = ft_strdup("(null)");
		if (precision >= 0 && precision < (signed)ft_strlen(result))
			result[precision] = '\0';
		return (result);
	}
	slen = ft_strlen(s);
	if (precision >= 0 && precision < slen)
		slen = precision;
	if ((result = (char *)malloc((slen + 1) * sizeof(char))) == NULL)
		return (NULL);
	result = ft_strncpy(result, s, slen);
	result[slen] = '\0';
	return (result);
}
