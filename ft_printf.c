/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:17:29 by smago             #+#    #+#             */
/*   Updated: 2020/07/02 18:05:59 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	result(t_print *text)
{
	int i;

	i = text->len;
	va_end(text->ap);
	free(text);
	return (i);
}

int			ft_printf(const char *str, ...)
{
	t_print *text;

	if (!(text = malloc(sizeof(t_print))))
		return (-1);
	va_start(text->ap, str);
	text->str = (char*)str;
	ft_struct_initialize(text);
	while (text->str[text->i])
	{
		if (text->str[text->i] == '%')
		{
			ft_struct_reinitialize(text);
			if (ft_conversion(text) == -1)
				return (-1);
		}
		else
		{
			ft_putchar(text->str[text->i]);
			text->len++;
		}
		text->i++;
	}
	return (result(text));
}
