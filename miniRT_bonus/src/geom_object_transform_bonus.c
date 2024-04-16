/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_object_transform_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/08 23:52:43 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

void	geom_translate(t_rt *rt)
{
	if (rt->tp.geom->type == SPHERE)
		rt->tp.geom->sph.ctr = tra_v(rt->tp.geom->sph.ctr, rt->tp.trsf.tra);
	else if (rt->tp.geom->type == QUAD)
		rt->tp.geom->qud.ctr = tra_v(rt->tp.geom->qud.ctr, rt->tp.trsf.tra);
	else if (rt->tp.geom->type == DISC)
		rt->tp.geom->dsc.ctr = tra_v(rt->tp.geom->dsc.ctr, rt->tp.trsf.tra);
	else if (rt->tp.geom->type == BOX || rt->tp.geom->type == DICE)
		rt->tp.geom->box.ctr = tra_v(rt->tp.geom->box.ctr, rt->tp.trsf.tra);
	else if (rt->tp.geom->type == PLANE)
		rt->tp.geom->pln.q = tra_v(rt->tp.geom->pln.q, rt->tp.trsf.tra);
	else if (rt->tp.geom->type == CYLINDER || rt->tp.geom->type == CONE)
		rt->tp.geom->trsf.tra = tra_v(rt->tp.geom->trsf.tra, rt->tp.trsf.tra);
	else if (rt->tp.geom->type == SAFE_CONE)
		rt->tp.geom->con.b_ctr = tra_v(rt->tp.geom->con.b_ctr,
				rt->tp.trsf.tra);
}

void	geom_rotate(t_rt *rt)
{
	if (rt->tp.geom->type == SPHERE)
		sphere_rotate(rt);
	else if (rt->tp.geom->type == QUAD)
		rot_2v(rt->tp.trsf, &rt->tp.geom->qud.u, &rt->tp.geom->qud.v);
	else if (rt->tp.geom->type == DISC)
		rot_1v(rt->tp.trsf, &rt->tp.geom->dsc.nrm);
	else if (rt->tp.geom->type == BOX || rt->tp.geom->type == DICE)
		rot_3v(rt->tp.trsf, &rt->tp.geom->box.u, &rt->tp.geom->box.v,
			&rt->tp.geom->box.w);
	else if (rt->tp.geom->type == PLANE)
		rot_1v(rt->tp.trsf, &rt->tp.geom->pln.d);
	else if (rt->tp.geom->type == CYLINDER)
		cylinder_rotate(rt);
	else if (rt->tp.geom->type == CONE)
		cone_rotate(rt);
	else if (rt->tp.geom->type == SAFE_CONE)
		rot_1v(rt->tp.trsf, &rt->tp.geom->sfc.gen);
}

void	cylinder_rotate(t_rt *rt)
{
	t_geometry	*tp_ptr;

	tp_ptr = rt->tp.geom;
	reverse_geom_cylinder(rt->tp.geom);
	rt->tp.geom->cyl.gen = rot_v(rt->tp.geom->cyl.gen, rt->tp.trsf.rot_ax,
			rt->tp.trsf.rot_an);
	rt->tp.geom = geom_cylinder(rt->tp.geom->cyl);
	free (tp_ptr);
}

void	cone_rotate(t_rt *rt)
{
	t_geometry	*tp_ptr;

	tp_ptr = rt->tp.geom;
	reverse_geom_cone(rt->tp.geom);
	rt->tp.geom->con.gen = rot_v(rt->tp.geom->con.gen, rt->tp.trsf.rot_ax,
			rt->tp.trsf.rot_an);
	rt->tp.geom = geom_cone(rt->tp.geom->con);
	free (tp_ptr);
}

void	sphere_rotate(t_rt *rt)
{
	t_geometry	*tp_ptr;

	tp_ptr = rt->tp.geom;
	reverse_geom_sphere(rt->tp.geom);
	rt->tp.geom->sph.ax = rot_v(rt->tp.geom->sph.ax, rt->tp.trsf.rot_ax,
			rt->tp.trsf.rot_an);
	rt->tp.geom = geom_sphere(rt->tp.geom->sph);
	free (tp_ptr);
}
