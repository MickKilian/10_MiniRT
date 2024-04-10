/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:21:16 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/04/10 13:06:57 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt.h"

t_httbl	*new_httbl(t_geometry *geom, t_material *mat)
{
	t_httbl	*new_httbl;

	new_httbl = ft_calloc(1, sizeof(t_httbl));
	if (!new_httbl)
		return (NULL);
	new_httbl->next = NULL;
	new_httbl->geom = geom;
	new_httbl->mat = mat;
	return (new_httbl);
}

void	httbl_addback(t_world *world, t_httbl *new_httbl)
{
	if (!new_httbl)
		return ;
	if (!world->httbl)
		world->httbl_head = new_httbl;
	else
	{
		while (world->httbl->next)
			world->httbl = world->httbl->next;
		world->httbl->next = new_httbl;
	}
	world->size += 1;
	world->httbl = world->httbl_head;
	return ;
}

void	httbl_record(t_world *world, t_geometry *geom, t_material *mat)
{
	if (!geom)
		return ;
	else if (geom->type == BOX)
	{
		add_box_quads(world, &geom->box, mat);
		free(geom);
		return ;
	}
	else if (geom->type == DICE)
	{
		add_box_quads(world, &geom->box, mat);
		add_dice_dots(world, &geom->box);
		free(geom);
		return ;
	}
	else if (geom->type == CYLINDER && CLOSE_VOLUMES)
		add_cyl_discs(world, geom, mat);
	else if (geom->type == CONE && CLOSE_VOLUMES)
		add_con_discs(world, geom, mat);
	else if (geom->type == SAFE_CONE)
	{
		create_safe_cone(world, &geom->sfc);
		free(geom);
		return ;
	}
	httbl_addback(world, new_httbl(geom, mat));
}

void	httbl_create(t_rt *rt)
{
	httbl_record(&rt->world, rt->tp.geom, rt->tp.mat);
}
