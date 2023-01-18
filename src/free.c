/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:35:52 by wcista            #+#    #+#             */
/*   Updated: 2023/01/18 17:45:31 by wcista           ###   ########.fr       */
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
	if (p->cmd1_args)
		free_tab(p->cmd1_args);
	if (p->cmd2_args)
		free_tab(p->cmd2_args);
	if (p->cmd1_path)
		free(p->cmd1_path);
	if (p->cmd2_path)
		free(p->cmd2_path);
	free(p);
}
