/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_plane_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:08:45 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 15:02:14 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

t_plane	plane(t_vec3 q, t_vec3 dir)
{
	t_plane	pln;

	pln.q = q;
	pln.d = dir;
	return (pln);
}

t_geometry	*geom_plane(t_plane pln)
{
	t_geometry	*geom;

	geom = ft_calloc(1, sizeof(t_geometry));
	geom->type = PLANE;
	geom->pln = pln;
	return (geom);
}

bool	hit_plane(t_rt *rt, t_ray r, t_itv tray, t_hit_rec *rec)
{
	t_vec3	nrm;
	double	d;

	nrm = vec3_unit(rt->world.httbl->geom->pln.d);
	d = vec3_dot(nrm, rt->world.httbl->geom->pln.q);
	if (ft_abs(vec3_dot(nrm, r.dir)) < EPSILON)
		return (0);
	rec->t = (d - vec3_dot(nrm, r.orig)) / vec3_dot(nrm, r.dir);
	if (!cts(tray, rec->t))
		return (0);
	rec->p = hit_pt(r, rec->t);
	rec->httbl = rt->world.httbl;
	rec->mat_rot_an = rt->world.httbl->mat->rot_an;
	set_map_coord_pln(rec);
	set_rec_mat(rt, rec);
	set_face_nrm(r, nrm, rec);
	if (rt->world.httbl->mat->bmp.is_present)
		alter_normal_with_bump(rt, rec);
	return (1);
}
