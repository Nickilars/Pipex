/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:48:28 by nrossel           #+#    #+#             */
/*   Updated: 2023/03/27 16:26:54 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* --------- Main --------------*/
int	main(int ac, char **av, char **envp)
{
	t_data	data;
	t_cmd	cmd;

	if (ac != 5)
		return (ft_printf("Argument number invalide"));
	if (is_empty(av[2]) || is_empty(av[4]))
		return (1);
	data.infile = open(av[1], O_RDONLY);
	data.outfile = open(av[4], O_CREAT | O_RDONLY | O_TRUNC | 0644);
	if (data.infile < 0 || data.outfile < 0)
	{
		perror("infile | outfile opening fail")
		return (1);
	}
	if (ac == 5)
		pipex(&data, av, envp);
}
