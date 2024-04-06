/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_world.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/06 01:44:05 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

bool	world_hit(t_rt *rt, t_ray r, t_itv tray, t_hit_rec *rec)
{
	bool	hit;

	//ft_bzero(rec, sizeof(t_hit_rec));
	hit = false;
	rt->world.httbl = rt->world.httbl_head;
	while (rt->world.httbl)
	{
		if (rt->world.httbl->geom->type != POINT && check_hit_httbl(rt, &r, &tray, rec))
		{
			if (rt->tp_shadow_comp)
				return (true);
			hit = true;
		}
		//if (rec->p.y > 19)
		//{
		//	printf("in world hit : %f %d %d ", rec->p.y, rt->world.httbl->geom->type, rt->tp_shadow_comp);
		//}
		rt->world.httbl = rt->world.httbl->next;
	}
	//if (rec->p.y > 19)
	//	printf("\n");
	rt->world.httbl = rt->world.httbl_head;
	return (hit);
}

bool	check_hit_httbl(t_rt *rt, t_ray *r, t_itv *tray, t_hit_rec *rec)
{
	//bool check;

	//if (rec->p.y > 19 && rt->world.httbl->geom->type == 2)
	//{
	//	check = true;
	//	printf("check quad : %f %d %d ", rec->p.y, rt->world.httbl->geom->type, rt->tp_shadow_comp);
	//}
	//else
	//	check = false;
	rt->tp_ray = tra_r(*r, vec3_scale(-1, rt->world.httbl->geom->trsf.tra));
	if (rt->world.httbl->geom->trsf.rot_an != 0)
		rt->tp_ray = rot_r(rt->tp_ray, rt->world.httbl->geom->trsf.rot_ax,
				rt->world.httbl->geom->trsf.rot_an);
	rt->tp_type = rt->world.httbl->geom->type;
	//if ((rt->tp_type == POINT && hit_pt_geom(rt, rt->tp_ray, *tray, rec))
	if ((rt->tp_type == PLANE && hit_plane(rt, rt->tp_ray, *tray, rec))
		|| (rt->tp_type == QUAD && hit_quad(rt, rt->tp_ray, *tray, rec))
		|| (rt->tp_type == DISC && hit_disc(rt, rt->tp_ray, *tray, rec))
		|| (rt->tp_type == SPHERE && hit_sphere(rt, rt->tp_ray, *tray, rec))
		|| (rt->tp_type == CYLINDER
			&& hit_cylinder_finite(rt, rt->tp_ray, *tray, rec))
		|| (rt->tp_type == CONE && hit_cone_finite(rt, rt->tp_ray, *tray, rec)))
	{
		//printf("in out ");
		//if (rec->p.y > 19)
		//{
		//	printf("in check it httbl type : %f %d", rec->p.y, rt->world.httbl->geom->type);
		//	//display_vec3(rt->world.httbl->geom->trsf.tra);
		//}
		//	display_vec3(rt->world.httbl->geom->trsf.tra);
		//	display_vec3(rt->world.httbl->geom->trsf.rot_ax);
		//	printf(" %f",rt->world.httbl->geom->trsf.rot_an);
		//	printf("\n");
		//}
		tray->max = rec->t;
		if (rt->world.httbl->geom->trsf_i.rot_an != 0)
			rot_2v(rt->world.httbl->geom->trsf_i, &rec->p, &rec->nrm);
		rec->p = tra_v(rec->p, rt->world.httbl->geom->trsf.tra);
	//	if (rec->p.y > 19)
	//		printf("in check it httbl type : %f %d\n", rec->p.y, rt->world.httbl->geom->type);
		rec->httbl = rt->world.httbl;
		return (true);
	}
	//if (check == true)
	//{
	//	printf("no hit %f\n", rec->p.y);
	//}
	return (false);
}

int	world_populate(t_world *world)
{
	(void)world;
	return (0);
}
