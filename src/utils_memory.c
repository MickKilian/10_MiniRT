/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:24:57 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 08:22:23 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	free_httbls(t_rt *rt, t_world *world)
{
	t_httbl	*temp;
	t_httbl	*httbl;

	httbl = world->httbl_head;
	while (httbl)
	{
		temp = httbl->next;
		free(httbl->geom);
		if (httbl->mat->txm.is_present)
			mlx_destroy_image(rt->mlx.ptr, httbl->mat->txm.img.ptr);
		if (httbl->mat->bmp.is_present)
			mlx_destroy_image(rt->mlx.ptr, httbl->mat->bmp.img.ptr);
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

void	free_tp(t_temp tp)
{
	if (tp.geom)
		free(tp.geom);
	if (tp.mat)
		free(tp.mat);
	//if (tp.txm_path)
	//	free(tp.txm_path);
	//if (tp.bmp_path)
	//	free(tp.bmp_path);
}
