/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:31:16 by wcista            #+#    #+#             */
/*   Updated: 2023/01/15 16:41:32 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (!s)
		return (NULL);
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (i + 1)
	{
		if (s[i] == (unsigned char) c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
