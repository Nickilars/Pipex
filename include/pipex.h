/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:58:23 by nrossel           #+#    #+#             */
/*   Updated: 2023/04/17 11:10:10 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

int		ft_init(int in_or_out, char **av, int ac);

void	ft_test(int fd_in, int v);
void	ft_new_pipe(int (*fd)[2]);
void	is_empty(char *str, char *file);
void	ft_close_pipe(int fd1, int fd2);
void	ft_write_outfile(int fd_in, int ac, char **av);
void	check_args(int ac, char *infile, char *outfile);
void	check_output(int ac, char **av, int pipe1, int pipe2);
void	first_process(char *cmd, int (*pipe1)[2], int (*pipe2)[2], char **envp);
void	secon_process(char *cmd, int (*pipe1)[2], int (*pipe2)[2], char **envp);

#endif