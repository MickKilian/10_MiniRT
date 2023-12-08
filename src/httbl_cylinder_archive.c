/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:08:45 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 04:42:31 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

t_cylinder	cylinder(const t_vec3 base_center, t_vec3 generator, double radius, double height)
{
	t_cylinder	cyl;

	cyl.base_center = base_center;
	cyl.generator = generator;
	cyl.radius = radius;
	cyl.height = height;
	cyl.interval_z = interval(base_center.z, base_center.z + height);
	return (cyl);
}

bool	hit_cylinder_finite(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec)
{
	double	rad = rt->world.httbl->geom.cyl.radius;
	t_vec3	n = vec3_unit(rt->world.httbl->geom.cyl.generator);
	double	t;

	// We look for t shen the ray r hits the side surface fo the cylinder.
	// at that point we have ||rxv||/||v|| = radius of cylider and v the direction vector of the line
	// if we take unit vector director n of the line and use r = P + td we obtain
	// t2 = (r2 - ||pxn||2) / ||dxn||2
	
	t = sqrt((rad * rad - vec3_length_squared(vec3_cross(r.orig, n))) / vec3_length_squared((vec3_cross(r.dir, n))));
	if (!contains(tray, t))
		return (0);
	rec->t = t;
	rec->p = hit_point(r, rec->t);
	if (!surrounds(rt->world.httbl->geom.cyl.interval_z, rec->p.z))
		return (0);
	// CHECK THIS
	rec->mat = rt->world.httbl->mat.type;
	if (rec->mat == LAMBERTIAN)
		rec->lamber = rt->world.httbl->mat.lamber;
	if (rec->mat == METAL)
		rec->metal = rt->world.httbl->mat.metal;
	if (rec->mat == DIELECTRIC)
		rec->dielec = rt->world.httbl->mat.dielec;
	if (rec->mat == DIFF_LIGHT)
		rec->diff_light = rt->world.httbl->mat.diff_light;
	//rec->color = rt->world.httbl->mat.albedo;
	set_face_normal(r, vec3_scale(1 / rt->world.httbl->geom.cyl.radius, vec3_substract2(new_vec3(rec->p.x, rec->p.y, 0),
					new_vec3(rt->world.httbl->geom.cyl.base_center.x, rt->world.httbl->geom.cyl.base_center.y, 0))), rec);
	return (1);
}
