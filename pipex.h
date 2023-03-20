/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:58:23 by nrossel           #+#    #+#             */
/*   Updated: 2023/03/20 18:33:32 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/include/libft.h"
# include <sys/type.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		fd[2];
	int		infile;
	int		outfile;
	int		status;
	pid_t	child1;
	pid_t	child2;
}	t_data;

#endif