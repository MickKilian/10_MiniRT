/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_special_build_con.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/23 10:03:59 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	add_con_discs(t_world *world, t_geometry *geom, t_material *mat)
{
	t_vec3	begin_disc_ctr;
	t_vec3	end_disc_ctr;
	t_vec3	gen;

	begin_disc_ctr = tra_v(rot_v(geom->con.b_ctr,
				geom->trsf_i.rot_ax, geom->trsf_i.rot_an), geom->trsf.tra);
	gen = rot_v(geom->con.gen,
			geom->trsf_i.rot_ax, geom->trsf_i.rot_an);
	httbl_addback(world, new_httbl(geom_disc(disc(begin_disc_ctr, gen,
					geom->con.r_max)), duplicate_mat(mat)));
	if (geom->con.r_min)
	{
		end_disc_ctr = tra_v(rot_v(vec3_add2(geom->con.b_ctr,
						vec3_scale(geom->con.h, geom->con.gen)),
					geom->trsf_i.rot_ax, geom->trsf_i.rot_an), geom->trsf.tra);
		httbl_addback(world, new_httbl(geom_disc(disc(end_disc_ctr,
						gen, geom->con.r_min)),
				duplicate_mat(mat)));
	}
}

void	create_safe_cone(t_world *world, t_safe_cone *sfc)
{
	int			i;
	t_vec3		pos;
	double		rot_an;
	t_material	*mat;

	i = 5;
	rot_an = acos(vec3_dot(new_vec3(0, 0, 1), sfc->gen));
	if (fabs(rot_an - PI) < EPSILON)
		create_safe_cone_base(world, sfc, new_vec3(0, 1, 0), rot_an);
	else
		create_safe_cone_base(world, sfc, vec3_unit(
				vec3_cross(new_vec3(0, 0, 1), sfc->gen)), rot_an);
	pos = sfc->b_ctr;
	while (i-- > 0)
	{
		if (!(i % 2))
			mat = mat_lamber(lamber(new_vec3(1, 0.2, 0)));
		else
			mat = mat_lamber(lamber(new_vec3(1, 1, 1)));
		httbl_record(world, geom_cone(cone(pos,
					vec3_scale(sfc->h / 5, sfc->gen),
					sfc->r_min + (i + 1) * sfc->r_step,
					sfc->r_min + i * sfc->r_step)), mat);
		pos = vec3_add2(pos, vec3_scale(sfc->h / 5, sfc->gen));
	}
}

void	create_safe_cone_base(t_world *world, t_safe_cone *sfc,
		t_vec3 rot_ax, double rot_an)
{
	t_vec3	pos;

	pos = vec3_add2(sfc->b_ctr,
			vec3_scale(sfc->h / 100, sfc->gen));
	httbl_record(world, geom_box(box(new_vec3(pos.x, pos.y, pos.z),
				rot_v(new_vec3((sfc->r_max * 6.0 / 5.0), 0, 0),
					rot_ax, rot_an),
				rot_v(new_vec3(0, (sfc->r_max * 6.0 / 5.0), 0),
					rot_ax, rot_an),
				rot_v(new_vec3(0, 0, sfc->h / 100),
					rot_ax, rot_an))),
		mat_lamber(lamber(new_vec3(1, 0.2, 0))));
}
