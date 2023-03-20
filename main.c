/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:48:28 by nrossel           #+#    #+#             */
/*   Updated: 2023/03/20 18:40:36 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int	main(int main, char **av, char **env)
{
	t_data	data;

	pipe(data.fd);
	if (!(access("infile", R_OK) == 0 || access("outfile", R_OK | W_OK) == 0))
		return (perror("Access infile | outfile: denied"));
	data.infile = open(av[1], O_RDONLY);
	data.outfile = open(av[1], O_WRONLY);
	data.child1 = fork();
	if (data.child1 < 0)
		return (perror("fork child1: "));
	if (data.child1)
	{
		//parent_process();
		close(data.fd1[1]); // close write side
		dup2(data.oufile, 1);
		close(data.infile);
		close(data.outfile);
	}
	else
	{
		//child_process();
		close(data.fd1[0]); // close read side
		dup2(data.infile, 0);
		close(data.infile);
		close(data.outfile);
	}
}
