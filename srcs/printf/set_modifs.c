/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_modifs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 19:52:57 by gargence          #+#    #+#             */
/*   Updated: 2016/09/21 13:30:11 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_names(char **names)
{
	names[0] = "END";
	names[1] = "BOLD";
	names[2] = "DARK";
	names[3] = "ITALICS";
	names[4] = "UNDERLINE";
	names[5] = "BLINK";
	names[6] = "HIGHLIGHT";
	names[7] = "BLACK";
	names[8] = "RED";
	names[9] = "GREEN";
	names[10] = "YELLOW";
	names[11] = "BLUE";
	names[12] = "MAGENTA";
	names[13] = "CYAN";
	names[14] = "NORMAL";
	names[15] = "BGNORMAL";
	names[16] = "BGRED";
	names[17] = "BGGREEN";
	names[18] = "BGYELLOW";
	names[19] = "BGBLUE";
	names[20] = "BGMAGENTA";
	names[21] = "BGCYAN";
	names[22] = "BGWHITE";
	names[23] = NULL;
}

static void	set_strings(char **strings)
{
	strings[0] = "\033[0m";
	strings[1] = "\033[1m";
	strings[2] = "\033[2m";
	strings[3] = "\033[3m";
	strings[4] = "\033[4m";
	strings[5] = "\033[5m";
	strings[6] = "\033[6m";
	strings[7] = "\033[30m";
	strings[8] = "\033[31m";
	strings[9] = "\033[32m";
	strings[10] = "\033[33m";
	strings[11] = "\033[34m";
	strings[12] = "\033[35m";
	strings[13] = "\033[36m";
	strings[14] = "\033[37m";
	strings[15] = "\033[40m";
	strings[16] = "\033[41m";
	strings[17] = "\033[42m";
	strings[18] = "\033[43m";
	strings[19] = "\033[44m";
	strings[20] = "\033[45m";
	strings[21] = "\033[46m";
	strings[22] = "\033[47m";
	strings[23] = NULL;
}

char		***set_modifs(void)
{
	char	***modifs;
	size_t	i;

	if ((modifs = (char ***)malloc(2 * sizeof(char **))) == NULL)
		return (NULL);
	if ((modifs[0] = (char **)malloc((MODIFS + 1) * sizeof(char *))) == NULL)
		return (NULL);
	if ((modifs[1] = (char **)malloc((MODIFS + 1) * sizeof(char *))) == NULL)
		return (NULL);
	set_names(modifs[0]);
	set_strings(modifs[1]);
	i = 0;
	while (i < MODIFS)
	{
		if (modifs[0][i] == NULL || modifs[1][i] == NULL)
			return (NULL);
		i++;
	}
	return (modifs);
}

void		free_modifs(char ***modifs)
{
	free(modifs[0]);
	free(modifs[1]);
	free(modifs);
}
