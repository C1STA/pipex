/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:06:29 by wcista            #+#    #+#             */
/*   Updated: 2023/01/16 12:46:32 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line_bonus.h"

int	ft_isback_n(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin_after_n(char *buffer)
{
	int		k;
	char	*dest;

	k = 0;
	while (buffer[k] != '\n' && buffer[k])
		k++;
	if (buffer[k] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	dest = malloc(sizeof(char) * (ft_strlen(buffer) - k));
	if (!dest)
		return (NULL);
	dest = ft_ret(buffer, dest, k);
	if (*dest == 0)
	{
		free(dest);
		return (NULL);
	}
	return (dest);
}

char	*ft_reader(int fd, char *buffer)
{
	int		n;
	char	*tmp;

	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	n = 1;
	while (ft_isback_n(buffer) != 0 && n != 0)
	{
		n = read(fd, tmp, BUFFER_SIZE);
		if (n == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[n] = '\0';
		if (tmp[0] != 0)
			buffer = ft_default_strjoin(buffer, tmp);
	}
	free(tmp);
	if (n == 0 && *buffer == '\0')
		return (NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[1024];

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = "";
	buffer[fd] = ft_reader(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_strjoin_n(buffer[fd]);
	buffer[fd] = ft_strjoin_after_n(buffer[fd]);
	return (line);
}
