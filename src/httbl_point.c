/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:08:45 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/23 16:38:47 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_point	point(const t_vec3 q)
{
	t_point	pnt;

	pnt.q = q;
	return (pnt);
}

t_geometry	*geom_point(t_point pnt)
{
	t_geometry	*geom;

	geom = ft_calloc(1, sizeof(t_geometry));
	geom->type = POINT;
	geom->pnt = pnt;
	return (geom);
}

bool	hit_point_geom(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec)
{
	//t_vec3	n;
	t_vec3	normal;
	t_vec3	ray_to_light;
	double	dot_prod;
	double	t;
	t_vec3	intersection;

	// To determine where the ray r hits the punctual light

	ray_to_light = vec3_substract2(rt->world.httbl->geom->pnt.q, r.orig);

	dot_prod = vec3_dot(vec3_unit(ray_to_light), vec3_unit(r.dir));

	// No hit if the ray is perpendicular to light_ray
	//if (dot_prod < EPSILON)
	//	return (0);
	// No hit if the cosine is negative
	if (dot_prod < 0.0) {
		//printf("                    nodot_prod : %f\n", dot_prod);
		return (0);
	}
	//else
		//printf("dot_prod : %f\n", dot_prod);
	// Return false if the hit point parameter t is outside the ray interval.
	t = vec3_length(ray_to_light);
	if (!contains(tray, t))
		return (0);
	
	// Determine if the hit point lies within the planar shape using its plane coordinates.
	intersection = hit_point(r, t);

	// Ray hits the 2D shape; set the rest of the hit record and return true.
	rec->t = t;
	rec->p = intersection;
	rec->mat = rt->world.httbl->mat->type;
	if (rec->mat == LAMBERTIAN)
		rec->lamber = rt->world.httbl->mat->lamber;
	if (rec->mat == METAL)
		rec->metal = rt->world.httbl->mat->metal;
	if (rec->mat == DIELECTRIC)
		rec->dielec = rt->world.httbl->mat->dielec;
	if (rec->mat == DIFF_LIGHT)
		rec->diff_light = rt->world.httbl->mat->diff_light;
	set_face_normal(r, normal, rec);

	return (1);
}

//bool	is_interior(double a, double b, t_hit_rec *rec)
//{
//	// Given the hit point in quad coordinate, returns false if it is outside the
//	// primitive, otherwise set the hit record UV coordinates and return true.
//
//	if ((a < 0) || (1 < a) || (b < 0) || (1 < b))
//		return (0);
//	else
//		return (1);
//	(void)rec;
//	//*// CHECK THIS
//	//rec->u = a;
//	//rec->v = b;
//	//return (1);
//}
