/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 19:56:33 by smago             #+#    #+#             */
/*   Updated: 2020/07/13 10:35:29 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(t_print *text)
{
	while (text->id[text->iz] != '\0')
	{
		ft_putchar(text->id[text->iz]);
		text->iz++;
		text->len++;
	}
	free(text->id);
	text->id = NULL;
}
