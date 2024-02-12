/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:08:45 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/01/30 05:28:04 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_cylinder	cylinder(const t_vec3 base_center, t_vec3 generator, double radius, double height)
{
	t_cylinder	cyl;

	cyl.base_center = base_center;
	cyl.generator = vec3_unit(generator);
	cyl.radius = radius;
	cyl.height = height;
	cyl.interval_z = interval(base_center.z, base_center.z + height);
	return (cyl);
}

bool	hit_cylinder(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec)
{
	t_half_poly	half_poly;
	t_vec3		oc;
	double		root;

	// To determine where the ray r hits the cylinder surface we use
	// oc: radius from center of cylinder to camera	
	// center: center of the cylinder
	// radius: radius of the cylinder
	// We simplify the quadratic equation noticing that we can devide
	// everything by a factor 2 and that a dot product of a vector
	// with itself is the length squared of that vector
	oc = vec3_substract2(r.orig, rt->world.httbl->geom.cyl.base_center);
	half_poly.a = r.dir.x * r.dir.x + r.dir.y * r.dir.y;
	half_poly.half_b = oc.x + r.dir.x + oc.y * r.dir.y;
	half_poly.c = oc.x * oc.x + oc.y * oc.y - (rt->world.httbl->geom.cyl.radius * rt->world.httbl->geom.cyl.radius);

	if (!search_poly_root(&half_poly, tray, &root))
		return (0);
	rec->t = root;
	rec->p = hit_point(r, rec->t);
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

bool	hit_cylinder_finite(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec)
{
	t_half_poly	half_poly;
	t_vec3		oc;
	double		root;

	// To determine where the ray r hits the cylinder surface we use
	// oc: radius from center of cylinder to camera	
	// center: center of the cylinder
	// radius: radius of the cylinder
	// We simplify the quadratic equation noticing that we can devide
	// everything by a factor 2 and that a dot product of a vector
	// with itself is the length squared of that vector
	oc = vec3_substract2(r.orig, rt->world.httbl->geom.cyl.base_center);
	half_poly.a = r.dir.x * r.dir.x + r.dir.y * r.dir.y;
	half_poly.half_b = 2 * (oc.x + r.dir.x + oc.y * r.dir.y);
	half_poly.c = oc.x * oc.x + oc.y * oc.y - (rt->world.httbl->geom.cyl.radius * rt->world.httbl->geom.cyl.radius);

	if (!search_poly_root(&half_poly, tray, &root))
		return (0);
	rec->t = root;
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
