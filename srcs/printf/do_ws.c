/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 18:47:50 by gargence          #+#    #+#             */
/*   Updated: 2016/10/07 18:25:41 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*do_conv_s_null(int precision)
{
	char	*result;

	result = ft_strdup("(null)");
	if (precision >= 0 && precision < (signed)ft_strlen(result))
		result[precision] = '\0';
	return (result);
}

char		*do_conv_ws(wchar_t *s, int precision)
{
	char	*result;
	char	*wc;
	size_t	i;

	if (s == NULL)
		return (do_conv_s_null(precision));
	if ((result = (char *)malloc(sizeof(char))) == NULL)
		return (NULL);
	*result = '\0';
	i = 0;
	while (s[i] != L'\0' && (precision < 0
		|| (signed)ft_strlen(result) < precision))
	{
		wc = do_conv_wc(s[i]);
		if ((signed)(ft_strlen(result) + ft_strlen(wc)) <= precision ||
			precision < 0)
			result = ft_strjoinfree(result, wc, 3);
		else
		{
			free(wc);
			return (result);
		}
		i++;
	}
	return (result);
}
