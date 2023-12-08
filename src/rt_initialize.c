/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:22:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 11:18:19 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

void	rt_initialize(t_rt *rt)
{
	rt->aspect_ratio = ASPECT_RATIO;
	rt->img_width = IMAGE_WIDTH;
	//Calculate the image height, and ensure that it's at least 1.
	rt->img_height = (int)((double)rt->img_width / rt->aspect_ratio);
	if (rt->img_height < 1)
		rt->img_height = 1;
}
