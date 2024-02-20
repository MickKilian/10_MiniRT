/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:22:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/12 09:58:15 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	rt_initialize(t_rt *rt)
{
	if (!rt->set_resolution) {
		rt->aspect_ratio = ASPECT_RATIO;
		rt->img_width = IMAGE_WIDTH;
		rt->img_height = (int)((double)rt->img_width / rt->aspect_ratio);
		if (rt->img_height < 1)
			rt->img_height = 1;
	}
}
