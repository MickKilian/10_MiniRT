/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:03:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/16 09:29:41 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scene_create.h"

void	write_resol(t_rt *rt)
{
	write_code(rt, "R");
	write_number(rt, rt->resol.img_width);
}

void	write_algo(t_rt *rt)
{
	write_code(rt, "P");
	write_number(rt, rt->algo.samples_per_pixel);
	write_number(rt, rt->algo.depth);
}

void	write_ambient(t_rt *rt)
{
	write_code(rt, "A");
	write_number(rt, rt->ambient.ratio);
	write_vec3(rt, rt->ambient.color);
}

void	write_cam(t_rt *rt)
{
	write_code(rt, "C");
	write_vec3(rt, rt->cam.center);
	write_vec3(rt, rt->cam.dir);
	write_number(rt, rt->cam.hfov);
}

void	write_plane(t_rt *rt)
{
	write_code(rt, "pl");
	write_vec3(rt, rt->geometry->pln.q);
	write_vec3(rt, rt->geometry->pln.d);
}

void	write_quad(t_rt *rt)
{
	write_code(rt, "qd");
	write_vec3(rt, rt->geometry->qud.center);
	write_vec3(rt, rt->geometry->qud.u);
	write_vec3(rt, rt->geometry->qud.v);
}

void	write_sphere(t_rt *rt)
{
	write_code(rt, "sp");
	write_vec3(rt, rt->geometry->sph.center);
	write_number(rt, rt->geometry->sph.radius);
}

void	write_disc(t_rt *rt)
{
	write_code(rt, "ds");
	write_vec3(rt, rt->geometry->dsc.center);
	write_vec3(rt, rt->geometry->dsc.normal);
	write_number(rt, rt->geometry->dsc.radius);
}

void	write_cylinder(t_rt *rt)
{
	write_code(rt, "cy");
	write_vec3(rt, rt->geometry->cyl.center);
	write_vec3(rt, rt->geometry->cyl.generator);
	write_number(rt, rt->geometry->cyl.radius);
	write_number(rt, rt->geometry->cyl.height);
	write_number(rt, rt->geometry->cyl.interval_z.min);
	write_number(rt, rt->geometry->cyl.interval_z.max);
}

void	write_cone(t_rt *rt)
{
	write_code(rt, "co");
	write_vec3(rt, rt->geometry->con.base_center);
	write_vec3(rt, rt->geometry->con.generator);
	write_number(rt, rt->geometry->con.radius_max);
	write_number(rt, rt->geometry->con.radius_min);
	write_number(rt, rt->geometry->con.height);
}

void	write_safe_cone(t_rt *rt)
{
	write_code(rt, "sc");
	write_vec3(rt, rt->geometry->sfc.base_center);
	write_vec3(rt, rt->geometry->sfc.generator);
	write_number(rt, rt->geometry->sfc.height);
}

void	write_dice(t_rt *rt)
{
	write_code(rt, "di");
	write_vec3(rt, rt->geometry->dce.center);
	write_vec3(rt, rt->geometry->dce.u);
	write_vec3(rt, rt->geometry->dce.v);
	write_number(rt, rt->geometry->dce.size);
}

void	write_lamber(t_rt *rt)
{
	write_vec3(rt, rt->material->lamber.color);
}

void	write_dielec(t_rt *rt)
{
	write_vec3(rt, rt->material->dielec.color);
	write_code(rt, "die");
	write_number(rt, rt->material->dielec.idx_refract);
}

void	write_metal(t_rt *rt)
{
	write_vec3(rt, rt->material->metal.color);
	write_code(rt, "met");
	write_number(rt, rt->material->metal.fuzz);
}

void	write_diff_light(t_rt *rt)
{
	write_vec3(rt, rt->material->diff_light.color);
	write_code(rt, "dif");
	write_number(rt, rt->material->diff_light.ratio);
}

void	write_tra(t_rt *rt)
{
	write_code(rt, "tra");
	write_vec3(rt, rt->trans);
}

void	write_rot(t_rt *rt)
{
	write_code(rt, "rot");
	write_vec3(rt, rt->rot_axis);
	write_number(rt, rt->rot_angle);
}
