# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smago <smago@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/30 19:57:23 by smago             #+#    #+#              #
#    Updated: 2020/07/13 19:32:50 by smago            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_A = libft.a

LIBDR = libft/

SRCS = display_char.c display_id.c display_str.c ft_conversion.c ft_error.c \
		ft_precision.c ft_printf.c ft_putchar.c ft_struct_initialize.c \
		ft_struct_reinitialize.c ft_untoa.c ft_width.c hexadecimal.c \
		hexadecimal2.c display_id_int.c ft_putstr.c

OBJECTS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror -I includes/

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_A)
	ar rc $@ $(OBJECTS)
	ranlib $(NAME)

$(LIBFT_A):
	make -C $(LIBDR)
	cp $(LIBDR)$(LIBFT_A) .
	mv $(LIBFT_A) $(NAME)

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	make -C $(LIBDR) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIBDR) fclean
	rm -f $(NAME)

bonus: all

re: fclean all