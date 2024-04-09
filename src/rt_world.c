/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_world.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/08 23:56:57 by mbourgeo         ###   ########.fr       */
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
			if (rt->tp.shadow_comp)
				return (true);
			hit = true;
		}
		//if (rec->p.y > 19)
		//{
		//	printf("in world hit : %f %d %d ", rec->p.y, rt->world.httbl->geom->type, rt->tp.shadow_comp);
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
	//	printf("check quad : %f %d %d ", rec->p.y, rt->world.httbl->geom->type, rt->tp.shadow_comp);
	//}
	//else
	//	check = false;
	rt->tp.ray = tra_r(*r, vec3_scale(-1, rt->world.httbl->geom->trsf.tra));
	if (rt->world.httbl->geom->trsf.rot_an != 0)
		rt->tp.ray = rot_r(rt->tp.ray, rt->world.httbl->geom->trsf.rot_ax,
				rt->world.httbl->geom->trsf.rot_an);
	rt->tp.type = rt->world.httbl->geom->type;
	//if ((rt->tp.type == POINT && hit_pt_geom(rt, rt->tp.ray, *tray, rec))
	if ((rt->tp.type == PLANE && hit_plane(rt, rt->tp.ray, *tray, rec))
		|| (rt->tp.type == QUAD && hit_quad(rt, rt->tp.ray, *tray, rec))
		|| (rt->tp.type == DISC && hit_disc(rt, rt->tp.ray, *tray, rec))
		|| (rt->tp.type == SPHERE && hit_sphere(rt, rt->tp.ray, *tray, rec))
		|| (rt->tp.type == CYLINDER
			&& hit_cylinder_finite(rt, rt->tp.ray, *tray, rec))
		|| (rt->tp.type == CONE && hit_cone_finite(rt, rt->tp.ray, *tray, rec)))
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
