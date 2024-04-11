/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_point_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:08:45 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/02 04:40:34 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

t_point	point(t_vec3 q)
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

bool	hit_pt_geom(t_rt *rt, t_ray r, t_itv tray, t_hit_rec *rec)
{
	t_vec3	nrm;
	t_vec3	ray_to_light;

	ray_to_light = vec3_sub2(rt->world.httbl->geom->pnt.q, r.orig);
	if (vec3_dot(vec3_unit(ray_to_light), vec3_unit(r.dir)) < 0)
		return (0);
	rec->t = vec3_len(ray_to_light);
	if (!cts(tray, rec->t))
		return (0);
	rec->p = hit_pt(r, rec->t);
	rec->httbl = rt->world.httbl;
	set_rec_mat(rt, rec);
	set_face_nrm(r, nrm, rec);
	return (1);
}
