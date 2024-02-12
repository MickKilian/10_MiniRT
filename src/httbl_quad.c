/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_quad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:23:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/08 01:06:15 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_quad	quad(const t_vec3 q, const t_vec3 u, const t_vec3 v)
{
	t_quad	qud;

	qud.q = q;
	qud.u = u;
	qud.v = v;
	return (qud);
}

bool	hit_quad(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec)
{
	t_vec3	n;
	t_vec3	normal;
	double	d;
	double	t;
	double	alpha;
	double	beta;
	double	denom;
	t_vec3	w;
	t_vec3	intersection;
	t_vec3	planar_hitpt_vector;

	// To determine where the ray r hits the plane we use
	// equation of a plane x.a + y.b + z.c = d

	n = vec3_cross(rt->world.httbl->geom.qud.u, rt->world.httbl->geom.qud.v);
	normal = vec3_unit(n);
	d = vec3_dot(normal, rt->world.httbl->geom.qud.q);
	w = vec3_scale(1 / vec3_dot(n, n), n);

	denom = vec3_dot(normal, r.dir);

	// No hit if the ray is parallel to the plane.
	if (fabs(denom) < EPSILON)
		return (0);

	// Return false if the hit point parameter t is outside the ray interval.
	t = (d - vec3_dot(normal, r.orig)) / denom;
	if (!contains(tray, t))
		return (0);

	// Determine if the hit point lies within the planar shape using its plane coordinates.
	intersection = hit_point(r, t);
	planar_hitpt_vector = vec3_add2(intersection, vec3_scale(-1, rt->world.httbl->geom.qud.q));
	alpha =vec3_dot(w, vec3_cross(planar_hitpt_vector, rt->world.httbl->geom.qud.v));
	beta = vec3_dot(w, vec3_cross(rt->world.httbl->geom.qud.u, planar_hitpt_vector));

	if (!is_interior(alpha, beta, rec))
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

bool	is_interior(double a, double b, t_hit_rec *rec)
{
	// Given the hit point in quad coordinate, returns false if it is outside the
	// primitive, otherwise set the hit record UV coordinates and return true.

	if ((a < 0) || (1 < a) || (b < 0) || (1 < b))
		return (0);
	else
		return (1);
	(void)rec;
	//*// CHECK THIS
	//rec->u = a;
	//rec->v = b;
	//return (1);
}
