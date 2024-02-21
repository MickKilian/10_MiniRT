/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:50:35 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/21 05:35:58 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_vec3	ray_color(t_rt *rt, int depth, const t_ray r)
{
	t_hit_rec	rec;
	t_ray		scattered;
	t_vec3		attenuation;
	t_vec3		color_from_emission;
	t_vec3		color_from_scatter;
	bool		has_hit;
	//t_vec3		test;

	//printf("Starting depth : %d\n", depth);
	ft_bzero(&rec, sizeof(t_hit_rec));
	// If we've exceeded the ray bounce limit, no more light is gathered.
	if (depth <= 0)
		return (new_vec3(0.0, 0.0, 0.0));
	// If the ray hits nothing, return the ambient color.
	// 0.001 prevents bugs from offset calculation of the surface hit point due to float precision
	//if (depth == 40) {
	//	printf("world_hit : %d\n", world_hit(rt, r, interval(0.001, INFINITY), &rec));
	//	printf("with mat : %d\n", rec.mat);
	//}
	has_hit = world_hit(rt, r, interval(0.001, INFINITY), &rec);
	//if (!has_hit || (has_hit && rec.geom_type == 0 && depth == MAX_DEPTH)) {
	//if (!has_hit || (has_hit && near_zero(vec3_substract2(r.orig, rt->cam.center)) && depth == MAX_DEPTH && rec.geom_type == 0)) {
	if (!has_hit) {
	//	printf("background light : ratio %f", rt->ambient.ratio);
	//	display_vec3(rt->ambient.color);
	//	printf("\n");
		color_from_emission = vec3_scale(rt->ambient.ratio, rt->ambient.color);
		color_from_scatter = new_vec3(0., 0., 0.);
		//if (depth == 40) {
		//	printf("NO HIT, depth : %d\n", depth);
		//	test = vec3_add2(color_from_emission, color_from_scatter);
		//	printf("test : ");
		//	display_vec3(test);
		//	printf("\n");
		//}
		return (vec3_add2(color_from_emission, color_from_scatter));
		//return ray_color_grad_blue(r);
	}
	if (rec.mat == DIFF_LIGHT)
	{
		//if (depth == 40) {
		//	printf("DIFF_LIGHT with depth %d\n", depth);
		//}
		color_from_emission = vec3_scale(rec.diff_light.ratio, rec.diff_light.color);
	//	printf("Emission : ratio %f", rec.diff_light.ratio);
	//	display_vec3(rec.diff_light.color);
	//	printf("\n");
		color_from_scatter = new_vec3(0., 0., 0.);
	}
	else
	{
		//printf("ELSE\n");
		if (rec.mat == LAMBERTIAN)
			lambertian_scatter(r, rec, &attenuation, &scattered);
		else if (rec.mat == METAL)
			metal_scatter(r, rec, &attenuation, &scattered);
		else if (rec.mat == DIELECTRIC)
			dielectric_scatter(r, rec, &attenuation, &scattered);
		color_from_emission = new_vec3(0., 0., 0.);
		color_from_scatter = vec3_prod_comp_by_comp(attenuation, ray_color(rt, depth - 1, scattered));
		//color_from_scatter = vec3_scale(0.5, vec3_add2(rec.normal, new_vec3(1, 1, 1)));
	}
	return (vec3_add2(color_from_emission, color_from_scatter));
}

t_vec3	ray_color_grad_blue(const t_ray r)
{
	t_vec3	pixel_color;

	//printf("r_dir : %f\n", r.dir.z);
	//Intialization of pixel_color
	ft_bzero(&pixel_color, sizeof(t_vec3));
    double a = 0.5 * (vec3_unit(r.dir).y + 1.0);
	pixel_color = vec3_add2(vec3_scale(1.0 - a, new_vec3(1.0, 1.0, 1.0)),
			vec3_scale(a, new_vec3(0.5, 0.7, 1.0)));
	return (pixel_color);
}

t_vec3	ray_color_grad_red(const t_ray r)
{
	t_vec3	pixel_color;

	//printf("r_dir : %f\n", r.dir.z);
	//Intialization of pixel_color
	ft_bzero(&pixel_color, sizeof(t_vec3));
    double a = 0.5 * (vec3_unit(r.dir).y + 1.0);
	pixel_color = vec3_add2(vec3_scale(1.0 - a, new_vec3(1.0, 1.0, 1.0)),
			vec3_scale(a, new_vec3(1.0, 0.5, 0.5)));
	return (pixel_color);
}

t_vec3	ray_color_grad_violet(const t_ray r)
{
	t_vec3	pixel_color;

	//printf("r_dir : %f\n", r.dir.z);
	//Intialization of pixel_color
	ft_bzero(&pixel_color, sizeof(t_vec3));
    double a = 0.5 * (vec3_unit(r.dir).y + 1.0);
	pixel_color = vec3_add2(vec3_scale(1.0 - a, new_vec3(1.0, 1.0, 1.0)),
			vec3_scale(a, new_vec3(0.5, 0.0, 1.0)));
	return (pixel_color);
}

t_vec3	ray_color_grad_yellow(const t_ray r)
{
	t_vec3	pixel_color;

	//printf("r_dir : %f\n", r.dir.z);
	//Intialization of pixel_color
	ft_bzero(&pixel_color, sizeof(t_vec3));
    double a = 0.5 * (vec3_unit(r.dir).y + 1.0);
	pixel_color = vec3_add2(vec3_scale(1.0 - a, new_vec3(1.0, 1.0, 1.0)),
			vec3_scale(a, new_vec3(1.0, 1.0, 0.18)));
	return (pixel_color);
}

t_vec3	ray_color_grad_sunset(const t_ray r)
{
	t_vec3	pixel_color;

	//printf("r_dir : %f\n", r.dir.z);
	//Intialization of pixel_color
	ft_bzero(&pixel_color, sizeof(t_vec3));
    double a = 0.5 * (vec3_unit(r.dir).y + 1.0);
	pixel_color = vec3_add2(vec3_scale(1.0 - a, new_vec3(1.0, 1.0, 1.0)),
			vec3_scale(a, new_vec3(0.38, 0.29, 0.14)));
	return (pixel_color);
}

t_vec3	ray_color_red()
{
	t_vec3	pixel_color;

	//Intialization of pixel_color
	ft_bzero(&pixel_color, sizeof(t_vec3));
	pixel_color = new_vec3(1.0, 0.0, 0.0);
	return (pixel_color);
}
