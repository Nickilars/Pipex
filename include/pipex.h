/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:58:23 by nrossel           #+#    #+#             */
/*   Updated: 2023/03/27 15:18:17 by nrossel          ###   ########.fr       */
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
	int		f;
}	t_cmd;

typedef struct s_data
{
	int		fd[2];
	int		infile;
	int		outfile;
	int		status;
	pid_t	pid1;
	pid_t	pid2;
	char	buffer[256];
	t_cmd	cmd1;
	t_cmd	cmd2;
	t_ind	index;
}	t_data;

int		is_empty(char *str);

char	*pipex_strdup(const char *s1);
char	**pipex_split(const char *s, char c);

void	error_msg(char *c);
void	free_pipex_struct(t_cmd *cmd);
void	free_all(t_cmd *cmd1, t_cmd *cmd2);
void	child1_process(t_data *data, char **envp);
void	child2_process(t_data *data, char **envp);
void	pipex(t_data *file, char **av, char **envp);

#endif