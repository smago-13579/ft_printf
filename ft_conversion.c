/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 19:30:17 by smago             #+#    #+#             */
/*   Updated: 2020/07/12 20:05:29 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	other_char(t_print *text)
{
	if (text->str[text->i] == '%')
	{
		while (text->width > 1 && text->sign == 0)
		{
			if (text->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			text->width--;
			text->len++;
		}
		ft_putchar('%');
		text->len++;
		while (text->width > 1 && text->sign < 0)
		{
			ft_putchar(' ');
			text->width--;
			text->len++;
		}
		return (0);
	}
	else
		return (ft_error(text));
}

int			ft_conversion(t_print *text)
{
	int i;

	i = 0;
	text->i++;
	ft_width(text);
	if (text->str[text->i] == '.')
		ft_precision(text);
	if (text->str[text->i] == 'd' || text->str[text->i] == 'i' || \
		text->str[text->i] == 'u')
		i = display_id(text);
	else if (text->str[text->i] == 'x')
		i = hexadecimal(text, 1);
	else if (text->str[text->i] == 'X')
		i = hexadecimal(text, 0);
	else if (text->str[text->i] == 'p')
		i = hexadecimal2(text);
	else if (text->str[text->i] == 's')
		i = display_str(text);
	else if (text->str[text->i] == 'c')
		display_char(text);
	else
		return (other_char(text));
	return (i);
}
