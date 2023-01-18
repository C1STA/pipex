/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:06:54 by wcista            #+#    #+#             */
/*   Updated: 2023/01/15 16:39:20 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	int				i;
	unsigned char	*p;

	i = 0;
	p = str;
	while (len--)
	{
		*(p + i) = (unsigned char)c;
		i++;
	}
	return (str);
}
