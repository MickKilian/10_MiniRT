/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_object_transform.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 23:27:45 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	geom_translate(t_rt *rt)
{
	if (rt->tp.geom->type == SPHERE)
		rt->tp.geom->sph.ctr = tra_v(rt->tp.geom->sph.ctr, rt->tp.trsf.tra);
	else if (rt->tp.geom->type == DISC)
		rt->tp.geom->dsc.ctr = tra_v(rt->tp.geom->dsc.ctr, rt->tp.trsf.tra);
	else if (rt->tp.geom->type == PLANE)
		rt->tp.geom->pln.q = tra_v(rt->tp.geom->pln.q, rt->tp.trsf.tra);
	else if (rt->tp.geom->type == CYLINDER)
		rt->tp.geom->trsf.tra = tra_v(rt->tp.geom->trsf.tra, rt->tp.trsf.tra);
}

void	geom_rotate(t_rt *rt)
{
	if (rt->tp.geom->type == SPHERE)
		sphere_rotate(rt);
	else if (rt->tp.geom->type == DISC)
		rot_1v(rt->tp.trsf, &rt->tp.geom->dsc.nrm);
	else if (rt->tp.geom->type == PLANE)
		rot_1v(rt->tp.trsf, &rt->tp.geom->pln.d);
	else if (rt->tp.geom->type == CYLINDER)
		cylinder_rotate(rt);
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
