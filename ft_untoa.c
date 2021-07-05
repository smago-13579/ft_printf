/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_untoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 21:41:10 by smago             #+#    #+#             */
/*   Updated: 2020/07/03 16:04:01 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_char(unsigned int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_untoa(unsigned int n)
{
	char	*str;
	int		i;

	i = num_char(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
	{
		return (NULL);
	}
	str[i--] = '\0';
	if (n == 0)
	{
		str[i] = '0';
	}
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
