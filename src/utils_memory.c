/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:24:57 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 03:17:16 by mbourgeo         ###   ########.fr       */
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
//	if (tp.mat->txm.is_present)
//	{
//		printf("freeing_tp_txm %s(%p)\n", tp.mat->txm.path, tp.mat->txm.path);
//		free(tp.mat->txm.path);
//	}
//	if (tp.mat->bmp.is_present)
//	{
//		printf("freeing_tp_bmp %s(%p)\n", tp.mat->bmp.path, tp.mat->bmp.path);
//		free(tp.mat->bmp.path);
//	}
	if (tp.mat)
		free(tp.mat);
	//if (tp.txm_path)
	//	free(tp.txm_path);
	//if (tp.bmp_path)
	//	free(tp.bmp_path);
}
