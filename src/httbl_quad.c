/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_quad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:23:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 10:54:20 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

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
	double	alpha;
	double	beta;
	t_vec3	pl_hitpt_vec;
	t_quad	qud;

	qud = rt->world.httbl->geom->qud;
	qud.q = vec3_sub2(vec3_sub2(qud.ctr, qud.u), qud.v);
	qud.nrm = vec3_cross(vec3_scale(2, qud.u), vec3_scale(2, qud.v));
	qud.w = vec3_scale(1 / vec3_dot(qud.nrm, qud.nrm), qud.nrm);
	qud.nrm = vec3_unit(qud.nrm);
	qud.d = vec3_dot(qud.nrm, qud.q);
	if (fabs(vec3_dot(qud.nrm, r.dir)) < EPSILON)
		return (0);
	rec->t = (qud.d - vec3_dot(qud.nrm, r.orig)) / vec3_dot(qud.nrm, r.dir);
	if (!cts(tray, rec->t))
		return (0);
	rec->p = hit_pt(r, rec->t);
	pl_hitpt_vec = vec3_sub2(rec->p, qud.q);
	alpha = vec3_dot(qud.w, vec3_cross(pl_hitpt_vec, vec3_scale(2, qud.v)));
	beta = vec3_dot(qud.w, vec3_cross(vec3_scale(2, qud.u), pl_hitpt_vec));
	if (!is_interior(alpha, beta))
		return (0);
	set_rec_mat(rt, rec);
	set_face_nrm(r, qud.nrm, rec);
	return (1);
}

bool	is_interior(double a, double b)
{
	return ((a > 0) && (1 > a) && (b > 0) && (1 > b));
}
