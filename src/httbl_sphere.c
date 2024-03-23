/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:08:45 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/22 07:12:43 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_sphere	sphere(t_vec3 ctr, double r)
{
	t_sphere	sph;

	sph.ctr = ctr;
	sph.rd = r;
	return (sph);
}

t_geometry	*geom_sphere(t_sphere sph)
{
	t_geometry	*geom;

	geom = ft_calloc(1, sizeof(t_geometry));
	geom->type = SPHERE;
	geom->sph = sph;
	return (geom);
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
	set_rec_mat(rt, rec);
	set_face_nrm(r, vec3_scale(1 / rt->world.httbl->geom->sph.rd,
			vec3_sub2(rec->p, rt->world.httbl->geom->sph.ctr)), rec);
	return (1);
}
