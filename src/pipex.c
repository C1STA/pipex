/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:06:05 by wcista            #+#    #+#             */
/*   Updated: 2023/01/21 20:04:48 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_one(t_p *p, char *av[], char *env[])
{
	int	infile;

	close (p->fd[0]);
	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		error_return(p, av, 1);
	dup2(infile, STDIN_FILENO);
	dup2(p->fd[1], STDOUT_FILENO);
	close(p->fd[1]);
	close(infile);
	get_data(p, av[2], env);
	if ((execve(p->cmd_path, p->cmd_args, env)) < 0)
		error_return(p, av, 0);
}

void	child_two(t_p *p, char *av[], char *env[])
{
	int	outfile;

	close(p->fd[1]);
	initialize_struct(p);
	outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile < 0)
		error_return(p, av, 1);
	dup2(outfile, STDOUT_FILENO);
	dup2(p->fd[0], STDIN_FILENO);
	close(p->fd[0]);
	close(outfile);
	get_data(p, av[3], env);
	if ((execve(p->cmd_path, p->cmd_args, env)) < 0)
		error_return(p, av, 0);
}

void	pipex(t_p *p, char *av[], char *env[])
{
	int		status;
	pid_t	child1;
	pid_t	child2;

	if ((pipe(p->fd)) < 0)
		return (perror("pipe"));
	child1 = fork();
	if (child1 < 0)
		return (perror("fork"));
	if (child1 == 0)
		child_one(p, av, env);
	child2 = fork();
	if (child2 < 0)
		return (perror("fork"));
	if (child2 == 0)
		child_two(p, av, env);
	close(p->fd[0]);
	close(p->fd[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

int	main(int ac, char *av[], char *env[])
{
	t_p		*p;

	if (ac != 5)
		return (ft_printf("Error\nThere are not four arguments.\n"), 1);
	p = (t_p *)malloc(sizeof(t_p));
	if (!p)
		return (1);
	initialize_struct(p);
	pipex(p, av, env);
	free_everything(p);
	return (0);
}
