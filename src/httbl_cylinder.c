/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:08:45 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/23 16:37:53 by mbourgeo         ###   ########.fr       */
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
	cyl.interval_z = interval(0, height);
	return (cyl);
}

t_geometry	*geom_cylinder(t_cylinder cyl)
{
	t_geometry	*geom;

	geom = ft_calloc(1, sizeof(t_geometry));
	geom->type = CYLINDER;
	geom->trans = cyl.base_center;
	geom->theta = new_vec3(-atan2(cyl.generator.y, cyl.generator.z),
			atan2(cyl.generator.x, cyl.generator.z),
			0);
	geom->cyl = cyl;
	geom->cyl.base_center = new_vec3(0, 0, 0);
	geom->cyl.generator = new_vec3(0, 0, 1.0);
	return (geom);
}

bool	hit_cylinder_finite(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec)
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
	oc = vec3_substract2(r.orig, rt->world.httbl->geom->cyl.base_center);
	half_poly.a = vec3_length_squared(vec3_prod_comp_by_comp(r.dir, new_vec3(1, 1, 0)));
	half_poly.half_b = 2 * vec3_dot(vec3_prod_comp_by_comp(oc, new_vec3(1, 1, 0)), vec3_prod_comp_by_comp(r.dir, new_vec3(1, 1, 0)));
	half_poly.c = vec3_length_squared(vec3_prod_comp_by_comp(oc, new_vec3(1, 1, 0))) - (rt->world.httbl->geom->cyl.radius * rt->world.httbl->geom->cyl.radius);

	if (!search_poly_root(&half_poly, tray, &root))
		return (0);
	rec->t = root;
	rec->p = hit_point(r, rec->t);
	if (!surrounds(rt->world.httbl->geom->cyl.interval_z, rec->p.z))
		return (0);
	// CHECK THIS
	rec->mat = rt->world.httbl->mat->type;
	if (rec->mat == LAMBERTIAN)
		rec->lamber = rt->world.httbl->mat->lamber;
	if (rec->mat == METAL)
		rec->metal = rt->world.httbl->mat->metal;
	if (rec->mat == DIELECTRIC)
		rec->dielec = rt->world.httbl->mat->dielec;
	if (rec->mat == DIFF_LIGHT)
		rec->diff_light = rt->world.httbl->mat->diff_light;
	//rec->color = rt->world.httbl->mat->color;
	set_face_normal(r, vec3_scale(1 / rt->world.httbl->geom->cyl.radius, vec3_substract2(new_vec3(rec->p.x, rec->p.y, 0),
					new_vec3(rt->world.httbl->geom->cyl.base_center.x, rt->world.httbl->geom->cyl.base_center.y, 0))), rec);
	return (1);
}
