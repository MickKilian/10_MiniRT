/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_map_coord_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:42:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 11:31:58 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	set_map_coord_pln(t_hit_rec *rec)
{
	t_plane	*pln;
	t_vec3	w;
	double	phi;

	pln = &rec->httbl->geom->pln;
	if (vec3_dot(pln->d, new_vec3(1, 0, 0)) != 0)
		w = vec3_unit(vec3_cross(pln->d, new_vec3(1, 0, 0)));
	else
		w = vec3_unit(vec3_cross(pln->d, new_vec3(0, 1, 0)));
	rec->uv = vec3_scale(0.1, new_vec3(vec3_dot(rec->p, w),
				vec3_dot(rec->p, vec3_unit(vec3_cross(pln->d, w))), 0));
	phi = atan2(-vec3_unit(rec->uv).y, vec3_unit(rec->uv).x) + PI;
	phi = ft_modulo(phi + rec->mat_rot_an, 2 * PI);
	rec->uv_cyl = new_vec3(phi / (2 * PI), vec3_len(rec->uv), 0);
}

void	set_map_coord_qud(t_hit_rec *rec)
{
	t_quad	*qud;
	double	phi;
	t_vec3	q;

	qud = &rec->httbl->geom->qud;
	q = vec3_sub2(rec->p, qud->ctr);
	rec->uv = new_vec3(vec3_dot(q, vec3_unit(qud->u)) / vec3_len(qud->u),
			vec3_dot(q, vec3_unit(qud->v)) / vec3_len(qud->v), 0);
	phi = atan2(-vec3_unit(rec->uv).y, vec3_unit(rec->uv).x) + PI;
	phi = ft_modulo(phi + rec->mat_rot_an, 2 * PI);
	rec->uv_cyl = new_vec3(phi / (2 * PI), vec3_len(rec->uv), 0);
}

void	set_map_coord_dsc(t_hit_rec *rec)
{
	t_disc	*dsc;
	double	phi;
	t_vec3	vec;

	dsc = &rec->httbl->geom->dsc;
	vec = vec3_sub2(new_vec3(rec->p.x, rec->p.y, 0),
			new_vec3(dsc->ctr.x, dsc->ctr.y, 0));
	phi = atan2(-vec3_unit(vec).y, vec3_unit(vec).x) + PI;
	phi = ft_modulo(phi + rec->mat_rot_an, 2 * PI);
	rec->uv = new_vec3(phi / (2 * PI), vec3_len(vec) / dsc->rd, 0);
	rec->uv_cyl = rec->uv;
}

void	set_map_coord_sph(t_hit_rec *rec, t_vec3 ctr)
{
	double	theta;
	double	phi;
	t_vec3	unit_vec;

	unit_vec = vec3_unit(vec3_sub2(rec->p, ctr));
	theta = acos(-unit_vec.z);
	phi = atan2(-unit_vec.y, unit_vec.x) + PI;
	phi = ft_modulo(phi + rec->mat_rot_an, 2 * PI);
	rec->uv = new_vec3(phi / (2 * PI), theta / PI, 0);
	rec->uv_cyl = rec->uv;
}

void	set_map_coord_cyl(t_hit_rec *rec, t_vec3 ctr, double h)
{
	double	phi;
	t_vec3	unit_vec;

	unit_vec = vec3_unit(vec3_sub2(new_vec3(rec->p.x, rec->p.y, 0),
				new_vec3(ctr.x, ctr.y, 0)));
	phi = atan2(-unit_vec.y, unit_vec.x) + PI;
	phi = ft_modulo(phi + rec->mat_rot_an, 2 * PI);
	rec->uv = new_vec3(phi / (2 * PI), (rec->p.z - (ctr.z - (h / 2))) / h, 0);
	rec->uv_cyl = rec->uv;
}
