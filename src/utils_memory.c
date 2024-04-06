/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:24:57 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/28 03:22:49 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	free_httbls(t_world *world)
{
	t_httbl	*temp;
	t_httbl	*httbl;

	httbl = world->httbl_head;
	while (httbl)
	{
		temp = httbl->next;
		free(httbl->geom);
		free(httbl->mat);
		free(httbl);
		httbl = temp;
	}
}

void	free_split_vec(char **vec)
{
	int	i;

	i = 0;
	while (vec[i])
	{
		free(vec[i]);
		i++;
	}
	free(vec);
}
