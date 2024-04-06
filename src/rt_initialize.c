/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:22:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/29 12:24:47 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

int	rt_initialize(t_rt *rt)
{
	if (!rt->set_resolution)
	{
		rt->aspect_ratio = ASPECT_RATIO;
		rt->img.w = IMAGE_WIDTH;
		rt->img.h = (int)((double)rt->img.w / rt->aspect_ratio);
		if (rt->img.h < 1)
			rt->img.h = 1;
	}
	if (mlx_initialize(&rt->mlx, rt->img.w, rt->img.h))
		return (display_error(ERR_MLX_INIT));
	if (image_create(&rt->mlx, &rt->img, rt->img.w, rt->img.h))
		return (display_error(ERR_IMG_CREATE));
	cam_initialize(rt);
	if (world_populate(&rt->world) || handle_textures(rt) || handle_bumps(rt))
		return (1);
	return (0);
}
