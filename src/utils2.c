/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:11:26 by nrossel           #+#    #+#             */
/*   Updated: 2023/03/27 15:58:47 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* --------- pipex_strdup --------------*/
char	*pipex_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*s_cpy;

	i = 0;
	len = ft_strlen(s1);
	s_cpy = malloc((len + 2) * sizeof(char));
	if (!s_cpy)
		return (0);
	while (i <= len && s1[i])
	{
		s_cpy[i] = s1[i];
		i++;
	}
	s_cpy[i++] = '/';
	s_cpy[i] = '\0';
	free(s1);
	return (s_cpy);
}

/* --------- is_empty --------------*/
int	is_empty(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
	}
	error(msg(str));
	return (1);
}

/* --------- error_msg --------------*/
void	error_msg(char *c)
{
	write(2, "-bash: ", 7);
	write(2, c, ft_strlen(c));
	write(2, ": ", 2);
	write(2, "command not found\n", 18);
}

/* --------- free pipex structure --------------*/
void	free_pipex_struct(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->cmd)
		free(cmd->cmd);
	ft_free_2da(cmd->path);
	while (cmd->args[i])
		free(cmd->args[i++]);
}

/* --------- free all structures --------------*/
void	free_all(t_cmd *cmd1, t_cmd *cmd2)
{
	free_pipex_struct(cmd1);
	free_pipex_struct(cmd2);
}
