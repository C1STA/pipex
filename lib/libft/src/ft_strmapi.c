/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 05:02:55 by wcista            #+#    #+#             */
/*   Updated: 2023/01/15 16:41:24 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*map;

	i = -1;
	map = ft_strdup(s);
	if (!map)
		return (NULL);
	while (s[++i])
		map[i] = (*f)(i, s[i]);
	map[i] = '\0';
	return (map);
}
