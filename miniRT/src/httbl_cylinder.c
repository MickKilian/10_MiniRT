/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:08:45 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 23:29:27 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_cylinder	cylinder(t_vec3 ctr, t_vec3 gen, double rd, double h)
{
	t_cylinder	cyl;

	cyl.ctr = ctr;
	cyl.gen = vec3_unit(gen);
	cyl.rd = rd;
	cyl.h = h;
	cyl.itv_z = itv(-h / 2, h / 2);
	return (cyl);
}

t_geometry	*geom_cylinder(t_cylinder cyl)
{
	t_geometry	*geom;

	geom = ft_calloc(1, sizeof(t_geometry));
	geom->type = CYLINDER;
	geom->trsf.tra = cyl.ctr;
	geom->trsf.rot_an = acos(vec3_dot(cyl.gen, new_vec3(0, 0, 1)));
	geom->trsf_i.rot_an = acos(vec3_dot(new_vec3(0, 0, 1), cyl.gen));
	if (fabs(geom->trsf.rot_an - PI) < EPSILON)
	{
		geom->trsf.rot_ax = new_vec3(0, 1, 0);
		geom->trsf_i.rot_ax = new_vec3(0, -1, 0);
	}
	else
	{
		geom->trsf.rot_ax = vec3_unit(vec3_cross(cyl.gen, new_vec3(0, 0, 1)));
		geom->trsf_i.rot_ax = vec3_unit(vec3_cross(new_vec3(0, 0, 1), cyl.gen));
	}
	geom->cyl = cyl;
	geom->cyl.ctr = new_vec3(0, 0, 0);
	geom->cyl.gen = new_vec3(0, 0, 1.0);
	return (geom);
}

void	reverse_geom_cylinder(t_geometry *geom)
{
	geom->cyl.ctr = geom->trsf.tra;
	rot_1v(geom->trsf_i, &geom->cyl.gen);
	geom->trsf.tra = new_vec3(0, 0, 0);
	geom->trsf.rot_ax = new_vec3(0, 0, 0);
	geom->trsf_i.rot_ax = new_vec3(0, 0, 0);
	geom->trsf.rot_an = 0;
	geom->trsf_i.rot_an = 0;
}

bool	hit_cylinder_finite(t_rt *rt, t_ray r, t_itv tray, t_hit_rec *rec)
{
	t_h_pol		h_pol;
	double		rts[2];

	set_poly_cylinder(rt, r, &h_pol);
	if (!search_poly_root_2(&h_pol, tray, &rts[0], &rts[1]))
		return (0);
	if (rts[0] && srs(rt->world.httbl->geom->cyl.itv_z, (hit_pt(r, rts[0])).z))
		rec->t = rts[0];
	else if (rts[1] && srs(rt->world.httbl->geom->cyl.itv_z,
			(hit_pt(r, rts[1])).z))
		rec->t = rts[1];
	else
		return (0);
	rec->p = hit_pt(r, rec->t);
	rec->httbl = rt->world.httbl;
	rec->mat_rot_an = rt->world.httbl->mat->rot_an;
	set_map_coord_cyl(rec, rt->world.httbl->geom->cyl.ctr,
		rt->world.httbl->geom->cyl.h);
	set_rec_mat(rt, rec);
	set_face_nrm(r, vec3_unit(vec3_prd(
				vec3_sub2(rec->p, rt->world.httbl->geom->cyl.ctr),
				new_vec3(1, 1, 0))), rec);
	return (1);
}

void	set_poly_cylinder(t_rt *rt, t_ray r, t_h_pol *h_pol)
{
	h_pol->oc = vec3_sub2(r.orig, rt->world.httbl->geom->cyl.ctr);
	h_pol->a = vec3_len_sq(vec3_prd(r.dir, new_vec3(1, 1, 0)));
	h_pol->h_b = vec3_dot(vec3_prd(h_pol->oc, new_vec3(1, 1, 0)),
			vec3_prd(r.dir, new_vec3(1, 1, 0)));
	h_pol->c = vec3_len_sq(vec3_prd(h_pol->oc, new_vec3(1, 1, 0)))
		- (rt->world.httbl->geom->cyl.rd * rt->world.httbl->geom->cyl.rd);
}
