/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:56:22 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/07 00:21:39 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

//fonction dest computes the pos_at (t_vec3) on the ray path starting from origin in the direction dir
t_vec3	hit_point(const t_ray r, double t)
{
	return (vec3_add2(r.orig, vec3_scale(t, r.dir)));
}

t_ray	new_ray(const t_vec3 orig, const t_vec3 dir)
{
	t_ray	r;

	r.orig = orig;
	r.dir = dir;
	return (r);
}

t_vec3	reflect(const t_vec3 v, const t_vec3 n)
{
    return (vec3_add2(v, vec3_scale(-2.0 * vec3_dot(v, n), n)));
}

t_vec3	refract(const t_vec3 r_in, const t_vec3 n, double eta_in_over_out)
{
	double	cos_theta;
	t_vec3	r_out_perp;
	t_vec3	r_out_para;

	cos_theta = fmin(vec3_dot(vec3_scale(-1.0, r_in), n), 1.0);
	r_out_perp = vec3_scale(eta_in_over_out, vec3_add2(r_in, vec3_scale(cos_theta, n)));
	r_out_para = vec3_scale(-sqrt(fabs(1.0 - vec3_length_squared(r_out_perp))), n);
	return (vec3_add2(r_out_perp, r_out_para));
}

double	reflectance(double cosine, double ref_idx)
{
	// Use Schlick's approximation for reflectance.
	double	r0;

	r0 = (1-ref_idx) / (1+ref_idx);
	r0 = r0*r0;
	return (r0 + (1-r0)*pow((1 - cosine),5));
}

t_ray	get_ray(const t_camera *cam, int i, int j)
{
	// Get a randomly sampled camera ray for the pixel at location i,j.
	t_vec3	pixel_center;
	t_vec3	pixel_sample;
	t_vec3	ray_origin;
	t_vec3	ray_direction;

	pixel_center = vec3_add3(
					cam->pixel00_loc,
					vec3_scale(1.0 * i, cam->pixel_delta_u),
					vec3_scale(1.0 * j, cam->pixel_delta_v));
	pixel_sample = vec3_add2(pixel_center, pixel_sample_square(cam));
	if (cam->defocus_angle <= 0)
		ray_origin = cam->center;
	else
		ray_origin = defocus_disk_sample(cam);
	ray_direction = vec3_substract2(pixel_sample, ray_origin);
	return (new_ray(ray_origin, ray_direction));
}

t_vec3	pixel_sample_square(const t_camera *cam)
{
	double	px;
	double	py;

	// Returns a random point in the square surrounding a pixel at the origin.
	px = -0.5 + random_double();
	py = -0.5 + random_double();
return (vec3_add2(vec3_scale(px, cam->pixel_delta_u), vec3_scale(py, cam->pixel_delta_v)));
}

t_vec3	defocus_disk_sample(const t_camera *cam)
{
	t_vec3	p;

	// Returns a random point in the camera defocus disk.
	p = random_in_unit_disk();
	return (vec3_add3(cam->center, vec3_scale(p.x, cam->defocus_disk_u), vec3_scale(p.y, cam->defocus_disk_v)));
}
