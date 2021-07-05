/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 22:23:05 by smago             #+#    #+#             */
/*   Updated: 2020/07/12 19:33:06 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flag(t_print *text)
{
	while (text->str[text->i] == '0' || text->str[text->i] == ' ' || \
		text->str[text->i] == '-' || text->str[text->i] == '+' || \
		text->str[text->i] == '#')
	{
		if (text->str[text->i] == '0')
			text->zero = 1;
		if (text->str[text->i] == ' ')
			text->space = 1;
		if (text->str[text->i] == '-')
			text->sign = -1;
		if (text->str[text->i] == '+')
			text->plus = 1;
		if (text->str[text->i] == '#')
			text->grid = 1;
		text->i++;
	}
}

void		ft_width(t_print *text)
{
	flag(text);
	if (text->str[text->i] == '*')
	{
		text->width = va_arg(text->ap, int);
		text->i++;
	}
	while (text->str[text->i] >= '0' && text->str[text->i] <= '9')
	{
		text->width = (text->width * 10) + (text->str[text->i] - 48);
		text->i++;
	}
	if (text->width < 0)
	{
		text->width = -text->width;
		text->sign = -1;
	}
}
