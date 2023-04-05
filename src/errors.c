/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:07:02 by wcista            #+#    #+#             */
/*   Updated: 2023/04/05 16:41:42 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error_return(t_p *p, char *s)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": ", 2);
	perror("");
	free_everything(p);
	exit(EXIT_FAILURE);
}
