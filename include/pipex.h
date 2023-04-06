/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:58:23 by nrossel           #+#    #+#             */
/*   Updated: 2023/04/06 09:42:20 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	char	*args[256];
	char	*cmd;
	char	**path;
}	t_cmd;

typedef struct s_data
{
	int		pipe1[2];
	int		pipe2[2];
	int		infile;
	int		outfile;
	int		status;
	t_cmd	cmd;
}	t_data;

int		is_empty(char *str);

void	ft_new_pipe(int (*fd)[2]);
void	ft_close_pipe(int fd1, int fd2);
void	ft_init(t_data *data, char **av, int ac);
void	check_args(int ac, char *infile, char *outfile);
void	ft_first_process(char *cmd, t_data *data, char **envp);
void	ft_second_process(char *cmd, t_data *data, char **envp);

char	**pipex_split(const char *s, char c);

#endif