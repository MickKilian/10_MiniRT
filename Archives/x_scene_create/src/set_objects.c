/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:03:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/16 09:21:15 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scene_create.h"

void	set_resol(t_rt *rt, double img_width)
{
	rt->resol.img_width = img_width;
	write_resol(rt);
}

void	set_algo(t_rt *rt, int samples_per_pixel, int depth)
{
	rt->algo.samples_per_pixel = samples_per_pixel;
	rt->algo.depth = depth;
	write_algo(rt);
}

void	set_ambient(t_rt *rt, double ratio, t_vec3 color)
{
	rt->ambient.ratio = ratio;
	rt->ambient.color = color;
	write_ambient(rt);
}

void	set_cam(t_rt *rt, t_vec3 center, t_vec3 dir, double hfov)
{
	rt->cam.center = center;
	rt->cam.dir = dir;
	rt->cam.hfov = hfov;
	write_cam(rt);
}

void	set_plane(t_rt *rt, t_vec3 q, t_vec3 d)
{
	rt->geometry->pln.q = q;
	rt->geometry->pln.d = d;
	write_plane(rt);
}

void	set_quad(t_rt *rt, t_vec3 center, t_vec3 u, t_vec3 v)
{
	rt->geometry->qud.center = center;
	rt->geometry->qud.u = u;
	rt->geometry->qud.v = v;
	write_quad(rt);
}

void	set_sphere(t_rt *rt, t_vec3 center, double radius)
{
	rt->geometry->sph.center = center;
	rt->geometry->sph.radius = radius;
	write_sphere(rt);
}

void	set_disc(t_rt *rt, t_vec3 center, t_vec3 normal, double radius)
{
	rt->geometry->dsc.center = center;
	rt->geometry->dsc.normal = normal;
	rt->geometry->dsc.radius = radius;
	write_disc(rt);
}

void	set_cylinder(t_rt *rt, t_vec3 center, t_vec3 generator, double radius, double height, t_interval interval_z)
{
	rt->geometry->cyl.center = center;
	rt->geometry->cyl.generator = generator;
	rt->geometry->cyl.radius = radius;
	rt->geometry->cyl.height = height;
	rt->geometry->cyl.interval_z = interval_z;
	write_cylinder(rt);
}

void	set_cone(t_rt *rt, t_vec3 base_center, t_vec3 generator, double radius_max, double radius_min, double height)
{
	rt->geometry->con.base_center = base_center;
	rt->geometry->con.generator = generator;
	rt->geometry->con.radius_max = radius_max;
	rt->geometry->con.radius_min = radius_min;
	rt->geometry->con.height = height;
	write_cone(rt);
}

void	set_safe_cone(t_rt *rt, t_vec3 base_center, t_vec3 generator, double height)
{
	rt->geometry->sfc.base_center = base_center;
	rt->geometry->sfc.generator = generator;
	rt->geometry->sfc.height = height;
	write_safe_cone(rt);
}

void	set_dice(t_rt *rt, t_vec3 center, t_vec3 u, t_vec3 v, double size)
{
	rt->geometry->dce.center = center;
	rt->geometry->dce.u = u;
	rt->geometry->dce.v = v;
	rt->geometry->dce.size = size;
	write_dice(rt);
}

void	set_lamber(t_rt *rt, t_vec3 color)
{
	rt->material->lamber.color = color;
	write_lamber(rt);
}

void	set_dielec(t_rt *rt, t_vec3 color, double idx_refract)
{
	rt->material->dielec.color = color;
	rt->material->dielec.idx_refract = idx_refract;
	write_dielec(rt);
}

void	set_metal(t_rt *rt, t_vec3 color, double fuzz)
{
	rt->material->metal.color = color;
	rt->material->metal.fuzz = fuzz;
	write_metal(rt);
}

void	set_diff_light(t_rt *rt, t_vec3 color, double ratio)
{
	rt->material->diff_light.color = color;
	rt->material->diff_light.ratio = ratio;
	write_diff_light(rt);
}

void	set_tra(t_rt *rt, t_vec3 trans)
{
	rt->trans = trans;
	write_tra(rt);
}

void	set_rot(t_rt *rt, t_vec3 rot_axis, double rot_angle)
{
	rt->rot_axis = rot_axis;
	rt->rot_angle = rot_angle;
	write_rot(rt);
}
