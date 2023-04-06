/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:16:21 by nrossel           #+#    #+#             */
/*   Updated: 2023/04/06 09:53:32 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* ----------------------- initialisation ------------------------- */
void	ft_init(t_data *data, char **av, int ac)
{
	data->cmd.args = 0;
	data->cmd.cmd = 0;
	data->cmd.path = 0;
	ft_new_pipe(&data->pipe1);
	ft_new_pipe(&data->pipe2);
	data->infile = open(av[1], O_RDONLY);
	data->outfile = open(av[ac - 1], O_CREAT | O_RDONLY | O_TRUNC | 0644);
	if (data.infile < 0 || data.outfile < 0)
	{
		perror("infile | outfile opening fail")
		exit (1);
	}
}

/* ----------------------- check si fichier vide ------------------------- */
void	is_empty(char *str, char *file)
{
	if (!str || !*str)
	{
		ft_putendl_fd(file, 2);
		exit(1);
	}
}

/* ----------------------- fonction pipe ------------------------- */
void	ft_new_pipe(int (*fd)[2])
{
	ft_close_pipe((*fd)[0], (*fd)[1]);
	pipe((*fd));
}

void	ft_close_pipe(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
