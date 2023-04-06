/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:44:09 by nrossel           #+#    #+#             */
/*   Updated: 2023/04/05 13:24:46 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	nb_char(const char *str, char c)
{
	int	i;
	int	sep;

	i = 0;
	sep = 0;
	while (*str)
	{
		if (*str != c && sep == 0)
		{
			sep = 1;
			i++;
		}
		else if (*str == c)
			sep = 0;
		str++;
	}
	return (i);
}

static char	*word_cpy(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 2) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i++] = '/';
	word[i] = '\0';
	return (word);
}

char	**pipex_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s)
		return (0);
	split = malloc((nb_char(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = -1;
	j = 0;
	index = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_cpy(s, index, i);
			index = -1;
		}
	}
	split[j] = 0;
	return (split);
}

// int main(void)
// {
	// char *str = "Salut:la:compagnie";
	// char **ret = pipex_split(str, ':');
	// int i = 0;
	// while (ret[i])
		// printf("%s", ret[i++]);
// }