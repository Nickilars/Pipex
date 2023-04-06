/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:44:20 by nrossel           #+#    #+#             */
/*   Updated: 2023/04/06 11:31:22 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* ----------------------- 3.contrôle des args ------------------------- */
void	check_args(int ac, char *infile, char *outfile)
{
	if (ac < 5)
	{
		ft_putendl_fd("Nombre d'arguments invalide", 2);
		exit(1);
	}
	is_empty(infile, "infile invalide");
	is_empty(outfile, "outfile invalide");
}

/* ------------------ 3.contrôle pipe de sortie ------------------- */
void	check_output(t_data data, int ac)
{
	if (ac % 2 == 0)
	{
		ft_write_outfile(data.outfile, data.pipe1[0]);
	}
	else
	{
		ft_write_outfile(data.outfile, data.pipe2[0]);
	}
}

void	ft_write_outfile(int outfile, int fd_in)
{
	char	buffer[1];
	int		c_read;

	if (outfile < 0)
		ft_exit(1, "outfile invalide");
	if (fd_in < 0)
		ft_exit(1, "fd_in invalide");
	c_read = read(fd_in, &buffer, sizeof(char));
	while (c_read > 0)
	{
		write(outfile, &buffer, 1);
		c_read = read(fd_in, &buffer, sizeof(char));
	}
}
