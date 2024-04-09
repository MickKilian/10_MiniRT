/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 05:34:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 20:12:32 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	mat_finalize(t_rt *rt)
{
	if (!rt->tp.mat)
		rt->tp.mat = mat_lamber(lamber(rgb2vec(rt->tp.color)));
	if (rt->tp.has_txm)
	{
		rt->tp.mat->txm.is_present = true;
		rt->tp.mat->txm.path = ft_strdup(rt->tp.txm_path);
		rt->tp.mat->txm.rot_an = rt->tp.txm_rot_an;
	}
	else
		rt->tp.mat->txm.is_present = false;
	if (rt->tp.has_bmp)
	{
		rt->tp.mat->bmp.is_present = true;
		rt->tp.mat->bmp.path = ft_strdup(rt->tp.bmp_path);
		rt->tp.mat->bmp.rot_an = rt->tp.bmp_rot_an;
	}
	else
		rt->tp.mat->bmp.is_present = false;
	if (rt->tp.has_pat)
	{
		rt->tp.mat->pat.is_present = true;
		rt->tp.mat->pat.type = rt->tp.pat;
		rt->tp.mat->pat.ratio = rt->tp.pat_ratio;
		rt->tp.mat->pat.rot_an = rt->tp.pat_rot_an;
	}
	else
		rt->tp.mat->pat.is_present = false;
	mat_rot_choice(rt);
}

void mat_rot_choice(t_rt *rt)
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

int	handle_textures(t_rt *rt)
{
	rt->world.httbl = rt->world.httbl_head;
	while (rt->world.httbl)
	{
		if (!rt->tp.ret && rt->world.httbl->mat->txm.is_present)
		{
			rt->world.httbl->mat->txm.img.ptr = mlx_xpm_file_to_image(rt->mlx.ptr, rt->world.httbl->mat->txm.path,
					&rt->world.httbl->mat->txm.img.w, &rt->world.httbl->mat->txm.img.h);
			if (!rt->world.httbl->mat->txm.img.ptr)
			{
				rt->world.httbl->mat->txm.is_present = false;
				rt->tp.ret = display_error_plus(ERR_LOADING_XPM_TEXT, rt->world.httbl->mat->txm.path);
				free(rt->world.httbl->mat->txm.path);
				break;
			}
			else
				rt->world.httbl->mat->txm.img.addr = mlx_get_data_addr(rt->world.httbl->mat->txm.img.ptr,
						&rt->world.httbl->mat->txm.img.bpp, &rt->world.httbl->mat->txm.img.line_length,
						&rt->world.httbl->mat->txm.img.endian);
			free(rt->world.httbl->mat->txm.path);
			rt->world.httbl->mat->txm.path = NULL;
		}
		rt->world.httbl = rt->world.httbl->next;
	}
	rt->world.httbl = rt->world.httbl_head;
	return (rt->tp.ret);
}

int	handle_bumps(t_rt *rt)
{
	rt->world.httbl = rt->world.httbl_head;
	while (rt->world.httbl)
	{
		if (!rt->tp.ret && rt->world.httbl->mat->bmp.is_present)
		{
			rt->world.httbl->mat->bmp.img.ptr = mlx_xpm_file_to_image(rt->mlx.ptr, rt->world.httbl->mat->bmp.path,
					&rt->world.httbl->mat->bmp.img.w, &rt->world.httbl->mat->bmp.img.h);
			if (!rt->world.httbl->mat->bmp.img.ptr)
			{
				rt->world.httbl->mat->bmp.is_present = false;
				rt->tp.ret = display_error_plus(ERR_LOADING_XPM_TEXT, rt->world.httbl->mat->bmp.path);
				free(rt->world.httbl->mat->bmp.path);
				break;
			}
			else
				rt->world.httbl->mat->bmp.img.addr = mlx_get_data_addr(rt->world.httbl->mat->bmp.img.ptr,
						&rt->world.httbl->mat->bmp.img.bpp, &rt->world.httbl->mat->bmp.img.line_length,
						&rt->world.httbl->mat->bmp.img.endian);
			free(rt->world.httbl->mat->bmp.path);
			rt->world.httbl->mat->bmp.path = NULL;
		}
		rt->world.httbl = rt->world.httbl->next;
	}
	rt->world.httbl = rt->world.httbl_head;
	return (rt->tp.ret);
}
