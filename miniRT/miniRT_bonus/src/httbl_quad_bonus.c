/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_quad_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:23:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 03:57:26 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

t_quad	quad(t_vec3 ctr, t_vec3 u, t_vec3 v)
{
	t_quad	qud;

	qud.ctr = ctr;
	qud.u = u;
	qud.v = v;
	return (qud);
}

t_geometry	*geom_quad(t_quad qud)
{
	t_geometry	*geom;

	geom = ft_calloc(1, sizeof(t_geometry));
	geom->type = QUAD;
	geom->qud = qud;
	return (geom);
}

bool	hit_quad(t_rt *rt, t_ray r, t_itv tray, t_hit_rec *rec)
{
	t_quad	qud;

	qud = rt->world.httbl->geom->qud;
	qud.q = vec3_sub2(vec3_sub2(qud.ctr, qud.u), qud.v);
	qud.nrm = vec3_unit(vec3_cross(qud.u, qud.v));
	qud.d = vec3_dot(qud.nrm, qud.q);
	if (ft_abs(vec3_dot(qud.nrm, r.dir)) < EPSILON)
		return (0);
	rec->t = (qud.d - vec3_dot(qud.nrm, r.orig)) / vec3_dot(qud.nrm, r.dir);
	if (!cts(tray, rec->t))
		return (0);
	if (!is_interior(qud, hit_pt(r, rec->t)))
		return (0);
	rec->p = hit_pt(r, rec->t);
	rec->httbl = rt->world.httbl;
	rec->mat_rot_an = rt->world.httbl->mat->rot_an;
	set_map_coord_qud(rec);
	set_rec_mat(rt, rec);
	set_face_nrm(r, qud.nrm, rec);
	if (rt->world.httbl->mat->bmp.is_present)
		alter_normal_with_bump(rt, rec);
	return (1);
}

bool	is_interior(t_quad qud, t_vec3 p_temp)
{
	if ((vec3_dot(qud.nrm, vec3_cross(vec3_scale(2, qud.u),
					vec3_sub2(p_temp, qud.q))) > 0
			&& vec3_dot(qud.nrm, vec3_cross(vec3_scale(2, qud.v),
					vec3_sub2(p_temp, vec3_add2(qud.q,
							vec3_scale(2, qud.u))))) > 0
			&& vec3_dot(qud.nrm, vec3_cross(vec3_scale(-2, qud.u),
					vec3_sub2(p_temp, vec3_add2(qud.q,
							vec3_scale(2, vec3_add2(qud.u, qud.v)))))) > 0
			&& vec3_dot(qud.nrm, vec3_cross(vec3_scale(-2, qud.v),
					vec3_sub2(p_temp, vec3_add2(qud.q,
							vec3_scale(2, qud.v))))) > 0))
		return (1);
	return (0);
}
