/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:30:56 by nrossel           #+#    #+#             */
/*   Updated: 2023/04/17 15:34:44 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* ----------------------- 1.trouver le chemin ------------------------- */
static char	**find_path(char **env)
{
	char	**path;

	while (*env)
	{
		if (ft_strncmp(*env, "PATH", 4) == 0)
			break ;
		env++;
	}
	path = ft_split(*env + 5, ':');
	return (path);
}

/* ----------------------- 2.test de commande ------------------------- */
static char	*if_cmd_work(char *cmd, char **paths)
{
	char	*path;
	int		i;

	if ((ft_strncmp(cmd, "./", 2) == 0)
		&& access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		if (!*path)
			ft_exit(1, "strjoin: paths + '/' = fail");
		path = ft_strjoin(path, cmd);
		if (!*path)
			ft_exit(1, "strjoin: path + cmd = fail");
		if (access(path, X_OK) == 0)
			return (path);
		i++;
	}
	ft_putendl_fd("Commande non-valide [1]", 2);
	return (NULL);
}

/* ----------------------- 3.lancer execve ------------------------- */
static void	ft_execve(char *cmd, int in, int out, char **env, int v)
{
	char	**path;
	char	**args;
	(void)	v;

	path = find_path(env);
	args = ft_split(cmd, ' ');
	args[0] = if_cmd_work(args[0], path);
	dup2(in, 0);
	dup2(out, 1);
	// ft_test(in, v);
	execve(args[0], args, env);
	ft_exit(1, "Error execve");
}

/* ----------------------- 4.premier processus ------------------------- */
void	first_process(char *cmd, int (*pipe1)[2], int (*pipe2)[2], char **envp)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		ft_exit(1, "Fork: erreur [1]");
	if (pid == 0)
	{
		ft_close_pipe((*pipe1)[1], (*pipe2)[0]);
		ft_execve(cmd, (*pipe1)[0], (*pipe2)[1], envp, 1);
	}
	ft_new_pipe(pipe1, 0);
}

/* ----------------------- 5.second processus ------------------------- */
void	secon_process(char *cmd, int (*pipe1)[2], int (*pipe2)[2], char **envp)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		ft_exit(1, "Fork: erreur [1]");
	if (pid == 0)
	{
		ft_close_pipe((*pipe1)[0], (*pipe2)[1]);
		ft_execve(cmd, (*pipe2)[0], (*pipe1)[1], envp, 2);
	}
	ft_new_pipe(pipe2, 0);
}
