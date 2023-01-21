/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:07:02 by wcista            #+#    #+#             */
/*   Updated: 2023/01/21 18:51:37 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error_return(t_p *p, char *av[], int n)
{
	if (n == 0)
	{
		write(2, p->cmd_args[0], ft_strlen(p->cmd_args[0]));
		write(2, ": command not found\n", 20);
	}
	if (n == 1)
		perror(av[1]);
	free_everything(p);
	exit(EXIT_FAILURE);
}
