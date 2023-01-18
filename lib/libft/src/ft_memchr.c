/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:45:58 by wcista            #+#    #+#             */
/*   Updated: 2023/01/15 16:39:09 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;
	size_t			i;

	i = 0;
	p_s = (unsigned char *) s;
	while (i < n)
	{
		if (p_s[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
