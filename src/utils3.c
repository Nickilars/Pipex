/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:59:08 by nrossel           #+#    #+#             */
/*   Updated: 2023/03/27 16:26:51 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* --------- child1 process --------------*/
static void	child1_process(int *fd, t_cmd cmd, char **env)
{
	
}

/* --------- child2 process --------------*/
static void	child1_process(int *fd, t_cmd cmd, char **env)
{
	
}

/* --------- exec_cmd --------------*/
void	exec_cmd(t_data cmd, char **envp)
{
	int	i;

	i = 0;
	cmd.status = 0;
	pipe(cmd.fd);
	cmd.pid1 = fork();
	if (cmd.pid1 < 0)
		return (perror("Fork_1"));
	if (!cmd.pid1)
		child1_process(cmd.fd, cmd.cmd1, envp);
	cmd.pid2 = fork();
	if (cmd.pid2 < 0)
		return (perror("Fork_2"));
	if (!cmd.pid2)
		child2_process(cmd.fd, cmd.cmd2, envp);
	close (cmd.fd[0]);
	close (cmd.fd[1]);
	waitpid (-1, &status, 0);
	waitpid (-1, &status, 0);
}
