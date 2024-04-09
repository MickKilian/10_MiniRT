/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_disc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:23:12 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 15:02:21 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_disc	disc(t_vec3 ctr, t_vec3 nrm, double rd)
{
	t_disc	dsc;

	dsc.ctr = ctr;
	dsc.nrm = nrm;
	dsc.rd = rd;
	return (dsc);
}

t_geometry	*geom_disc(t_disc dsc)
{
	t_geometry	*geom;

	geom = ft_calloc(1, sizeof(t_geometry));
	geom->type = DISC;
	geom->dsc = dsc;
	return (geom);
}

bool	hit_disc(t_rt *rt, t_ray r, t_itv tray, t_hit_rec *rec)
{
	t_vec3	nrm;
	double	d;
	t_vec3	p_temp;

	nrm = vec3_unit(rt->world.httbl->geom->dsc.nrm);
	d = vec3_dot(nrm, rt->world.httbl->geom->dsc.ctr);
	if (ft_abs(vec3_dot(nrm, r.dir)) < EPSILON)
		return (0);
	rec->t = (d - vec3_dot(nrm, r.orig)) / vec3_dot(nrm, r.dir);
	if (!cts(tray, rec->t))
		return (0);
	p_temp = hit_pt(r, rec->t);
	if (vec3_len(vec3_sub2(p_temp, rt->world.httbl->geom->dsc.ctr))
		> rt->world.httbl->geom->dsc.rd)
		return (0);
	rec->p = p_temp;
	rec->httbl = rt->world.httbl;
	rec->mat_rot_an = rt->world.httbl->mat->rot_an;
	set_map_coord_dsc(rec);
	set_rec_mat(rt, rec);
	set_face_nrm(r, nrm, rec);
	if (rt->world.httbl->mat->bmp.is_present)
		alter_normal_with_bump(rt, rec);
	return (1);
}
