/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:48:28 by nrossel           #+#    #+#             */
/*   Updated: 2023/04/06 11:42:10 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* --------- Main --------------*/
int	main(int ac, char **av, char **envp)
{
	t_data	data;
	int		i;

	check_args(ac, av[1], av[ac - 1]);
	ft_init(&data, av, ac);
	i = 0;
	while (i < ac - 3)
	{
		if (i % 2 == 0)
			ft_first_process(*(av + 2), &data, envp, i);
		else
			ft_second_process(*(av + 2), &data, envp);
		i++;
	}
	ft_close_pipe(data.pipe1[1], data.pipe2[1]);
	while (i-- < 0)
		wait(&data.status);
	check_output(data, ac - 3);
}
