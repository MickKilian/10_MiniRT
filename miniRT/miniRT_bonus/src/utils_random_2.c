/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_random_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:32:41 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 10:15:52 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_vec3	rdm_unit_vector(void)
{
	return (vec3_unit(rdm_in_unit_sphere()));
}

t_vec3	rdm_in_same_hemisphere(t_vec3 normal)
{
	t_vec3	vec_on_unit_sphere;

	vec_on_unit_sphere = rdm_unit_vector();
	if (vec3_dot(normal, vec_on_unit_sphere) > 0.0)
		return (vec_on_unit_sphere);
	else
		return (vec3_scale(-1.0, vec_on_unit_sphere));
}

t_vec3	rdm_in_unit_disk(void)
{
	t_vec3	p;

	while (true)
	{
		p = new_vec3(rdm_dbl_itv(-1, 1),
				rdm_dbl_itv(-1, 1), 0);
		if (vec3_len_sq(p) < 1)
			return (p);
	}
}

t_vec3	pixel_sample_square(t_camera *cam)
{
	double	px;
	double	py;

	if (cam->sampling)
	{
		px = -0.5 + rdm_dbl();
		py = -0.5 + rdm_dbl();
	}
	else
	{
		px = -0.5;
		py = -0.5;
	}
	return (vec3_add2(vec3_scale(px, cam->pixel_delta_u),
			vec3_scale(py, cam->pixel_delta_v)));
}

t_vec3	defocus_disk_sample(t_camera *cam)
{
	t_vec3	p;

	p = rdm_in_unit_disk();
	return (vec3_add3(cam->ctr, vec3_scale(p.x, cam->defocus_disk_u),
			vec3_scale(p.y, cam->defocus_disk_v)));
}
