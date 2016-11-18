/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gargence <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 10:00:44 by gargence          #+#    #+#             */
/*   Updated: 2016/10/07 18:34:57 by gargence         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

# define MODIFS 23

typedef enum			e_flags
{
	none = 0,
	sharp = 1,
	zero = 2,
	minus = 4,
	plus = 8,
	space = 16,
}						t_flags;

typedef struct			s_format
{
	t_flags				flags;
	int					width;
	int					precision;
	char				modifier;
	char				*conversion;
}						t_format;

typedef struct			s_printflist
{
	char				type;
	char				*data;
	struct s_printflist	*next;
}						t_printflist;

int						ft_printf(const char *format, ...);
t_printflist			*cut_format(const char *format);
char					***set_modifs(void);
t_printflist			*converse(t_printflist *begin_list, va_list ap,
						char ***modifs);
void					free_modifs(char ***modifs);
int						converse_text(t_printflist *list);
int						converse_conv(t_printflist *list, va_list ap);
int						converse_modif(t_printflist *list, char ***modifs);
char					*get_flags(char *str, t_format *conv);
int						get_width(char *str, va_list ap);
int						get_precision(char *str, va_list ap);
char					get_modifier(char *str);
void					get_adapt(t_format *conv);
char					*do_conv_int(t_format conv, va_list ap);
char					*do_conv_uint(t_format conv, va_list ap);
char					*do_conv_wchar(t_format conv, va_list ap);
char					*do_conv_char(t_format conv, va_list ap);
char					*do_conv_d(intmax_t arg, int precision, t_format conv);
char					*do_conv_ud(uintmax_t arg, int precision);
char					*do_conv_uo(uintmax_t arg, int precision);
char					*do_conv_uh(uintmax_t arg, int precision);
char					*do_conv_uuph(uintmax_t arg, int precision);
char					*do_conv_c(char c);
char					*do_conv_s(char *s, int precision);
char					*do_conv_wc(wint_t c);
char					*do_conv_ws(wchar_t *s, int precision);
char					*do_conv_end(char *p);
char					*sharp_flag(char *result, char conversion);
char					*sharp_o(char *result);
char					*sharp_x(char *result);
char					*sharp_p(char *result);
char					*sharp_upx(char *result);
char					*other_flags(char *result, t_format conv);
int						print_printflist(t_printflist *list);

#endif
