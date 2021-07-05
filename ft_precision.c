/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 11:50:41 by smago             #+#    #+#             */
/*   Updated: 2020/06/27 21:31:42 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision(t_print *text)
{
	text->i++;
	text->precision = 0;
	if (text->str[text->i] == '*')
	{
		text->precision = va_arg(text->ap, int);
		text->i++;
	}
	while (text->str[text->i] >= '0' && text->str[text->i] <= '9')
	{
		text->precision = (text->precision * 10) + (text->str[text->i] - 48);
		text->i++;
	}
}
