/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:34:06 by wcista            #+#    #+#             */
/*   Updated: 2023/01/18 16:59:09 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/* void	child_one(int f1, char *cmd1)
{
	dup2(f1, STDIN_FILENO);
}

void	child_two(int f2, char *cmd2)
{
} */

void	get_paths(t_p *p, char *env[])
{
	char	*path_line;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			path_line = ft_substr(env[i], 5, ft_strlen(env[i]));
		i++;
	}
	p->paths = ft_split(path_line, ':');
	i = 0;
	while (p->paths[i])
	{
		p->paths[i] = ft_strjoin_free(p->paths[i], "/");
		i++;
	}
	free(path_line);
	path_line = NULL;
}

void	check_access(t_p *p)
{
	int		i;
	char	*tmp;

	i = 0;
	while (p->paths[i])
	{
		p->cmd1_path = ft_strjoin(p->paths[i], p->cmd1_args[0]);
		if (!access(p->cmd1_path, F_OK | X_OK))
			return ;
		free(p->cmd1_path);
		i++;
	}
	perror("Access ");
	p->cmd1_path = NULL;
	error_return(p, 0);
}

int	check_raw_access(t_p *p, char *av[])
{
	char	**cmd;

	cmd = ft_split(av[2], ' ');
	if (!access(cmd[0], F_OK | X_OK))
	{
		p->cmd1_path = ft_substr(cmd[0], 0, ft_strlen(cmd[0]));
		p->cmd1_args = ft_split(av[2], ' ');
		free_tab(cmd);
		return (0);
	}
	free_tab(cmd);
	return (1);
}

void	get_data(t_p *p, char *av[], char *env[])
{
	if (check_raw_access(p, av))
	{
		get_paths(p, env);
		p->cmd1_args = ft_split(av[2], ' ');
		p->cmd2_args = ft_split(av[3], ' ');
		check_access(p);
	}
}

void	initialize_struct(t_p *p)
{
	p->paths = NULL;
	p->cmd1_args = NULL;
	p->cmd2_args = NULL;
	p->cmd1_path = NULL;
	p->cmd2_path = NULL;
}
