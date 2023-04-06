/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 09:30:56 by nrossel           #+#    #+#             */
/*   Updated: 2023/04/06 10:22:23 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* ----------------------- trouver le chemin ------------------------- */
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

/* ----------------------- test de commande ------------------------- */
static char	*if_cmd_work(char *cmd, char **paths)
{
	char *path;

	if (access(cmd, X_OK) != 0)
	{
		ft_putendl_fd("Commande non-valide", 2)
		exit (1);
	}
	while (*paths)
	{
		path = ft_strjoin(path[i], cmd);
		if (access(path, X_OK) == 0)
			return (path);
		paths++;
	}
	ft_putendl_fd("Commande non-valide", 2);
	return (NULL);
}

/* ----------------------- lancer execve ------------------------- */
static void	ft_execve(char *cmd, t_data *cmd, char **envp)
{
	cmd->cmd.path = find_path(envp);
	cmd->args = ft_split(cmd, ' ');
	cmd->args[0] = if_cmd_work(cmd->args[0], data->cmd.path);
	dup2(cmd->infile, 0);
	dup2(cmd->pipe1[1], 1);
}

/* ----------------------- premier processus ------------------------- */
void	ft_first_process(char *cmd, t_data *data, char **envp);
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
		ft_close_pipe(data->pipe1[0], data->pipe2[1]);
		ft_execve(cmd, data, envp);
	}
	ft_new_pipe(&data->pipe1);
}

/* ----------------------- second processus ------------------------- */
void	ft_second_process(char *cmd, t_data *data, char **envp);
{
	
}
