/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_bumps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 11:37:33 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	modify_bump_normal(t_vec3 *nrm, t_vec3 ref, double grad_u, double grad_v)
{
	 t_vec3	u;
	 t_vec3	v;

	 u = vec3_cross(*nrm, ref);
	 v = vec3_cross(*nrm, u);
	 *nrm = vec3_add2(*nrm, vec3_scale(grad_v, u));
	 *nrm = vec3_add2(*nrm, vec3_scale(grad_u, v));
	 *nrm = vec3_unit(*nrm);
}

void	alter_normal_with_bump(t_rt *rt, t_hit_rec *rec)
{
	double	grad_u;
	double	grad_v;

	grad_u = get_bump_gradient(&rt->world.httbl->mat->bmp.img, rec->uv, 1, 10);
	grad_v = get_bump_gradient(&rt->world.httbl->mat->bmp.img, rec->uv, 2, 10);
	modify_bump_normal(&rec->nrm, rt->cam.vup, grad_u, grad_v);
}
