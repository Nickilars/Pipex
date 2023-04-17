/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:48:28 by nrossel           #+#    #+#             */
/*   Updated: 2023/04/17 11:39:59 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* --------- Main --------------*/
int	main(int ac, char **av, char **envp)
{
	int		pipe1[2];
	int		pipe2[2];
	int		i;
	int		status;

	check_args(ac, av[1], av[ac - 1]);
	ft_new_pipe(&pipe1);
	ft_new_pipe(&pipe2);
	pipe1[0] = ft_init(0, av, ac);
	printf("Pipe1 on main = %d\n", pipe1[0]);
	i = 0;
	while (i < ac - 3)
	{
		if (i % 2 == 0)
			first_process(*(av + 2), &pipe1, &pipe2, envp);
		else
			secon_process(*(av + 2), &pipe1, &pipe2, envp);
		i++;
	}
	ft_close_pipe(pipe1[1], pipe2[1]);
	while (i-- > 0)
		wait(&status);
	check_output(ac, av, pipe1[0], pipe2[0]);
}
