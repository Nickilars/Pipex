/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:44:20 by nrossel           #+#    #+#             */
/*   Updated: 2023/04/17 11:41:39 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* ----------------------- 1.contrôle des args ------------------------- */
void	check_args(int ac, char *infile, char *outfile)
{
	if (ac < 5)
		ft_exit(1, "Argument numbers invalides");
	is_empty(infile, "infile invalide");
	is_empty(outfile, "outfile invalide");
}

/* ------------------ 2.contrôle pipe de sortie ------------------- */
void	check_output(int ac, char **av, int pipe1, int pipe2)
{
	printf("pipe1 on check_output = %d\n", pipe1);
	printf("pipe2 on check_output = %d\n", pipe2);
	if (ac % 2 == 0)
	{
		ft_write_outfile(pipe2, ac, av);
	}
	else
	{
		ft_write_outfile(pipe1, ac, av);
	}
}

/* ------------------ 3.sortie final ------------------- */
void	ft_write_outfile(int fd_in, int ac, char **av)
{
	char	buffer[1];
	int		c_read;
	int		outfile;

	outfile = ft_init(1, av, ac);
	if (outfile < 0)
		ft_exit(1, "outfile invalide");
	if (fd_in < 0)
		ft_exit(1, "fd_in invalide");
	c_read = read(fd_in, &buffer, sizeof(char));
	if (c_read < 0)
		ft_exit(1, "Error while read()");
	while (c_read > 0)
	{
		write(outfile, &buffer, 1);
		c_read = read(fd_in, &buffer, sizeof(char));
	}
	// while (1)
}

void	ft_test(int fd_in, int v)
{
	char	buffer[1];
	int		c_read;

	c_read = read(fd_in, &buffer, sizeof(char));
	if (c_read < 0)
		ft_exit(1, "Error with read");
	if (c_read == 0)
		ft_exit(1, "Error, no char read");
	while (c_read > 0)
	{
		ft_putchar_fd(buffer[0], 2);
		c_read = read(fd_in, &buffer, sizeof(char));
	}
	if (v == 1)
		ft_putstr_fd ("1\n", 2);
	else
		ft_putstr_fd ("2\n", 2);
}
