/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_compute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:56:22 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 15:19:33 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_ray	get_ray(t_camera *cam, int i, int j)
{
	t_vec3	pixel_ctr;
	t_vec3	pixel_sample;
	t_vec3	ray_origin;
	t_vec3	ray_direction;

	pixel_ctr = vec3_add3(
			cam->pixel00_loc,
			vec3_scale(1.0 * i, cam->pixel_delta_u),
			vec3_scale(1.0 * j, cam->pixel_delta_v));
	pixel_sample = vec3_add2(pixel_ctr, pixel_sample_square(cam));
	if (cam->defocus_angle <= 0)
		ray_origin = cam->ctr;
	else
		ray_origin = defocus_disk_sample(cam);
	ray_direction = vec3_sub2(pixel_sample, ray_origin);
	return (new_ray(ray_origin, ray_direction));
}

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (vec3_add2(v, vec3_scale(-2.0 * vec3_dot(v, n), n)));
}

t_vec3	refract(t_vec3 r_in, t_vec3 n, double eta_in_over_out)
{
	double	cos_theta;
	t_vec3	r_out_perp;
	t_vec3	r_out_para;

	cos_theta = fmin(vec3_dot(vec3_scale(-1.0, r_in), n), 1.0);
	r_out_perp = vec3_scale(eta_in_over_out,
			vec3_add2(r_in, vec3_scale(cos_theta, n)));
	r_out_para = vec3_scale(-sqrt(ft_abs(1.0 - vec3_len_sq(r_out_perp))), n);
	return (vec3_add2(r_out_perp, r_out_para));
}

double	reflectance(double cosine, double ref_idx)
{
	double	r0;

	r0 = (1 - ref_idx) / (1 + ref_idx);
	r0 = r0 * r0;
	return (r0 + (1 - r0) * pow((1 - cosine), 5));
}
