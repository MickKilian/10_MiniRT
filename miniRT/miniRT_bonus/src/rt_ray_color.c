/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:50:35 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 15:21:05 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_vec3	ray_color(t_rt *rt, int depth, t_ray r)
{
	t_hit_rec	rec;
	t_vec3		lighting_color;

	rt->cur_httbl = NULL;
	ft_bzero(&rec, sizeof(t_hit_rec));
	if (depth <= 0)
		return (new_vec3(0, 0, 0));
	if (!world_hit(rt, r, itv(0.001, INFINITY), &rec))
		return (vec3_scale(rt->ambient.ratio, rt->ambient.color));
	else if (rec.mat_type == DIFF_LIGHT)
		return (vec3_scale(rec.diff_light.ratio, rec.diff_light.color));
	else
	{
		if (rec.mat_type == LAMBERTIAN)
			lambertian_scatter(&rec);
		else if (rec.mat_type == METAL)
			metal_scatter(r, &rec);
		else if (rec.mat_type == DIELECTRIC)
			dielectric_scatter(r, &rec);
		lighting_color = point_lights(rt, &rec);
		if (!NORMAL_MODE)
			return (vec3_add2(lighting_color, vec3_prd(rec.att,
						ray_color(rt, depth - 1, rec.sctt))));
		return (vec3_scale(0.5, vec3_add2(rec.nrm, new_vec3(1, 1, 1))));
	}
}
