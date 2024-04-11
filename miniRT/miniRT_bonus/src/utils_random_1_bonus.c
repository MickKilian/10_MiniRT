/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_random_1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:32:41 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/28 11:35:36 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

t_vec3	get_rdm_dev(t_camera *cam)
{
	t_vec3	dev;

	dev.x = cam->pixel_delta_u.x * (rdm_dbl() - 0.5);
	dev.y = cam->pixel_delta_v.y * (rdm_dbl() - 0.5);
	dev.z = 0.0;
	return (dev);
}

double	rdm_dbl(void)
{
	return ((double)rand() / ((double)RAND_MAX + 1.0));
}

double	rdm_dbl_itv(double min, double max)
{
	min = min + max;
	max = ft_max(min - max, max);
	min = min - max;
	return (min + (max - min) * rdm_dbl());
}

t_vec3	rdm_vec3_itv(double min, double max)
{
	return (new_vec3(rdm_dbl_itv(min, max),
			rdm_dbl_itv(min, max),
			rdm_dbl_itv(min, max)));
}

t_vec3	rdm_in_unit_sphere(void)
{
	t_vec3	vec;

	while (true)
	{
		vec = rdm_vec3_itv(-1.0, 1.0);
		if (vec3_len_sq(vec) < 1.0)
			return (vec);
	}
}
