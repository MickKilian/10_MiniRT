/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_create_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 05:34:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 10:59:45 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

bool	mat_finalize(t_rt *rt)
{
	if (!rt->tp.mat)
		rt->tp.mat = mat_lamber(lamber(rgb2vec(rt->tp.color)));
	rt->tp.mat->txm.is_present = false;
	rt->tp.mat->bmp.is_present = false;
	rt->tp.mat->pat.is_present = false;
	if (rt->tp.has_txm)
	{
		rt->tp.mat->txm.is_present = true;
		rt->tp.mat->txm.path = ft_strdup(rt->tp.txm_path);
		rt->tp.mat->txm.rot_an = rt->tp.txm_rot_an;
	}
	if (rt->tp.has_bmp)
	{
		rt->tp.mat->bmp.is_present = true;
		rt->tp.mat->bmp.path = ft_strdup(rt->tp.bmp_path);
	}
	if (rt->tp.has_pat)
	{
		rt->tp.mat->pat.is_present = true;
		rt->tp.mat->pat.type = rt->tp.pat;
		rt->tp.mat->pat.ratio = rt->tp.pat_ratio;
		rt->tp.mat->pat.rot_an = rt->tp.pat_rot_an;
	}
	mat_rot_choice(rt);
	return (0);
}

void	mat_rot_choice(t_rt *rt)
{
	if (rt->tp.has_txm)
		rt->tp.mat->rot_an = rt->tp.txm_rot_an;
	else if (rt->tp.has_pat)
		rt->tp.mat->rot_an = rt->tp.pat_rot_an;
	else if (rt->tp.has_bmp)
		rt->tp.mat->rot_an = rt->tp.bmp_rot_an;
	else
		rt->tp.mat->rot_an = 0;
}

t_material	*duplicate_mat(t_material *src)
{
	t_material	*dest;

	dest = ft_calloc(1, sizeof(t_material));
	dest = memcpy(dest, src, sizeof(t_material));
	if (src->txm.is_present)
		dest->txm.path = ft_strdup(src->txm.path);
	if (src->bmp.is_present)
		dest->bmp.path = ft_strdup(src->bmp.path);
	return (dest);
}
