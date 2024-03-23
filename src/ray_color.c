/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:50:35 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/22 18:51:55 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_vec3	ray_color(t_rt *rt, int depth, t_ray r)
{
	t_hit_rec	rec;

	ft_bzero(&rec, sizeof(t_hit_rec));
	if (depth <= 0)
		return (new_vec3(0, 0, 0));
	if (!world_hit(rt, r, itv(0.001, INFINITY), &rec))
		return (vec3_scale(rt->ambient.ratio, rt->ambient.color));
	else if (rec.mat == DIFF_LIGHT)
		return (vec3_scale(rec.diff_light.ratio, rec.diff_light.color));
	else
	{
		if (rec.mat == LAMBERTIAN)
			lambertian_scatter(&rec);
		else if (rec.mat == METAL)
			metal_scatter(r, &rec);
		else if (rec.mat == DIELECTRIC)
			dielectric_scatter(r, &rec);
		if (!NORMAL_MODE)
			return (vec3_prd(rec.att, ray_color(rt, depth - 1, rec.sctt)));
		return (vec3_scale(0.5, vec3_add2(rec.nrm, new_vec3(1, 1, 1))));
	}
}

t_vec3	ray_color_grad_blue(t_ray r)
{
	t_vec3	pixel_color;
	double	a;

	ft_bzero(&pixel_color, sizeof(t_vec3));
	a = 0.5 * (vec3_unit(r.dir).y + 1.0);
	pixel_color = vec3_add2(vec3_scale(1.0 - a, new_vec3(1.0, 1.0, 1.0)),
			vec3_scale(a, new_vec3(0.5, 0.7, 1.0)));
	return (pixel_color);
}
