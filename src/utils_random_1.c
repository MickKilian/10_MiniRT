/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_random_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:32:41 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 06:52:37 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_vec3	get_random_dev(t_camera *cam)
{
	t_vec3	dev;

	dev.x = cam->pixel_delta_u.x * (random_double() - 0.5);
	dev.y = cam->pixel_delta_v.y * (random_double() - 0.5);
	dev.z = 0.0;
	return (dev);
}

double	random_double(void)
{
	return ((double)rand() / ((double)RAND_MAX + 1.0));
}

double	random_double_interval(double min, double max)
{
	return (min + (max - min) * random_double());
}

t_vec3	random_vec3_interval(double min, double max)
{
	return (new_vec3(random_double_interval(min, max),
			random_double_interval(min, max),
			random_double_interval(min, max)));
}

t_vec3	random_in_unit_sphere(void)
{
	t_vec3	vec;

	while (true)
	{
		vec = random_vec3_interval(-1.0, 1.0);
		if (vec3_len_sq(vec) < 1.0)
			return (vec);
	}
}
