/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:16:21 by nrossel           #+#    #+#             */
/*   Updated: 2023/04/17 11:18:59 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* ----------------------- 1.initialisation ------------------------- */
int	ft_init(int in_or_out, char **av, int ac)
{
	int	in;
	int	out;

	if (in_or_out == 0)
	{
		(void) ac;
		in = open(av[1], O_RDONLY);
		if (in < 0)
			ft_exit(1, "infile opening fail");
		return (in);
	}
	if (in_or_out == 1)
	{
		if (access(av[ac - 1], F_OK) == 0)
			unlink(av[ac - 1]);
		out = open(av[ac - 1], O_CREAT | O_WRONLY, 0777);
		if (out < 0)
			ft_exit(1, "outfile opening fail");
		return (out);
	}
	return (-1);
}

/* ----------------------- 2.check si fichier vide ------------------------- */
void	is_empty(char *str, char *file)
{
	if (!str || !*str)
		ft_exit(1, file);
}

/* ----------------------- 3.nouveau pipe ------------------------- */
void	ft_new_pipe(int (*fd)[2])
{
	ft_close_pipe((*fd)[0], (*fd)[1]);
	pipe((*fd));
}

/* ----------------------- 4.fermer pipe ------------------------- */
void	ft_close_pipe(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
