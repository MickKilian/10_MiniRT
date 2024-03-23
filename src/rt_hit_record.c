/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hit_record.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:45:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 05:03:06 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	set_face_nrm(const t_ray r, const t_vec3 out_nrm, t_hit_rec *rec)
{
	rec->front_face = (vec3_dot(r.dir, out_nrm) < 0.01);
	if (rec->front_face)
		rec->nrm = out_nrm;
	else
		rec->nrm = vec3_scale(-1.0, out_nrm);
}

void	set_rec_mat(t_rt *rt, t_hit_rec *rec)
{
	rec->mat = rt->world.httbl->mat->type;
	if (rec->mat == LAMBERTIAN)
		rec->lamber = rt->world.httbl->mat->lamber;
	if (rec->mat == METAL)
		rec->metal = rt->world.httbl->mat->metal;
	if (rec->mat == DIELECTRIC)
		rec->dielec = rt->world.httbl->mat->dielec;
	if (rec->mat == DIFF_LIGHT)
		rec->diff_light = rt->world.httbl->mat->diff_light;
}
