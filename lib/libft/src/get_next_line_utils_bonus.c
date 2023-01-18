/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:06:32 by wcista            #+#    #+#             */
/*   Updated: 2023/01/16 12:46:42 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line_bonus.h"

void	ft_free_str(char **str)
{
	if (str != NULL && **str != '\0')
	{
		free(*str);
		*str = NULL;
	}
}

char	*ft_default_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	len;
	int		i;
	int		j;

	if ((!s1) && (!s2))
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	len = (i + j + 1);
	dest = malloc((len) * sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		dest[j++] = s1[i];
	i = -1;
	while (s2[++i])
		dest[j++] = s2[i];
	dest[j] = '\0';
	ft_free_str(&s1);
	return (dest);
}

char	*ft_ret(char *buffer, char *dest, int k)
{
	int	i;

	i = 0;
	k++;
	while (buffer[k])
		dest[i++] = buffer[k++];
	dest[i] = '\0';
	free(buffer);
	return (dest);
}

char	*ft_strjoin_n(char *s1)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	k = 0;
	if (!(s1))
		return (NULL);
	while (s1[k] != '\n' && s1[k])
		k++;
	dest = malloc(sizeof(char) * k + 2);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && i <= k)
	{
		dest[i] = s1[j];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
