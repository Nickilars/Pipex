/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:44:20 by nrossel           #+#    #+#             */
/*   Updated: 2023/04/06 09:15:43 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
