/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:35:52 by wcista            #+#    #+#             */
/*   Updated: 2023/01/21 17:08:00 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_tab(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_everything(t_p *p)
{
	if (p->paths)
		free_tab(p->paths);
	if (p->cmd_args)
		free_tab(p->cmd_args);
	if (p->cmd_path)
		free(p->cmd_path);
	free(p);
}
