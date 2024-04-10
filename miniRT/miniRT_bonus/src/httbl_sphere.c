/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:08:45 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 11:06:56 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_sphere	sphere(t_vec3 ctr, double r)
{
	t_sphere	sph;

	sph.ctr = ctr;
	sph.rd = r;
	sph.ax = new_vec3(0, 0, 1);
	return (sph);
}

t_geometry	*geom_sphere(t_sphere sph)
{
	t_geometry	*geom;

	geom = ft_calloc(1, sizeof(t_geometry));
	geom->type = SPHERE;
	geom->sph = sph;
	geom->trsf.tra = sph.ctr;
	geom->trsf.rot_an = acos(vec3_dot(sph.ax, new_vec3(0, 0, 1)));
	geom->trsf_i.rot_an = acos(vec3_dot(new_vec3(0, 0, 1), sph.ax));
	if (ft_abs(geom->trsf.rot_an - PI) < EPSILON)
	{
		geom->trsf.rot_ax = new_vec3(0, 1, 0);
		geom->trsf_i.rot_ax = new_vec3(0, -1, 0);
	}
	else
	{
		geom->trsf.rot_ax = vec3_unit(vec3_cross(sph.ax, new_vec3(0, 0, 1)));
		geom->trsf_i.rot_ax = vec3_unit(vec3_cross(new_vec3(0, 0, 1), sph.ax));
	}
	geom->sph = sph;
	geom->sph.ctr = new_vec3(0, 0, 0);
	geom->sph.ax = new_vec3(0, 0, 1.0);
	return (geom);
}

void	reverse_geom_sphere(t_geometry *geom)
{
	geom->sph.ctr = geom->trsf.tra;
	rot_1v(geom->trsf_i, &geom->sph.ax);
	geom->trsf.tra = new_vec3(0, 0, 0);
	geom->trsf.rot_ax = new_vec3(0, 0, 0);
	geom->trsf_i.rot_ax = new_vec3(0, 0, 0);
	geom->trsf.rot_an = 0;
	geom->trsf_i.rot_an = 0;
}

bool	hit_sphere(t_rt *rt, t_ray r, t_itv tray, t_hit_rec *rec)
{
	t_h_pol		h_pol;
	double		root;

	h_pol.oc = vec3_sub2(r.orig, rt->world.httbl->geom->sph.ctr);
	h_pol.a = vec3_len_sq(r.dir);
	h_pol.h_b = vec3_dot(h_pol.oc, r.dir);
	h_pol.c = vec3_len_sq(h_pol.oc) - (rt->world.httbl->geom->sph.rd
			* rt->world.httbl->geom->sph.rd);
	if (!search_poly_root(&h_pol, tray, &root))
		return (0);
	rec->t = root;
	rec->p = hit_pt(r, rec->t);
	rec->httbl = rt->world.httbl;
	rec->mat_rot_an = rt->world.httbl->mat->rot_an;
	set_map_coord_sph(rec, rt->world.httbl->geom->sph.ctr);
	set_rec_mat(rt, rec);
	set_face_nrm(r, vec3_scale(1 / rt->world.httbl->geom->sph.rd,
			vec3_sub2(rec->p, rt->world.httbl->geom->sph.ctr)), rec);
	if (rt->world.httbl->mat->bmp.is_present)
		alter_normal_with_bump(rt, rec);
	return (1);
}
