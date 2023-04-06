/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:30:56 by nrossel           #+#    #+#             */
/*   Updated: 2023/04/06 12:37:44 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* ----------------------- 1.trouver le chemin ------------------------- */
static char	**find_path(char **env)
{
	char	**path;

	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", 4) == 0)
			break ;
		env++;
	}
	path = pipex_split(*env + 5, ':');
	return (path);
}

/* ----------------------- 2.test de commande ------------------------- */
static char	*if_cmd_work(char *cmd, char **paths)
{
	char	*path;

	// if ((ft_strncmp(cmd, "./", 2) == 0)
	// && access(cmd, X_OK) == 0)
	// {
		//return (ft_strdup(cmd));
	// }
	while (*paths)
	{
		path = ft_strjoin(*paths, cmd);
		if (access(path, X_OK) == 0)
			return (path);
		paths++;
	}
	ft_putendl_fd("Commande non-valide", 2);
	return (NULL);
}

/* ----------------------- 3.lancer execve ------------------------- */
static void	ft_execve(char *cmd, int in, int out, char **env)
{
	char	**path;
	char	**args;

	path = find_path(env);
	args = ft_split(cmd, ' ');
	args[0] = if_cmd_work(args[0], path);
	dup2(in, 0);
	dup2(out, 1);
	execve(args[0], args, env);
}

/* ----------------------- 4.premier processus ------------------------- */
void	ft_first_process(char *cmd, t_data *data, char **envp, int index)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_putendl_fd("Fork: erreur", 2);
		exit (1);
	}
	if (pid == 0)
	{
		if (index != 0)
		{
			ft_close_pipe(data->pipe1[0], data->pipe2[1]);
			ft_execve(cmd, data->pipe2[0], data->pipe1[1], envp);
		}
		else
		{
			ft_close_pipe(data->pipe1[0], data->pipe2[0]);
			ft_execve(cmd, data->infile, data->pipe1[1], envp);
		}
	}
	ft_new_pipe(&data->pipe1);
}

/* ----------------------- 5.second processus ------------------------- */
void	ft_second_process(char *cmd, t_data *data, char **envp)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_putendl_fd("Fork: erreur", 2);
		exit (1);
	}
	if (pid == 0)
	{
		ft_close_pipe(data->pipe2[0], data->pipe1[1]);
		ft_execve(cmd, data->pipe1[0], data->pipe2[1], envp);
	}
	ft_new_pipe(&data->pipe2);
}
