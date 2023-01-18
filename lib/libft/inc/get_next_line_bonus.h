/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:06:34 by wcista            #+#    #+#             */
/*   Updated: 2023/01/15 15:15:02 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_reader(int fd, char *buffer);
int		ft_isback_n(char *str);
char	*ft_default_strjoin(char *s1, char *s2);
char	*ft_strjoin_after_n(char *buffer);
char	*ft_strjoin_n(char *s1);
char	*ft_ret(char *buffer, char *dest, int k);
void	ft_free_str(char **str);

#endif