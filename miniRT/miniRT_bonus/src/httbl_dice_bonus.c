/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_dice_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 02:57:02 by mbourgeo          #+#    #+#             */
/*   Updated: 2024/03/21 07:54:42 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mini_rt_bonus.h"

t_dice	dice(t_vec3 ctr, t_vec3 dir_1, t_vec3 dir_2, double size)
{
	t_dice	dce;

	dce.ctr = ctr;
	dce.u = vec3_unit(dir_1);
	dce.v = vec3_unit(dir_2);
	dce.w = vec3_unit(vec3_cross(dce.u, dce.v));
	dce.h = size;
	return (dce);
}

t_dice_dots	dice_dots(t_vec3 u, t_vec3 v, int code)
{
	t_dice_dots	dice_dots;

	dice_dots.u = u;
	dice_dots.v = v;
	dice_dots.code = code;
	return (dice_dots);
}

t_geometry	*geom_dce(t_box box)
{
	t_geometry	*geom;

	geom = ft_calloc(1, sizeof(t_geometry));
	geom->type = DICE;
	geom->box = box;
	return (geom);
}
