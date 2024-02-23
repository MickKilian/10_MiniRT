/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:08:45 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/02/23 16:37:37 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_cone	cone(const t_vec3 base_center, t_vec3 generator, double radius_min, double radius_max, double height)
{
	t_cone	con;

	con.base_center = base_center;
	con.generator = vec3_unit(generator);
	con.radius_min = radius_min;
	con.radius_max = radius_max;
	con.height = height;
	con.interval_z = interval(0, height);
	return (con);
}

t_geometry	*geom_cone(t_cone con)
{
	t_geometry	*geom;

	geom = ft_calloc(1, sizeof(t_geometry));
	geom->type = CONE;
	geom->trans = con.base_center;
	geom->theta = new_vec3(-atan2(con.generator.y, con.generator.z),
			atan2(con.generator.x, con.generator.z),
			0);
	geom->con = con;
	geom->con.base_center = new_vec3(0, 0, 0);
	geom->con.tip = new_vec3(0, 0, -con.radius_min / (con.radius_max - con.radius_min) * con.height);
	geom->con.generator = new_vec3(0, 0, 1.0);
	return (geom);
}

bool	hit_cone_finite(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec)
{
	t_half_poly	half_poly;
	t_vec3		oc;
	double		root, h_squared, r_squared;

	// To determine where the ray r hits the sphere surface we use
	// oc: radius from center of sphere to camera	
	// center: center of the sphere
	// radius: radius of the sphere
	// We simplify the quadratic equation noticing that we can devide
	// everything by a factor 2 and that a dot product of a vector
	// with itself is the length squared of that vector
	//printf("radius : %f, height : %f", rt->world.httbl->geom->con.radius, rt->world.httbl->geom->con.height);
	//printf("z : %f\n", r.dir.z);
	oc = vec3_substract2(r.orig, rt->world.httbl->geom->con.tip);
	//oc.z = rt->world.httbl->geom->con.height - oc.z;
	//half_poly.a = vec3_length_squared(vec3_prod_comp_by_comp(r.dir, new_vec3(1, 1, 0)));
	//half_poly.half_b = 2 * vec3_dot(vec3_prod_comp_by_comp(oc, new_vec3(1, 1, 0)), vec3_prod_comp_by_comp(r.dir, new_vec3(1, 1, 0)));
	//half_poly.c = vec3_length_squared(vec3_prod_comp_by_comp(oc, new_vec3(1, 1, 0))) - (rt->world.httbl->geom->con.radius * rt->world.httbl->geom->con.radius);

	h_squared = rt->world.httbl->geom->con.height * rt->world.httbl->geom->con.radius_max / (rt->world.httbl->geom->con.radius_max - rt->world.httbl->geom->con.radius_min);
	h_squared *= h_squared;
	r_squared = rt->world.httbl->geom->con.radius_max * rt->world.httbl->geom->con.radius_max;
	half_poly.a = h_squared * vec3_length_squared(vec3_prod_comp_by_comp(r.dir, new_vec3(1, 1, 0)))
		- r_squared * vec3_length_squared(vec3_prod_comp_by_comp(r.dir, new_vec3(0, 0, 1)));
	half_poly.half_b = 2 * h_squared * vec3_dot(vec3_prod_comp_by_comp(oc, new_vec3(1, 1, 0)), vec3_prod_comp_by_comp(r.dir, new_vec3(1, 1, 0)))
		- 2 * r_squared * vec3_dot(vec3_prod_comp_by_comp(oc, new_vec3(0, 0, 1)), vec3_prod_comp_by_comp(r.dir, new_vec3(0, 0, 1)));
	half_poly.c = h_squared * vec3_length_squared(vec3_prod_comp_by_comp(oc, new_vec3(1, 1, 0)))
		- r_squared * vec3_length_squared(vec3_prod_comp_by_comp(oc, new_vec3(0, 0, 1)));

	if (!search_poly_root(&half_poly, tray, &root))
		return (0);
	rec->t = root;
	rec->p = hit_point(r, rec->t);
	if (!surrounds(rt->world.httbl->geom->con.interval_z, rec->p.z))
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
	set_face_normal(r, vec3_scale(1 / rt->world.httbl->geom->con.radius_max, vec3_substract2(new_vec3(rec->p.x, rec->p.y, 0),
					new_vec3(rt->world.httbl->geom->con.tip.x, rt->world.httbl->geom->con.tip.y, 0))), rec);
	return (1);
}
