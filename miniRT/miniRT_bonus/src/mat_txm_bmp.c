/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_txm_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 05:34:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 10:59:59 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	handle_textures(t_rt *rt)
{
	t_httbl		*httbl;
	t_material	*mat;

	httbl = rt->world.httbl_head;
	while (httbl)
	{
		mat = httbl->mat;
		if (!rt->tp.ret && mat->txm.is_present)
			if (create_txm_image(rt, mat))
				break ;
		httbl = httbl->next;
	}
	return (rt->tp.ret);
}

int	handle_bumps(t_rt *rt)
{
	t_httbl		*httbl;
	t_material	*mat;

	httbl = rt->world.httbl_head;
	while (httbl)
	{
		mat = httbl->mat;
		if (!rt->tp.ret && mat->bmp.is_present)
			if (create_bmp_image(rt, mat))
				break ;
		httbl = httbl->next;
	}
	return (rt->tp.ret);
}

int	create_txm_image(t_rt *rt, t_material *mat)
{
	mat->txm.img.ptr = mlx_xpm_file_to_image(rt->mlx.ptr, mat->txm.path,
			&mat->txm.img.w, &mat->txm.img.h);
	if (!mat->txm.img.ptr)
	{
		mat->txm.is_present = false;
		rt->tp.ret = display_error_plus(ERR_LOADING_XPM_TEXT, mat->txm.path);
		free(mat->txm.path);
		return (1);
	}
	else
	{
		mat->txm.img.is_set = true;
		mat->txm.img.addr = mlx_get_data_addr(mat->txm.img.ptr,
				&mat->txm.img.bpp, &mat->txm.img.line_length,
				&mat->txm.img.endian);
	}
	free(mat->txm.path);
	mat->txm.path = NULL;
	return (0);
}

int	create_bmp_image(t_rt *rt, t_material *mat)
{
	mat->bmp.img.ptr = mlx_xpm_file_to_image(rt->mlx.ptr, mat->bmp.path,
			&mat->bmp.img.w, &mat->bmp.img.h);
	if (!mat->bmp.img.ptr)
	{
		mat->bmp.is_present = false;
		rt->tp.ret = display_error_plus(ERR_LOADING_XPM_TEXT, mat->bmp.path);
		free(mat->bmp.path);
		return (1);
	}
	else
	{
		mat->bmp.img.is_set = true;
		mat->bmp.img.addr = mlx_get_data_addr(mat->bmp.img.ptr,
				&mat->bmp.img.bpp, &mat->bmp.img.line_length,
				&mat->bmp.img.endian);
	}
	free(mat->bmp.path);
	mat->bmp.path = NULL;
	return (0);
}
