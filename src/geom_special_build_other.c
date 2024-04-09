/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_special_build_other.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/09 21:31:39 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

void	add_box_quads(t_world *world, t_box *box, t_material *mat)
{
	httbl_addback(world, new_httbl(geom_quad(quad(
					vec3_add2(box->ctr, box->w), box->u, box->v)),
			duplicate_mat(mat)));
	httbl_addback(world, new_httbl(geom_quad(quad(
					vec3_add2(box->ctr, box->u),
					vec3_scale(-1, box->w), box->v)), duplicate_mat(mat)));
	httbl_addback(world, new_httbl(geom_quad(quad(
					vec3_add2(box->ctr, vec3_scale(-1, box->w)),
					vec3_scale(-1, box->u), box->v)), duplicate_mat(mat)));
	httbl_addback(world, new_httbl(geom_quad(quad(
					vec3_add2(box->ctr,
						vec3_scale(-1, box->u)), box->w, box->v)),
			duplicate_mat(mat)));
	httbl_addback(world, new_httbl(geom_quad(quad(
					vec3_add2(box->ctr, box->v), box->u,
					vec3_scale(-1, box->w))), duplicate_mat(mat)));
	httbl_addback(world, new_httbl(geom_quad(quad(
					vec3_add2(box->ctr,
						vec3_scale(-1, box->v)), box->u, box->w)),
			duplicate_mat(mat)));
	if (mat->txm.is_present)
		free(mat->txm.path);
	if (mat->bmp.is_present)
		free(mat->bmp.path);
	free(mat);
}

void	add_dice_dots(t_world *world, t_box *box)
{
	add_dice_face(world, box, dice_dots(vec3_scale(-1, box->w), box->v, 16));
	add_dice_face(world, box, dice_dots(box->u, vec3_scale(-1, box->w), 257));
	add_dice_face(world, box, dice_dots(box->u, box->v, 273));
	add_dice_face(world, box, dice_dots(vec3_scale(-1, box->u), box->v, 325));
	add_dice_face(world, box, dice_dots(box->u, box->w, 341));
	add_dice_face(world, box, dice_dots(box->w, box->v, 365));
}

void	add_dice_face(t_world *world, t_box *box, t_dice_dots dice_dots)
{
	int		i;
	t_disc	new_disc;

	i = 0;
	while (dice_dots.code)
	{
		if (dice_dots.code % 2)
		{
			new_disc = disc(vec3_add2(box->ctr,
						vec3_add2(vec3_add2(
								vec3_scale(0.66 * (i % 3 - 1), dice_dots.u),
								vec3_scale(0.66 * (i / 3 - 1), dice_dots.v)),
							vec3_cross(dice_dots.u, dice_dots.v))),
					vec3_unit(vec3_cross(dice_dots.u, dice_dots.v)),
					vec3_len(dice_dots.u) / 5);
			httbl_addback(world, new_httbl(geom_disc(new_disc),
					mat_lamber(lamber(new_vec3(1, 1, 1)))));
		}
		dice_dots.code /= 2;
		i++;
	}
}

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
