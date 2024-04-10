/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_special_build_other.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 23:28:10 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	add_cyl_discs(t_world *world, t_geometry *geom, t_material *mat)
{
	t_vec3	begin_disc_ctr;
	t_vec3	end_disc_ctr;
	t_vec3	gen;

	begin_disc_ctr = tra_v(rot_v(vec3_add2(geom->cyl.ctr,
					vec3_scale(-geom->cyl.h / 2, geom->cyl.gen)),
				geom->trsf_i.rot_ax, geom->trsf_i.rot_an), geom->trsf.tra);
	gen = rot_v(geom->cyl.gen,
			geom->trsf_i.rot_ax, geom->trsf_i.rot_an);
	httbl_addback(world, new_httbl(geom_disc(disc(begin_disc_ctr, gen,
					geom->cyl.rd)), duplicate_mat(mat)));
	end_disc_ctr = tra_v(rot_v(vec3_add2(geom->cyl.ctr,
					vec3_scale(geom->cyl.h / 2, geom->cyl.gen)),
				geom->trsf_i.rot_ax, geom->trsf_i.rot_an), geom->trsf.tra);
	httbl_addback(world, new_httbl(geom_disc(disc(end_disc_ctr,
					gen, geom->cyl.rd)), duplicate_mat(mat)));
}
