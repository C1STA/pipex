/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:08:39 by wcista            #+#    #+#             */
/*   Updated: 2023/01/16 12:47:12 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putnbr_hexa(unsigned int n, char *base)
{
	int	len;

	len = 0;
	if (n < 16)
		len += ft_putchar(base[n]);
	if (n >= 16)
	{
		len += ft_putnbr_hexa(n / 16, base);
		len += ft_putnbr_hexa(n % 16, base);
	}
	return (len);
}
