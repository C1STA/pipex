/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:52:20 by wcista            #+#    #+#             */
/*   Updated: 2023/04/05 16:30:33 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include "../lib/libft/inc/libft.h"

typedef struct s_pipex
{
	char	**paths;
	char	**cmd_args;
	char	*cmd_path;
	int		fd[2];
}	t_p;

// Free (the world)
void	free_everything(t_p *p);
void	free_tab(char **array);
void	error_return(t_p *p, char *s);

// Reading and treating data from arguments and environnement
void	get_paths(t_p *p, char *env[]);
void	get_data(t_p *p, char *av, char *env[]);
void	check_access(t_p *p);
void	initialize_struct(t_p *p);

#endif