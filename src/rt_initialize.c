/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:22:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 05:03:42 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	rt_initialize(t_rt *rt)
{
	if (!rt->set_resolution)
	{
		rt->aspect_ratio = ASPECT_RATIO;
		rt->img_w = IMAGE_WIDTH;
		rt->img_h = (int)((double)rt->img_w / rt->aspect_ratio);
		if (rt->img_h < 1)
			rt->img_h = 1;
	}
}
