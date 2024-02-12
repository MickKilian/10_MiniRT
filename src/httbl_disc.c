/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_disc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:23:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 02:21:58 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_disc	disc(const t_vec3 center, const t_vec3 normal, double radius)
{
	t_disc	dsc;

	dsc.center = center;
	dsc.normal = normal;
	dsc.radius = radius;
	return (dsc);
}

bool	hit_disc(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec)
{
	t_vec3	n;
	t_vec3	normal;
	double	d;
	double	t;
	double	denom;
	t_vec3	intersection;

	// To determine where the ray r hits the plane we use
	// equation of a plane x.a + y.b + z.c = d

	n = rt->world.httbl->geom.dsc.normal;
	normal = vec3_unit(n);
	d = vec3_dot(normal, rt->world.httbl->geom.dsc.center);

	denom = vec3_dot(normal, r.dir);

	// No hit if the ray is parallel to the plane.
	if (fabs(denom) < EPSILON)
		return (0);

	// Return false if the hit point parameter t is outside the ray interval.
	t = (d - vec3_dot(normal, r.orig)) / denom;
	if (!contains(tray, t))
		return (0);

	// Determine if the hit point lies within the disc base of the radius value.
	intersection = hit_point(r, t);
	if (vec3_length(vec3_substract2(intersection, rt->world.httbl->geom.dsc.center)) > rt->world.httbl->geom.dsc.radius)
		return (0);

	// Ray hits the 2D shape; set the rest of the hit record and return true.
	rec->t = t;
	rec->p = intersection;
	rec->mat = rt->world.httbl->mat.type;
	if (rec->mat == LAMBERTIAN)
		rec->lamber = rt->world.httbl->mat.lamber;
	if (rec->mat == METAL)
		rec->metal = rt->world.httbl->mat.metal;
	if (rec->mat == DIELECTRIC)
		rec->dielec = rt->world.httbl->mat.dielec;
	if (rec->mat == DIFF_LIGHT)
		rec->diff_light = rt->world.httbl->mat.diff_light;
	set_face_normal(r, normal, rec);

	return (1);
}
