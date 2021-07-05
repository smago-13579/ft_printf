/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 09:49:27 by smago             #+#    #+#             */
/*   Updated: 2020/07/14 12:44:11 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	new_string(t_print *text, unsigned int nbr)
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

static int	char_num(unsigned int nbr)
{
	int i;

	i = 1;
	while (nbr >= 16)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

static void	grid(t_print *text, int i)
{
	if (text->grid == 1)
	{
		text->id[0] = '0';
		text->id[1] = 'x';
	}
	if (i == 0)
	{
		while (text->id[i])
		{
			text->id[i] = ft_toupper(text->id[i]);
			i++;
		}
	}
}

int			hexadecimal(t_print *text, int i)
{
	unsigned int nbr;

	nbr = va_arg(text->ap, unsigned int);
	text->s_len = char_num(nbr);
	if (text->grid == 1)
		text->s_len += 2;
	if (!(text->id = (char*)malloc(sizeof(char) * (text->s_len + 1))))
		return (ft_error(text));
	text->id[text->s_len--] = '\0';
	new_string(text, nbr);
	if (text->precision == 0 && ft_strncmp(text->id, "0", 1) == 0)
	{
		free(text->id);
		if (!(text->id = ft_strdup("")))
			return (ft_error(text));
	}
	grid(text, i);
	return (display_id(text));
}
