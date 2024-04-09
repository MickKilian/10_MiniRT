/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_hit_record.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:45:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/08 11:01:11 by mbourgeo         ###   ########.fr       */
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

void	set_map_coord_pln(t_hit_rec *rec)
{
	t_plane	*pln;
	t_vec3	w;

	pln = &rec->httbl->geom->pln;
	if (vec3_dot(pln->d, new_vec3(1, 0, 0)) != 0)
		w = vec3_unit(vec3_cross(pln->d, new_vec3(1, 0, 0)));
	else
		w = vec3_unit(vec3_cross(pln->d, new_vec3(0, 1, 0)));
	rec->uv = vec3_scale(0.1, new_vec3(vec3_dot(rec->p, w), vec3_dot(rec->p, vec3_unit(vec3_cross(pln->d, w))), 0));
}

void	set_map_coord_qud(t_hit_rec *rec)
{
	t_quad	*qud;

	qud = &rec->httbl->geom->qud;
	rec->uv = new_vec3(vec3_dot(rec->p, vec3_unit(qud->u)) / 2 / vec3_len(qud->u), vec3_dot(rec->p, vec3_unit(qud->v)) / 2 / vec3_len(qud->v), 0);
}

void	set_map_coord_dsc(t_hit_rec *rec)
{
	t_disc	*dsc;
	double	phi;
	t_vec3	vec;

	dsc = &rec->httbl->geom->dsc;
	vec = vec3_sub2(new_vec3(rec->p.x, rec->p.y, 0), new_vec3(dsc->ctr.x, dsc->ctr.y, 0));
	phi = atan2(-vec3_unit(vec).y, vec3_unit(vec).x) + PI;
	rec->uv = new_vec3(phi / (2 * PI), vec3_len(vec) / dsc->rd, 0);
}

void	set_map_coord_sph(t_hit_rec *rec, t_vec3 ctr)
{
	double	theta;
	double	phi;
	t_vec3	unit_vec;

	unit_vec = vec3_unit(vec3_sub2(rec->p, ctr));
	theta = acos(-unit_vec.z);
	phi = atan2(-unit_vec.y, unit_vec.x) + PI;
	rec->uv = new_vec3(phi / (2 * PI), theta / PI, 0);
}

void	set_map_coord_cyl(t_hit_rec *rec, t_vec3 ctr, double h)
{
	double	phi;
	t_vec3	unit_vec;

	unit_vec = vec3_unit(vec3_sub2(new_vec3(rec->p.x, rec->p.y, 0), new_vec3(ctr.x, ctr.y, 0)));
	phi = atan2(-unit_vec.y, unit_vec.x) + PI;
	rec->uv = new_vec3(phi / (2 * PI), (rec->p.z - (ctr.z - (h / 2))) / h, 0);
}

void	set_map_coord_con(t_hit_rec *rec, t_vec3 ctr, double h)
{
	double	phi;
	t_vec3	unit_vec;

	unit_vec = vec3_unit(vec3_sub2(new_vec3(rec->p.x, rec->p.y, 0), new_vec3(ctr.x, ctr.y, 0)));
	phi = atan2(-unit_vec.y, unit_vec.x) + PI;
	rec->uv = new_vec3(phi / (2 * PI), (rec->p.z - (ctr.z - (h / 2))) / h, 0);
}

void	set_rec_mat(t_rt *rt, t_hit_rec *rec)
{
	rec->mat_type = rt->world.httbl->mat->type;
	if (rec->mat_type == LAMBERTIAN)
	{
		rec->lamber = rt->world.httbl->mat->lamber;
		if (rt->world.httbl->geom->type == SPHERE
				|| rt->world.httbl->geom->type == CYLINDER
				|| rt->world.httbl->geom->type == CONE
				|| rt->world.httbl->geom->type == PLANE
				|| rt->world.httbl->geom->type == QUAD
				|| rt->world.httbl->geom->type == DISC)
		{
			if (rt->world.httbl->mat->txm.is_present)
				rec->lamber.color = get_pixel_color(&rt->world.httbl->mat->txm.img, rec->uv);
			else if (rt->world.httbl->mat->pat.is_present && rt->world.httbl->mat->pat.type == CHECKBOARD)
				rec->lamber.color = pattern_color(checkboard_zone(rec->uv, rt->world.httbl->mat->pat.ratio), rec->lamber.color, compl_color(rec->lamber.color));
			else if (rt->world.httbl->mat->pat.is_present && rt->world.httbl->mat->pat.type == LINES_LONG)
				rec->lamber.color = pattern_color(long_zone(rec->uv, rt->world.httbl->mat->pat.ratio), rec->lamber.color, compl_color(rec->lamber.color));
			else if (rt->world.httbl->mat->pat.is_present && rt->world.httbl->mat->pat.type == LINES_LAT)
				rec->lamber.color = pattern_color(lat_zone(rec->uv, rt->world.httbl->mat->pat.ratio), rec->lamber.color, compl_color(rec->lamber.color));
			else if (rt->world.httbl->mat->pat.is_present && rt->world.httbl->mat->pat.type == SPIRAL_2_COLORS)
				rec->lamber.color = pattern_color(spiral_zone(rec->uv, rt->world.httbl->mat->pat.ratio), rec->lamber.color, compl_color(rec->lamber.color));
			else if (rt->world.httbl->mat->pat.is_present && rt->world.httbl->mat->pat.type == SPIRAL_GRADIENT)
				rec->lamber.color = gradient_color_spiral(rec->uv, rt->world.httbl->mat->pat.ratio,
						rec->lamber.color);
		}
	}
	if (rec->mat_type == METAL)
	{
		rec->metal = rt->world.httbl->mat->metal;
		//rec->metal.color = color_pattern(rec->uv, 10, rec->metal.color, compl_color(rec->metal.color));
	}
	if (rec->mat_type == DIELECTRIC)
		rec->dielec = rt->world.httbl->mat->dielec;
	if (rec->mat_type == DIFF_LIGHT)
		rec->diff_light = rt->world.httbl->mat->diff_light;
}
