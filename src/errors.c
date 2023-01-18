/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:07:02 by wcista            #+#    #+#             */
/*   Updated: 2023/01/18 16:23:54 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error_return(t_p *p, int n)
{
	if (n == 0)
		ft_printf("Error\nThe command is not accessible.\n");
	free_everything(p);
	exit(EXIT_FAILURE);
}
