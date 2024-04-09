/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:08:45 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 15:02:29 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_cone	cone(t_vec3 b_ctr, t_vec3 gen, double r_max, double r_min)
{
	t_cone	con;

	con.b_ctr = b_ctr;
	con.h = vec3_len(gen);
	con.gen = vec3_unit(gen);
	con.r_max = r_max;
	con.r_min = r_min;
	con.itv_z = itv(0, con.h);
	return (con);
}

t_geometry	*geom_cone(t_cone con)
{
	t_geometry	*geom;

	geom = ft_calloc(1, sizeof(t_geometry));
	geom->type = CONE;
	geom->trsf.tra = con.b_ctr;
	geom->trsf.rot_an = acos(vec3_dot(con.gen,
				new_vec3(0, 0, 1)));
	geom->trsf_i.rot_an = acos(vec3_dot(new_vec3(0, 0, 1), con.gen));
	if (ft_abs(geom->trsf.rot_an - PI) < EPSILON)
	{
		geom->trsf.rot_ax = new_vec3(0, 1, 0);
		geom->trsf_i.rot_ax = new_vec3(0, -1, 0);
	}
	else
	{
		geom->trsf.rot_ax = vec3_unit(vec3_cross(con.gen, new_vec3(0, 0, 1)));
		geom->trsf_i.rot_ax = vec3_unit(vec3_cross(new_vec3(0, 0, 1), con.gen));
	}
	geom->con = con;
	geom->con.b_ctr = new_vec3(0, 0, 0);
	geom->con.tip = new_vec3(0, 0, con.r_max / (con.r_max - con.r_min) * con.h);
	geom->con.gen = new_vec3(0, 0, 1);
	return (geom);
}

void	reverse_geom_cone(t_geometry *geom)
{
	geom->con.b_ctr = geom->trsf.tra;
	rot_1v(geom->trsf_i, &geom->con.gen);
	geom->trsf.tra = new_vec3(0, 0, 0);
	geom->trsf.rot_ax = new_vec3(0, 0, 0);
	geom->trsf_i.rot_ax = new_vec3(0, 0, 0);
	geom->trsf.rot_an = 0;
	geom->trsf_i.rot_an = 0;
}

bool	hit_cone_finite(t_rt *rt, t_ray r, t_itv tray, t_hit_rec *rec)
{
	t_h_pol		h_pol;
	double		root_1;
	double		root_2;

	set_poly_cone(rt, r, &h_pol);
	if (!search_poly_root_2(&h_pol, tray, &root_1, &root_2))
		return (0);
	if (root_1 && srs(rt->world.httbl->geom->con.itv_z, (hit_pt(r, root_1)).z))
	{
		rec->t = root_1;
		rec->p = hit_pt(r, rec->t);
	}
	else if (root_2 && srs(rt->world.httbl->geom->con.itv_z,
			(hit_pt(r, root_2)).z))
	{
		rec->t = root_2;
		rec->p = hit_pt(r, rec->t);
	}
	else
		return (0);
	rec->httbl = rt->world.httbl;
	rec->mat_rot_an = rt->world.httbl->mat->rot_an;
	set_map_coord_con(rec, rt->world.httbl->geom->con.b_ctr,
			rt->world.httbl->geom->con.h);
	set_rec_mat(rt, rec);
	set_face_nrm(r, vec3_unit(new_vec3(rec->p.x, rec->p.y,
				vec3_len(new_vec3(rec->p.x, rec->p.y, 0))
				/ rt->world.httbl->geom->con.h)), rec);
	if (rt->world.httbl->mat->bmp.is_present)
		alter_normal_with_bump(rt, rec);
	return (1);
}

void	set_poly_cone(t_rt *rt, t_ray r, t_h_pol *h_pol)
{
	h_pol->oc = vec3_sub2(r.orig, rt->world.httbl->geom->con.tip);
	h_pol->h_sq = rt->world.httbl->geom->con.h
		* rt->world.httbl->geom->con.r_max
		/ (rt->world.httbl->geom->con.r_max
			- rt->world.httbl->geom->con.r_min);
	h_pol->h_sq *= h_pol->h_sq;
	h_pol->r_sq = rt->world.httbl->geom->con.r_max
		* rt->world.httbl->geom->con.r_max;
	h_pol->a = h_pol->h_sq * vec3_len_sq(vec3_prd(r.dir, new_vec3(1, 1, 0)))
		- h_pol->r_sq * vec3_len_sq(vec3_prd(r.dir, new_vec3(0, 0, 1)));
	h_pol->h_b = h_pol->h_sq * vec3_dot(vec3_prd(h_pol->oc, new_vec3(1, 1, 0)),
			vec3_prd(r.dir, new_vec3(1, 1, 0)))
		- h_pol->r_sq * vec3_dot(vec3_prd(h_pol->oc, new_vec3(0, 0, 1)),
			vec3_prd(r.dir, new_vec3(0, 0, 1)));
	h_pol->c = h_pol->h_sq * vec3_len_sq(vec3_prd(h_pol->oc, new_vec3(1, 1, 0)))
		- h_pol->r_sq * vec3_len_sq(vec3_prd(h_pol->oc, new_vec3(0, 0, 1)));
}
