/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:08:45 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/13 02:02:03 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_sphere	sphere(const t_vec3 center, double r)
{
	t_sphere	sph;

	sph.center = center;
	sph.radius = r;
	return (sph);
}

bool	hit_sphere(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec)
{
	t_half_poly	half_poly;
	t_vec3		oc;
	double		root;

	// To determine where the ray r hits the sphere surface we use
	// oc: radius from center of sphere to camera	
	// center: center of the sphere
	// radius: radius of the sphere
	// We simplify the quadratic equation noticing that we can devide
	// everything by a factor 2 and that a dot product of a vector
	// with itself is the length squared of that vector
	oc = vec3_substract2(r.orig, rt->world.httbl->geom.sph.center);
	half_poly.a = vec3_length_squared(r.dir);
	half_poly.half_b = 2 * vec3_dot(oc, r.dir);
	half_poly.c = vec3_length_squared(oc) - (rt->world.httbl->geom.sph.radius * rt->world.httbl->geom.sph.radius);

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
	//rec->color = rt->world.httbl->mat.color;
	set_face_normal(r, vec3_scale(1 / rt->world.httbl->geom.sph.radius, vec3_substract2(rec->p, rt->world.httbl->geom.sph.center)), rec);
	return (1);
}
