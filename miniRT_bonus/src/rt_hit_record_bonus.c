/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hit_record_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:45:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 23:52:32 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

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
	if (rec->mat_type == METAL)
	{
		rec->metal = rt->world.httbl->mat->metal;
		rec->col = rt->world.httbl->mat->metal.color;
	}
	if (rec->mat_type == DIELECTRIC)
	{
		rec->dielec = rt->world.httbl->mat->dielec;
		rec->col = rt->world.httbl->mat->dielec.color;
	}
	if (rec->mat_type == DIFF_LIGHT)
	{
		rec->diff_light = rt->world.httbl->mat->diff_light;
		rec->col = rt->world.httbl->mat->diff_light.color;
	}
	check_rec_color(rt, rec);
	set_rec_mat_color(rec);
}

void	set_rec_mat_color(t_hit_rec *rec)
{
	if (rec->mat_type == LAMBERTIAN)
		rec->lamber.color = rec->col;
	if (rec->mat_type == METAL)
		rec->metal.color = rec->col;
	if (rec->mat_type == DIELECTRIC)
		rec->dielec.color = rec->col;
	if (rec->mat_type == DIFF_LIGHT)
		rec->diff_light.color = rec->col;
}

void	check_rec_color(t_rt *rt, t_hit_rec *rec)
{
	t_geometry	*geom;

	geom = rt->world.httbl->geom;
	if ((rec->mat_type == LAMBERTIAN || rec->mat_type == METAL)
		&& (geom->type == SPHERE || geom->type == CYLINDER || geom->type == CONE
			|| geom->type == PLANE || geom->type == QUAD || geom->type == DISC))
		set_rec_color(rt, rec);
}

void	set_rec_color(t_rt *rt, t_hit_rec *rec)
{
	t_material	*mat;

	mat = rt->world.httbl->mat;
	if (mat->txm.is_present)
		rec->col = get_pixel_color(&mat->txm.img, rec->uv);
	else if (mat->pat.is_present && mat->pat.type == CHECKBOARD)
		rec->col = pattern_color(checkboard_zone(rec->uv, mat->pat.ratio),
				rec->col, compl_color(rec->col));
	else if (mat->pat.is_present && mat->pat.type == LINES_LONG)
		rec->col = pattern_color(long_zone(rec->uv, mat->pat.ratio),
				rec->col, compl_color(rec->col));
	else if (mat->pat.is_present && mat->pat.type == LINES_LAT)
		rec->col = pattern_color(lat_zone(rec->uv, mat->pat.ratio),
				rec->col, compl_color(rec->col));
	else if (mat->pat.is_present && mat->pat.type == SPIRAL_2_COLORS)
		rec->col = pattern_color(spiral_zone(rec->uv_cyl, mat->pat.ratio),
				rec->col, compl_color(rec->col));
	else if (mat->pat.is_present && mat->pat.type == SPIRAL_GRADIENT)
		rec->col = gradient_color_spiral(rec->uv_cyl, mat->pat.ratio,
				rec->col);
}
