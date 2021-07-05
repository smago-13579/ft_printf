/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:59:04 by smago             #+#    #+#             */
/*   Updated: 2020/07/13 19:51:54 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	new_string(t_print *text, size_t nbr)
{
	int i;

	if (nbr == 0)
		text->id[text->s_len--] = '0';
	while (nbr > 0)
	{
		i = nbr % 16;
		nbr /= 16;
		if (i < 10)
			text->id[text->s_len--] = i + '0';
		else if (i == 10)
			text->id[text->s_len--] = 'a';
		else if (i == 11)
			text->id[text->s_len--] = 'b';
		else if (i == 12)
			text->id[text->s_len--] = 'c';
		else if (i == 13)
			text->id[text->s_len--] = 'd';
		else if (i == 14)
			text->id[text->s_len--] = 'e';
		else if (i == 15)
			text->id[text->s_len--] = 'f';
	}
}

static int	char_num(size_t nbr)
{
	int i;

	i = 1;
	while (nbr >= 16)
	{
		nbr /= 16;
		i++;
	}
	i += 2;
	return (i);
}

int			hexadecimal2(t_print *text)
{
	size_t nbr;

	nbr = va_arg(text->ap, size_t);
	text->s_len = char_num(nbr);
	if (!(text->id = (char*)malloc(sizeof(char) * (text->s_len + 1))))
		return (ft_error(text));
	text->id[text->s_len--] = '\0';
	if (nbr == 0 && text->precision == 0)
		text->id[2] = '\0';
	else
		new_string(text, nbr);
	text->id[0] = '0';
	text->id[1] = 'x';
	return (display_id(text));
}
