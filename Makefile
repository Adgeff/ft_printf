# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gargence <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/03 19:18:31 by gargence          #+#    #+#              #
#    Updated: 2016/10/07 18:11:44 by gargence         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

PRINTFFILES =	converse.c\
				converse_conv.c\
				cut_format.c\
				do.c\
				do_c.c\
				do_d.c\
				do_end.c\
				do_s.c\
				do_ud.c\
				do_uh.c\
				do_uo.c\
				do_uuph.c\
				do_wc.c\
				do_ws.c\
				ft_printf.c\
				get.c\
				modif.c\
				other_flags.c\
				set_modifs.c\
				sharp_flag.c

PRINTFSRCS =	$(addprefix srcs/printf/, $(PRINTFFILES))

PRINTFOBJS =	$(PRINTFFILES:.c=.o)

LIBFTFILES =	ft_atoi.c\
				ft_bzero.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_lstadd.c\
				ft_lstaddend.c\
				ft_lstdel.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlen.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_memalloc.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memdel.c\
				ft_memmove.c\
				ft_memset.c\
				ft_power.c\
				ft_putchar.c\
				ft_putchar_fd.c\
				ft_putendl.c\
				ft_putendl_fd.c\
				ft_putnbr.c\
				ft_putnbr_fd.c\
				ft_putstr.c\
				ft_putstr_fd.c\
				ft_special_float.c\
				ft_sqrt.c\
				ft_strcat.c\
				ft_strchr.c\
				ft_strclr.c\
				ft_strcmp.c\
				ft_strcpy.c\
				ft_strdel.c\
				ft_strdup.c\
				ft_strequ.c\
				ft_striter.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strjoinfree.c\
				ft_strlcat.c\
				ft_strlen.c\
				ft_strmap.c\
				ft_strmapi.c\
				ft_strncat.c\
				ft_strncmp.c\
				ft_strncpy.c\
				ft_strnequ.c\
				ft_strnew.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strrev.c\
				ft_strsplit.c\
				ft_strstr.c\
				ft_strsub.c\
				ft_strtrim.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_wstrlen.c\
				get_next_line.c

LIBFTSRCS =		$(addprefix srcs/libft/, $(LIBFTFILES))

LIBFTOBJS =		$(LIBFTFILES:.c=.o)

CC =			gcc

FLAG =			-Wall -Wextra -Werror

INCLUDES =		includes/

COLOR =			\033[1;32m

END =			\033[0m

all : $(NAME)

$(NAME) :
	@echo "$(COLOR)Compilation...$(END)"
	@$(CC) -c $(FLAGS) $(PRINTFSRCS) $(LIBFTSRCS) -I $(INCLUDES)
	@echo "$(COLOR)Compilation done !$(END)"
	@echo "$(COLOR)Creating $(NAME)...$(END)"
	@ar -rc $(NAME) $(PRINTFOBJS) $(LIBFTOBJS)
	@ranlib $(NAME)
	@echo "$(COLOR)$(NAME) created !$(END)"

clean :
	@echo "$(COLOR)Deleting object files...$(END)"
	@rm -rf $(PRINTFOBJS) $(LIBFTOBJS)
	@echo "$(COLOR)Object files deledted !$(END)"

fclean : clean
	@echo "$(COLOR)Deleting $(NAME)...$(END)"
	@rm -rf $(NAME)
	@echo "$(COLOR)$(NAME) deleted !$(END)"

re : fclean all

easy : all clean

libft : $(LIBFT)

$(LIBFT) :
	@echo "$(COLOR)Compilation...$(END)"
	@$(CC) -c $(FLAGS) $(LIBFTSRCS) -I $(INCLUDES)
	@echo "$(COLOR)Compilation done !$(END)"
	@echo "$(COLOR)Creating $(LIBFT)...$(END)"
	@ar -rc $(LIBFT) $(LIBFTOBJS)
	@ranlib $(LIBFT)
	@echo "$(COLOR)$(LIBFT) created !$(END)"

libftclean :
	@echo "$(COLOR)Deleting object files...$(END)"
	@rm -rf $(LIBFTOBJS)
	@echo "$(COLOR)Object files deledted !$(END)"

libftfclean : libftclean
	@echo "$(COLOR)Deleting $(LIBFT)...$(END)"
	@rm -rf $(LIBFT)
	@echo "$(COLOR)$(LIBFT) deleted !$(END)"

libftre : libftfclean libft

libfteasy : libft libftclean

.PHONY : clean
