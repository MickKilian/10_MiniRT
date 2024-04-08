/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 05:34:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/06 10:38:38 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	mat_finalize(t_rt *rt)
{
	if (!rt->tp_mat)
		rt->tp_mat = mat_lamber(lamber(rgb2vec(rt->tp_color)));
	if (rt->tp_has_txm)
	{
		rt->tp_mat->txm.is_present = true;
		rt->tp_mat->txm.path = ft_strdup(rt->tp_txm_path);
	}
	else
		rt->tp_mat->txm.is_present = false;
	if (rt->tp_has_bmp)
	{
		rt->tp_mat->bmp.is_present = true;
		rt->tp_mat->bmp.path = ft_strdup(rt->tp_bmp_path);
	}
	else
		rt->tp_mat->bmp.is_present = false;
	if (rt->tp_has_pat)
	{
		rt->tp_mat->pat.is_present = true;
		rt->tp_mat->pat.type = rt->tp_pat;
		rt->tp_mat->pat.ratio = rt->tp_pat_ratio;
	}
	else
		rt->tp_mat->pat.is_present = false;
}

t_material	*duplicate_mat(t_material *src)
{
	t_material	*dest;

	dest = ft_calloc(1, sizeof(t_material));
	dest = memcpy(dest, src, sizeof(t_material));
	return (dest);
}

int	handle_textures(t_rt *rt)
{
	rt->world.httbl = rt->world.httbl_head;
	while (rt->world.httbl)
	{
		if (!rt->tp_ret && rt->world.httbl->mat->txm.is_present)
		{
			rt->world.httbl->mat->txm.img.ptr = mlx_xpm_file_to_image(rt->mlx.ptr, rt->world.httbl->mat->txm.path,
					&rt->world.httbl->mat->txm.img.w, &rt->world.httbl->mat->txm.img.h);
			if (!rt->world.httbl->mat->txm.img.ptr)
			{
				rt->world.httbl->mat->txm.is_present = false;
				rt->tp_ret = display_error_plus(ERR_LOADING_XPM_TEXT, rt->world.httbl->mat->txm.path);
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
	return (rt->tp_ret);
}

int	handle_bumps(t_rt *rt)
{
	rt->world.httbl = rt->world.httbl_head;
	while (rt->world.httbl)
	{
		if (!rt->tp_ret && rt->world.httbl->mat->bmp.is_present)
		{
			rt->world.httbl->mat->bmp.img.ptr = mlx_xpm_file_to_image(rt->mlx.ptr, rt->world.httbl->mat->bmp.path,
					&rt->world.httbl->mat->bmp.img.w, &rt->world.httbl->mat->bmp.img.h);
			if (!rt->world.httbl->mat->bmp.img.ptr)
			{
				rt->world.httbl->mat->bmp.is_present = false;
				rt->tp_ret = display_error_plus(ERR_LOADING_XPM_TEXT, rt->world.httbl->mat->bmp.path);
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
	return (rt->tp_ret);
}
