/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:54:17 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/02 03:46:58 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	cam_initialize(t_rt *rt)
{
	if (!rt->set_algo)
	{
		rt->spp = SAMPLES_PER_PIXEL;
		rt->max_depth = MAX_DEPTH;
	}
	rt->cam.defocus_angle = 0.0;
	rt->cam.focus_dist = 10;
	rt->cam.look_from = rt->cam.ctr;
	rt->cam.look_at = vec3_add2(rt->cam.ctr, rt->cam.dir);
	rt->cam.vup = new_vec3(0.0, 0.0, 1.0);
	cam_viewport_compute(rt);
	rt->cam.defocus_radius = rt->cam.focus_dist
		* tan(deg2rad(rt->cam.defocus_angle / 2));
	rt->cam.defocus_disk_u = vec3_scale(rt->cam.defocus_radius, rt->cam.u);
	rt->cam.defocus_disk_v = vec3_scale(rt->cam.defocus_radius, rt->cam.v);
}

void	cam_viewport_compute(t_rt *rt)
{
	rt->cam.viewport_w = 2.0 * tan(deg2rad(rt->cam.hfov) / 2.0)
		* rt->cam.focus_dist;
	rt->cam.viewport_h = rt->cam.viewport_w * ((double)rt->img.h
			/ (double)rt->img.w);
	rt->cam.w = vec3_unit(vec3_sub2(rt->cam.look_from, rt->cam.look_at));
	rt->cam.u = vec3_unit(vec3_cross(rt->cam.vup, rt->cam.w));
	rt->cam.v = vec3_cross(rt->cam.w, rt->cam.u);
	rt->cam.viewport_u = vec3_scale(rt->cam.viewport_w, rt->cam.u);
	rt->cam.viewport_v = vec3_scale(-rt->cam.viewport_h, rt->cam.v);
	rt->cam.pixel_delta_u = vec3_scale(1.0 / rt->img.w, rt->cam.viewport_u);
	rt->cam.pixel_delta_v = vec3_scale(1.0 / rt->img.h, rt->cam.viewport_v);
	rt->cam.viewport_upper_left = vec3_add3(
			vec3_add2(rt->cam.ctr, vec3_scale(-rt->cam.focus_dist, rt->cam.w)),
			vec3_scale(-0.5, rt->cam.viewport_u),
			vec3_scale(-0.5, rt->cam.viewport_v));
	rt->cam.pixel00_loc = vec3_add3(
			rt->cam.viewport_upper_left,
			vec3_scale(0.5, rt->cam.pixel_delta_u),
			vec3_scale(0.5, rt->cam.pixel_delta_v));
}
