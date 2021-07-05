/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_id_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 09:44:29 by smago             #+#    #+#             */
/*   Updated: 2020/07/13 19:28:35 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	space(t_print *text)
{
	if (text->space == 1 && text->id[0] != '-' && text->plus == 0)
	{
		ft_putchar(' ');
		text->len++;
		text->width--;
	}
	else if (text->plus == 1 && text->id[0] != '-')
	{
		if (text->sign < 0)
		{
			ft_putchar('+');
			text->len++;
		}
		text->width--;
	}
}

int			display_id_int(t_print *text)
{
	if (text->str[text->i] == 'd' || text->str[text->i] == 'i' || \
		text->str[text->i] == 'u')
	{
		if (text->str[text->i] == 'd' || text->str[text->i] == 'i')
		{
			if (!(text->id = ft_itoa(va_arg(text->ap, int))))
				return (ft_error(text));
		}
		else if (text->str[text->i] == 'u')
		{
			if (!(text->id = ft_untoa(va_arg(text->ap, unsigned int))))
				return (ft_error(text));
		}
		if (ft_strncmp(text->id, "0", 1) == 0 && text->precision == 0)
		{
			free(text->id);
			if (!(text->id = ft_strdup("")))
				return (ft_error(text));
		}
	}
	space(text);
	return (0);
}
