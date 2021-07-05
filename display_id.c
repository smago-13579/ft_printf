/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 14:45:25 by smago             #+#    #+#             */
/*   Updated: 2020/07/13 19:28:13 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	precision_more_strlen(t_print *text)
{
	if (text->id[text->iz] == '-')
	{
		ft_putchar('-');
		text->len++;
		text->precision++;
		text->iz++;
	}
	while (text->precision > text->s_len)
	{
		ft_putchar('0');
		text->precision--;
		text->width--;
		text->len++;
	}
}

static void	width_display_id(t_print *text)
{
	while (text->width > text->s_len && text->width > text->precision)
	{
		if (text->zero == 1 && text->precision <= 0 && text->sign == 0)
		{
			if (text->id[text->iz] == '-')
			{
				ft_putchar('-');
				text->len++;
				text->iz++;
			}
			else if (text->plus == 1 && text->id[0] != '-')
			{
				ft_putchar('+');
				text->plus = 0;
			}
			ft_putchar('0');
		}
		else
			ft_putchar(' ');
		text->width--;
		text->len++;
	}
}

static void	display_plus(t_print *text)
{
	if (text->plus == 1 && text->sign == 0 && text->id[0] != '-')
	{
		ft_putchar('+');
		text->len++;
		text->plus = 0;
	}
}

static void	algorithm(t_print *text)
{
	if (text->sign == 0)
	{
		if (text->id[0] == '-' && text->precision > (text->s_len - 1))
			text->width--;
		width_display_id(text);
		display_plus(text);
		if (text->precision > text->s_len)
			precision_more_strlen(text);
		ft_putstr(text);
	}
	else if (text->sign < 0)
	{
		if (text->precision > text->s_len)
			precision_more_strlen(text);
		ft_putstr(text);
		width_display_id(text);
	}
}

int			display_id(t_print *text)
{
	if (display_id_int(text) == -1)
		return (-1);
	text->s_len = ft_strlen(text->id);
	if (text->width > text->precision && text->width > text->s_len)
		algorithm(text);
	else if (text->precision > text->s_len)
	{
		display_plus(text);
		precision_more_strlen(text);
		ft_putstr(text);
	}
	else
	{
		display_plus(text);
		ft_putstr(text);
	}
	return (0);
}
