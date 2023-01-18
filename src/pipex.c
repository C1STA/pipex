/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcista <wcista@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:06:05 by wcista            #+#    #+#             */
/*   Updated: 2023/01/18 17:47:43 by wcista           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/* void	pipex(int f1, int f2, char *cmd1, char *cmd2)
{
	int		fd[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	if ((pipe(fd)) < 0)
		return (perror("Pipe : "));
	if ((child1 = fork()) < 0)
		return (perror("Fork(c1) : "));
	if (child1 == 0)
		child_one(f1, cmd1);
	if ((child2 = fork() < 0))
		return (perror("Fork(c2) : "));
	if (child2 == 0)
		child_two(f2, cmd2);
	close(fd[0]);
	close(fd[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}*/

int	main(int ac, char *av[], char *env[])
{
	t_p	*p;

	if (ac != 5)
		return (ft_printf("Error\nThere are not four arguments.\n"), 1);
	p = (t_p *)malloc(sizeof(t_p));
	if (!p)
		return (1);
	initialize_struct(p);
	get_data(p, av, env);
	free_everything(p);
	return (0);
}

// Dans le process child :
// On ouvre le fichier infile qui nous renvoie un fd.
// On utilise ce fd en tant qu'entree std pour que cmd1 lise depuis ce fichier.
// On ex
// On execute 

/* 	if ((execve(p->cmd1_path, p->cmd1_args, env)) == -1)
		perror("execve "); */

/* 	int		f1;
	int		f2;

	f1 = open(av[1], O_RDONLY);
	f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (-1);
	pipex(f1, f2, av, env); */

/* 	int		fd[2];
	pid_t	id;
	int		file;
	int		file2;

	if ((pipe(fd)) == -1)
	{
		perror("pipe");
		return (1);
	}
	if ((id = fork()) == -1)
	{
		perror("fork");
		return (1);
	}
	else if (id == 0)
	{
		close(fd[0]);
		file = open(av[1], O_RDONLY, 0777);
		dup2(file, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(file);
		execve(av[2], NULL, env);
	}
	else
	{
		wait(id);
		close(fd[1]);
		file2 = open(av[4], O_RDWR, 0644);
		dup2(fd[0], STDIN_FILENO);
		dup2(file2, STDOUT_FILENO);
		close(file2);
		execve(av[3], NULL, env);
	}
	return (0); */