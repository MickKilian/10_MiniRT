/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_scatter_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 02:25:58 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/28 11:05:28 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

bool	lambertian_scatter(t_hit_rec *rec)
{
	t_vec3	sctt_dir;

	sctt_dir = vec3_add2(rec->nrm, rdm_unit_vector());
	if (vec3_is_nz(sctt_dir))
		sctt_dir = rec->nrm;
	rec->sctt = new_ray(rec->p, sctt_dir);
	rec->att = rec->lamber.color;
	return (1);
}

bool	metal_scatter(t_ray r_in, t_hit_rec *rec)
{
	t_vec3	refl;

	refl = reflect(vec3_unit(r_in.dir), rec->nrm);
	rec->sctt = new_ray(rec->p, vec3_add2(refl, vec3_scale(rec->metal.fuzz,
					rdm_unit_vector())));
	rec->att = rec->metal.color;
	return (1);
}

bool	dielectric_scatter(t_ray r_in, t_hit_rec *rec)
{
	double	refr_ratio;
	double	cos_theta;
	double	sin_theta;
	t_vec3	dir;
	bool	cannot_refract;

	if (rec->front_face)
		refr_ratio = 1.0 / rec->dielec.idx_refract;
	else
		refr_ratio = rec->dielec.idx_refract;
	cos_theta = fmin(vec3_dot(vec3_scale(-1.0,
					vec3_unit(r_in.dir)), rec->nrm), 1.0);
	sin_theta = sqrt(1.0 - cos_theta * cos_theta);
	cannot_refract = refr_ratio * sin_theta > 1.0;
	if (cannot_refract || reflectance(cos_theta, refr_ratio) > rdm_dbl())
		dir = reflect(vec3_unit(r_in.dir), rec->nrm);
	else
	dir = refract(vec3_unit(r_in.dir), rec->nrm, refr_ratio);
	rec->sctt = new_ray(rec->p, dir);
	rec->att = rec->dielec.color;
	return (1);
}
