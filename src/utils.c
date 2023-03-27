/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:13:27 by nrossel           #+#    #+#             */
/*   Updated: 2023/03/27 16:02:17 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* --------- init_cmd --------------*/
static void	init_cmd(int fd_file, t_cmd *cmd)
{
	cmd->args = 0;
	cmd->cmd = 0;
	cmd->path = 0;
	cmd->f = fd_file;
}

/* --------- get_path --------------*/
char	**get_path(char **envp)
{
	char	**ret;
	char	*env;
	int		i;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			env = ft_substr(envp[i], 6, ft_strlen(envp[i]));
			if (!env)
				return (NULL);
			ret = pipex_split(envp[i], ':');
			if (!ret)
			{
				free(env);
				return (NULL);
			}
			free(env);
			return (ret);
		}
	}
	return (NULL);
}

/* --------- get_cmd --------------*/
static int	get_cmd(char **envp, t_cmd *data_cmd, char *cmd)
{
	int		i;
	char	**tmp;

	i = -1;
	data_cmd->path = get_path(envp);
	if (!data_path)
		return (1);
	tmp = pipex_split(cmd, ' ');
	if (!tmp)
		return (1);
	data_cmd->cmd = ft_substr(tmp[i + 1], 0, ft_strlen(tmp[i + 1]));
	if (!data_cmd->cmd)
		return (ft_free_2da(tmp, NULL));
	while (tmp[++i])
	{
		data_cmd->args[i] = ft_substr(tmp[i], 0, ft_strlen(tmp[i]));
		if (!data_cmd->args[i])
		{
			ft_free_2da(data_cmd->args[1], NULL);
			return (ft_free_2da(tmp, "Erreur ft_substr"));
		}
	}
	data_cmd->args[i] = '\0';
	free (tmp);
	return (0);
}

/* --------- check_cmd --------------*/
static int	check_cmp(t_cmd *cmd_data)
{
	int		i;
	char	*cmd;

	i = -1;
	while (cmd_data->path[++i])
	{
		cmd = ft_strjoin(cmd_data->path[i], cmd_data->cmd);
		if (!cmd)
			return (0);
		if (access(cmd, X_OK) != -1)
		{
			free(cmd);
			return (1);
		}
		free(cmd);
	}
	error_msg(cmd_data->cmd);
	return (0);
}

/* --------- pipex --------------*/
void	pipex(t_data *file, char **av, char **envp)
{
	init_cmd(file->infile, &file->cmd1);
	init_cmd(file->outfile, &file->cmd2);
	if (get_cmd(envp, file->cmd1, av[1]) && get_cmd(envp, file->cmd2, av[4]))
		return (free_all(&file->cmd1, &file->cmd2));
	if (!check_cmd(file->cmd1) || !check_cmd(file->cmd2))
		return (free_all(&file->cmd1, &file->cmd2));
	exec_cmd(file, envp);
	free_all(&file->cmd1, &file->cmd2);
}
