/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hit_record.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:45:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 23:25:35 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	set_face_nrm(const t_ray r, const t_vec3 out_nrm, t_hit_rec *rec)
{
	rec->front_face = (vec3_dot(r.dir, out_nrm) < 0.01);
	if (rec->front_face)
		rec->nrm = vec3_unit(out_nrm);
	else
		rec->nrm = vec3_unit(vec3_scale(-1.0, out_nrm));
}

void	set_rec_mat(t_rt *rt, t_hit_rec *rec)
{
	rec->mat_type = rt->world.httbl->mat->type;
	if (rec->mat_type == LAMBERTIAN)
	{
		rec->lamber = rt->world.httbl->mat->lamber;
		rec->col = rt->world.httbl->mat->lamber.color;
	}
	if (rec->mat_type == DIFF_LIGHT)
	{
		rec->diff_light = rt->world.httbl->mat->diff_light;
		rec->col = rt->world.httbl->mat->diff_light.color;
	}
	set_rec_mat_color(rec);
}

void	set_rec_mat_color(t_hit_rec *rec)
{
	if (rec->mat_type == LAMBERTIAN)
		rec->lamber.color = rec->col;
	if (rec->mat_type == DIFF_LIGHT)
		rec->diff_light.color = rec->col;
}
