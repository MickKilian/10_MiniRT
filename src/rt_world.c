/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_world.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 10:07:09 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

bool	world_hit(t_rt *rt, t_ray r, t_itv tray, t_hit_rec *rec)
{
	bool	hit;

	ft_bzero(rec, sizeof(t_hit_rec));
	hit = false;
	while (rt->world.httbl)
	{
		if (check_hit_httbl(rt, &r, &tray, rec))
			hit = true;
		rt->world.httbl = rt->world.httbl->next;
	}
	rt->world.httbl = rt->world.httbl_head;
	return (hit);
}

bool	check_hit_httbl(t_rt *rt, t_ray *r, t_itv *tray, t_hit_rec *rec)
{
	rt->tp_ray = tra_r(*r, vec3_scale(-1, rt->world.httbl->geom->trsf.tra));
	if (rt->world.httbl->geom->trsf.rot_an != 0)
		rt->tp_ray = rot_r(rt->tp_ray, rt->world.httbl->geom->trsf.rot_ax,
				rt->world.httbl->geom->trsf.rot_an);
	rt->tp_type = rt->world.httbl->geom->type;
	if ((rt->tp_type == POINT && hit_pt_geom(rt, rt->tp_ray, *tray, rec))
		|| (rt->tp_type == PLANE && hit_plane(rt, rt->tp_ray, *tray, rec))
		|| (rt->tp_type == QUAD && hit_quad(rt, rt->tp_ray, *tray, rec))
		|| (rt->tp_type == DISC && hit_disc(rt, rt->tp_ray, *tray, rec))
		|| (rt->tp_type == SPHERE && hit_sphere(rt, rt->tp_ray, *tray, rec))
		|| (rt->tp_type == CYLINDER
			&& hit_cylinder_finite(rt, rt->tp_ray, *tray, rec))
		|| (rt->tp_type == CONE && hit_cone_finite(rt, rt->tp_ray, *tray, rec)))
	{
		tray->max = rec->t;
		if (rt->world.httbl->geom->trsf_i.rot_an != 0)
			rot_2v(rt->world.httbl->geom->trsf_i, &rec->p, &rec->nrm);
		rec->p = tra_v(rec->p, rt->world.httbl->geom->trsf.tra);
		return (true);
	}
	return (false);
}

int	world_populate(t_world *world)
{
	(void)world;
	return (0);
}
