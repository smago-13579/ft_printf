/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 22:47:56 by smago             #+#    #+#             */
/*   Updated: 2020/07/05 23:31:45 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	width_display_str(t_print *text)
{
	while (text->width > text->s_len && text->sign == 0)
	{
		ft_putchar(' ');
		text->s_len++;
		text->len++;
	}
}

static int	display_str_str(t_print *text)
{
	int i;

	i = 0;
	text->s_len = ft_strlen(text->s);
	if (text->precision < 0)
		text->precision = 2147483647;
	if (text->s_len > text->precision)
		text->s_len = text->precision;
	width_display_str(text);
	while (i < text->precision && text->s[i] != '\0')
	{
		ft_putchar(text->s[i]);
		text->len++;
		i++;
	}
	if (text->sign < 0)
	{
		text->sign = 0;
		width_display_str(text);
	}
	return (0);
}

static int	display_str_null(t_print *text)
{
	if (!(text->s = ft_strdup("(null)")))
		return (ft_error(text));
	display_str_str(text);
	free(text->s);
	text->s = NULL;
	return (0);
}

int			display_str(t_print *text)
{
	if (!(text->s = va_arg(text->ap, char*)))
		return (display_str_null(text));
	else
		return (display_str_str(text));
}
