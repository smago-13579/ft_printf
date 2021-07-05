/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 23:47:10 by smago             #+#    #+#             */
/*   Updated: 2020/07/05 23:34:33 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_char(t_print *text)
{
	char c;

	c = va_arg(text->ap, int);
	while (text->width > 1 && text->sign == 0)
	{
		ft_putchar(' ');
		text->len++;
		text->width--;
	}
	ft_putchar(c);
	text->len++;
	while (text->width > 1 && text->sign == -1)
	{
		ft_putchar(' ');
		text->len++;
		text->width--;
	}
}
