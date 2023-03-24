/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_newcontent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrossel <nrossel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:20:14 by nrossel           #+#    #+#             */
/*   Updated: 2023/02/24 09:17:25 by nrossel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

t_node	*ft_dlst_newcontent(int data)
{
	t_node	*new_node;
	int		*data_mllc;

	new_node = malloc(sizeof(t_node));
	data_mllc = malloc(sizeof(int));
	if (!new_node || !data_mllc)
		return (0);
	*data_mllc = data;
	new_node->data = data_mllc;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->norm = 0;
	return (new_node);
}
