/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:58:23 by nrossel           #+#    #+#             */
/*   Updated: 2023/03/24 10:02:41 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/include/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		fd1[2];
	int		fd2[2];
	int		infile;
	int		outfile;
	int		status;
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd;
	char	buffer[256];
	char	**args;
	char	**envp;
}	t_data;

#endif