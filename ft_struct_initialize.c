/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_initialize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:52:04 by smago             #+#    #+#             */
/*   Updated: 2020/07/13 10:24:33 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_struct_initialize(t_print *text)
{
	text->i = 0;
	text->iz = 0;
	text->len = 0;
	text->width = 0;
	text->zero = 0;
	text->sign = 0;
	text->space = 0;
	text->plus = 0;
	text->grid = 0;
	text->precision = -1;
	text->s_len = 0;
	text->s = NULL;
	text->id = NULL;
}
