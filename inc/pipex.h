/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:52:20 by wcista            #+#    #+#             */
/*   Updated: 2023/01/18 15:27:20 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include "../lib/libft/inc/libft.h"

typedef struct s_pipex
{
	char	**paths;
	char	**cmd1_args;
	char	**cmd2_args;
	char	*cmd1_path;
	char	*cmd2_path;
}	t_p;

// Free (the world)
void	free_everything(t_p *p);
void	free_tab(char **array);
void	error_return(t_p *p, int n);

// Reading and treating data from arguments and environnement
void	get_paths(t_p *p, char *env[]);
void	get_data(t_p *p, char *av[], char *env[]);
void	check_access(t_p *p);
void	initialize_struct(t_p *p);

#endif