/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 18:23:28 by smago             #+#    #+#             */
/*   Updated: 2020/07/02 17:48:30 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_error(t_print *text)
{
	va_end(text->ap);
	if (text->id)
	{
		free(text->id);
		text->id = NULL;
	}
	free(text);
	return (-1);
}
