/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_memory_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:24:57 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 11:35:08 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

void	free_httbls(t_rt *rt, t_world *world)
{
	t_httbl	*temp;
	t_httbl	*httbl;

	httbl = world->httbl_head;
	while (httbl)
	{
		temp = httbl->next;
		free(httbl->geom);
		if (httbl->mat->txm.img.is_set)
			mlx_destroy_image(rt->mlx.ptr, httbl->mat->txm.img.ptr);
		else if (httbl->mat->txm.is_present)
			free(httbl->mat->txm.path);
		if (httbl->mat->bmp.img.is_set)
			mlx_destroy_image(rt->mlx.ptr, httbl->mat->bmp.img.ptr);
		else if (httbl->mat->bmp.is_present)
			free(httbl->mat->bmp.path);
		free(httbl->mat);
		free(httbl);
		httbl = temp;
	}
}

int	free_split_vec(char **vec)
{
	int	i;

	i = 0;
	while (vec[i])
	{
		free(vec[i]);
		i++;
	}
	free(vec);
	return (0);
}

int	free_tp(t_temp tp)
{
	if (tp.geom)
		free(tp.geom);
	if (tp.mat)
		free(tp.mat);
	return (0);
}
