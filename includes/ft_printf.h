/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:22:19 by smago             #+#    #+#             */
/*   Updated: 2020/07/13 10:23:24 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_print
{
	va_list		ap;
	int			i;
	int			iz;
	int			len;
	int			width;
	int			zero;
	int			sign;
	int			space;
	int			plus;
	int			grid;
	int			precision;
	int			s_len;
	char		*id;
	char		*s;
	char		*str;
}				t_print;

int				ft_printf(const char *str, ...);
void			ft_struct_initialize(t_print *text);
void			ft_struct_reinitialize(t_print *text);
void			ft_width(t_print *text);
void			ft_precision(t_print *text);
int				ft_conversion(t_print *text);
int				display_id(t_print *text);
int				display_id_int(t_print *text);
int				display_str(t_print *text);
void			display_char(t_print *text);
void			ft_putchar(char c);
void			ft_putstr(t_print *text);
char			*ft_untoa(unsigned int n);
int				hexadecimal(t_print *text, int i);
int				hexadecimal2(t_print *text);
int				ft_error(t_print *text);

#endif
