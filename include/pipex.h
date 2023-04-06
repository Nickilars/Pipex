/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:58:23 by nrossel           #+#    #+#             */
/*   Updated: 2023/04/06 12:32:35 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	int		pipe1[2];
	int		pipe2[2];
	int		infile;
	int		outfile;
	int		status;
}	t_data;

void	is_empty(char *str, char *file);
void	ft_new_pipe(int (*fd)[2]);
void	ft_close_pipe(int fd1, int fd2);
void	check_output(t_data data, int ac);
void	ft_write_outfile(int outfile, int fd_in);
void	ft_init(t_data *data, char **av, int ac);
void	check_args(int ac, char *infile, char *outfile);
void	ft_first_process(char *cmd, t_data *data, char **envp, int index);
void	ft_second_process(char *cmd, t_data *data, char **envp);

char	**pipex_split(const char *s, char c);

#endif