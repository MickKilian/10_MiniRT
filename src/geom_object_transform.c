/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_object_transform.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/25 13:36:01 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	geom_translate(t_rt *rt)
{
	if (rt->tp_geom->type == SPHERE)
		rt->tp_geom->sph.ctr = tra_v(rt->tp_geom->sph.ctr, rt->tp_trsf.tra);
	else if (rt->tp_geom->type == QUAD)
		rt->tp_geom->qud.ctr = tra_v(rt->tp_geom->qud.ctr, rt->tp_trsf.tra);
	else if (rt->tp_geom->type == DISC)
		rt->tp_geom->dsc.ctr = tra_v(rt->tp_geom->dsc.ctr, rt->tp_trsf.tra);
	else if (rt->tp_geom->type == BOX || rt->tp_geom->type == DICE)
		rt->tp_geom->box.ctr = tra_v(rt->tp_geom->box.ctr, rt->tp_trsf.tra);
	else if (rt->tp_geom->type == PLANE)
		rt->tp_geom->pln.q = tra_v(rt->tp_geom->pln.q, rt->tp_trsf.tra);
	else if (rt->tp_geom->type == CYLINDER || rt->tp_geom->type == CONE)
		rt->tp_geom->trsf.tra = tra_v(rt->tp_geom->trsf.tra, rt->tp_trsf.tra);
	else if (rt->tp_geom->type == SAFE_CONE)
		rt->tp_geom->con.b_ctr = tra_v(rt->tp_geom->con.b_ctr,
				rt->tp_trsf.tra);
	else if (rt->tp_geom->type == PENCIL)
		rt->tp_geom->con.b_ctr = tra_v(rt->tp_geom->con.b_ctr,
				rt->tp_trsf.tra);
}

void	geom_rotate(t_rt *rt)
{
	if (rt->tp_geom->type == SPHERE)
		sphere_rotate(rt);
	else if (rt->tp_geom->type == QUAD)
		rot_2v(rt->tp_trsf, &rt->tp_geom->qud.u, &rt->tp_geom->qud.v);
	else if (rt->tp_geom->type == DISC)
		rot_1v(rt->tp_trsf, &rt->tp_geom->dsc.nrm);
	else if (rt->tp_geom->type == BOX || rt->tp_geom->type == DICE)
		rot_3v(rt->tp_trsf, &rt->tp_geom->box.u, &rt->tp_geom->box.v,
			&rt->tp_geom->box.w);
	else if (rt->tp_geom->type == PLANE)
		rot_1v(rt->tp_trsf, &rt->tp_geom->pln.d);
	else if (rt->tp_geom->type == CYLINDER)
		cylinder_rotate(rt);
	else if (rt->tp_geom->type == CONE)
		cone_rotate(rt);
	else if (rt->tp_geom->type == SAFE_CONE)
		rot_1v(rt->tp_trsf, &rt->tp_geom->sfc.gen);
	else if (rt->tp_geom->type == PENCIL)
		rot_1v(rt->tp_trsf, &rt->tp_geom->pnc.gen);
}

void	cylinder_rotate(t_rt *rt)
{
	t_geometry	*tp_ptr;

	tp_ptr = rt->tp_geom;
	reverse_geom_cylinder(rt->tp_geom);
	rt->tp_geom->cyl.gen = rot_v(rt->tp_geom->cyl.gen, rt->tp_trsf.rot_ax,
			rt->tp_trsf.rot_an);
	rt->tp_geom = geom_cylinder(rt->tp_geom->cyl);
	free (tp_ptr);
}

void	cone_rotate(t_rt *rt)
{
	t_geometry	*tp_ptr;

	tp_ptr = rt->tp_geom;
	reverse_geom_cone(rt->tp_geom);
	rt->tp_geom->con.gen = rot_v(rt->tp_geom->con.gen, rt->tp_trsf.rot_ax,
			rt->tp_trsf.rot_an);
	rt->tp_geom = geom_cone(rt->tp_geom->con);
	free (tp_ptr);
}

void	sphere_rotate(t_rt *rt)
{
	t_geometry	*tp_ptr;

	tp_ptr = rt->tp_geom;
	reverse_geom_sphere(rt->tp_geom);
	rt->tp_geom->sph.ax = rot_v(rt->tp_geom->sph.ax, rt->tp_trsf.rot_ax,
			rt->tp_trsf.rot_an);
	rt->tp_geom = geom_sphere(rt->tp_geom->sph);
	free (tp_ptr);
}
